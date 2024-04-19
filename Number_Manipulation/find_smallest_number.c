#include <stdio.h>

int main() {
    FILE *file;
    int number, smallest;
    char filename[100];

    printf("Input filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("No file found :(\n");
        return 1;
    }

    printf("Numbers in %s: \n", filename);

    while (fscanf(file, " %d", &number) == 1) {
        printf("%d\n", number);
        if (number < smallest) {
            smallest = number;
        }
    }

    fclose(file);

    printf("The smallest number is %d\n", smallest);

    return 0;
}
