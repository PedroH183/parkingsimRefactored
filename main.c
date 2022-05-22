#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "entradas.h"
//#include "arquivos.h"
//#include "utilitarios.h"
#include "servidor.h"

int main(int argc, char *argv[])
{
    char aux,nome[255],siape[255],cpf[255],nasci[255],rg[255],tipo[255],salario[255],endereco[255];
    //servidor * _servidor = malloc(MAX*sizeof(servidor));
    servidor * _servidor[MAX];
    limpar_vet_ptrs(_servidor);

    fflush(stdin);
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
        input = ler_menu(input);
        
        switch(input)
        {
            case sair_do_programa:
                printf("\nSalvando dados e terminando programa...\n\n");
                //escrever_arquivo();
                return 0;
            case inserir_servidor:
        
                //do {
                ler_campo("Digite o nome do Servidor \n:",nome); // obrigatorio e não pode repetir
                ler_campo("Digite o siape do Servidor : \n:", siape); // obrigadorio e não pode repetir
                ler_campo("Digite o cpf do Servidor \n:", cpf); // obrigatorio e não pode repetir
                
                //strcpy(aux,'1');

                //}while( checa_branco(nome,siape,cpf,aux) );
                ler_campo("Digite a data de nascimento do servidor :\n", nasci);
                ler_campo("Digite o rg do Servidor : \n:",rg);
                ler_campo("Digite o salario do servidor : \n:",salario);
                ler_campo("Digite o endereco do Servidor : \n:",endereco);

                criar_servidor(nome,siape,cpf,nasci,rg,tipo,salario,endereco,_servidor);
                
                break;
            case alterar_servidor:
                //
                break;
            case remover_servidor:
                //
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

                if( input == '1' || input == '2' || input == '3' )
                {
                    list_serv(_servidor);
                    //copying_nomes(input);
                }else if( input == '4'){
                    //print_serv_cod();
                }else if(input == '5'){
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

    //free(_servidor);
    libera_memoria(_servidor);
    return 0;
}