#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *file = fopen("wejscie_1_2.txt", "r");
    if (file == NULL) {
        printf("Błąd wejścia");
        return 1;
    }

    int n, m;

    fscanf(file, "%d %d", &n, &m);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(m * sizeof(double));
    }

    // Read the matrix from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int A;
            fscanf(file, "%d", &A);
            matrix[i][j] = (pow(sin(A), 2)-3)/sqrt(A+1);
            if(A <= -1) matrix[i][j] = 3.31;
            // printf("for %d:       %f / %f = %f but %f\nsin(A) = %f\npow() = %f\n", A, (pow(sin(A), 2)-3), sqrt(A+1), (pow(sin(A), 2)-3)/sqrt(A+1), matrix[i][j], sin(A), pow(sin(A), 2));
            // matrix[i][j] = A;
        }
    }

    fclose(file);

    // Wypisywanie pobranej macierzy
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
