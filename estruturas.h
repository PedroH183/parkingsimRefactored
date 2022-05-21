#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAX 100

typedef struct Veiculo
{
    int codigo;
    char modelo[255];
    char descricao[255];
    char marca[255];
    char placa[255];
} veiculo;

typedef struct Servidor
{
    int codigo;
    //int ativo; // 0 para livre 1 para ocupado
    char nome[255];
    char siape[255];
    char cpf[255];
    char nascimento[255];
    char endereco[255];
    char rg[255];
    char salario[255];
    char tipo[255];

    veiculo veiculo[10];
} servidor;

#endif