#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLASSES 4

enum Classificacao{
    FRACA, 
    MEDIA,
    FORTE
};

int verificarSenha(int quantidades[]){
    for(int i=0; i<CLASSES; i++){
        if(quantidades[i] < 2)
            return 0;
    }

    return 1;
}

int verificarCaracterAscii(int caracter){

    if(caracter >= (int)'A' && caracter <= (int)'Z')
        return 0;

    if(caracter >= (int)'a' && caracter <= (int)'z')
        return 1;

    if(caracter >= (int)'0' && caracter <= (int)'9')
        return 2;
    
    return 3;
}

int main(){

    enum Classificacao classificacaoSenha;
    int tam_max = 100, tam = 0, aux;
    //quantidades[classes] - maisculas, minusculas, numerais, especiais
    int quantidades[CLASSES] = {0};
    char *senha = malloc(tam_max * sizeof(char));
    int *senha_ascii;

    printf("Bem vindo ao verificar de senhas, aqui você vai poder classificar suas senhas\n");
    printf("Senha Forte - Senha Média - Senha Fraca\n");
    printf("Digite a senha que deseja verificar a classificação: ");
    scanf("%s", senha);

    tam = strlen(senha);

    senha_ascii = malloc(tam * sizeof(int));

    for(int i=0; i<tam; i++)
        senha_ascii[i] = (int) senha[i];

    for(int i=0; i<tam; i++){
        int aux = verificarCaracterAscii(senha_ascii[i]);
        quantidades[aux]++;
    }

    int verificacao = verificarSenha(quantidades);

    classificacaoSenha = FRACA;

    if(verificacao)
        classificacaoSenha = MEDIA;

    if(verificacao && tam >= 16)
        classificacaoSenha = FORTE;

    switch (classificacaoSenha)
    {
    case FRACA:
        printf("Sua senha é fraca!");
        break;
    case MEDIA:
        printf("Sua senha é média!");
        break;
    case FORTE:
        printf("Sua senha é forte!");
        break;
    }

    return 0;
}