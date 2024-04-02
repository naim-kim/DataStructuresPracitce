// Data Structures-02   22000056 김나임

#include <stdio.h>

int main() {
    FILE *file;
    int number, smallest;
    char filename[100];
    char ch;
    int alphabet[26] = {0};
    int numbers[10] = {0};

    printf("Input filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("No file found :(\n");
        return 1;
    }
 
    while ((ch = fgetc(file)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            alphabet[ch - 'a']++;
        } else if (ch >= '0' && ch <= '9') {
            numbers[ch - '0']++;
        }
    }
    
    fclose(file);
    
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, alphabet[i]); // uppercase
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, numbers[i]);
    }
    
    return 0;
}