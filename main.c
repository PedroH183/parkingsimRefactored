#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./DotH//estruturas.h"
#include "./DotH//utilitarios.h"
#include "./DotH//entradas.h"
#include "./DotH//arquivos.h"
#include "./DotH//servidor.h"
#include "./DotH//utilitarios.h"
#include "./Doth//gerenciamento.h"


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
    int codigo;

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
        
                servidor = inserir_servidor(servidor, criar_servidor(servidor,&tamanho), &tamanho);
                system("pause");
                system("cls");
                
                break;
            case alterar_servidor:
                
                printf("\nDigite o codigo do servidor\n>"); // deletar por indice ?? 
                scanf("%d",&codigo);
                fflush(stdin);
                servidor = modify_servidor( servidor, buscar_codigo(codigo,&tamanho,servidor), &tamanho );
                system("pause");
                system("cls");
                
                break;
            case remover_servidor:

                printf("\nDigite o codigo do servidor\n>"); // deletar por indice ?? 
                scanf("%d",&codigo);
                fflush(stdin);
                servidor = deletar_servidor(servidor,buscar_codigo(codigo,&tamanho,servidor), &tamanho);
            
                break;
            case listar_servidor:

                printf("Digite a forma como deseja printar os servidores\n\n");
                printf("1. Printar apenas os Tecnicos \n");
                printf("2. Printar apenas os professores \n");
                printf("3. Printar Todos \n");
                printf("4. Printar um servidor pelo cod dele.\n");
                printf("5. Para retornar ao menu\n");
                    
                scanf("%c",&input);
                fflush(stdin);
                
                if( input == print_tecnicos || input == print_prof || input == print_all) // para print específico posso colocar aqui ?? 
                {
                    organizando_nomes(&tamanho, servidor, input);

                }
                else if(input == print_especif)
                {
                    printf("\nDigite o codigo do servidor\n>");
                    scanf("%d",&codigo);
                    fflush(stdin);

                    codigo = buscar_codigo(codigo,&tamanho,servidor);
                    if(codigo == -1) break;

                    int vet_espcf[] = {codigo};
                    size_t quantia_de_prints = 1;

                    list_serv(input,servidor,vet_espcf, &quantia_de_prints );
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

    free(servidor); // é apenas um ponteiro
    return 0;
}