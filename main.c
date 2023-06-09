#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./DotH//estruturas.h"
#include "./DotH//entradas.h"
#include "./DotH//arquivos.h"
#include "./DotH//veiculo.h"
#include "./DotH/gerenciamento.h"

int main()
{
    size_t tamanho = buscar_tamanho();
    servidor_t* servidor = malloc(MEM);

    if(tamanho)
    {
        if(ler_dados(servidor, tamanho) == -1)
        {
            printf("Falha na leitura do arquivo!\n");
            return 0;
        }
    }

    fflush(stdin);
    char input = '~';
    int codigo;

    /*Buffers dos inputs de veiculo*/
    int int_buff;
    char char_buff[TAM_STR], opt;
    int indice_servidor, indice_veiculo;

    do
    {
        printf("1. Inser. servidor\n");
        printf("2. Atual. servidor\n");
        printf("3. Delet. servidor\n");
        printf("4. Lista. servidor\n\n");
        printf("5. Inser. veiculo\n");
        printf("6. Atual. veiculo\n");
        printf("7. Delet. veiculo\n");
        printf("8. Lista. veiculo\n\n");
        printf("9. Salvar dados\n");
        printf("0. Terminar programa\n\n");

        printf("Escolha: ");
        scanf(" %c", &input);
        
        switch(input)
        {
            case sair_do_programa:

                printf("\nSalvando dados e terminando programa...\n\n");
                if(escrever_arquivo(servidor, tamanho, "wb+") == -1)
                {
                    printf("Falha na escrita do arquivo!\n");
                }
                free(servidor);
                return 0;

            case insert_servidor:

                servidor = inserir_servidor(servidor, criar_servidor(servidor,&tamanho), &tamanho);
                break;

            case alterar_servidor:
                
                printf("\nDigite o codigo do servidor\n>");
                scanf("%d",&codigo);
                fflush(stdin);
                servidor = modify_servidor( servidor, buscar_codigo(codigo,&tamanho,servidor), &tamanho );
                
                break;
            case remover_servidor:

                printf("\nDigite o codigo do servidor\n>");
                scanf("%d",&codigo);
                fflush(stdin);

                if( buscar_codigo(codigo, &tamanho, servidor) == -1){
                    break;
                }
                
                int_buff = checar_vazio(servidor[buscar_codigo(codigo,&tamanho,servidor)].veiculo);

                if( int_buff )
                {
                    printf("\n####O SERVIDOR TEM VEICULOS CADASTRADOS!!####\n");
                    listar_por_servidor(servidor[buscar_codigo(codigo,&tamanho,servidor)]);

                    printf("\n##DESEJA REALMENTE DELETAR O SERVIDOR?##\n1-SIM\t2-NAO\n>");
                    scanf(" %c",&opt);
                    fflush(stdin);

                    switch ( opt )
                    {
                    case '1':
                        servidor = deletar_servidor(servidor,buscar_codigo(codigo,&tamanho,servidor), &tamanho);
                        break;
                    default:
                        printf("\n");
                        break;
                    }
                }else {
                    servidor = deletar_servidor(servidor,buscar_codigo(codigo,&tamanho,servidor), &tamanho);
                }
                fflush(stdin);
                break;
            case listar_servidor:

                printf("Digite a forma como deseja printar os servidores\n\n");
                printf("1. Printar apenas os Tecnicos \n");
                printf("2. Printar apenas os professores \n");
                printf("3. Printar Todos \n");
                printf("4. Printar um servidor pelo cod dele.\n");
                printf("5. Para retornar ao menu\n");

                scanf(" %c", &input);

                if(!tamanho)
                {
                    printf("\nDB Vazio! Cadastre alguem !!\n\n");
                    break;
                }
                
                if( input == print_tecnicos || input == print_prof || input == print_all)
                {
                    organizando_nomes(&tamanho, servidor, input);

                }
                else if(input == print_especif)
                {
                    printf("\nDigite o codigo do servidor\n>");
                    scanf("%d",&codigo);
                    fflush(stdin);

                    codigo = buscar_codigo(codigo,&tamanho,servidor);
                    if(codigo == -1) break;

                    int vet_espcf[] = {codigo};
                    size_t qtd_de_registros_ind = 1;
                    
                    list_serv(input,servidor,vet_espcf, &qtd_de_registros_ind, 1);
                }
        
                break;
            case inserir_veiculo:

                printf("Digite o codigo do proprietario: ");
                scanf("%d", &int_buff);
                fflush(stdin);

                if(checar_prop_existe(servidor, tamanho, int_buff) >= 0)
                {
                    indice_servidor = checar_prop_existe(servidor, tamanho, int_buff);

                    if(checar_cheio(servidor[indice_servidor].veiculo) >= MAX_V)
                    {
                        printf("Limite de veiculos excedido!\n");
                        break;
                    }
                    else
                    {
                        indice_veiculo = checar_cheio(servidor[indice_servidor].veiculo);

                        servidor[indice_servidor].veiculo[indice_veiculo].codigo = gerador_codigo(servidor, tamanho);
                        do
                        {
                            printf("Digite a descricao do veiculo: ");
                            ler(char_buff);

                            if(checar_desc_existe(servidor, tamanho, char_buff) == 1)
                            {
                                printf("Descricao em uso, tente novamente!\n");
                            }

                        } while (checar_desc_existe(servidor, tamanho, char_buff) == 1);
                        
                        strcpy(servidor[indice_servidor].veiculo[indice_veiculo].descricao, char_buff);

                        printf("Digite a marca do veiculo: ");
                        ler(char_buff);
                        strcpy(servidor[indice_servidor].veiculo[indice_veiculo].marca, char_buff);

                        printf("Digite o modelo do veiculo: ");
                        ler(char_buff);
                        strcpy(servidor[indice_servidor].veiculo[indice_veiculo].modelo, char_buff);

                        do
                        {
                            printf("Digite a placa do veiculo: ");
                            ler(char_buff);

                            if(checar_placa_existe(servidor, tamanho, char_buff) == 1)
                            {
                                printf("Placa ja registrada, tente novamente!\n");
                            }

                        } while (checar_placa_existe(servidor, tamanho, char_buff) == 1);

                        strcpy(servidor[indice_servidor].veiculo[indice_veiculo].placa, char_buff);

                        servidor[indice_servidor].veiculo[indice_veiculo].ocupado = 1;
                    }
                }
                else
                {
                    printf("Nenhum servidor com esse codigo!\n");
                    break;
                }

                break;
            case alterar_veiculo:
                printf("Digite o codigo do veiculo: ");
                scanf("%d", &int_buff);
                fflush(stdin);

                if(checar_veic_existe(servidor, tamanho, int_buff, &indice_servidor, &indice_veiculo) == 1)
                {
                    do
                    {
                        printf("Digite a descricao do veiculo: ");
                        ler(char_buff);

                        if(checar_desc_existe(servidor, tamanho, char_buff) == 1)
                        {
                            printf("Descricao em uso, tente novamente!\n");
                        }

                    } while (checar_desc_existe(servidor, tamanho, char_buff) == 1);

                    strcpy(servidor[indice_servidor].veiculo[indice_veiculo].descricao, char_buff);

                    printf("Digite a marca do veiculo: ");
                    ler(char_buff);
                    strcpy(servidor[indice_servidor].veiculo[indice_veiculo].marca, char_buff);

                    printf("Digite o modelo do veiculo: ");
                    ler(char_buff);
                    strcpy(servidor[indice_servidor].veiculo[indice_veiculo].modelo, char_buff);

                    do
                    {
                        printf("Digite a placa do veiculo: ");
                        ler(char_buff);

                        if(checar_placa_existe(servidor, tamanho, char_buff) == 1)
                        {
                            printf("Placa ja registrada, tente novamente!\n");
                        }

                    } while (checar_placa_existe(servidor, tamanho, char_buff) == 1);

                    strcpy(servidor[indice_servidor].veiculo[indice_veiculo].placa, char_buff);
                }
                else
                {
                    printf("Nenhum veiculo com esse codigo!\n");
                    break;
                }
                
                break;
            case remover_veiculo:
                printf("1. Remover um veiculo de um servidor\n");
                printf("2. Remover todos os veiculos de um servidor\n");
                printf("> ");
                scanf("%c", &opt);
                fflush(stdin);

                switch(opt)
                {
                    case '1':
                        printf("Digite o codigo do veiculo: ");
                        scanf("%d", &int_buff);
                        fflush(stdin);

                        if(checar_veic_existe(servidor, tamanho, int_buff, &indice_servidor, &indice_veiculo) == 1)
                        {
                            servidor[indice_servidor].veiculo[indice_veiculo].ocupado = 0;
                            strcpy(servidor[indice_servidor].veiculo[indice_veiculo].descricao, "");
                            strcpy(servidor[indice_servidor].veiculo[indice_veiculo].placa, "");
                            printf("Veiculo deletado!\n");
                        }
                        else
                        {
                            printf("Nenhum veiculo com esse codigo!\n");
                            break;
                        }

                        break;
                    case '2':
                        printf("Digite o codigo do proprietario: ");
                        scanf("%d", &int_buff);
                        fflush(stdin);

                        if(checar_prop_existe(servidor, tamanho, int_buff) >= 0)
                        {
                            indice_servidor = checar_prop_existe(servidor, tamanho, int_buff);

                            if(checar_vazio(servidor[indice_servidor].veiculo) == 0)
                            {
                                printf("Servidor nao possui veiculos!\n");
                                break;
                            }

                            for(int i = 0; i < MAX_V; i++)
                            {
                                servidor[indice_servidor].veiculo[i].ocupado = 0;
                                strcpy(servidor[indice_servidor].veiculo[indice_veiculo].descricao, "");
                                strcpy(servidor[indice_servidor].veiculo[indice_veiculo].placa, "");
                            }
                        }
                        else
                        {
                            printf("Nenhum servidor com esse codigo!\n");
                            break;
                        }

                        break;
                    default:
                        printf("Escolha invalida\n");
                        break;
                }

                break;
            case listar_veiculo:
                printf("1. Listar por codigo do veiculo.\n");
                printf("2. Listar por servidor.\n");
                printf("3. Listar em ordem alfabetica.\n");
                printf("> ");
                scanf("%c", &opt);
                fflush(stdin);

                switch(opt)
                {
                    case listar_um_veiculo:
                        printf("Digite o codigo do veiculo: ");
                        scanf("%d", &int_buff);
                        fflush(stdin);

                        if(checar_veic_existe(servidor, tamanho, int_buff, &indice_servidor, &indice_veiculo) == 1)
                        {
                            listar_por_codigo(servidor[indice_servidor], indice_veiculo);
                        }
                        else
                        {
                            printf("Nenhum veiculo com esse codigo!\n");
                            break;
                        }

                        break;
                    case listar_veiculos_servidor:
                        printf("Digite o codigo do servidor: ");
                        scanf("%d", &int_buff);
                        fflush(stdin);

                        if(checar_prop_existe(servidor, tamanho, int_buff) >= 0)
                        {
                            indice_servidor = checar_prop_existe(servidor, tamanho, int_buff);

                            if(checar_vazio(servidor[indice_servidor].veiculo) == 0)
                            {
                                printf("Servidor nao possui veiculos!\n");
                                break;
                            }

                            listar_por_servidor(servidor[indice_servidor]);
                        }
                        else
                        {
                            printf("Nenhum servidor com esse codigo!\n");
                            break;
                        }

                        break;
                    case listar_veiculos_ordenado:
                        printf("Digite o codigo do servidor: ");
                        scanf("%d", &int_buff);
                        fflush(stdin);

                        if(checar_prop_existe(servidor, tamanho, int_buff) >= 0)
                        {
                            indice_servidor = checar_prop_existe(servidor, tamanho, int_buff);

                            if(checar_vazio(servidor[indice_servidor].veiculo) == 0)
                            {
                                printf("Servidor nao possui veiculos!\n");
                                break;
                            }

                            listar_ordenado(servidor[indice_servidor]);
                        }
                        else
                        {
                            printf("Nenhum servidor com esse codigo!\n");
                            break;
                        }
                        break;
                    default:
                        printf("Escolha invalida\n");
                        break;
                }
                break;
            case salvar_dados:
                if(escrever_arquivo(servidor, tamanho, "rb+") == -1)
                {
                    printf("Falha na escrita do arquivo!\n");
                    return 0;
                }
                printf("Dados salvos!\n\n");
                break;
            default:
                printf("\nEscolha invalida.\n\n");
        }

    } while (input != '0');

    return 0;
}