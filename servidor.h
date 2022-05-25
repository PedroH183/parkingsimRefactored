#ifndef SERVIDOR_H
#define SERVIDOR_H


char* criar_servidor(char *nome_temp,char *siape_temp,char *cpf_temp, char *nasci_temp,
                    char *ende_temp, char *rg_temp,char *salar_temp,char *tipo_temp, servidor *_servidor_ptr);
void list_serv(servidor *);
void libera_memoria(servidor *ptr_servidor);
FILE *open_file(char mode[]);
void limpar_vet_ptrs(servidor *_servidor);
int quantia_regist_arq();
int escrever_arquivo(void * objeto, size_t tam_struct, int cont);
int ler_arquivo(void * objeto, size_t tam_struct, int cont);
const char *rece_type_serv(char opcao[]);
char *caixa_correcao(char campo[]);
const char *ler_campo(char *texto, char *campo);
int busca_livre(servidor * grupo);
int cod_p_cadastro(servidor *_servidor_ptr);

#endif