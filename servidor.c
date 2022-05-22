#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "servidor.h"
//#include "entradas.h"
#include "arquivos.h"
#include "utilitarios.h"


void criar_servidor(char nome_temp[],char siape_temp[],char cpf_temp[], char nasci_temp[],
                    char ende_temp[], char rg_temp[],char salar_temp[],char tipo_temp[], servidor *_servidor_ptr[])
{ 
    FILE *arquivo = open_file("rb+");
    // criar uma logica para codigo
    /*
      criar um campo ativos para sobre-escrever os dados daquela estrutura em específico
      é mais fácil que trabalhar com realoc
    */
    int codigo = (quantia_regist_arq(arquivo) + 1);
    pop_struct(arquivo,_servidor_ptr);

    /*
      fazer um teste de campos inativos e sobre-escrever nesse exato indice 
      se falso eu verifico a quantia de saves se é maior que SERV_REGIS 
      caso os dois de cima sejam falsos não há espaço
   
    if(codigo > SERV_REGIS){
      printf("Nao ha mais espaço disponivel!!\n");
      return;
    }
    */

    _servidor_ptr[codigo] = malloc(sizeof(servidor));// ponteiro recebendo um bloco de memória 
    _servidor_ptr[codigo]->codigo = codigo; // inteiro
    strcpy(_servidor_ptr[codigo]->nome, nome_temp);
    strcpy(_servidor_ptr[codigo]->siape,siape_temp);
    strcpy(_servidor_ptr[codigo]->cpf,cpf_temp);
    strcpy(_servidor_ptr[codigo]->nascimento, nasci_temp);
    strcpy(_servidor_ptr[codigo]->endereco,ende_temp);
    strcpy(_servidor_ptr[codigo]->rg,rg_temp);
    strcpy(_servidor_ptr[codigo]->salario, salar_temp);
    strcpy(_servidor_ptr[codigo]->tipo,tipo_temp);
    
    fseek(arquivo,0,SEEK_END);  
    //fprintf(arquivo,FORMATO_ESCREVER,povo[codigo]->id,povo[codigo]->nome,povo[codigo]->idade);
    fwrite(_servidor_ptr[codigo],sizeof(servidor),1,arquivo);
    
    limpar_vet_ptrs(_servidor_ptr); // pego o vetor inteiro de ponteiros e limpo
    fclose(arquivo);
  return ;
}

void list_serv(servidor * _servidor[])//recebe um vetor de ponteiros 
{
  limpar_vet_ptrs(_servidor);
  FILE *arquivo = open_file("rb+");
  pop_struct(arquivo,_servidor);

  printf("\n############Listando#########\n");

  for(int i = 1 ; i <= MAX ; ++i)
  {
    if( _servidor[i] != NULL)
    {
      printf("Codigo: %d\nNome: %s\nSia: %s\nCpf: %s\nNascimento: %s\nEndereco: %s\nRg: %s\nSalario: %s\nTipo: %s\n\n",
            _servidor[i]->codigo,
            _servidor[i]->nome,
            _servidor[i]->siape,
            _servidor[i]->cpf,
            _servidor[i]->nascimento,
            _servidor[i]->endereco,
            _servidor[i]->rg,
            _servidor[i]->salario,
            _servidor[i]->tipo);
    }
  }
  
  printf("\n\n########FIM DA LISTAGEM######\n");

  limpar_vet_ptrs(_servidor);
  fclose(arquivo);
  return;
}


void libera_memoria(servidor *ptr_servidor[]) // liberar a alocação 
{
  for(int i = 1 ; i< MAX; ++i )
  {
    if(ptr_servidor[i] != NULL)
    {
      free(ptr_servidor[i]);
    }
  }
}

FILE *open_file(char mode[])
{
  FILE *arquivo = fopen("servs.bin",mode); // abre um arquivo

  if(arquivo == NULL){
    arquivo = fopen("servs.bin","wb+");// cria o arquivo
  }
  return arquivo;
}

void pop_struct(FILE *file,servidor *ptr_serv[])// função que popula as structs !! 
{
  int quantia_saves = quantia_regist_arq(file);
  printf("@@@A QUANTIA DE SAVES no arquivo::[ %d ]@@@\n",quantia_saves);

  for(int i = 1; i <= quantia_saves ; ++i)
  {
    ptr_serv[i] = malloc(sizeof(servidor)); // quando recebe um malloc ele deixa de ser null ?
  }
  
  fseek(file,0,SEEK_SET);// se o arquivo estiver no inicio o final é o começo,
  int i = 1;

  while(!feof(file))
  {
    //fscanf(file,FORMATO_LER,povo[i]->id,povo[i]->nome,povo[i]->idade);
    fread(ptr_serv[i],sizeof(servidor),1,file);
    //printf("SAVE ::[ %d ]@@@",i);
    i++;
  }
 
  return ;
}

void limpar_vet_ptrs(servidor *_servidor[]) // tira possiveis interferencias dos apontadores 
{
  for(int i = 0; i <= MAX; i++)
  {
    _servidor[i] = NULL;
  }

  return;
}

int quantia_regist_arq(FILE *ptr_f)
{
	int qutd_saves = 0;
	fseek(ptr_f,0,SEEK_END);
	qutd_saves = (ftell(ptr_f)/sizeof(servidor)); // retorna a quantia de registros savos

	return qutd_saves;
}