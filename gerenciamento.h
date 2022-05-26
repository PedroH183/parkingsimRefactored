#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include <stdlib.h>
#include <stdio.h>

#include "estruturas.h"
#include "arquivos.h"

controle inicializar_controle(controle controle)
{
	controle.tamanho = buscar_tamanho();
	controle.servidor = malloc(controle.tamanho*sizeof(servidor));

	return controle;
}

controle inserir_servidor(controle controle)
{
	controle.tamanho++;
	controle.servidor = realloc(controle.servidor, controle.tamanho*sizeof(servidor));

	for(int i = 0; i < controle.tamanho; i++)
	{
		if(controle.servidor[i].ocupado != 1)
		{
			printf("Nome: ");
			fgets(controle.servidor[i].nome, sizeof(controle.servidor[i].nome), stdin);
			controle.servidor[i].ocupado = 1;
			break;
		}
	}

	return controle;
}

controle remover_servidor(controle controle, int indice)
{
	if(indice > controle.tamanho)
	{
		printf("Indice fora dos limites, estrutura inalterada\n");
		return controle;
	}

	for(int i = indice; i < controle.tamanho; i++)
	{
		controle.servidor[i] = controle.servidor[i+1];
	}

	controle.tamanho--;
	controle.servidor = realloc(controle.servidor, controle.tamanho*sizeof(servidor));

	return controle;
}

#endif