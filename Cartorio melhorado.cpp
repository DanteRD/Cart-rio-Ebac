#include <stdio.h> // Biblioteca para entrada e sa�da
#include <stdlib.h> // Biblioteca para aloca��o de mem�ria e comandos como system
#include <locale.h> // Biblioteca para suporte a localiza��o (acentua��o, etc.)
#include <string.h> // Biblioteca para manipula��o de strings

// Fun��o respons�vel por registrar usu�rios no sistema
int registro() {
    // Declara��o de vari�veis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    // Solicita��o do CPF
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    // O nome do arquivo ser� o CPF do usu�rio
    strcpy(arquivo, cpf);

    // Cria��o do arquivo e escrita inicial com o CPF
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) { // Verifica se o arquivo foi criado com sucesso
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    fprintf(file, cpf);
    fclose(file);

    // Adiciona uma v�rgula como separador
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita��o do nome
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita��o do sobrenome
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicita��o do cargo
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    printf("Cadastro realizado com sucesso!\n");
    system("pause"); // Pausa para o usu�rio visualizar a mensagem
    return 0;
}

// Fun��o respons�vel por consultar informa��es de um usu�rio
int consulta() {
    setlocale(LC_ALL, "portuguese"); // Configura a localiza��o para suporte a acentua��o

    char cpf[40];
    char conteudo[200];

    // Solicita o CPF a ser consultado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    // Abre o arquivo correspondente ao CPF
    FILE *file = fopen(cpf, "r");
    if (file == NULL) { // Verifica se o arquivo existe
        printf("N�o foi poss�vel abrir o arquivo. Usu�rio n�o localizado.\n");
        return 1;
    }

    // Exibe o conte�do do arquivo
    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    printf("\n\n");
    fclose(file);
    system("pause");
    return 0;
}

// Fun��o respons�vel por deletar um usu�rio
int deletar() {
    char cpf[40];

    // Solicita o CPF a ser deletado
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    // Remove o arquivo correspondente ao CPF
    if (remove(cpf) == 0) {
        printf("O usu�rio foi deletado com sucesso!\n");
    } else {
        printf("N�o foi poss�vel deletar. O usu�rio n�o existe.\n");
    }
    system("pause");
    return 0;
}

// Fun��o principal
int main() {
    int opcao = 0; // Vari�vel para armazenar a escolha do menu
    int x = 1; // Controle do loop principal
    char senhadigitada[40]; // Vari�vel para a senha
    int comparacao; // Vari�vel para armazenar o resultado da compara��o da senha

    // Tela inicial
    printf("\tCart�rio da EBAC \n\n");
    printf("Login de administrador!\n");
    printf("\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    // Verifica a senha digitada
    comparacao = strcmp(senhadigitada, "admin");
    if (comparacao == 0) { // Senha correta
        system("cls"); // Limpa a tela (somente no Windows)
        while (x == 1) { // Loop principal do sistema
            system("cls");
            setlocale(LC_ALL, "portuguese");

            // Menu principal
            printf("\tCart�rio da EBAC \n\n");
            printf("Escolha a op��o desejada do menu: \n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do Sistema\n");
            printf("\nOp��o: ");
            scanf("%d", &opcao);

            system("cls");

            // Processa a escolha do usu�rio
            switch (opcao) {
                case 1:
                    registro(); // Chama a fun��o de registro
                    break;
                case 2:
                    consulta(); // Chama a fun��o de consulta
                    break;
                case 3:
                    deletar(); // Chama a fun��o de deletar
                    break;
                case 4:
                    printf("Obrigado por usar o Cart�rio da EBAC.\n");
                    return 0; // Encerra o programa
                default:
                    printf("Essa op��o n�o est� dispon�vel!\n");
                    system("pause");
                    break;
            }
        }
    } else {
        printf("Senha incorreta.\n");
    }
    return 0;
}

