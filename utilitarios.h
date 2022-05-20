#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#define TAM sizeof(_servidor)/sizeof(servidor)

#include <string.h>

int comparar_servidor(const void *v1, const void *v2) //Logica implementada em qsort
{
    const servidor *s1 = v1;
    const servidor *s2 = v2;

    return strcmp(s1->nome, s2->nome);
}

int encontrar_servidor(char * nome, servidor * vetor, int tam_vetor) //So funciona para vetores ordenados
{
    servidor alvo, *resultado;
    strcpy(alvo.nome, nome);
    resultado = bsearch(&alvo, vetor, tam_vetor, sizeof(servidor), comparar_servidor); //Bsearch (pesquisa binaria) retorna um ponteiro

    if(resultado)
    {
        return 1;
    } else
    {
        return 0;
    }
}

//Usar operador de ponteiros quando passar argumentos. Ex: imprimir_servidor(&servidor[i])
void imprimir_servidor(servidor * _servidor)
{
    printf("Codigo: %d\nNome: %s\nSia: %s\nCpf: %s\nNascimento: %s\nEndereco: %s\nRg: %s\nSalario: %s\nTipo: %s\n\n",
            _servidor->codigo,
            _servidor->nome,
            _servidor->sia,
            _servidor->cpf,
            _servidor->nascimento,
            _servidor->endereco,
            _servidor->rg,
            _servidor->salario,
            _servidor->tipo);
}

#endif