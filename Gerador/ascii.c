#include <stdio.h>

int main(){
    FILE *arquivo;

    arquivo = fopen("Arquivos/Ascii.txt", "w");

    int init = 32, end = 126;

    for(int i=init; i<=end; i+=5){
        fprintf(arquivo, "%3d\t%c", i, (char)i);
        fprintf(arquivo, "\t%3d\t%c", i+1, (int) i+1);
        fprintf(arquivo, "\t%3d\t%c", i+2, (int) i+2);
        fprintf(arquivo, "\t%3d\t%c", i+3, (int) i+3);
        fprintf(arquivo, "\t%3d\t%c\n", i+4, (int) i+4);
    }

    fclose(arquivo);

    return 0;
}