#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cliente.h"

void imprime(Cliente *c)
{
    printf("***********************\n");
    printf("Nome do Cliente: ");
    printf("%s\n", c->nome);
    printf("Data de Nascimento: ");
    printf("%s\n", c->dataNascimento);
    printf("***********************\n");
}

Cliente *criaCliente(int cod, char *nome, char *data)
{
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    novo->codCliente = cod;
    strcpy(novo->nome, nome);
    strcpy(novo->dataNascimento, data);
    return novo;
}

void salva(Cliente *c, FILE *out)
{
    fwrite(&c->codCliente, sizeof(int), 1, out);
    fwrite(c->nome, sizeof(char), sizeof(c->nome), out);
    fwrite(c->dataNascimento, sizeof(char), sizeof(c->dataNascimento), out);
}

Cliente *le(FILE *in)
{
    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    if (0 >= fread(&c->codCliente, sizeof(int), 1, in))
    {
        free(c);
        return NULL;
    }
    fread(c->nome, sizeof(char), sizeof(c->nome), in);
    fread(c->dataNascimento, sizeof(char), sizeof(c->dataNascimento), in);
    return c;
}

int tamanho()
{
    return sizeof(int)          //cod
           + sizeof(char) * 50  //nome
           + sizeof(char) * 20; //data de nascimento
}

int quantidade(FILE *in)
{
    rewind(in);
    Cliente *c;
    int cont = 0;
    while ((c = le(in)) != NULL)
    {
        cont++;
        free(c);
    }
    return cont;
}