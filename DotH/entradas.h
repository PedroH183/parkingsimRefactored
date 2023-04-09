#ifndef ENTRADAS_H
#define ENTRADAS_H

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "estruturas.h"
#include "servidor.h"

char* caixa_correcao(char *campo);

enum menu{
    sair_do_programa = '0',
    insert_servidor = '1',
    alterar_servidor = '2',
    remover_servidor = '3',
    listar_servidor = '4',
    inserir_veiculo = '5',
    alterar_veiculo = '6',
    remover_veiculo = '7',
    listar_veiculo = '8',
    salvar_dados = '9',
};

enum menu_listar_serv
{
    print_tecnicos = '1',
    print_prof = '2',
    print_all = '3',
    print_especif ='4',
};

enum menu_listar_veic
{
  listar_um_veiculo = '1',
  listar_veiculos_servidor = '2',
  listar_veiculos_ordenado = '3',
};

int buscar_codigo(int ipt_codigo, size_t* qtd_regis, servidor_t* ptr_str)
{
  for(int i = 0 ; i < (*qtd_regis); ++i)
  {
    if(ptr_str[i].codigo == ipt_codigo) return i;
  }
  printf("\nCODIGO NAO REGISTRADO !!\n");
  return -1; // não encontrou correspondência
}

int codigo_gerador(servidor_t *ptr_registros,size_t *quantia_registros)
{
  srand( (unsigned) time(NULL)); // random seed 
  int controle_loop;
  int codigo;

  do{
    controle_loop = 1;
    codigo = (int)rand()%1000;

    for(int i = 0; i < (*quantia_registros); ++i)
    {
      if(ptr_registros[i].codigo != codigo) continue;
      controle_loop = 0;
    }
  }while( controle_loop != 1);

  return codigo;
}

char ler_menu(char input)
{

    return input;
}

char* ler_campo( char *texto, char *campo )
{
    fflush(stdin);
    printf( texto );
    scanf("%s", campo);
    getchar();
    fflush(stdin);

  return caixa_correcao(campo);
}

char* caixa_correcao(char *campo)
{
  for(int i = 0 ; i < TAM_STR; ++i)
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
    } 
    
    return campo;
}

#endif