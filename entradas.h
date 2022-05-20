#ifndef ENTRADAS_H
#define ENTRADAS_H

#include <string.h>
#include <stdlib.h>

enum menu
{
    sair_do_programa = '0',
    inserir_servidor = '1',
    alterar_servidor = '2',
    remover_servidor = '3',
    listar_servidor = '4',
    inserir_veiculo = '5',
    alterar_veiculo = '6',
    remover_veiculo = '7',
    listar_veiculo = '8',
};

int em_branco(char *string)
{
    if(!strcmp(string, "")) {
        return 1;
    } else {
        return 0;
    }
}

void ler_menu(char input)
{
    scanf("%c", &input);
    fflush(stdin);
}

int ler_string(int (*f)(char[]), char *string)
{

}

#endif