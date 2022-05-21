#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "estruturas.h"

int escrever_arquivo(void * objeto, size_t tam_struct, int cont)
{
    FILE *fptr = fopen("data.bin", "w");
    if(fptr == NULL)
    {
        return 1;
    }

    fwrite(objeto, tam_struct * cont, 1, fptr);

    fclose(fptr);
}

int ler_arquivo(void * objeto, size_t tam_struct, int cont)
{
    FILE *fptr = fopen("data.bin", "r");
    if(fptr == NULL)
    {
        return 1;
    }

    fread(objeto, tam_struct * cont, 1, fptr);

    fclose(fptr);
}

#endif