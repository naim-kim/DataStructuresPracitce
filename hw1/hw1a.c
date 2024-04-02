// Data Structures-02   22000056 김나임

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

    while (fscanf(file, "%d", &number) == 1) {
        if (number < smallest) {
            smallest = number;
        }
    }

    fclose(file);

    printf("The smallest number is %d\n", smallest);

    return 0;
}
