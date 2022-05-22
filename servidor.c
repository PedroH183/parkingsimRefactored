#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "estruturas.h"
#include "servidor.h"
//#include "entradas.h"
#include "arquivos.h"
#include "utilitarios.h"


char* criar_servidor(char nome_temp[],char siape_temp[],char cpf_temp[], char nasci_temp[],
                    char rg_temp[],char tipo_temp[],char salar_temp[],char ende_temp[], servidor *_servidor_ptr)
{ 
    FILE *f_ptr = fopen("data.bin", "rb+");
    int codigo = (quantia_regist_arq(f_ptr) + 1); // retrição lógica
    fclose(f_ptr);
    
    /*
      criar um campo ativos para sobre-escrever os dados daquela estrutura em específico
      é mais fácil que trabalhar com realoc
    */

    /*
      fazer um teste de campos inativos e sobre-escrever nesse exato indice 
      se falso eu verifico a quantia de saves se é maior que SERV_REGIS 
      caso os dois de cima sejam falsos não há espaço
   
    if(codigo > SERV_REGIS){
      printf("Nao ha mais espaço disponivel!!\n");
      return;
    }
    */

    _servidor_ptr[codigo].codigo = codigo; // inteiro
    _servidor_ptr[codigo].ativo = 1;
    strcpy(_servidor_ptr[codigo].nome, nome_temp);
    strcpy(_servidor_ptr[codigo].siape,siape_temp);
    strcpy(_servidor_ptr[codigo].cpf,cpf_temp);
    strcpy(_servidor_ptr[codigo].nascimento, nasci_temp);
    
    strcpy(_servidor_ptr[codigo].rg,rg_temp);
    strcpy(_servidor_ptr[codigo].tipo,tipo_temp);
    strcpy(_servidor_ptr[codigo].salario, salar_temp);
    strcpy(_servidor_ptr[codigo].endereco,ende_temp);
  
  return "\nCADASTRO REALIZADO COM SUCESSO !\n";
}

void list_serv(servidor * _servidor)//recebe um vetor de inteiros que vai ser ordenado !! 
{
  printf("\n############Listando#########\n");

  for(int i = 1 ; i <= MAX ; ++i)
  {
    if( (&_servidor[i])->ativo != 0)
    {
      printf("Codigo: %d\nNome: %s\nSiape: %s\nCpf: %s\nNascimento: %s\nEndereco: %s\nRg: %s\nSalario: %s\nTipo: %s\n\n",
            (&_servidor[i])->codigo,
            (&_servidor[i])->nome,
            (&_servidor[i])->siape,
            (&_servidor[i])->cpf,
            (&_servidor[i])->nascimento,
            (&_servidor[i])->endereco,
            (&_servidor[i])->rg,
            (&_servidor[i])->salario,
            (&_servidor[i])->tipo);
    }
  }
  
  printf("\n\n########FIM DA LISTAGEM######\n");

  return;
}


void libera_memoria(servidor *ptr_servidor) // liberar a alocação 
{
  for(int i = 1 ; i< MAX; ++i )
  {
    if( (&ptr_servidor[i]) != NULL)
    {
      free((&ptr_servidor[i]));
    }
  }
}

void limpar_vet_ptrs(servidor *_servidor) // tira possiveis interferencias dos apontadores 
{
  for(int i = 0; i <= MAX; i++)
  {
      (&_servidor)[i] = NULL;
  }

  return;
}

int quantia_regist_arq(FILE *ptr_f) 
{
  /*
    Usar a lógica de um arquivo auxiliar que salva a quantia de registros feitos 
    Criar um arquivo que vai armazenar os indices == Codigo



  */

	int qutd_saves = 0;
	fseek(ptr_f,0,SEEK_END);
	qutd_saves = (ftell(ptr_f)/sizeof(servidor)); // retorna a quantia de registros savos

	return qutd_saves;
}

const char *rece_type_serv(char opcao[])
{
  if( !strcmp(opcao,"1") ) return "Professor";
  if( !strcmp(opcao,"2") ) return "Tecnico";
  else {
      printf("\nDigite uma opcao valida !!!\n");
      return "ERRO";
    }
}