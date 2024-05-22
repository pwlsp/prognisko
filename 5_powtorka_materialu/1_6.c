#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void oblicz_R(int **A, int **B, int **R, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] != B[i][j])
                R[i][j] = 0;
            else
                R[i][j] = 1;
        }
    }
}
void oblicz_P(int **A, int **B, int **P, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] <= B[i][j])
                P[i][j] = 0;
            else
                P[i][j] = 1;
        }
    }
}

int main()
{
    FILE *wejA = fopen("wejscie_1_6_A.txt", "r");
    if (wejA == NULL)
    {
        printf("Błąd wejścia A");
        return 1;
    }
    FILE *wejB = fopen("wejscie_1_6_B.txt", "r");
    if (wejB == NULL)
    {
        printf("Błąd wejścia B");
        return 1;
    }

    int n, m, nb, mb;

    fscanf(wejA, "%d %d", &n, &m);
    fscanf(wejB, "%d %d", &nb, &mb);

    if (n != nb || m != mb)
    {
        printf("Podane wielkości macierzy A i B różnią się");
        return 1;
    }

    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        A[i] = (int *)malloc(m * sizeof(int));
    }
    int **B = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        B[i] = (int *)malloc(m * sizeof(int));
    }
    int **R = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        R[i] = (int *)malloc(m * sizeof(int));
    }
    int **P = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        P[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int Aa, Bb;
            fscanf(wejA, "%d", &Aa);
            A[i][j] = Aa;
            fscanf(wejB, "%d", &Bb);
            B[i][j] = Bb;

            // R[i][j] = A;
        }
    }

    fclose(wejA);
    fclose(wejB);

    // Wypisywanie macierzy
    printf("Program na wejściu pobiera dwa pliki, których pierwsze wiersze zawierają n i m.\n\n");
    printf("A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    oblicz_P(A, B, P, n, m);
    oblicz_R(A, B, R, n, m);

    printf("\n");
    printf("R:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    printf("\nP:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }

    // zwalnianie pamięci
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < n; i++)
    {
        free(B[i]);
    }
    free(B);
    for (int i = 0; i < n; i++)
    {
        free(R[i]);
    }
    free(R);
    for (int i = 0; i < n; i++)
    {
        free(P[i]);
    }
    free(P);

    // printf("\ntest\n");

    return 0;
}
