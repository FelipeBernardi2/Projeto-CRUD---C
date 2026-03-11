/*
    Autor: Felipe de Oliveira Bernardi
    Data Ínicio: 05/03/2026
    Objetivo: Fazer um cadastro de clientes
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define MAX 25 // Capacidade da lista

//Tipos - Registro |
typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[20];
    char cpf[20];
    char email[50];
    char data_nasc[20];
} reg_clientes;

typedef struct {
    reg_clientes ficha[MAX];
    int inicio;
    int fim;
} lista;

//VOID do Ponteiro
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//VOID pra limpar as mensagens
void limpa_mensagem() {
    gotoxy(6, 23);
    printf("                                                                          ");
}

//VOID LIMPA TELA DE ERRO
void limpa_tela_erro() {
    gotoxy(2, 12);
    printf("                                                                          ");
}

//VOID LIMPA FILEIRA NOME ATUAL
void limpa_nomeatual() {
    gotoxy(2, 6);
    printf("                                                                          ");
}

//VOID Tela Principal
void tela() {
    system("cls");
    int c;
    int l;

    for (l = 1; l < 25; l++) {
        gotoxy(01, l);
        printf("|");

        gotoxy(80, l);
        printf("|");
    }

    for (c = 1; c < 81; c++) {
        gotoxy(c, 01);
        printf("-");

        gotoxy(c, 4);
        printf("-");

        gotoxy(c, 22);
        printf("-");

        gotoxy(c, 24);
        printf("-");
    }

    gotoxy(01, 01);
    printf("+");
    //same
    gotoxy(80, 01);
    printf("+");

    gotoxy(01, 4);
    printf("+");
    //same
    gotoxy(80, 4);
    printf("+");

    gotoxy(01, 22);
    printf("+");
    //same
    gotoxy(80,22);
    printf("+");

    gotoxy(01, 24);
    printf("+");
    //same
    gotoxy(80, 24);
    printf("+");

    gotoxy(2, 2);
    printf("UNICV");

    gotoxy(61, 2);
    printf("Estrutura de dados");

    gotoxy(73, 3);
    printf("Felipe");

    gotoxy(2, 23);
    printf("MSG:");

    gotoxy(01, 26);
};

//Função que chama a Tela de cadastro de clientes
void tela_clientes() {

    gotoxy(10, 6);
    printf("Codigo do Cliente..: ");

    gotoxy(10, 12);
    printf("1 - Nome do Cliente....: ");

    gotoxy(10, 13);
    printf("2 - Endereco do Cliente: ");

    gotoxy(10, 14);
    printf("3 - Telefone do Cliente: ");

    gotoxy(10, 15);
    printf("4 - CPF do Cliente.....: ");

    gotoxy(10, 16);
    printf("5 - Email do Cliente...: ");

    gotoxy(10, 17);
    printf("6 - Data de Nascimento.: ");
}

//Cadastro de clientes...
void cadastra_cliente (lista *puxar_lista) {

    reg_clientes clie;
    int resp;

    do {
        int existe = 0;
        tela();

        gotoxy(25, 03);
        printf("Cadastra cliente");

        tela_clientes();

        gotoxy(32, 6);
        scanf("%d", &clie.codigo);
        getchar();

        if (clie.codigo < 1) {
            limpa_mensagem();
            gotoxy(6,23);
            printf("ERRO! Codigo invalido! (2 - Sair): ");

            getchar();
            break;
        }

        for (int i = 0; i < puxar_lista->fim; i++) {
            if (clie.codigo == puxar_lista->ficha[i].codigo) {
                existe = 1;
                break;
            }
        }

        if (existe == 1) {
            limpa_mensagem();
            gotoxy(6, 23);
            printf("ERRO! Codigo ja Cadastrado (2 - Voltar): ");
            getchar();
            getchar();
            return;
        }

        gotoxy(37, 12);
        fgets(clie.nome, sizeof(clie.nome), stdin);
        clie.nome[strcspn(clie.nome, "\n")] = '\0';

        gotoxy(37, 13);
        fgets(clie.endereco, sizeof(clie.endereco), stdin);
        clie.endereco[strcspn(clie.endereco, "\n")] = '\0';

        gotoxy(37, 14);
        fgets(clie.telefone, sizeof(clie.telefone), stdin);
        clie.telefone[strcspn(clie.telefone, "\n")] = '\0';

        gotoxy(37, 15);
        fgets(clie.cpf, sizeof(clie.cpf), stdin);
        clie.cpf[strcspn(clie.cpf, "\n")] = '\0';

        gotoxy(37, 16);
        fgets(clie.email, sizeof(clie.email), stdin);
        clie.email[strcspn(clie.email, "\n")] = '\0';

        gotoxy(37, 17);
        fgets(clie.data_nasc, sizeof(clie.data_nasc), stdin);
        clie.data_nasc[strcspn(clie.data_nasc, "\n")] = '\0';

        gotoxy(6, 23);
        printf("Deseja Salvar os Dados Digitados? (1 - Sim | 2 - Nao): ");
        scanf("%d", &resp);
        if (resp == 1) {

            if (puxar_lista->fim >= MAX){
                limpa_mensagem();
                gotoxy(6, 23);
                printf("Nao e Possivel Inserir Em Lista Cheia (2 - Retornar): ");
                getchar();
                getchar();
            } else {
                puxar_lista->ficha[puxar_lista->fim] = clie;
                puxar_lista->fim++;
            }
        }

        limpa_mensagem();
        gotoxy(6, 23);
        printf("Deseja Cadastrar Outro Cliente? (1 - Sim | 2 - Nao): ");
        scanf("%d", &resp);

        getchar();
    } while (resp == 1);
}

//Função Alteração de Clientes
void altera_cliente (lista *puxar_lista) {
    int resp;

    do {
        int encontrado = 0;
        tela();

        gotoxy(25, 3);
        printf("--Alteracao de Clientes--");

        gotoxy(6, 23);
        printf("Digite o codigo do cliente do qual deseja alterar: ");
        scanf("%d", &resp);

        for (int i = 0; i < puxar_lista->fim; i++) {
            if (resp == puxar_lista->ficha[i].codigo) {
                gotoxy(25, 5);
                printf("Cliente encontrado!");
                encontrado = 1;

                gotoxy(10, 6);
                printf("Codigo do Cliente: %d", puxar_lista->ficha[i].codigo);

                gotoxy(10, 12);
                printf("1 - Nome do Cliente....: %s", puxar_lista->ficha[i].nome);

                gotoxy(10, 13);
                printf("2 - Endereco do Cliente: %s", puxar_lista->ficha[i].endereco);

                gotoxy(10, 14);
                printf("3 - Telefone do Cliente: %s", puxar_lista->ficha[i].telefone);

                gotoxy(10, 15);
                printf("4 - CPF do Cliente.....: %s", puxar_lista->ficha[i].cpf);

                gotoxy(10, 16);
                printf("5 - Email do Cliente...: %s", puxar_lista->ficha[i].email);

                gotoxy(10, 17);
                printf("6 - Data de Nascimento.: %s", puxar_lista->ficha[i].data_nasc);

                limpa_mensagem();
                gotoxy(6, 23);
                printf("Selecione a opcao que deseja alterar: ");
                scanf("%d", &resp);

                switch (resp) {
                case 1:
                    limpa_nomeatual();
                    gotoxy(10, 6);
                    printf("Nome Atual: %s", puxar_lista->ficha[i].nome);

                    limpa_mensagem();
                    gotoxy(6, 23);
                    printf("Deseja realmente alterar? (1 - Sim | 2 - Nao): ");
                    scanf("%d", &resp);
                    
                    if (resp == 1) {
                        getchar();

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Digite o Novo Nome: ");
                        fgets(puxar_lista->ficha[i].nome, sizeof(puxar_lista->ficha[i].nome), stdin);
                        puxar_lista->ficha[i].nome[strcspn(puxar_lista->ficha[i].nome, "\n")] = '\0';

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Alteracao Realizada Com Sucesso!");
                    }
                    break;
                case 2:
                    limpa_nomeatual();
                    gotoxy(10, 6);
                    printf("Endereco Atual: %s", puxar_lista->ficha[i].endereco);

                    limpa_mensagem();
                    gotoxy(6, 23);
                    printf("Deseja realmente alterar? (1 - Sim | 2 - Nao): ");
                    scanf("%d", &resp);
                    
                    if (resp == 1) {
                        getchar();

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Digite o Novo Endereco: ");
                        fgets(puxar_lista->ficha[i].endereco, sizeof(puxar_lista->ficha[i].endereco), stdin);
                        puxar_lista->ficha[i].endereco[strcspn(puxar_lista->ficha[i].endereco, "\n")] = '\0';

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Alteracao Realizada Com Sucesso!");
                    }
                    break;
                case 3:
                    limpa_nomeatual();
                    gotoxy(10, 6);
                    printf("Telefone Atual: %s", puxar_lista->ficha[i].telefone);

                    limpa_mensagem();
                    gotoxy(6, 23);
                    printf("Deseja realmente alterar? (1 - Sim | 2 - Nao): ");
                    scanf("%d", &resp);
                    
                    if (resp == 1) {
                        getchar();

                        gotoxy(10, 6);
                        printf("Telefone do Cliente: %s", puxar_lista->ficha[i].telefone);

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Digite o Novo Telefone: ");
                        fgets(puxar_lista->ficha[i].telefone, sizeof(puxar_lista->ficha[i].telefone), stdin);
                        puxar_lista->ficha[i].telefone[strcspn(puxar_lista->ficha[i].telefone, "\n")] = '\0';

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Alteracao Realizada Com Sucesso!");
                    }
                    break;
                case 4:
                    limpa_nomeatual();
                    gotoxy(10, 6);
                    printf("CPF Atual: %s", puxar_lista->ficha[i].cpf);

                    limpa_mensagem();
                    gotoxy(6, 23);
                    printf("Deseja realmente alterar? (1 - Sim | 2 - Nao): ");
                    scanf("%d", &resp);
                    
                    if (resp == 1) {
                        getchar();

                        gotoxy(10, 6);
                        printf("CPF do Cliente: %s", puxar_lista->ficha[i].cpf);

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Digite o Novo CPF: ");
                        fgets(puxar_lista->ficha[i].cpf, sizeof(puxar_lista->ficha[i].cpf), stdin);
                        puxar_lista->ficha[i].cpf[strcspn(puxar_lista->ficha[i].cpf, "\n")] = '\0';

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Alteracao Realizada Com Sucesso!");
                    }
                    break;
                case 5:
                    limpa_nomeatual();
                    gotoxy(10, 6);
                    printf("Email Atual: %s", puxar_lista->ficha[i].email);

                    limpa_mensagem();
                    gotoxy(6, 23);
                    printf("Deseja realmente alterar? (1 - Sim | 2 - Nao): ");
                    scanf("%d", &resp);
                    
                    if (resp == 1) {
                        getchar();

                        gotoxy(10, 6);
                        printf("Email do Cliente: %s", puxar_lista->ficha[i].email);

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Digite o Novo Email: ");
                        fgets(puxar_lista->ficha[i].email, sizeof(puxar_lista->ficha[i].email), stdin);
                        puxar_lista->ficha[i].email[strcspn(puxar_lista->ficha[i].email, "\n")] = '\0';

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Alteracao Realizada Com Sucesso!");
                    }
                    break;
                case 6:
                    limpa_nomeatual();
                    gotoxy(10, 6);
                    printf("Data de Nascimento Atual: %s", puxar_lista->ficha[i].data_nasc);

                    limpa_mensagem();
                    gotoxy(6, 23);
                    printf("Deseja realmente alterar? (1 - Sim | 2 - Nao): ");
                    scanf("%d", &resp);
                    
                    if (resp == 1) {
                        getchar();

                        gotoxy(10, 6);
                        printf("Data de Nascimento do Cliente: %s", puxar_lista->ficha[i].data_nasc);

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Digite a Nova Data de Nascimento: ");
                        fgets(puxar_lista->ficha[i].data_nasc, sizeof(puxar_lista->ficha[i].data_nasc), stdin);
                        puxar_lista->ficha[i].data_nasc[strcspn(puxar_lista->ficha[i].data_nasc, "\n")] = '\0';

                        limpa_mensagem();
                        gotoxy(6, 23);
                        printf("Alteracao Realizada Com Sucesso!");
                    }
                    break;
                    
                
                default:
                    limpa_mensagem();
                    gotoxy(6, 23);
                    printf("Opcao Invalida (2 - Sair): ");
                    scanf("%d", &resp);
                    break;
                }

                break;
            }
        }

            if (encontrado == 0) {
                gotoxy(30, 12);
                printf("ERRO!");

                limpa_mensagem();
                gotoxy(6, 23);
                printf("Codigo de Cliente Nao Encontrado! (2 - Sair): ");
                scanf("%d", &resp);
                limpa_tela_erro();
            }

        limpa_mensagem();
        gotoxy(6, 23);
        printf("Deseja alterar outro cliente? (1 - Sim | 2 - Nao): ");
        scanf("%d", &resp);
      
    } while (resp == 1);
}

//Função Consulta de Clientes...
void consulta_cliente (lista *puxar_lista) {
    int resp;

    do {
        int codigo;
        int encontrado = 0;
        tela();

        gotoxy(25, 3);
        printf("--Consulta de Clientes--");

        gotoxy(6, 23);
        printf("Digite o Codigo do Cliente que Deseja Consultar: ");
        scanf("%d", &codigo);

        for (int i = 0; i < puxar_lista->fim; i++) {
            if (codigo == puxar_lista->ficha[i].codigo) {
                gotoxy(25, 5);
                printf("Cliente encontrado!");
                encontrado = 1;

                gotoxy(10, 6);
                printf("Codigo do Cliente: %d", puxar_lista->ficha[i].codigo);

                gotoxy(10, 12);
                printf("1 - Nome do Cliente....: %s", puxar_lista->ficha[i].nome);

                gotoxy(10, 13);
                printf("2 - Endereco do Cliente: %s", puxar_lista->ficha[i].endereco);

                gotoxy(10, 14);
                printf("3 - Telefone do Cliente: %s", puxar_lista->ficha[i].telefone);

                gotoxy(10, 15);
                printf("4 - CPF do Cliente.....: %s", puxar_lista->ficha[i].cpf);

                gotoxy(10, 16);
                printf("5 - Email do Cliente...: %s", puxar_lista->ficha[i].email);

                gotoxy(10, 17);
                printf("6 - Data de Nascimento.: %s", puxar_lista->ficha[i].data_nasc);

                break;
            }

        }

        if (encontrado == 0) {
                limpa_mensagem();
                gotoxy(6, 23);
                printf("ERRO! Codigo nao encontrado! (2 - Sair): ");
                getchar();
                getchar();
            }

            limpa_mensagem();
            gotoxy(6, 23);
            printf("Deseja Consultar Outro Cliente? (1 - Sim | 2 - Nao): ");
            scanf("%d", &resp);
    } while (resp == 1);
}

//Função Exclusão de Clientes...
void exclusao_clientes(lista *puxar_lista) {
    int resp;

    do {
        int codigo;
        int encontrado = 0;
        tela();

        gotoxy(25, 3);
        printf("--Exclusao de Clientes--");

        gotoxy(6, 23);
        printf("Digite o Codigo do Cliente que Deseja Excluir: ");
        scanf("%d", &codigo);

        for (int i = 0; i < puxar_lista->fim; i++) {
            if (codigo == puxar_lista->ficha[i].codigo) {
                gotoxy(25, 5);
                printf("Cliente encontrado!");
                encontrado = 1;

                gotoxy(10, 6);
                printf("Codigo do Cliente: %d", puxar_lista->ficha[i].codigo);

                gotoxy(10, 12);
                printf("1 - Nome do Cliente....: %s", puxar_lista->ficha[i].nome);

                gotoxy(10, 13);
                printf("2 - Endereco do Cliente: %s", puxar_lista->ficha[i].endereco);

                gotoxy(10, 14);
                printf("3 - Telefone do Cliente: %s", puxar_lista->ficha[i].telefone);

                gotoxy(10, 15);
                printf("4 - CPF do Cliente.....: %s", puxar_lista->ficha[i].cpf);

                gotoxy(10, 16);
                printf("5 - Email do Cliente...: %s", puxar_lista->ficha[i].email);

                gotoxy(10, 17);
                printf("6 - Data de Nascimento.: %s", puxar_lista->ficha[i].data_nasc);

                limpa_mensagem();
                gotoxy(6, 23);
                printf("Deseja Realmente Excluir Este Cadastro? (1 - Sim | 2 - Nao): ");
                scanf("%d", &resp);
                getchar();

                if (resp == 1) {
                    for (int j = i; j < puxar_lista->fim - 1; j++) {
                        puxar_lista->ficha[j] = puxar_lista->ficha[j + 1];
                    }

                    puxar_lista->fim--;

                    limpa_mensagem();
                    gotoxy(6, 23);
                    printf("Cliente excluido com sucesso! (2 - Voltar): ");
                    getchar();
                }
                break;
            }
        }

        if (encontrado == 0) {
                limpa_mensagem();
                gotoxy(6, 23);
                printf("ERRO! Codigo nao encontrado! (2 - Sair): ");
                getchar();
                getchar();
            }

        limpa_mensagem();
        gotoxy(6, 23);
        printf("Deseja Excluir Outro Cliente? (1 - Sim | 2 - Nao): ");
        scanf("%d", &resp);
    } while (resp == 1);
}

int main() {
    int opcao;
    lista puxar_lista;
    puxar_lista.inicio = 0;
    puxar_lista.fim = 0;
    system("cls");
    do {
        tela();
        gotoxy(25, 3);
        printf("-----Sistema de Clientes-----\n");

        gotoxy(30, 10);
        printf("1 - Inclusao");

        gotoxy(30, 12);
        printf("2 - Alteracao");

        gotoxy(30, 14);
        printf("3 - Consulta");

        gotoxy(30, 16);
        printf("4 - Exclusao");

        gotoxy(30, 18);
        printf("5 - Finalizar o programa");

        gotoxy(7, 23);
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
    case 1:
        cadastra_cliente(&puxar_lista);
        break;
    case 2:
        altera_cliente(&puxar_lista);
        break;
    case 3:
        consulta_cliente(&puxar_lista);
        break;
    case 4:
        exclusao_clientes(&puxar_lista);
        break;
    }

    } while (opcao != 5);

    return 0;
}