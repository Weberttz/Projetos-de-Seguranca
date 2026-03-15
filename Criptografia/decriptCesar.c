#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Criptografia utilizando Cifra de César

int verificarArgumentos(int qntArgumentos){
    int qntEsperada = 3;
    return (qntArgumentos < qntEsperada)? 0:1;
}

int main(int argc, char *argv[]){

    if(!verificarArgumentos(argc)){
        printf("Uso: ./programa arquivo chave\n");
    }

    FILE *arquivo;

    int byte, chave = atoi(argv[2]), novoByte, capacidade = 1024, k = 0, tamanhoByte = 256;
    char *caminho, *conteudo = malloc(capacidade);
    
    caminho = argv[1];

    arquivo = fopen(caminho, "rb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        return 0;
    }   

    while((byte = fgetc(arquivo)) != EOF){

        if(k == capacidade){
            capacidade*=2;
            conteudo = realloc(conteudo, capacidade);
        }

        if(byte + chave < tamanhoByte)
            novoByte = (unsigned int) (byte - chave);
        else
            novoByte = (unsigned int) (byte + tamanhoByte - chave);

        conteudo[k] = novoByte;
        k++;
    }

    fclose(arquivo);

    arquivo = fopen(caminho, "w+");

    for(int i=0; i<k; i++)
        fputc(conteudo[i], arquivo);

    fclose(arquivo);

    printf("Arquivo criptografado com sucesso!");

    return 0;
}