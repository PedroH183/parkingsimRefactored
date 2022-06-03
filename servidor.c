#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h> 

#include "./DotH\\estruturas.h"
#include "./DotH\\servidor.h"

servidor_t criar_servidor(servidor_t* ptr_regis,int *tamanho)
{ 
    servidor_t novo_servidor;
    char aux[TAM_STR];
    srand( (unsigned) time(NULL)); // random seed 
     
    do{

    strcpy( novo_servidor.nome  ,ler_campo("Digite o nome do Servidor \n>",  novo_servidor.nome   )); // obrigatorio e pode se repetir      
    strcpy( novo_servidor.siape ,ler_campo("Digite o siape do Servidor\n>",  novo_servidor.siape  )); // obrigadorio e não pode repetir
    strcpy( novo_servidor.cpf   ,ler_campo("Digite o cpf do Servidor  \n>",  novo_servidor.cpf    )); // obrigatorio e não pode repetir

    }while( inpt_branco_ou_rept( novo_servidor.nome, novo_servidor.siape, novo_servidor.cpf, ptr_regis, tamanho, -1) );

    strcpy( novo_servidor.nascimento,ler_campo("Digite a data de nascimento do servidor\n>",novo_servidor.nascimento));
    strcpy( novo_servidor.rg        ,ler_campo("Digite o rg do Servidor\n>",                novo_servidor.rg        ));
    strcpy( novo_servidor.salario   ,ler_campo("Digite o salario do servidor\n>",           novo_servidor.salario   ));
    strcpy( novo_servidor.endereco  ,ler_campo("Digite o endereco do Servidor\n>",          novo_servidor.endereco  ));
    novo_servidor.codigo = rand()%1000; 

    do{
        strcpy(      aux           ,ler_campo("Digite o tipo de Servidor\n1-Professor  2-Tecnico\n::",   aux));
        strcpy( novo_servidor.tipo ,rece_type_serv(aux) );

      }while( strcmp( (aux) ,"1") && strcmp( (aux) ,"2") );
    
    return novo_servidor;
}

void list_serv(char choice, servidor_t* servidor , int *ordenados_indices, size_t* quantia_regis)// deve receber como parametro um vetor ordenado
{
  int ptrints_quantia = 0;
  printf("\n############Listando#########\n");

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
    ptrints_quantia++;
    }
  }
  printf("\n########FIM DA LISTAGEM######\n");

  if(!ptrints_quantia)
  {
    printf("\nSEM REGISTROS PARA ESSE TIPO DE SERVIDOR\nCadastre um novo servidor\n\n");
  }

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
  if(!(*quant_regist))
  {
    printf("\nCADASTRE PELO MENOS UM SERVIDOR!\n\n");
    return;
  }
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

  list_serv(opcao, ptr_regis, vet_indice, quant_regist);

  return ;
}

servidor_t* modify_servidor( servidor_t* servidor_ptr, int indice, size_t* tamanho )
{
    if(indice == -1) return servidor_ptr; // não executa nenhuma mudança

    do{
    strcpy( servidor_ptr[indice].nome  ,ler_campo("Digite o Novo nome do Servidor \n>",  servidor_ptr[indice].nome   )); // obrigatorio
    strcpy( servidor_ptr[indice].siape ,ler_campo("Digite o Novo siape do Servidor\n>",  servidor_ptr[indice].siape  )); // obrigadorio e não pode repetir
    strcpy( servidor_ptr[indice].cpf   ,ler_campo("Digite o Novo cpf do Servidor  \n>",  servidor_ptr[indice].cpf    )); // obrigatorio e não pode repetir
    
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
    if(opcao == '1') return (!strcmp("Tecnico",type_serv)) ;
    else if(opcao == '2') return (!strcmp("Professor",type_serv)) ;
    else return 1;
}

int buscar_codigo(int ipt_codigo, size_t* qtd_regis, servidor_t* ptr_str) // função para apagar por codigo !!
{
  for(int i =0 ; i < (*qtd_regis); ++i)
  {
    if(ptr_str[i].codigo == ipt_codigo) return i;
  }
  printf("\nCODIGO NAO REGISTRADO !!\n");
  return -1; // não encontrou correspondência
}


int inpt_branco_ou_rept(char *nome, char *siape,char *cpf, servidor_t* ptr_regis, size_t* tamanho, int indice)
{
    int input1,input2,input3,teste;

    input1 = strcmp(siape,"\0");
    input2 = strcmp(cpf,"\0"); 
    input3 = strcmp(nome,"\0");  // pode repetir

    if( !(input1 && input2 && input3) ) 
    {
        printf("\nDigite Valores validos para entrada\nCAMPOS: SIAPE, NOME E CPF SAO OBRIGATORIOS!!\n\n");
        return 1;
    }
    /*Avaliar se esta repetido */
    for( int i = 0; i < (*tamanho) ; ++i)
    {
        if(i != indice)
        {
            teste = ( strcmp( ptr_regis[i].siape, siape) && strcmp( ptr_regis[i].cpf, cpf) );
            if( !teste ) 
            {
                printf("\nAlguns dos dados estao repetidos !!!\nTente novamente\n\n");
                return 1;
            }
        }
    }
  return 0; // se chegou aqui ele passou no teste
}

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