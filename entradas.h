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
/*
    inserir formatação de texto
*/

char ler_menu(char input)
{
    scanf("%c", &input);
    fflush(stdin);
    return input;
}

char *ler_campo(char *texto, char *campo)
{
    printf(texto);
    fgets(campo,sizeof(campo),stdin);
    campo[strcspn(campo,"\n")] = '\0';
    fflush(stdin);
} // não precisa de return pq altera no endereço de memória por meio de um ponteiro
 
#endif