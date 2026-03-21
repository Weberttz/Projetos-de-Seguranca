#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(){
    FILE *arquivo;
    char *senha = malloc(100*sizeof(char));
    const char caminho[] = "Arquivos/senhasHash.txt";
    int verificacao = 0;
    arquivo = fopen(caminho, "r");
  
    printf("Digite sua senha: ");
    fgets(senha, 100, stdin);
    senha[strcspn(senha, "\n")] = '\0';

    unsigned char hash[SHA256_DIGEST_LENGTH]; // 32 bytes
    char hashStr[SHA256_DIGEST_LENGTH * 2 + 1]; // 65 bytes
    char hashArquivo[SHA256_DIGEST_LENGTH * 2 + 1];

    SHA256((unsigned char*)senha, strlen(senha), hash);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        sprintf(&hashStr[i*2], "%02x", hash[i]);
    }

    while(fgets(hashArquivo, sizeof(hashArquivo), arquivo)){
        //hashArquivo[strcspn(hashArquivo, "\n")] = '\0'; // remover \n
        if(!strcmp(hashArquivo, hashStr)){
            verificacao = 1;
            break;
        }
    }

    (verificacao)? printf("Acesso permitido."):printf("Acesso negado.");

    free(senha);
    fclose(arquivo);

    return 0;
}