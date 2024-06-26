#include <stdio.h>
#include <stdlib.h>

// Function prototypes: parameters: h= height(rows), w=width(columns)
float **add_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float **multiply(float** a, int ah, int aw, float** b, int bh, int bw);
float **transpose_matrix(float** a, int ah, int aw);
float **make2dArray(int rows, int cols);
void free2dArray(float** arr, int rows);

int main() {
    char s; // User operation selection
    printf("What operation do you want? ('a' for addition, 'm' for multiplication, 't' for transpose)\n");
    scanf(" %c", &s);

    // Allow only 'a', 'm', 't' inputs
    while (s != 'a' && s != 'm' && s != 't') {
        printf("Please select 'a', 'm', or 't':\n");
        scanf(" %c", &s);
    }

    // Input file names
    char file1[100], file2[100];
    printf("Input file names:\n");
    scanf("%s", file1);

    if (s != 't') {
        scanf("%s", file2);
    }

    FILE *f1 = fopen(file1, "r");
    FILE *f2 = NULL;

    if (s != 't') {
        f2 = fopen(file2, "r");
    }

    if (f1 == NULL || (s != 't' && f2 == NULL)) {
        printf("Error finding file :(\n");
        return 1;
    }

    int rows1, cols1, rows2, cols2;

    // Read dimensions
    fscanf(f1, "%d %d", &rows1, &cols1);
    if (s != 't') {
        fscanf(f2, "%d %d", &rows2, &cols2);
    }

    // Dimension check for addition
    if (s == 'a' && (rows1 != rows2 || cols1 != cols2)) {
        printf("Matrix dimensions mismatch for addition\n");
        return 1;
    }

    // Read elements
    float **matrix1 = make2dArray(rows1, cols1);
    float **matrix2 = NULL;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            fscanf(f1, "%f", &matrix1[i][j]);
        }
    }

    if (s != 't') {
        matrix2 = make2dArray(rows2, cols2);
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                fscanf(f2, "%f", &matrix2[i][j]);
            }
        }
    }

    fclose(f1);
    if (s != 't') {
        fclose(f2);
    }

    float **result = NULL;
    int finalR, finalC;

    switch(s) {
        case 'a': // Addition
            result = add_matrix(matrix1, rows1, cols1, matrix2, rows2, cols2);
            finalR = rows1;
            finalC = cols1;
            break;
        case 'm': // Multiplication
            result = multiply(matrix1, rows1, cols1, matrix2, rows2, cols2);
            finalR = rows1;
            finalC = cols2;
            break;
        case 't': // Transpose
            result = transpose_matrix(matrix1, rows1, cols1);
            finalR = cols1;
            finalC = rows1;
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }

    // Print the output
    printf("The output is:\n");
    printf("%d %d\n", finalR, finalC);
    for (int i = 0; i < finalR; i++) {
        for (int j = 0; j < finalC; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    // Free matrices
    free2dArray(matrix1, rows1);
    if (s != 't') {
        free2dArray(matrix2, rows2);
    }
    free2dArray(result, finalR);

    return 0;
}

// Function to add matrices
float **add_matrix(float** a, int ah, int aw, float** b, int bh, int bw) {
    float **result = make2dArray(ah, aw);
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < aw; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

// Function to multiply matrices
float **multiply(float** a, int ah, int aw, float** b, int bh, int bw) {
    if (aw != bh) {
        printf("Matrix dimensions mismatch for multiplication\n");
        exit(1);
    }
    float **result = make2dArray(ah, bw);
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < bw; j++) {
            result[i][j] = 0;
            for (int k = 0; k < aw; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

// Function to transpose matrix
float **transpose_matrix(float** a, int ah, int aw) {
    float **result = make2dArray(aw, ah);
    for (int i = 0; i < aw; i++) {
        for (int j = 0; j < ah; j++) {
            result[i][j] = a[j][i];
        }
    }
    return result;
}

// Function to allocate memory
float **make2dArray(int rows, int cols) {
    float **arr = (float **)malloc(rows * sizeof(float *));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = (float *)malloc(cols * sizeof(float));
        if (arr[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
    return arr;
}

// Function to free memory
void free2dArray(float** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}
