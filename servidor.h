#ifndef SERVIDOR_H
#define SERVIDOR_H

servidor_t criar_servidor();
servidor_t* inserir_servidor(servidor_t* servidor_ptr, servidor_t servidor, size_t* tamanho);
void list_serv(char choice, servidor_t* servidor , int ordenados_indices[], size_t* quantia_regis);

const char *rece_type_serv(const char *opcao);
servidor_t* deletar_servidor(servidor_t* servidor_ptr, int indice, size_t* tamanho);

int em_branco(char *string);
char ler_menu(char input);
char *ler_campo( char *texto, char *campo );
char *caixa_correcao( char *campo );
void opcao_list_serv();

void organizando_nomes(size_t* quant_regist, servidor_t* ptr_regis, char opcao);
void ordena_servidor(char choice,char copy_nome[][TAM_STR],size_t *quantia_regis,servidor_t* ptr_regis);
void verificador_quantia(char choice,int quantia, int *ordenador,servidor_t* ptr_regis,size_t *quantia_registros);
int check_type_serv(char opcao,char type_serv[]);

#endif