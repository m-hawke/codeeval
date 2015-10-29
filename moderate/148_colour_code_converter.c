#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define LINE_LEN            1024

typedef struct rgb {
    float r;
    float g;
    float b;
} RGB;


void HSVtoRGB(float h, float s, float v, RGB *rgb)
{
    int i;
    float f, p, q, t;

    if( s == 0 ) {
        // achromatic (grey)
        rgb->r = rgb->g = rgb->b = round(v*255);
        return;
    }

    h /= 60;            // sector 0 to 5
    i = floor( h );
    f = h - i;          // factorial part of h
    p = v * ( 1 - s );
    q = v * ( 1 - s * f );
    t = v * ( 1 - s * ( 1 - f ) );

    switch( i ) {
        case 0:
            rgb->r = v; rgb->g = t; rgb->b = p;
            break;
        case 1:
            rgb->r = q; rgb->g = v; rgb->b = p;
            break;
        case 2:
            rgb->r = p; rgb->g = v; rgb->b = t;
            break;
        case 3:
            rgb->r = p; rgb->g = q; rgb->b = v;
            break;
        case 4:
            rgb->r = t; rgb->g = p; rgb->b = v;
            break;
        default:        // case 5:
            rgb->r = v; rgb->g = p; rgb->b = q;
            break;
    }

    rgb->r = round(rgb->r * 255);
    rgb->g = round(rgb->g * 255);
    rgb->b = round(rgb->b * 255);
}

void HSLtoRGB(float h, float s, float l, RGB *rgb)
{
    float v;

    rgb->r = rgb->g = rgb->b = l;   /* default */

    v = (l <= 0.5) ? (l * (1.0 + s)) : (l + s - l * s);
    if (v > 0)
    {
        float m;
        float sv;
        int sextant;
        float fract, vsf, mid1, mid2;

        m = l + l - v;
        sv = (v - m ) / v;
        h /= 60;
        sextant = (int)h;
        fract = h - sextant;
        vsf = v * sv * fract;
        mid1 = m + vsf;
        mid2 = v - vsf;

        switch (sextant) {
            case 0:
                rgb->r = v; rgb->g = mid1; rgb->b = m;
                break;
            case 1:
                rgb->r = mid2; rgb->g = v; rgb->b = m;
                break;
            case 2:
                rgb->r = m; rgb->g = v; rgb->b = mid1;
                break;
            case 3:
                rgb->r = m; rgb->g = mid2; rgb->b = v;
                break;
            case 4:
                rgb->r = mid1; rgb->g = m; rgb->b = v;
                break;
            case 5:
                rgb->r = v; rgb->g = m; rgb->b = mid2;
                break;
        }
    }

    rgb->r = round(rgb->r * 255);
    rgb->g = round(rgb->g * 255);
    rgb->b = round(rgb->b * 255);
}

void CMYK_to_RGB(float c, float m, float y, float k, RGB *rgb) {
    rgb->r = round(255 * (1-c) * (1-k));
    rgb->g = round(255 * (1-m) * (1-k));
    rgb->b = round(255 * (1-y) * (1-k));
}

void hex_to_RGB(char *hex_string, RGB *rgb) {
    int value;
    sscanf(hex_string+1, "%2x", &value); rgb->r = value;
    sscanf(hex_string+3, "%2x", &value); rgb->g = value;
    sscanf(hex_string+5, "%2x", &value); rgb->b = value;
}


int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    RGB rgb;

    while (fgets(line, LINE_LEN, file)) {
        if (line[0] == '#') {
            hex_to_RGB(line, &rgb);
        }
        else if (line[0] == '(') {
            float c = atof(strtok(line+1, ","));
            float m = atof(strtok(NULL, ","));
            float y = atof(strtok(NULL, ","));
            float k = atof(strtok(NULL, ","));
            CMYK_to_RGB(c, m, y, k, &rgb);
        }
        else if (!strncmp(line, "HSV", 3)) {
            int h = atoi(strtok(line+4, ","));
            int s = atoi(strtok(NULL, ","));
            int v = atoi(strtok(NULL, ","));
            HSVtoRGB(h, s/100.0, v/100.0, &rgb);
        }
        else if (!strncmp(line, "HSL", 3)) {
            int h = atoi(strtok(line+4, ","));
            int s = atoi(strtok(NULL, ","));
            int l = atoi(strtok(NULL, ","));
            HSLtoRGB(h, s/100.0, l/100.0, &rgb);
        }

        printf("RGB(%d,%d,%d)\n", (int)rgb.r, (int)rgb.g, (int)rgb.b);
    }

    return 0;
}
