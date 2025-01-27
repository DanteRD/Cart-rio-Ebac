#include <stdio.h> // Biblioteca para entrada e saída
#include <stdlib.h> // Biblioteca para alocação de memória e comandos como system
#include <locale.h> // Biblioteca para suporte a localização (acentuação, etc.)
#include <string.h> // Biblioteca para manipulação de strings

// Função responsável por registrar usuários no sistema
int registro() {
    // Declaração de variáveis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    // Solicitação do CPF
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    // O nome do arquivo será o CPF do usuário
    strcpy(arquivo, cpf);

    // Criação do arquivo e escrita inicial com o CPF
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) { // Verifica se o arquivo foi criado com sucesso
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    fprintf(file, cpf);
    fclose(file);

    // Adiciona uma vírgula como separador
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicitação do nome
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicitação do sobrenome
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Solicitação do cargo
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    printf("Cadastro realizado com sucesso!\n");
    system("pause"); // Pausa para o usuário visualizar a mensagem
    return 0;
}

// Função responsável por consultar informações de um usuário
int consulta() {
    setlocale(LC_ALL, "portuguese"); // Configura a localização para suporte a acentuação

    char cpf[40];
    char conteudo[200];

    // Solicita o CPF a ser consultado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    // Abre o arquivo correspondente ao CPF
    FILE *file = fopen(cpf, "r");
    if (file == NULL) { // Verifica se o arquivo existe
        printf("Não foi possível abrir o arquivo. Usuário não localizado.\n");
        return 1;
    }

    // Exibe o conteúdo do arquivo
    printf("\nEssas são as informações do usuário:\n");
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    printf("\n\n");
    fclose(file);
    system("pause");
    return 0;
}

// Função responsável por deletar um usuário
int deletar() {
    char cpf[40];

    // Solicita o CPF a ser deletado
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    // Remove o arquivo correspondente ao CPF
    if (remove(cpf) == 0) {
        printf("O usuário foi deletado com sucesso!\n");
    } else {
        printf("Não foi possível deletar. O usuário não existe.\n");
    }
    system("pause");
    return 0;
}

// Função principal
int main() {
    int opcao = 0; // Variável para armazenar a escolha do menu
    int x = 1; // Controle do loop principal
    char senhadigitada[40]; // Variável para a senha
    int comparacao; // Variável para armazenar o resultado da comparação da senha

    // Tela inicial
    printf("\tCartório da EBAC \n\n");
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
            printf("\tCartório da EBAC \n\n");
            printf("Escolha a opção desejada do menu: \n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do Sistema\n");
            printf("\nOpção: ");
            scanf("%d", &opcao);

            system("cls");

            // Processa a escolha do usuário
            switch (opcao) {
                case 1:
                    registro(); // Chama a função de registro
                    break;
                case 2:
                    consulta(); // Chama a função de consulta
                    break;
                case 3:
                    deletar(); // Chama a função de deletar
                    break;
                case 4:
                    printf("Obrigado por usar o Cartório da EBAC.\n");
                    return 0; // Encerra o programa
                default:
                    printf("Essa opção não está disponível!\n");
                    system("pause");
                    break;
            }
        }
    } else {
        printf("Senha incorreta.\n");
    }
    return 0;
}

