#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

//flag de compilação : gcc hash.c -lssl -lcrypto -o hash

int verificarArgumentos(int argc){
    int qntEsperada = 2;

    return (argc < qntEsperada)? 0:1;
}

int main(int argc, char *argv[]){
    
    if(!verificarArgumentos(argc)){
        printf("Uso: ./programa senha\n");
        return 0;
    }
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char *senha = argv[1];
    
    SHA256((unsigned char*)senha, strlen(senha), hash);

    printf("Hash: ");
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }

    FILE *arquivoSenhas, *arquivoHashs; 
    const char caminhoHashs[] = "Arquivos/senhasHash.txt";
    const char caminhoSenhas[] = "Arquivos/senhas.txt";

    arquivoSenhas = fopen(caminhoSenhas, "a");
    arquivoHashs = fopen(caminhoHashs, "a");

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        fprintf(arquivoSenhas, "%c", senha[i]);
    } 

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        fprintf(arquivoHashs, "%02x", hash[i]);
    }

    fprintf(arquivoSenhas, "\n");
    fprintf(arquivoHashs, "\n");

    printf("\nSenha armazenada no arquivo %s\n", caminhoSenhas);
    printf("Transformação de senha em hash feita com sucesso!\nVerifique o arquivo %s\n", caminhoHashs);
    fclose(arquivoSenhas);
    fclose(arquivoHashs);

    return 0;
}