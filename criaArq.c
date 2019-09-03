#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"cliente.h"

int main(int argc, char const *argv[])
{
    FILE *arq = fopen("fileIn.dat", "wb");

    salva(criaCliente(10,"nome10", "10/00/0000"), arq);
    salva(criaCliente(8,"nome2", "00/01/0000"), arq);
    salva(criaCliente(4,"nome3", "00/00/1000"), arq);
    salva(criaCliente(1,"nome4", "00/00/0100"), arq);
    salva(criaCliente(3,"nome5", "00/00/0010"), arq);
    salva(criaCliente(12,"nome6", "00/00/0001"), arq);
    salva(criaCliente(6,"nome7", "11/11/1111"), arq);

    fclose(arq);

    return 0;
}