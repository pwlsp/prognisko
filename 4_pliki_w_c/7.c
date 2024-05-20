#include <stdio.h>

int main()
{
    FILE *plik, *temporary;
    plik = fopen("plik.txt", "r");
    temporary = fopen("temporary_file.txt", "w");
    char drugi_format[] = {'-', 'A', '1', 'a', '1', 'a'};

    int format = 1;
    printf("wybierz format wyjściowy (1-2): ");
    scanf("%d", &format);
    if (format != 1 && format != 2)
    {
        printf("Niepoprawny format. Wybieram format 1.");
        format = 1;
    }

    int ile_naglowkow[15];
    for (int i = 0; i < 15; i++)
    {
        ile_naglowkow[i] = 0;
    }

    char linia[200];

    while (fgets(linia, 200, plik))
    {
        int i = 0;
        while (linia[i] == '*')
        {
            i++;
        }
        int gwiazd = i;
        ile_naglowkow[gwiazd]++;

        for (int j = gwiazd+1; j < 15; j++){
            ile_naglowkow[j] = 0;
        }

        i++;

        if (gwiazd > 0){
            for(int t = 0; t<gwiazd-1; t++){
                fprintf(temporary, "\t");
            }
            if (format == 1){
                for (int n = 1; n <= gwiazd; n++){
                    fprintf(temporary, "%d.", ile_naglowkow[n]);
                }
            }
            if(format == 2){
                    if(gwiazd > 3){
                        fprintf(temporary, "(%c)", drugi_format[gwiazd] + ile_naglowkow[gwiazd]-1);
                    }
                    else{
                        fprintf(temporary, "%c.", drugi_format[gwiazd] + ile_naglowkow[gwiazd]-1);
                    }
                }
            fprintf(temporary, " ");
        }

        fprintf(temporary, "%s", &linia[i]);
    }

    fclose(plik);
    fclose(temporary);

    FILE *cel, *z;
    cel = fopen("plik.txt", "w");
    z = fopen("temporary_file.txt", "r");

    //Teraz przepisujemy z temporary do oryginalnego

    char linia2[200];

    while (fgets(linia2, 200, z))
    {
        fprintf(cel, "%s", linia2);
    }

    remove("temporary_file.txt");

    printf("\nZ treści zadania zrozumiałem, że konwersja ma zostać przeprowadzona na oryginalnym pliku.\nDlatego tworzę plik pomocniczy i potem przepisuję z powrotem do oryginalnego jego zawartość i go usuwam.\nZ tego powodu trzeba przywracać plik wejściowy do stanu sprzed konwersji.\nKonwersja formatu powinna być widoczna w pliku wejściowym \"plik.txt\"\n");

    

    return 0;
}