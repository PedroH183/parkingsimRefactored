#ifndef VEICULO_H
#define VEICULO_H

int checar_prop_existe(servidor_t* servidor, size_t tamanho, int codigo);
int checar_veic_existe(servidor_t* servidor, size_t tamanho, int codigo, int* ind_s, int* ind_v);
int checar_cheio(veiculo_t veiculo[]);
int checar_vazio(veiculo_t veiculo[]);
int checar_cod_existe(servidor_t* servidor, size_t tamanho, int r_cod);
int checar_desc_existe(servidor_t* servidor, size_t tamanho, char buffer[]);
int checar_placa_existe(servidor_t* servidor, size_t tamanho, char buffer[]);
int gerador_codigo(servidor_t* servidor, size_t tamanho);
void ler(char buffer[]);
void listar_por_codigo(servidor_t servidor, int ind_v);
void listar_por_servidor(servidor_t servidor);
void listar_ordenado(servidor_t servidor);

#endif