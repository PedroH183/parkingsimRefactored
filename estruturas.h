#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct Veiculo
{
    int ocupado;
    int codigo;
    char modelo[255];
    char descricao[255];
    char marca[255];
    char placa[255];
} veiculo;

typedef struct Servidor
{
    int ocupado;
    int codigo;
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

typedef struct Controle
{
	int tamanho;
	servidor* servidor;
} controle;

#endif