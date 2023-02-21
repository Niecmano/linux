#include <stdio.h>
#include <string.h>

    int contains(char red[], char kljucnaRec[]);

    int main(int argc, char* argv[]) {

        char fajl[50];
        strcpy(fajl, argv[2]);
        char izraz[50];
        strcpy(izraz, argv[1]);
        char red[150] = "";

        FILE* fp = fopen(fajl, "r");
        if (fp == NULL) {
            printf("Greska! Prosledjeni fajl ne postoji\n");
            return -1;
        }

  
        while (fgets(red, sizeof(red), fp)) {

            red[strcspn(red, "\n")] = '\0';
            if (contains(red, izraz)) printf("%s\n", red);
        }

        fclose(fp);
        return 0;
    }

    int contains(char red[], char izraz[]) {

           int n1 = strlen(red);
           int n2 = strlen(izraz);
           int i, j;
           
           for (i = 0; i <= n1 - n2; i++) {
	               for (j = 0; j < n2; j++) {
                   if (red[i+j] != izraz[j]) break;
               }
               
               if (j == n2) return 1;
            }
           return 0;
    }

