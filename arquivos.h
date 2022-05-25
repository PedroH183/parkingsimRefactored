#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "estruturas.h"

#define NOME_ARQUIVO "data.bin"

int escrever_arquivo(controle* ptr_controle)
{
	FILE *fptr = fopen(NOME_ARQUIVO, "wb");
	if(fptr == NULL)
	{
		return 1;
	}

	fwrite(ptr_controle->servidor, ptr_controle->tamanho*sizeof(servidor), 1, fptr);

	fclose(fptr);
}

int ler_arquivo(controle* ptr_controle)
{
	FILE *fptr = fopen(NOME_ARQUIVO, "rb");
	if(fptr == NULL)
	{
		return 1;
	}

	fread(ptr_controle->servidor, ptr_controle->tamanho*sizeof(servidor), 1, fptr);

	fclose(fptr);
}

int buscar_tamanho()
{
	FILE *fptr = fopen(NOME_ARQUIVO, "ab");
	if(fptr == NULL)
	{
		return 1;
	}

	fseek(fptr, 0L, SEEK_END);
	int tamanho = ftell(fptr);

	return tamanho / sizeof(servidor);
}

#endif