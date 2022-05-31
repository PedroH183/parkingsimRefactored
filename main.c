#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "entradas.h"
#include "arquivos.h"
#include "utilitarios.h"
#include "servidor.h"
#include "gerenciamento.h"


int main()
{
    size_t tamanho = buscar_tamanho();
    servidor_t* servidor = malloc(MEM);

    if(tamanho)
    {
        ler_dados(servidor, tamanho);
    }

    fflush(stdin);
    char input = '~';
    int indice;

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
        input = ler_menu(input);
        
        switch(input)
        {
            case sair_do_programa:
                printf("\nSalvando dados e terminando programa...\n\n");
                escrever_arquivo(servidor, tamanho);

                return 0;
            case insert_servidor:
        
                servidor = inserir_servidor(servidor, criar_servidor(), &tamanho);
                
                break;
            case alterar_servidor:
                //
                break;
            case remover_servidor:

                /**
                 * Inserir a checagem de existencia de codigo para não apagar o vazio.
                 */

                printf("\nDigite o indice do servidor\n>"); // deletar por indice ?? 
                scanf("%d",&indice);
                fflush(stdin);
                servidor = deletar_servidor(servidor,indice, &tamanho);
            
                break;
            case listar_servidor:

                opcao_list_serv();
                
                scanf("%c",&input);
                fflush(stdin);
                
                if( input == print_tecnicos || input == print_prof || input == print_all )
                {
                    list_serv(servidor, tamanho); // esse list serv tem que já chamar uma função para ordenar 
                    //copying_nomes(input);
                }else if( input == print_especif )
                {
                    //print_serv_cod();
                    /**
                     * procurar um indice/codigo especifico e printar ele.
                     */
                }else if( input == return_menu )
                {
                    printf("\n\n");
                    break;
                }else{
                    printf("\nEssa opção não existe !\n");
                    break;
                }
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

    return 0;
}