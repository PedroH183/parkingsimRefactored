#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h> 

#include "./DotH//estruturas.h"
#include "./DotH//veiculo.h"

/*
    Inserir:
        - Checar armazenamento
        - Pedir codigo do proprietario e checar se em branco/existe
        - Atribuir codigo ao veiculo, checar se em branco/existe
        - Pedir descricao do veiculo, checar se em branco/existe
        - Pedir marca do veiculo, checar se em branco
        - Pedir modelo do veiculo, checar se em branco
        - Pedir placa do veiculo, checar se em branco
    Alterar:
        - Pedir codigo do veiculo, checar se em branco/existe
        - Pedir nova descricao, checar se em branco/existe
        - Pedir nova marca, checar se em branco
        - Pedir novo modelo, checar se em branco
        - Pedir nova placa, cehcar se em branco
    Deletar:
        - Pedir codigo do veiculo, checar se em branco/existe
        - Colocar ocupado como livre.
    Listar:
        - 1. Listar por codigo, 2. Listar por servidor, 3. Listar alfab.
        - Se 1, pedir cod do veiculo, checar se em branco/existe
        - Se 2, pedir cod do servidor, checar se em branco/existe
        - Se 3, pedir cod do servidor, checar se em branco/existe, ordenar.
*/

int checar_prop_existe(servidor_t* servidor, size_t tamanho, int codigo)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(servidor[i].codigo == codigo)
        {
            return i;
        }
    }

    return -1;
}

int checar_veic_existe(servidor_t* servidor, size_t tamanho, int codigo, int* ind_s, int* ind_v)
{
    for(int i = 0; i < tamanho; i++)
    {
        for(int j =  0; j < MAX_V; j++)
        {
            if(servidor[i].veiculo[j].codigo == codigo)
            {
                *ind_s = i;
                *ind_v = j;
                return 1;
            }
        }
    }

    return 0;
}

int checar_cheio(veiculo_t veiculo[])
{
    int cont = 0;

    for(int i = 0; i < MAX_V; i++)
    {
        if(veiculo[i].ocupado == 0)
        {
            return i;
        }

        else if(veiculo[i].ocupado == 1)
        {
            cont++;
        }
    }

    return cont;
}

int checar_cod_existe(veiculo_t veiculo[], int r_cod)
{
    for(int i = 0; i < MAX_V; i++)
    {
        if(veiculo[i].codigo == r_cod)
        {
            return 1;
        }
    }

    return 0;
}

int gerador_codigo(veiculo_t veiculo[], int indice)
{
    srand(time(NULL));
    int r;

    do
    {
        r = indice*10 + (rand() % MAX_V);
    } while (checar_cod_existe(veiculo, r) == 1);

    return r;
}

void ler(char buffer[])
{
    do
    {
        fgets(buffer, TAM_STR, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
    } while (buffer[0] == '\0');    
}

int checar_desc_existe(servidor_t* servidor, size_t tamanho, char buffer[])
{
    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < MAX_V; j++)
        {
            if(strcmp(servidor[i].veiculo[j].descricao, buffer) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

void listar_por_codigo(servidor_t* servidor, int ind_s, int ind_v)
{
    printf("Dono: %s\n", servidor[ind_s].nome);
    printf("Codigo: %d\n", servidor[ind_s].veiculo[ind_v].codigo);
    printf("Descri: %s\n", servidor[ind_s].veiculo[ind_v].descricao);
    printf("Marca: %s\n", servidor[ind_s].veiculo[ind_v].marca);
    printf("Modelo: %s\n", servidor[ind_s].veiculo[ind_v].modelo);
    printf("Placa: %s\n", servidor[ind_s].veiculo[ind_v].placa);
}

void listar_por_servidor(servidor_t* servidor, int ind_s)
{
    printf("%s\n\n", servidor[ind_s].nome);

    for(int i = 0; i < MAX_V; i++)
    {
        if(servidor[ind_s].veiculo[i].ocupado == 1)
        {
            printf("Codigo: %d\n", servidor[ind_s].veiculo[i].codigo);
            printf("Descri: %s\n", servidor[ind_s].veiculo[i].descricao);
            printf("Marca: %s\n", servidor[ind_s].veiculo[i].marca);
            printf("Modelo: %s\n", servidor[ind_s].veiculo[i].modelo);
            printf("Placa: %s\n\n", servidor[ind_s].veiculo[i].placa);
        }
    }
}

void listar_ordenado(servidor_t* servidor, int ind_s)
{
    veiculo_t veiculos_ordenados[MAX_V];
    memcpy(veiculos_ordenados, servidor[ind_s].veiculo, sizeof(servidor[ind_s].veiculo));

    for(int i = 1; i < MAX_V; i++)
    {
        for(int j = 0; j < (MAX_V - i - 1); j++)
        {
            if(tolower(veiculos_ordenados[j].modelo[0]) > tolower(veiculos_ordenados[j+1].modelo[0]))
            {
                veiculo_t aux = veiculos_ordenados[j];
                veiculos_ordenados[j] = veiculos_ordenados[j+1];
                veiculos_ordenados[j+1] = aux;
            }
        }
    }

    printf("%s\n\n", servidor[ind_s].nome);
    for(int i = 0; i < MAX_V; i++)
    {
        if(veiculos_ordenados[i].ocupado == 1)
        {
            printf("Codigo: %d\n", veiculos_ordenados[i].codigo);
            printf("Descri: %s\n", veiculos_ordenados[i].descricao);
            printf("Marca: %s\n", veiculos_ordenados[i].marca);
            printf("Modelo: %s\n", veiculos_ordenados[i].modelo);
            printf("Placa: %s\n\n", veiculos_ordenados[i].placa);
        }
    }
}

int checar_vazio(servidor_t* servidor, int ind_s)
{
    int cont = 0;

    for(int i = 0; i < MAX_V; i++)
    {
        if(servidor[ind_s].veiculo[i].ocupado == 1)
        {
            cont++;
        }
    }

    return cont;
}
