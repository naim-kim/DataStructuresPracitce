#include <stdio.h>
#include <stdlib.h> // atof
#include <string.h>

int main() {
    FILE *file;
    char filename[500];
    float sum = 0;
    char text[500];

    printf("Input filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("No file found :(\n");
        return 1;
    }
    
    while (fscanf(file, "%s", text) != EOF) {
        int i;
        for (i = 0; text[i] != '\0'; i++) {
            if ((text[i] >= '0' && text[i] <= '9') || text[i] == '.') {
                float number = atof(&text[i]);
                sum += number;
                //printf("number: %.2f sum= %.2f\n", number,sum);
                break;
            }
        }
    }

    fclose(file);

    printf("The sum is %.2f\n", sum);

    return 0;
}
