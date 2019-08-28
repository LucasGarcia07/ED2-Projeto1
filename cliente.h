#ifndef CLIENTE_H
#define CLIENTE_H 

#include <stdlib.h>
#include <stdio.h>

typedef struct cliente
{
	int codCliente;
	char nome[50], dataNascimento[20];
} Cliente;

void imprime(Cliente *c);

Cliente *cliente(int cod, char *nome, char *data);

void salva(Cliente *c, FILE *out);

Cliente *le(FILE *in);

int tamanho();

int quantidade(FILE *in);

#endif