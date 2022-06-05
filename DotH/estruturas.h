#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#define TAM_STR 100

typedef struct Veiculo
{
    int ocupado; // controle de veiculos 
    int codigo;
    char modelo[TAM_STR];
    char descricao[TAM_STR];
    char marca[TAM_STR];
    char placa[TAM_STR];
} veiculo_t;

typedef struct Servidor
{
    int codigo; // random number
    char nome[TAM_STR];
    char siape[TAM_STR];
    char cpf[TAM_STR];
    char nascimento[TAM_STR];
    char endereco[TAM_STR];
    char rg[TAM_STR];
    char salario[TAM_STR];
    char tipo[TAM_STR];
    veiculo_t veiculo[10];
} servidor_t;

#endif