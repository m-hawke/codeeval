#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int age;

    while (fgets(line, 1024, file)) {
        sscanf(line, "%d", &age);

        if (0 <= age && age <= 2)
            printf("Still in Mama's arms\n");
        else if (3 <= age && age <= 4)
            printf("Preschool Maniac\n");
        else if (5 <= age && age <= 11)
            printf("Elementary school\n");
        else if (12 <= age && age <= 14)
            printf("Middle school\n");
        else if (15 <= age && age <= 18)
            printf("High school\n");
        else if (19 <= age && age <= 22)
            printf("College\n");
        else if (23 <= age && age <= 65)
            printf("Working for the man\n");
        else if (66 <= age && age <= 100)
            printf("The Golden Years\n");
        else
            printf("This program is for humans\n");
    }

    return 0;
}
