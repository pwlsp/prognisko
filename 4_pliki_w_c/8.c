#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DLUGOSC_LINI 1000
#define MAX_KOLUMN 100

int main() {
    FILE *wej = fopen("wejscie.txt", "r");
    if (wej == NULL) {
        printf("blad wejscia");
        exit(1);
    }

    int sumy[MAX_KOLUMN] = {0};
    int wystapienia[MAX_KOLUMN] = {0};
    char wiersz[MAX_DLUGOSC_LINI];

    while (fgets(wiersz, sizeof(wiersz), wej)) {
        int liczba;
        char *ptr = wiersz;
        int kolumna = 0;

        while (sscanf(ptr, "%d", &liczba) == 1) {
            sumy[kolumna] += liczba;
            wystapienia[kolumna] += 1;
            kolumna++;

            // Move to the next number in the wiersz
            while (*ptr != ' ' && *ptr != '\0') {
                ptr++;
            }
            while (*ptr == ' ') {
                ptr++;
            }
        }
    }

    fclose(wej);

    FILE *wyj = fopen("wyjscie.txt", "w");
    if (wyj == NULL) {
        printf("błąd pliku wyjściowego");
        exit(1);
    }

    fprintf(wyj, "Suma:");
    for (int i = 0; i < MAX_KOLUMN; i++) {
        if (wystapienia[i] > 0) {
            fprintf(wyj, " %d", sumy[i]);
        }
    }
    fprintf(wyj, "\n");

    fprintf(wyj, "Średnia:");
    for (int i = 0; i < MAX_KOLUMN; i++) {
        if (wystapienia[i] > 0) {
            fprintf(wyj, " %.2f", (float)sumy[i] / wystapienia[i]);
        }
    }
    fprintf(wyj, "\n");

    fclose(wyj);

    return 0;
}
