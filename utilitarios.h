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

int comparar_veiculo(const void *v1, const void*v2)
{
    const veiculo *veic1 = v1;
    const veiculo *veic2 = v2;

    return veic1->codigo == veic2->codigo ? 0 : 1
}

void * encontrar_elemento(const void *valor, void * base, size_t *nmembros, size_t tamanho, int(*compar)(const void *v1, const void*v2))
{
    const void *resultado = base;
    size_t cnt = 0;

    while(cnt < *nmembros && (*compar)(valor, resultado) != 0)
    {
        resultado += tamanho;
        ++cnt;
    }

    return cnt < *nmembros ? (void *) resultado : NULL;
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