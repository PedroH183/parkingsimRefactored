#ifndef SERVIDOR_H
#define SERVIDOR_H


char* criar_servidor(char nome_temp[],char siape_temp[],char cpf_temp[], char nasci_temp[],
                    char ende_temp[], char rg_temp[],char salar_temp[],char tipo_temp[], servidor *_servidor_ptr);
void list_serv(servidor *);
void libera_memoria(servidor *ptr_servidor);
FILE *open_file(char mode[]);
void pop_struct(servidor *ptr_serv);
void limpar_vet_ptrs(servidor *_servidor);
int quantia_regist_arq(FILE *ptr_f);
int escrever_arquivo(void * objeto, size_t tam_struct, int cont);
int ler_arquivo(void * objeto, size_t tam_struct, int cont);
const char *rece_type_serv(char opcao[]);

#endif