#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "estruturas.h"
#include <stdio.h>

#define NOME_ARQUIVO "data.bin"

int escrever_arquivo(servidor_t* servidor_ptr, size_t tamanho)
{
    FILE* fptr = fopen(NOME_ARQUIVO, "wb");
    if(fptr == NULL)
    {
        return -1;
    }

    fwrite(servidor_ptr, tamanho * sizeof(servidor_t), 1, fptr);
    fclose(fptr);
    return 1;
}

int ler_dados(servidor_t* servidor_ptr, size_t tamanho)
{
    FILE* fptr = fopen(NOME_ARQUIVO, "rb");
    if(fptr == NULL)
    {
        return -1;
    }

    fread(servidor_ptr, tamanho * sizeof(servidor_t), 1, fptr);
    fclose(fptr);
    return 1;
}

size_t buscar_tamanho()
{
    FILE* fptr = fopen(NOME_ARQUIVO, "ab");
    if(fptr == NULL)
    {
        return -1;
    }

    fseek(fptr, 0L, SEEK_END);
    size_t tamanho = ftell(fptr);

    fclose(fptr);
    return tamanho / sizeof(servidor_t); // retorna a quantia de registros dentro do arquivo 
}

#endif