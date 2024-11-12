// KopirujSoubor.cpp : Tento soubor obsahuje funkci main. Provádìní programu se tam zahajuje a ukonèuje.
//

#include <iostream>
#include <Windows.h>

//*** nadefinujeme si navratove kody
#define CHYBA_SOURCE_CANT_OPEN -1
#define CHYBA_DESTINATION_CANT_CREATE -2
#define CHYBA_DISK_FULL -3
#define VSE_OK 0


void AlokujBuffer(unsigned char** data, int delka) {
    *data = (unsigned char*)malloc(sizeof(unsigned char) * delka);
}

void UvolniBuffer(unsigned char** buffer) {
    free(*buffer);
}

void ZobrazUkazatelStavu(unsigned int stav, unsigned int celkem) {
    float procenta = 100.0f / celkem * stav;
    printf("Zkopirovano: %.2f%% [", procenta);
    for (int i = 0; i < (int)(procenta / 10); i++) printf("#");
    for (int i = (int)(procenta / 10); i < 10; i++) printf(".");
    printf("]\r");
}

int KopirujSoubor(char* zdrojsoubor, char* cilsoubor, int buffervelikost, unsigned char** buffer) {
    FILE* souborodkud;
    FILE* souborkam;

    //*** naalokujeme pomocnou pamet, pres kterou se budou kopirovat data
    AlokujBuffer(buffer, buffervelikost);

    if (fopen_s(&souborodkud, zdrojsoubor, "rb") != 0) {
        printf("Nemohu otevrit zdrojovy soubor.\n");
        return(CHYBA_SOURCE_CANT_OPEN); //*** navrat s chybovym kodem
    }

    if (fopen_s(&souborkam, cilsoubor, "wb") != 0) {
        printf("Nemohu vytvorit cilovy soubor.\n");
        return(CHYBA_DESTINATION_CANT_CREATE); //*** navrat s chybovym kodem
    }

    //*** zjistime velikost souboru - metoda s vyuzitim cisteho C
    fseek(souborodkud, 0, SEEK_END); // presuneme se na konec souboru
    int velikost_souboru = ftell(souborodkud); // zjistime aktualni hodnotu ukazatele v souboru
    fseek(souborodkud, 0, SEEK_SET); // presuneme se na zacatek souboru
    printf("Velikost souboru je: %d\n", velikost_souboru);

    size_t nacteno; // pocet nactenych bajtu
    size_t zapsano; // pocet zapsanych bajtu
    unsigned int precteno_bajtu = 0; // kolik bajtu jsme jiz precetli

    do {
        nacteno = fread_s(*buffer, buffervelikost, 1, buffervelikost, souborodkud); // pokud se podivate na vstupni parametry tak velikost elementu je 1(bajt) pocet elementu je buffer size
        zapsano = fwrite(*buffer, 1, nacteno, souborkam);
        if (zapsano < nacteno) { //*** kdyz je pocet zapsanych mensi nez pocet prectenych, tak na cilovem adresari neni misto, nebo je tam nejaka chyba
            printf("Na cilovem disku neni dost mista!");
            fclose(souborodkud);
            return(CHYBA_DISK_FULL);
        }
        precteno_bajtu += nacteno;
        ZobrazUkazatelStavu(precteno_bajtu, velikost_souboru);
    } while (nacteno == buffervelikost);  //*** nacitame dokud nenacteme mene bajtu, nez je velikost bufferu -> dosahli jsme konec souboru, nacetli jsme uz vsechno.

    //*** musime uzavrit soubory, jinak budou mit velikost nula
    fclose(souborkam);
    fclose(souborodkud);

    UvolniBuffer(buffer);

    return(VSE_OK); //*** ukoncime s OK kodem
}

int main()
{
    char file_source[1024];
    char file_destination[1024];
    int buffer_size;
    unsigned char* buffer;

    printf("Supr kopy by 21-5KB\n=========================\n\n");
    printf("Zadej cestu a jmeno zdrojoveho souboru: ");
    scanf_s("%s", file_source, 1024);
    printf("Zadej cestu a jmeno ciloveho souboru: ");
    scanf_s("%s", file_destination, 1024);
    printf("Zadej velikost mezipameti v bajtech: ");
    scanf_s("%d", &buffer_size);

    DWORD startime = GetTickCount();

    if (KopirujSoubor(file_source, file_destination, buffer_size, &buffer) != VSE_OK) {
        printf("Kopirovani se nezdarilo.\n");
    }

    DWORD copytime = GetTickCount() - startime;
    printf("\n");

    printf("Kopirovani trvalo: %d ms coz je: %d s %d ms\n", copytime, copytime / 1000, copytime % 1000);
}