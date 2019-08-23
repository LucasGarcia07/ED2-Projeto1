#include"cliente.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

//Imprime cliente
void imprime(Cliente *clt){
    printf("**********************************************");
    printf("\nCódigo Cliente: ");
    printf("%d", clt->cod);
    printf("\nNome Cliente: ");
    printf("%s", clt->nome);
    printf("\nData de Nascimento: ");
    printf("%s", clt->dataNascimento);
    printf("\n**********************************************");
}

//Cria cliente

Cliente *criaCliente(int cod, char *nome, char *dataNascimento){
    
    Cliente *clt = (Cliente*)malloc(sizeof(Cliente));
    //inicializa espaço de memória com zeros
    if(clt) memset(clt, 0, sizeof(Cliente));
    //copiar valores para os campos de cliente
    clt->cod = cod;
    strcpy(clt->nome, nome);
    strcpy(clt->dataNascimento, dataNascimento);
    return clt;
}
void salva(Cliente *clt, FILE *out){

    fwrite(&clt->cod, sizeof(int), 1, out);
    fwrite(clt->nome, sizeof(char), sizeof(clt->nome), out);
    fwrite(clt->data_nascimento, sizeof(char), sizeof(clt->data_nascimento), out);
}

Cliente *le(FILE *in) {
    Cliente *clt = (Cliente *) malloc(sizeof(Cliente));
    if (0 >= fread(&clt->cod, sizeof(int), 1, in)) {
	free(clt);
	return NULL;
    }
    fread(clt->nome, sizeof(char), sizeof(clt->nome), in);
    
    fread(clt->data_nascimento, sizeof(char), sizeof(clt->data_nascimento), in);
    return clt;
}

int tamanho() {
    return sizeof(int)  //cod
            + sizeof(char) * 50 //nome
            + sizeof(char) * 11 //data_nascimento
}