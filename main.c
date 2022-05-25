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
    int done = 1,op;
    char aux[MAX],nome[MAX],siape[MAX],cpf[MAX],nasci[MAX],rg[MAX],tipo_serv[MAX],salario[MAX],endereco[MAX];

    
    servidor * _servidor = malloc(MAX*sizeof(servidor));
    ler_arquivo(_servidor,sizeof(servidor),MAX);

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
                escrever_arquivo(_servidor,sizeof(servidor),MAX);

                return 0;
            case inserir_servidor:
        
                //do {
                strcpy(nome,ler_campo("Digite o nome do Servidor \n:",nome)); // obrigatorio e não pode repetir
                strcpy(siape,ler_campo("Digite o siape do Servidor\n:",siape)); // obrigadorio e não pode repetir
                strcpy(cpf,ler_campo("Digite o cpf do Servidor  \n:",cpf)); // obrigatorio e não pode repetir
                
                //strcpy(aux,'1');

                //}while( checar_em_branco(nome,siape,cpf,aux) );
                strcpy(nasci,ler_campo("Digite a data de nascimento do servidor\n:", nasci));
                strcpy(rg,ler_campo("Digite o rg do Servidor\n:",rg));
                strcpy(salario,ler_campo("Digite o salario do servidor\n:",salario));
                strcpy(endereco,ler_campo("Digite o endereco do Servidor\n:",endereco));

                do{
                    strcpy(aux,ler_campo("Digite o tipo de Servidor\n1-Professor  2-Tecnico\n::",aux));
                    strcpy(tipo_serv,rece_type_serv(aux));
                }while(strcmp(aux,"1") && strcmp(aux,"2"));
                

                printf("\n%s\n",criar_servidor(nome,siape,cpf,nasci,rg,tipo_serv,salario,endereco,_servidor));
                
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
                
                if( input == print_tecnicos || input == print_prof || input == print_all )
                {
                    list_serv(_servidor);
                    //copying_nomes(input);
                }else if( input == print_especif )
                {
                    //print_serv_cod();
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

    free(_servidor);
    //libera_memoria(_servidor);
    return 0;
}