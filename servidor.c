#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h> 

#include "./DotH//estruturas.h"
#include "./DotH//servidor.h"

servidor_t criar_servidor(servidor_t* ptr_regis, size_t *tamanho)
{ 
    servidor_t novo_servidor;
    int comparar_com_todos = -1;
    char aux[TAM_STR];
     
    do{

    strcpy( novo_servidor.nome  ,ler_campo("Digite o nome do Servidor \n>",  novo_servidor.nome   )); 
    strcpy( novo_servidor.siape ,ler_campo("Digite o siape do Servidor\n>",  novo_servidor.siape  )); 
    strcpy( novo_servidor.cpf   ,ler_campo("Digite o cpf do Servidor  \n>",  novo_servidor.cpf    )); 

    }while( inpt_branco_ou_rept( novo_servidor.nome, novo_servidor.siape, novo_servidor.cpf, ptr_regis, tamanho, comparar_com_todos) );

    strcpy( novo_servidor.nascimento,ler_campo("Digite a data de nascimento do servidor\n>",novo_servidor.nascimento));
    strcpy( novo_servidor.rg        ,ler_campo("Digite o rg do Servidor\n>",                novo_servidor.rg        ));
    strcpy( novo_servidor.salario   ,ler_campo("Digite o salario do servidor\n>",           novo_servidor.salario   ));
    strcpy( novo_servidor.endereco  ,ler_campo("Digite o endereco do Servidor\n>",          novo_servidor.endereco  ));
    novo_servidor.codigo =  codigo_gerador(ptr_regis,tamanho);

    do{
        strcpy(      aux           ,ler_campo("Digite o tipo de Servidor\n1-Professor  2-Tecnico\n>>",   aux));
        strcpy( novo_servidor.tipo ,rece_type_serv(aux) );

      }while( strcmp( aux ,"1") && strcmp( aux ,"2") );

    for(int i = 0; i < MAX_V; i++)
    {
      novo_servidor.veiculo[i].ocupado = 0;
    }
    
    return novo_servidor;
}

void list_serv(char choice, servidor_t* servidor , int *ordenados_indices, size_t* quantia_regis, int quantia_prints)
{
  if(!quantia_prints)
  {
    printf("\nNao existe esse tipo de servidor no arquivo !!\n\n");
    return;
  }
  printf("\n######LISTANDO SERVIDORES#######\n");

  for(int i = 0 ; i < (*quantia_regis) ; ++i)
  {
    if( check_type_serv(choice, servidor[ordenados_indices[i]].tipo) )
    {
    printf("Codigo: %d\nNome: %s\nSiape: %s\nCpf: %s\nNascimento: %s\nEndereco: %s\nRg: %s\nSalario: %s\nTipo: %s\n\n",
            servidor[ordenados_indices[i]].codigo,
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
  printf("\n########FIM DA LISTAGEM######\n\n");

  return;
}

const char *rece_type_serv(const char *opcao)
{
  if( !strcmp(opcao,"1") ) return "Professor";
  if( !strcmp(opcao,"2") ) return "Tecnico";
  else {
    printf("\n");
    return "ERRO";
    }
}

void organizando_nomes(size_t* quant_regist, servidor_t* ptr_regis, char opcao)
{
  int vet_indice[(*quant_regist)], aux;

  for(int i = 0; i < (*quant_regist) ; ++i)
  {
    vet_indice[i] = i;
  }
  
  for( int i = 0 ; i < (*quant_regist) - 1  ; ++i)
  {
    for( int j = 0 ; j < ((*quant_regist) - i - 1 ) ; ++j)
    {
      if( (tolower(ptr_regis[ vet_indice[j] ].nome[0]) > tolower(ptr_regis[  vet_indice[ j+1 ]].nome[0]) ) ||
        ( (tolower(ptr_regis[ vet_indice[j] ].nome[0]) == tolower(ptr_regis[ vet_indice[ j+1 ]].nome[0])) &&
        (  tolower(ptr_regis[ vet_indice[j] ].nome[1]) > tolower(ptr_regis[  vet_indice[ j+1 ]].nome[1])) ) )
      {
        aux = vet_indice[ j ];
        vet_indice[ j ] = vet_indice[ j + 1 ];
        vet_indice[ j + 1 ] = aux;
      }
    }
  }

  list_serv(opcao, ptr_regis, vet_indice, quant_regist, quantia_p_printar(quant_regist,opcao,ptr_regis));

  return ;
}

servidor_t* modify_servidor( servidor_t* servidor_ptr, int indice, size_t* tamanho )
{
  if(indice == -1) return servidor_ptr; // não executa nenhuma mudança

  do{
  strcpy( servidor_ptr[indice].nome  ,ler_campo("Digite o Novo nome do Servidor \n>",  servidor_ptr[indice].nome   )); 
  strcpy( servidor_ptr[indice].siape ,ler_campo("Digite o Novo siape do Servidor\n>",  servidor_ptr[indice].siape  )); 
  strcpy( servidor_ptr[indice].cpf   ,ler_campo("Digite o Novo cpf do Servidor  \n>",  servidor_ptr[indice].cpf    ));
    
  }while( inpt_branco_ou_rept(servidor_ptr[indice].nome, servidor_ptr[indice].siape, servidor_ptr[indice].cpf, servidor_ptr, tamanho, indice) );

  strcpy( servidor_ptr[indice].nascimento,ler_campo("Digite a Nova data de nascimento do servidor\n>",servidor_ptr[indice].nascimento));
  strcpy( servidor_ptr[indice].rg        ,ler_campo("Digite o Novo rg do Servidor\n>",                servidor_ptr[indice].rg        ));
  strcpy( servidor_ptr[indice].salario   ,ler_campo("Digite o Novo salario do servidor\n>",           servidor_ptr[indice].salario   ));
  strcpy( servidor_ptr[indice].endereco  ,ler_campo("Digite o Novo endereco do Servidor\n>",          servidor_ptr[indice].endereco  ));

  printf("CADASTRO ATUALIZADO !! \n\n");

  return servidor_ptr;
}

int check_type_serv(char opcao,char *type_serv)
{
    if(opcao == '1') return !strcmp("Tecnico",type_serv);
    else if(opcao == '2') return !strcmp("Professor",type_serv);
    else return 1;
}

int inpt_branco_ou_rept(char *nome, char *siape,char *cpf, servidor_t* ptr_regis, size_t* tamanho, int indice)
{
  if( !( strcmp(siape,"\0") && strcmp(cpf,"\0") && strcmp(nome,"\0")) ) 
  {
    printf("\nCAMPOS: SIAPE, NOME E CPF SAO OBRIGATORIOS!!\n\n");
    return 1;
  }

  for( int i = 0; i < (*tamanho) ; ++i)
  {
    if(i != indice)
    {
      if( !( strcmp( ptr_regis[i].siape, siape) && strcmp( ptr_regis[i].cpf, cpf) ) ) 
      {
        printf("\nAlguns dos dados estao repetidos !!!\n\n");
        return 1;
        }
    }
  }
  return 0;
}

int quantia_p_printar(size_t *tamanho, char tipo ,servidor_t *ptr_dados)
{
  int quantia = 0;
  char tipo_servidor[TAM_STR];
  
  if( tipo == '1' )
    strcpy(tipo_servidor,"Tecnico");
  else if( tipo == '2')
    strcpy(tipo_servidor, "Professor");
  else
    return 1;

  for(int i = 0 ; i < *tamanho ; ++i)
  {
    if( !strcmp(ptr_dados[i].tipo,tipo_servidor) )
    {
      quantia++;
    }
  }

  return quantia;
}