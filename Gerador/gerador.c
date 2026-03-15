#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define CLASSES 4

struct Perguntas{
    char str[50];
};

struct Senhas{
    int qnt_digitos;
    //char maiusculas, minusculas, numerais, especiais;
    char opcoes[CLASSES];
    char *str;
};

struct Senhas senha;

void perguntas(char str[], int i, int *contador){
    do{
        printf("%s", str);
        scanf("%c%*c" , &senha.opcoes[i]);
        if(senha.opcoes[i] == 'n')
            *contador = *contador + 1;

    }while (senha.opcoes[i] != 's' && senha.opcoes[i] != 'n');
}

char aleatoriedade(char opcoes[]){
    int x = 0;
    char digito;
    char *strM = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *strm = "abcdefghijklmnopqrstuvwxyz";
    char *strE = "!@#$%%¨&*()'`´><;:.,}{[]+-";
    char *strN = "1234567890";
    
    while(1){
        //Colocar algortimo de Fisher Yates
        x = rand()%CLASSES;
        if(opcoes[x] == 's')
            break;
    }

    switch(x){
        case 0:
            x = rand()%strlen(strM);
            digito = strM[x];
            break;
        case 1:
            x = rand()%strlen(strm);
            digito = strm[x];
            break;
        case 2:
            x = rand()%strlen(strN);
            digito = strN[x];
            break;
        case 3:
            x = rand()%strlen(strE);
            digito = strE[x];
            break;
    }

    return digito; 
}

int main(){

    //Espaço amostral : 33 a 126 
    //Fórmula : rand() % (b - a + 1) + a

    int qnt_frases = 4, contador = 0, possivel = 0;
    senha.qnt_digitos = 0;

    struct Perguntas frases[qnt_frases];
    strcpy(frases[0].str, "A sua senha deve ter letras maiusculas?(s/n): ");
    strcpy(frases[1].str, "A sua senha deve ter letras minusculas?(s/n): ");
    strcpy(frases[2].str, "A sua senha deve ter numeros?(s/n): ");
    strcpy(frases[3].str, "A sua senha deve ter caracteres especiais?(s/n): ");

    srand(time(NULL));
    printf("Digite a quantidade de digitos da sua senha: ");
    scanf("%d%*c", &senha.qnt_digitos);

    while(possivel == 0){
        for(int i=0; i<qnt_frases; i++)
            perguntas(frases[i].str, i, &contador);
    
        if(contador != qnt_frases)
            possivel = 1;
        else
            printf("Impossivel criar senhas com todas as categorias negadas! Por favor, digite novamente\n");
        
        contador = 0;
    }

    senha.str = (char*) malloc(senha.qnt_digitos*sizeof(char));
    
    for(int i = 0; i<senha.qnt_digitos; i++){
        senha.str[i] = aleatoriedade(senha.opcoes);
    }

    printf("A senha: %s", senha.str);

    return 0;
}