#ifndef SERVIDOR_H
#define SERVIDOR_H

servidor_t criar_servidor();
servidor_t* inserir_servidor(servidor_t* servidor_ptr, servidor_t servidor, size_t* tamanho);
servidor_t* modify_servidor( servidor_t* servidor_ptr, int indice, size_t* tamanho );
servidor_t* deletar_servidor(servidor_t* servidor_ptr, int indice, size_t* tamanho);
char* ler_campo( char *texto, char *campo );
char* caixa_correcao(char *campo);
char ler_menu(char input);
void list_serv(char choice, servidor_t* servidor , int *ordenados_indices, size_t* quantia_regis, int quantia_prints);
void organizando_nomes(size_t* quant_regist, servidor_t* ptr_regis, char opcao);
int inpt_branco_ou_rept(char *nome, char *siape,char *cpf, servidor_t* ptr_regis, size_t* tamanho,int indice);
int check_type_serv(char opcao,char *type_serv);
int buscar_codigo(int ipt_codigo, size_t* qtd_regis, servidor_t* ptr_str);
int codigo_gerador(servidor_t *ptr_registros,size_t *quantia_registros);
int quantia_p_printar(size_t *tamanho, char tipo,servidor_t *ptr_dados);
const char *rece_type_serv(const char opcao);




#endif