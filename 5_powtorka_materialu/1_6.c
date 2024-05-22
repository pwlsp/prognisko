#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *wejA = fopen("wejscie_1_6_A.txt", "r");
    if (wejA == NULL) {
        printf("Błąd wejścia A");
        return 1;
    }
    FILE *wejB = fopen("wejscie_1_6_B.txt", "r");
    if (wejB == NULL) {
        printf("Błąd wejścia B");
        return 1;
    }

    int n, m, nb, mb;

    fscanf(wejA, "%d %d", &n, &m);
    fscanf(wejB, "%d %d", &nb, &mb);

    if (n != nb || m != mb) {
        printf("Podane wielkości macierzy A i B różnią się");
        return 1;
    }

    int **R = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        R[i] = (int *)malloc(m * sizeof(int));
    }
    int **P = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        P[i] = (int *)malloc(m * sizeof(int));
    }

    // Read the matrix from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int A, B;
            fscanf(wejA, "%d", &A);
            fscanf(wejB, "%d", &B);
            if(A != B) R[i][j] = 0;
            else R[i][j] = 1;
            if(A <= B) P[i][j] = 0;
            else P[i][j] = 1;
            
            // if(A<=B)

            // R[i][j] = A;
        }
    }

    fclose(wejA);
    fclose(wejB);

    // Wypisywanie macierzy
    printf("Program na wejściu pobiera dwa pliki, których pierwsze wiersze zawierają n i m.\n\n");
    printf("R:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    printf("\nP:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(R[i]);
    }
    free(R);
    for (int i = 0; i < n; i++) {
        free(P[i]);
    }
    free(P);

    return 0;
}
