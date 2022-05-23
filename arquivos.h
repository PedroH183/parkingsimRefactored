#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "estruturas.h"

#define NAME_FILE "data.bin"

int escrever_arquivo(void * objeto, size_t tam_struct, int cont)
{
    FILE *fptr = fopen(NAME_FILE, "wb");
    if(fptr == NULL)
    {
        return 1;
    }

    fwrite(objeto, tam_struct * cont, 1, fptr);

    fclose(fptr);
}

int ler_arquivo(void * objeto, size_t tam_struct, int cont)
{
    FILE *fptr = fopen(NAME_FILE, "rb");
    if(fptr == NULL)
    {
        fptr = fopen(NAME_FILE,"wb");
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