#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include <stdlib.h>
#include <stdio.h>

#include "estruturas.h"
#include "arquivos.h"

#define MEM tamanho * sizeof(servidor_t)

servidor_t* inserir_servidor( servidor_t* servidor_ptr, servidor_t servidor, size_t* tamanho )
{
    (*tamanho)++;
    servidor_ptr = realloc(servidor_ptr, (*tamanho) * sizeof(servidor_t));
    servidor_ptr[(*tamanho) - 1] = servidor; // recebe - 1 

    return servidor_ptr;
}

servidor_t* deletar_servidor( servidor_t* servidor_ptr, int indice, size_t* tamanho )
{
    if( (*tamanho) == 1 )
    {
        (*tamanho)--;
        free(servidor_ptr);
        servidor_ptr = malloc((*tamanho) * sizeof(servidor_t)); 
    }
    else if (!(*tamanho)) // se não contiver nada não apaga nada, pq senão trava o programa !! 
    {
        return servidor_ptr;
    }
    else
    {
        for( int i = indice; i < (*tamanho); i++ ) // não deveria ser tamanho menos 1 ? 
        {
            servidor_ptr[i] = servidor_ptr[i + 1];
        }
        (*tamanho)--;
        servidor_ptr = realloc( servidor_ptr, (*tamanho) * sizeof(servidor_t) );
    }

    printf("\nSERVIDOR DELETADO COM SUCESSO!\n\n");
    return servidor_ptr;
}

#endif