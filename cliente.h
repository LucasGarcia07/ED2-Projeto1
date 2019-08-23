#ifndef CLIENTE_H
#define CLIENTE_H

#include<stdio.h>
#include<stdlib.h>

struct cliente{
    int codCliente;
    char nome[50];
    char dataNascimento[20];
};typedef struct cliente Cliente;

Cliente *criaCliente(int cod, char *nome, char *dataNascimento);
void salva(Cliente *clt, FILE *out);
Cliente *le(FILE *in);
int tamanho();

#endif