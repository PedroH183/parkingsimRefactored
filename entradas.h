#ifndef ENTRADAS_H
#define ENTRADAS_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_STR 100

enum menu
{
    sair_do_programa = '0',
    insert_servidor = '1',
    alterar_servidor = '2',
    remover_servidor = '3',
    listar_servidor = '4',
    inserir_veiculo = '5',
    alterar_veiculo = '6',
    remover_veiculo = '7',
    listar_veiculo = '8',
};

enum menu_listar_serv
{
    print_tecnicos = '1',
    print_prof = '2',
    print_all = '3',
    print_especif ='4',
    return_menu = '5',
};

void opcao_list_serv()
{
    printf("Digite a forma como deseja printar os servidores\n\n");
    printf("1. Printar apenas os Tecnicos \n");
    printf("2. Printar apenas os professores \n");
    printf("3. Printar Todos \n");
    printf("4. Printar um servidor pelo cod dele.\n");
    printf("5. Para retornar ao menu\n");
}


#endif