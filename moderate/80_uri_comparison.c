#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_LEN            1024
#define MAX_SCHEME_LENGTH   6
#define MAX_HOST_LENGTH     100

char *unquote(const char *quoted, char *unquoted) {
    char *result = unquoted;

    while (*quoted) {
        if ((*quoted == '%') && *(quoted+1) && *(quoted+2) &&
            isxdigit(*(quoted+1)) && isxdigit(*(quoted+2))) {
                char c;
                if (*(quoted+1) >= 'A')
                    c = *(quoted+1) - 'A' + 10;
                else if (*(quoted+1) >= 'a')
                    c = *(quoted+1) - 'a' + 10;
                else
                    c = *(quoted+1) - '0';
                c *= 16;

                if (*(quoted+2) >= 'A')
                    c += *(quoted+2) - 'A' + 10;
                else if (*(quoted+2) >= 'a')
                    c += *(quoted+2) - 'a' + 10;
                else
                    c += *(quoted+2) - '0';
                *result++ = c;
                quoted += 3;
        }
        else
            *result++ = *quoted++;
    }
    *result = '\0';

    return unquoted;
}

char *get_scheme(char *uri, char *scheme) {
    char *p;
    char *tmp_scheme = scheme;

    if (p = strstr(uri, "://")) {
        while (uri < p)
            *tmp_scheme++ = tolower(*uri++);
    }
    *tmp_scheme = '\0';

    return scheme;
}

char *get_host(char *uri, char *host) {
    char *tmp_host = host;

    if (uri = strstr(uri, "://")) {
        uri += 3;
        while (*uri && *uri != ':' && *uri != '/')
            *tmp_host++ = tolower(*uri++);
    }
    *tmp_host = '\0';

    return host;
}

int get_port(char *uri) {
    /* Extract and return the remote host's port as an int.
     * Default to 80 if not present in `uri`.
     */
    int port = 80;

    if (uri = strstr(uri, "://")) {
        /* skip over host */
        uri += 3;
        while (*uri && *uri != ':' && *uri != '/')
            uri++;

        if (*uri && *uri == ':') {
           port = atoi(uri+1);
        }
    }

    return port;
}

char *locate_path(char *uri) {
    /* Returns a pointer to the first character of the path component of the
     * given URI. This is the first character following the host:port.
     */
    if (uri = strstr(uri, "://")) {
        /* skip over host */
        uri += 3;
        while (*uri && *uri != ':' && *uri != '/')
            uri++;

        /* skip over port if present */
        if (*uri && *uri == ':') {
            uri++;
            while (isdigit(*uri))
                uri++;
        }
    }

    return uri;
}

int uri_compare(const char *uri_1, const char *uri_2) {
    char unquoted_1[LINE_LEN];
    char unquoted_2[LINE_LEN];
    char scheme_1[MAX_SCHEME_LENGTH+1];
    char scheme_2[MAX_SCHEME_LENGTH+1];
    char host_1[MAX_HOST_LENGTH+1];
    char host_2[MAX_HOST_LENGTH+1];

    unquote(uri_1, unquoted_1);
    unquote(uri_2, unquoted_2);

#ifdef DEBUG
    printf("comparing unquoted_1 = '%s'\n          "
           "unquoted_2 = '%s'\n", unquoted_1, unquoted_2);
    printf("schemes? %s\n",
                strcmp(get_scheme(unquoted_1, scheme_1),
                       get_scheme(unquoted_2, scheme_2)) ? "no" : "yes");
    printf("hosts? %s\n",
                strcmp(get_host(unquoted_1, host_1),
                       get_host(unquoted_2, host_2)) ? "no" : "yes");
    printf("ports? %s\n",
                (get_port(unquoted_1) == get_port(unquoted_2)) ? "yes" : "no");
    printf("paths? %s\n",
                strcmp(locate_path(unquoted_1),
                       locate_path(unquoted_2)) ? "no" : "yes");
#endif

    return (!strcmp(get_scheme(unquoted_1, scheme_1),
                    get_scheme(unquoted_2, scheme_2)) &&
            !strcmp(get_host(unquoted_1, host_1),
                    get_host(unquoted_2, host_2)) &&
            (get_port(unquoted_1) == get_port(unquoted_2)) &&
            !strcmp(locate_path(unquoted_1), locate_path(unquoted_2)));
}


int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        /* get rid of any newline character */
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        char *uri_1 = line;
        char *uri_2 = strchr(line, ';');
        *uri_2 = '\0';
        uri_2++;

        if (uri_compare(uri_1, uri_2))
            printf("True\n");
        else
            printf("False\n");
    }

    return 0;
}
