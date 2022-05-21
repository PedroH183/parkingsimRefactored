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

// #define FORMATO_LER "{\n\t\"nome:\": \"%[^\"]\",\n\t\"codigo\": %d\n}"
// #define FORMATO_ESCREVER "{\n\t\"nome:\": \"%s\",\n\t\"codigo\": %d\n}"

// int escrever_arquivo(servidor * _servidor)
// {
//     FILE *fptr = fopen("dados.txt", "w");
//     if(fptr == NULL) {
//         return 1;
//     }
    
//     for(int i = 0; i < MAX; i++) {
//         fprintf(fptr, FORMATO_ESCREVER, _servidor[i].nome, _servidor[i].codigo);
//     }
    
//     fclose(fptr);
// }

// int ler_arquivo(servidor * _servidor)
// {
//     FILE *fptr = fopen("dados.txt", "r");
//     if(fptr == NULL) {
//         return 1;
//     }
    
//     for(int i = 0; i < MAX; i++) {
//         fscanf(fptr, FORMATO_LER, _servidor[i].nome, &_servidor[i].codigo);
//     }
    
//     fclose(fptr);
// }

#endif