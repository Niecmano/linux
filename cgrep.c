#include <stdio.h>
#include <string.h>

int contains(char red[150], char kljucnaRec[10]);

int main(int argc, char* argv[]) {

    char fajl[10];
    strcpy(fajl, argv[2]);
    char kljucnaRec[10];
    strcpy(kljucnaRec, argv[1]);
    char red[150] = "";

    FILE* fp = fopen(fajl, "r");
    if (fp == NULL) {
        printf("Greska! Prosledjeni fajl ne postoji\n");
        return 1;
    }

    while (fgets(red, sizeof(red), fp)) {
        
        red[strcspn(red, "\n")] = '\0';
        if (contains(red, kljucnaRec)) printf("%s\n", red);
    }

    fclose(fp);
    return 0;
}

int contains(char red[150], char kljucnaRec[10]) {

    char nizReci[40][40];
    int word = 0;
    int kar = 0;

    for (int i = 0; red[i] != '\0'; i++) {
        if (red[i] != ' ') {
            nizReci[word][kar] = red[i];
            kar++;
        }
        else {
            nizReci[word][kar] = '\0';
            word++;
            kar = 0;
        }
    }

    nizReci[word][kar] = '\0';
    for (int i = 0; i <= word; i++) {
        if (!strcmp(kljucnaRec, nizReci[i])) return 1;
    }
    return 0;
}
