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

    // char input;

    // do
    // {
    //     printf("1. Inser. servidor\n");
    //     printf("2. Atual. servidor\n");
    //     printf("3. Delet. servidor\n");
    //     printf("4. Lista. servidor\n\n");
    //     printf("5. Inser. veiculo\n");
    //     printf("6. Atual. veiculo\n");
    //     printf("7. Delet. veiculo\n");
    //     printf("8. Lista. veiculo\n\n");
    //     printf("0. Terminar programa\n\n");

    //     printf("Escolha: ");
    //     ler_menu(input);
        
    //     switch(input)
    //     {
    //         sair_do_programa:
    //             printf("\nSalvando dados e terminando programa...\n\n");
    //             //escrever_arquivo();
    //             return 0;
    //         inserir_servidor:
    //             //
    //             break;
    //         alterar_servidor:
    //             //
    //             break;
    //         remover_servidor:
    //             //
    //             break;
    //         listar_servidor:
    //             //
    //             break;
    //         inserir_veiculo:
    //             //
    //             break;
    //         alterar_veiculo:
    //             //
    //             break;
    //         remover_veiculo:
    //             //
    //             break;
    //         listar_veiculo:
    //             //
    //             break;
    //         default:
    //             printf("\nEscolha invalida.\n\n");
    //     }

    // } while (input != '0');

    //

	// for(int i = 0; i < MAX; i++) {
	//     strcpy(_servidor[i].nome, "Tiago");
	//     _servidor[i].codigo = i;
	// }
	
	// escrever_arquivo(_servidor);
	
	ler_arquivo(_servidor);
	
	// for(int i = 0; i < MAX; i++) {
	//     printf("Nome: %s Codigo: %d\n",
	//      _servidor[i].nome, _servidor[i].codigo);
	// }

    qsort(_servidor, MAX, sizeof(servidor), comparar_servidor);

    for(int i = 0; i < MAX; i++)
    {
        printf("%s\n", _servidor[i].nome);
    }

    printf("%d", encontrar_servidor("Xerxs", _servidor, MAX)); // Exemplo, retorna 0

    free(_servidor);

    return 0;
}