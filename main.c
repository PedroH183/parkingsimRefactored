#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "entradas.h"
#include "arquivos.h"
#include "utilitarios.h"

int main(int argc, char *argv[])
{
    servidor * _servidor = malloc(MAX*sizeof(servidor));

    char input = '~';

    do
    {
        printf("1. Inser. servidor\n");
        printf("2. Atual. servidor\n");
        printf("3. Delet. servidor\n");
        printf("4. Lista. servidor\n\n");
        printf("5. Inser. veiculo\n");
        printf("6. Atual. veiculo\n");
        printf("7. Delet. veiculo\n");
        printf("8. Lista. veiculo\n\n");
        printf("0. Terminar programa\n\n");

        printf("Escolha: ");
        ler_menu(input);
        
        switch(input)
        {
            case sair_do_programa:
                printf("\nSalvando dados e terminando programa...\n\n");
                //escrever_arquivo();
                return 0;
            case inserir_servidor:
                //
                break;
            case alterar_servidor:
                //
                break;
            case remover_servidor:
                //
                break;
            case listar_servidor:
                //
                break;
            case inserir_veiculo:
                //
                break;
            case alterar_veiculo:
                //
                break;
            case remover_veiculo:
                //
                break;
            case listar_veiculo:
                //
                break;
            default:
                printf("\nEscolha invalida.\n\n");
        }

    } while (input != '0');

    free(_servidor);

    return 0;
}