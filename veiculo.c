#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h> 

#include "./DotH//estruturas.h"
#include "./DotH//veiculo.h"

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

int checar_cod_existe(servidor_t* servidor, size_t tamanho, int r_cod)
{
    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0 ; j < MAX_V; j++)
        {
            if(servidor[i].veiculo[j].codigo == r_cod)
            {
                return 1;
            }
        }
    }

    return 0;
}

int gerador_codigo(servidor_t* servidor, size_t tamanho)
{
    srand(time(NULL));
    int r;

    do
    {
        r = rand() % (MAX_V * tamanho);
    } while (checar_cod_existe(servidor, tamanho, r) == 1);

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

int checar_placa_existe(servidor_t* servidor, size_t tamanho, char buffer[])
{
    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < MAX_V; j++)
        {
            if(strcmp(servidor[i].veiculo[j].placa, buffer) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

void listar_por_codigo(servidor_t servidor, int ind_v)
{
    printf("\n############Listando#########\n");
    printf("Dono: %s\n", servidor.nome);
    printf("Codigo: %d\n", servidor.veiculo[ind_v].codigo);
    printf("Descri: %s\n", servidor.veiculo[ind_v].descricao);
    printf("Marca: %s\n", servidor.veiculo[ind_v].marca);
    printf("Modelo: %s\n", servidor.veiculo[ind_v].modelo);
    printf("Placa: %s\n", servidor.veiculo[ind_v].placa);
    printf("\n########FIM DA LISTAGEM######\n\n");
}

void listar_por_servidor(servidor_t servidor)
{
    printf("\n############Listando#########\n");
    printf("%s\n\n", servidor.nome);

    for(int i = 0; i < MAX_V; i++)
    {
        if(servidor.veiculo[i].ocupado == 1)
        {
            printf("Codigo: %d\n", servidor.veiculo[i].codigo);
            printf("Descri: %s\n", servidor.veiculo[i].descricao);
            printf("Marca: %s\n", servidor.veiculo[i].marca);
            printf("Modelo: %s\n", servidor.veiculo[i].modelo);
            printf("Placa: %s\n\n", servidor.veiculo[i].placa);
        }
    }
    printf("\n########FIM DA LISTAGEM######\n\n");
}

void listar_ordenado(servidor_t servidor)
{
    veiculo_t veiculos_ordenados[MAX_V];
    memcpy(veiculos_ordenados, servidor.veiculo, sizeof(servidor.veiculo));

    for(int i = 0; i < MAX_V - 1; i++)
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

    printf("\n############Listando#########\n");
    printf("%s\n\n", servidor.nome);

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
    printf("\n########FIM DA LISTAGEM######\n\n");
}

int checar_vazio(veiculo_t veiculo[])
{
    int cont = 0;

    for(int i = 0; i < MAX_V; i++)
    {
        if(veiculo[i].ocupado == 1)
        {
            cont++;
        }
    }

    return cont;
}