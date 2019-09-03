#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"cliente.h"
//retorna menor
Cliente *ordena(Cliente **arrayClientes, int M, int CONGELADO, int FLAGIN){
        int i = 0, j =0;        
        Cliente *temp = (Cliente*)malloc(sizeof(Cliente));
        for(i = 1; i < M; i++){
            for(j = 0; j < M-1; j++){                       
                if(arrayClientes[j]->codCliente > arrayClientes[j+1]->codCliente){
                    temp = arrayClientes[j];
                    arrayClientes[j] = arrayClientes[j+1];
                    arrayClientes[j+1] = temp;
                }
            }
        }
    return arrayClientes[CONGELADO];
}
void subSelec(char nome[50],int M){
    int count = 0, Intname = 0, FLAGIN = 0, FLAGHV = 0, CONGELADO = 0, i = 0;
    char filename[30];
    //gera um nome de arquivo P diferente a cada iteração
    sprintf(filename, "P-%d.dat", Intname);
    FILE *in = fopen(nome, "rb");
    Cliente **arrayClientes = (Cliente**)malloc(M * sizeof(Cliente));
    Cliente *menor = (Cliente*)malloc(sizeof(Cliente));
    Cliente *prox = (Cliente*)malloc(sizeof(Cliente));
    
    for(i = 0; i < M; i++){
        arrayClientes[i] = (Cliente*)malloc(sizeof(Cliente));
    }    
    
    for(i = 0; i < M; i++){
        arrayClientes[i] = le(in);
    }
    while(FLAGHV == 0 || CONGELADO != 0){
        
        Intname++;
        sprintf(filename, "P-%d.dat", Intname);
        FILE *out = fopen(filename, "wb");
        CONGELADO = 0;
        FLAGIN = 0;
        FLAGHV = 0;

        while(CONGELADO < M && FLAGHV == 0){

            menor = ordena(arrayClientes, M, CONGELADO, FLAGIN);

            if(menor->codCliente != 9999){
                salva(menor, out);
            }else{
                FLAGHV++;
            }
            
            prox = le(in);
            
            for(i = 0; i < M; i++){
                if(arrayClientes[i] == menor && prox != NULL){
                    arrayClientes[i] = prox;                    
                    if(arrayClientes[i]->codCliente < menor->codCliente){
                        CONGELADO++;
                    }
                }else if(arrayClientes[i] == menor && prox == NULL){
                    arrayClientes[i]->codCliente = 9999;
                    strcpy(arrayClientes[i]->nome, "HIGH-VALUE");
                    strcpy(arrayClientes[i]->dataNascimento, "00/00/0000"); 
                    FLAGIN++;
                }
            }      
        }
        fclose(out);   
    }
}

void imprimePart(char nomepart[10]){
    printf("%s\n", nomepart);
    FILE *in = fopen(nomepart, "rb");
    rewind(in);
    Cliente *c;
    while((c = le(in))!= NULL){
        imprime(c);
        free(c);
    }
    fclose(in);
}

int main(int argc, char const *argv[])
{   
    char nomearq[50], nomepart[10];
    int tamanho = 0, aux = 2;
    
    while(aux != 3){
        while(aux == 2){
            printf("Digite o nome do arquivo de entrada: ");
            scanf("%s", nomearq);
            printf("\n");
            printf("Digite o tamanho do array em memória principal: ");
            scanf("%d", &tamanho);
            printf("\n");
            subSelec(nomearq, tamanho);
            printf("As partições de saída são nominadas como P-1.dat, P-2.dat,... Digite o nome da partição a ser impressa: ");
            scanf("%s", nomepart);
            printf("\n");
            imprimePart(nomepart);
            printf("Digite 1 para continuar imprimindo partições, 2 para passar outra entrada ou 3 para sair: ");
            scanf("%d", &aux);
        }   
        while(aux == 1){
            printf("As partições de saída são nominadas como P-1.dat, P-2.dat,... Digite o nome da partição a ser impressa: ");
            scanf("%s", nomepart);
            printf("\n");
            imprimePart(nomepart);
            printf("Digite 1 para continuar imprimindo partições, 2 para passar outra entrada ou 3 para sair: ");
            scanf("%d", &aux);
        }
    }

    return 0;
}


