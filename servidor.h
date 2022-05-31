#ifndef SERVIDOR_H
#define SERVIDOR_H

servidor_t criar_servidor();
void list_serv();
servidor_t* inserir_servidor(servidor_t* servidor_ptr, servidor_t servidor, size_t* tamanho);

const char *rece_type_serv(const char *opcao);
servidor_t* deletar_servidor(servidor_t* servidor_ptr, int indice, size_t* tamanho);

int em_branco(char *string);
char ler_menu(char input);
char *ler_campo( char *texto, char *campo );
char *caixa_correcao( char *campo );
void opcao_list_serv();

#endif