#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "estruturas.h"
#include "servidor.h"
#include "entradas.h"


servidor_t criar_servidor()
{ 
    servidor_t novo_servidor;
    char aux[TAM_STR];

    //do {
      novo_servidor.codigo = rand();                                                                    // obrigatorio e não pode repetir
      strcpy( novo_servidor.nome  ,ler_campo("Digite o nome do Servidor \n:",  novo_servidor.nome   )); // obrigatorio
      strcpy( novo_servidor.siape ,ler_campo("Digite o siape do Servidor\n:",  novo_servidor.siape  )); // obrigadorio e não pode repetir
      strcpy( novo_servidor.cpf   ,ler_campo("Digite o cpf do Servidor  \n:",  novo_servidor.cpf    )); // obrigatorio e não pode repetir
                
    //strcpy(aux,'1');

    //}while( checar_em_branco(novo_servidor.nome,novo_servidro.siape,novo_servidor.cpf, aux) ); checar em branco --> checar repetição --> permitir passagem
    
    strcpy( novo_servidor.nascimento,ler_campo("Digite a data de nascimento do servidor\n:",novo_servidor.nascimento));
    strcpy( novo_servidor.rg        ,ler_campo("Digite o rg do Servidor\n:",                novo_servidor.rg        ));
    strcpy( novo_servidor.salario   ,ler_campo("Digite o salario do servidor\n:",           novo_servidor.salario   ));
    strcpy( novo_servidor.endereco  ,ler_campo("Digite o endereco do Servidor\n:",          novo_servidor.endereco  ));

    do{
        strcpy(      aux           ,ler_campo("Digite o tipo de Servidor\n1-Professor  2-Tecnico\n::",   aux));
        strcpy( novo_servidor.tipo ,rece_type_serv(aux) );

      }while( strcmp( (aux) ,"1") && strcmp( (aux) ,"2") );
    
    return novo_servidor;
}

void list_serv( servidor_t* servidor , size_t quantia_registr)// deve receber como parametro um vetor ordenado
{
  printf("\n############Listando#########\n");

  for(int i = 0 ; i < quantia_registr ; ++i) // quantia_registr == tamanho == quantia de registros salvos.
  {
    printf("Indice: %d\nCodigo: %d\nNome: %s\nSiape: %s\nCpf: %s\nNascimento: %s\nEndereco: %s\nRg: %s\nSalario: %s\nTipo: %s\n\n",
            i,
            servidor[i].codigo,
            servidor[i].nome,
            servidor[i].siape,
            servidor[i].cpf,
            servidor[i].nascimento,
            servidor[i].endereco,
            servidor[i].rg,
            servidor[i].salario,
            servidor[i].tipo);
  }
  
  printf("\n\n########FIM DA LISTAGEM######\n");

  return;
}

const char *rece_type_serv(const char *opcao)
{
  if( !strcmp(opcao,"1") ) return "Professor";
  if( !strcmp(opcao,"2") ) return "Tecnico";
  else {
      printf("\nDigite uma opcao valida !!!\n");
      return "ERRO";
    }
}

/*FUNÇÕES DE ENTRADA.H DANDO IMPLICT DECLARATION*/

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

char* ler_campo( char *texto, char *campo )
{
  printf( texto );
  fgets( campo, TAM_STR, stdin ); // aplicar o sizeof(campo) não funciona, pq ? ele puxa o tamanho do ponteiro ?
  campo[ strcspn(campo,"\n") ] = '\0';
  fflush( stdin );

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

/*FIM DAS FUNÇÕES RETIRADAS DE ENTRADA.H*/
