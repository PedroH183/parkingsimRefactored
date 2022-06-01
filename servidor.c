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

void list_serv(char choice, servidor_t* servidor , int ordenados_indices[], size_t* quantia_regis)// deve receber como parametro um vetor ordenado
{
  printf("\n############Listando#########\n");

  for(int i = 0 ; i < (*quantia_regis) ; ++i) // quantia_registr == tamanho == quantia de registros salvos.
  {
    if( check_type_serv(choice, servidor[ordenados_indices[i]].tipo) )
    {
    printf("Indice: %d\nCodigo: %d\nNome: %s\nSiape: %s\nCpf: %s\nNascimento: %s\nEndereco: %s\nRg: %s\nSalario: %s\nTipo: %s\n\n",
            ordenados_indices[i], // indice real a ser printado
            servidor[ordenados_indices[i]].codigo, // será que precisa mesmo de codigo ? 
            servidor[ordenados_indices[i]].nome,
            servidor[ordenados_indices[i]].siape,
            servidor[ordenados_indices[i]].cpf,
            servidor[ordenados_indices[i]].nascimento,
            servidor[ordenados_indices[i]].endereco,
            servidor[ordenados_indices[i]].rg,
            servidor[ordenados_indices[i]].salario,
            servidor[ordenados_indices[i]].tipo);
    }
  }
  printf("\n########FIM DA LISTAGEM######\n");

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

void organizando_nomes(size_t* quant_regist, servidor_t* ptr_regis, char opcao)
{
  char nomes[(*quant_regist)][100],aux[100];

  for(int i = 0 ; i < (*quant_regist) ; ++i)
  {
    strcpy(nomes[i], ptr_regis[i].nome);
  }
  
  for( int i = 0 ; i < (*quant_regist) ; ++i){
    for( int j = 0 ; j < ((*quant_regist) - i - 1) ; ++j)
    {
      if( (tolower(nomes[j][0]) > tolower(nomes[j+1][0]) ) || ( (tolower(nomes[j][0]) == tolower(nomes[j+1][0])) && (tolower(nomes[j][1]) > tolower(nomes[j+1][1])) ) )
      {
        strcpy(aux,nomes[j]);
        strcpy(nomes[j],nomes[j+1]);
        strcpy(nomes[j+1],aux);
      }
    }
  }

  return ordena_servidor(opcao,nomes,quant_regist,ptr_regis);
}

void ordena_servidor(char choice,char copy_nome[][TAM_STR],size_t* quantia_regis,servidor_t* ptr_regis)
{
  int quantia = 0,vet_indices[(*quantia_regis)];

  for(int i = 0 ; i < (*quantia_regis) ; ++i)
  {
    for(int j = 0 ; j < ((*quantia_regis) - i) ; ++j)
    {
      if( !strcmp(ptr_regis[j].nome, copy_nome[i]) ) // tirei o check typeserv daqui 
      {
        vet_indices[i] = j;
        quantia++;
      }
    }
  }

    verificador_quantia(choice,quantia,vet_indices,ptr_regis,quantia_regis);
    return ;
}

void verificador_quantia(char choice,int quantia, int *ordenador,servidor_t* ptr_regis,size_t *quantia_registros)
{
    if (!(quantia)) printf("\nSem registros!!\nCadastre um novo Servidor!!\n");
    else list_serv(choice, ptr_regis, ordenador, quantia_registros); // não preciso passar quantia, posso passar choice para list serv, ficaria mais controlado
}

void opcao_list_serv()
{
    printf("Digite a forma como deseja printar os servidores\n\n");
    printf("1. Printar apenas os Tecnicos \n");
    printf("2. Printar apenas os professores \n");
    printf("3. Printar Todos \n");
    printf("4. Printar um servidor pelo cod dele.\n");
    printf("5. Para retornar ao menu\n");
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
  fgets( campo, TAM_STR, stdin );
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


int check_type_serv(char opcao,char type_serv[])
{
    if(opcao == '1') return (!strcmp("Tecnico",type_serv)) ;
    else if(opcao == '2') return (!strcmp("Professor",type_serv)) ;
    else return 1;
}