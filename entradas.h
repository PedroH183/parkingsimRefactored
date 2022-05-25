#ifndef ENTRADAS_H
#define ENTRADAS_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

enum menu_listar_serv
{
    print_tecnicos = '1',
    print_prof = '2',
    print_all = '3',
    print_especif ='4',
    return_menu = '5',
};

int em_branco(char *string)
{
    if(!strcmp(string, "")) {
        return 1;
    } else {
        return 0;
    }
}

char ler_menu(char input)
{
    scanf("%c", &input);
    fflush(stdin);
    return input;
}

const char *ler_campo(char *texto, char *campo)
{
    fflush( stdin );
    printf( texto );
    fgets( campo, MAX, stdin);
    campo[ strcspn(campo,"\n") ] = '\0';
    fflush( stdin );

    return campo;
}

char *caixa_correcao(char campo[])
{
    for(int i = 0 ; i < MAX ; ++i)
    {
        campo[0] = toupper(campo[0]);

        if(campo[i] == ' '){
            campo[i+1] = toupper(campo[i+1]);
        }
        if(campo[i-1] == ' '){
            continue;
        }else{
            campo[i] = tolower(campo[i]);
        }
    } // deixei dessa forma pq aberto ocupa um espaço desnecessário.
    
    return campo;
}


#endif