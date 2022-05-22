#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "estruturas.h"

int escrever_arquivo(void * objeto, size_t tam_struct, int cont)
{
    FILE *fptr = fopen("data.bin", "wb");
    if(fptr == NULL)
    {
        return 1;
    }

    fwrite(objeto, tam_struct * cont, 1, fptr);

    fclose(fptr);
}

int ler_arquivo(void * objeto, size_t tam_struct, int cont)
{
    FILE *fptr = fopen("data.bin", "rb");
    if(fptr == NULL)
    {
        fptr = fopen("data.bin","w");
        if(fptr == NULL)
        {
            perror("\nERRO AO TENTAR CRIAR O ARQUIVO !! \n");
            exit(1); // erro interpretado ;
        }
    }

    fread(objeto, tam_struct * cont, 1, fptr);

    fclose(fptr);
}

#endif