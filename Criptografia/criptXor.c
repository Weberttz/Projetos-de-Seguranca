#include <stdio.h>
#include <stdlib.h>

//Criptografia e Descriptografia utilizando a operação XOR
int verificarArgumentos(int qntArgumentos){
    int qntEsperada = 3;
    return (qntArgumentos < qntEsperada)? 0:1;
}

int main(int argc, char *argv[]){
    
    if(!verificarArgumentos(argc)){
        printf("Uso: ./programa arquivo chave\n");
        return 0;
    }
    
    FILE *arquivo;
    int chave = atoi(argv[2]), k = 0;
    int byte, novoByte, capacidade = 1024;
    char *conteudo = malloc(capacidade), *caminho;

    caminho = argv[1];
    arquivo = fopen(caminho, "rb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        free(conteudo);
        return 0;
    }

    while((byte = fgetc(arquivo)) != EOF)
    {   
        if(k == capacidade){
            capacidade *= 2;
            conteudo = realloc(conteudo, capacidade);
        }

        novoByte = (unsigned int) byte^chave;

        conteudo[k] = novoByte;
        k++;
    }

    fclose(arquivo);

    arquivo = fopen(caminho, "wb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo de escrita");
        free(conteudo);
        return 0;
    }
    
    for(int i=0; i<k; i++)
        fputc(conteudo[i], arquivo);

    fclose(arquivo);

    free(conteudo);

    printf("Arquivo criptografado/descriptografado com sucesso!");

    return 0;
}