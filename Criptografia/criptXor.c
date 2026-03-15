#include <stdio.h>
#include <stdlib.h>

//Criptografia e Descriptografia utilizando a operação XOR

int main(){
    FILE *arquivo;

    int chave = 100, k = 0;
    int caracter, aux, capacidade = 1024;
    char *conteudo = malloc(capacidade), *caminho;

    do{
        printf("Digite o caminho do arquivo que deseja criptografar: ");
        scanf("%s%*c", caminho);
        arquivo = fopen(caminho, "rb");
    }while(arquivo == NULL);

    while((caracter = fgetc(arquivo)) != EOF)
    {   
        if(k == capacidade){
            capacidade *= 2;
            conteudo = realloc(conteudo, capacidade);
        }

        aux = (unsigned char) caracter^chave;

        conteudo[k] =  aux;
        k++;
    }

    fclose(arquivo);

    arquivo = fopen("Arquivos/TrabalhoEtica.pdf", "w+");

    for(int i=0; i<k; i++)
        fputc(conteudo[i], arquivo);

    fclose(arquivo);

    printf("Arquivo criptografado/descriptografado com sucesso!");

    return 0;
}