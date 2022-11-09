#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main() {
    char* fi = "C:\\Users\\lucas\\source\\untitled2\\tt.txt";
    FILE *f = fopen(fi, "r");
    char str1[MAX],str2[MAX],str3[MAX];
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    printf("hi");

    while(!feof(f)){
        fgets(str1, sizeof(str1),f);
        puts(str1);
}


    fclose(f);

    return 0;


    }

