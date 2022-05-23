#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "estruturas.h"
#include "servidor.h"
//#include "entradas.h"
#include "arquivos.h"
#include "utilitarios.h"


char* criar_servidor(char *nome_temp,char *siape_temp,char *cpf_temp, char *nasci_temp,
                    char *rg_temp,char *tipo_temp,char *salar_temp,char *ende_temp, servidor *_servidor_ptr)
{ 
    int codigo = (quantia_regist_arq() + 1); // retrição lógica
    
    if(codigo >= MAX) // codigo sempre que retornar de codigo será 101 ! erro de tamanho
    {
      codigo = busca_livre(_servidor_ptr);
    }

    _servidor_ptr[codigo].codigo = codigo; // inteiro
    _servidor_ptr[codigo].ativo = true;
    strcpy(_servidor_ptr[codigo].nome, caixa_correcao(nome_temp));
    strcpy(_servidor_ptr[codigo].siape,caixa_correcao(siape_temp));
    strcpy(_servidor_ptr[codigo].cpf,caixa_correcao(cpf_temp));
    strcpy(_servidor_ptr[codigo].nascimento, caixa_correcao(nasci_temp));
    
    strcpy(_servidor_ptr[codigo].rg,caixa_correcao(rg_temp));
    strcpy(_servidor_ptr[codigo].tipo,caixa_correcao(tipo_temp));
    strcpy(_servidor_ptr[codigo].salario, caixa_correcao(salar_temp));
    strcpy(_servidor_ptr[codigo].endereco,caixa_correcao(ende_temp));

    escrever_arquivo(_servidor_ptr,sizeof(servidor),MAX);
    
    return "CADASTRO REALIZADO COM SUCESSO !";
}

void list_serv(servidor * _servidor)//recebe um vetor de inteiros que vai ser ordenado !! 
{
  printf("\n############Listando#########\n");

  for(int i = 1 ; i <= MAX ; ++i)
  {
    if( (&_servidor[i])->ativo) // só prita se for true
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

int quantia_regist_arq() 
{
  FILE *f_ptr = fopen(NAME_FILE, "rb+");
	int qutd_saves = 0;

	fseek(f_ptr,0,SEEK_END);
	qutd_saves = (ftell(f_ptr)/sizeof(servidor)); // retorna a quantia de registros savos
  
  fclose(f_ptr);

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