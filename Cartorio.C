#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região              // system("pause") é para pausar na tela de escolha na qual ele foi selecionado 
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastar os usuarios no sistema
{
	    // inicio de criação de variaveis/strings
	    char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// final de criação da variavel/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario1/string
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das string 
		
		FILE *file;
		file= fopen(arquivo,"w"); //criar o arquivo eo "w" significa escrever
		fprintf(file,cpf); //salvo o valor da variavel
		fclose(file); //fecho o arquivo
		
		file=fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file=fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
	    printf("Digite o sobrenome a ser cadastrado: ");
	    scanf("%s", sobrenome);
	    
	    file = fopen(arquivo,"a");
	    fprintf(file,sobrenome);
	    fclose(file);
	    
	    file=fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
	    
	    printf("Digite o seu Cargo a ser cadastrado:");
	    scanf("%s", cargo);
	    
	    file = fopen(arquivo,"a");
	    fprintf(file,cargo);
		fclose(file);
		
		system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf(" Não foi possivel abrir o arquivo, não localizado!.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)  // serve pra pausar enquannto ele estiver esperando na variavel ou no conteudo. 
	{
     printf("\nEssas são as informações dp usuário: ");
     printf("%s", conteudo);
     printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); 
	{
	   printf("O Usuário já foi Deletado! ");
	}
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}

int main() 
{
	int opcao=0; // definindo as variaveis 
	int x=1;  // variavel 
	
  	for(x=1;x=1;) // x é oq faz pra voltar pro inicio da tela 
	{
	
	system("cls");
	
	
	setlocale(LC_ALL, "portuguese"); // Definindo as linguagens 
	
	printf("\tCartório da EBAC \n\n"); //inicio do menu
	printf("Escolha a opção desejada do menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("\opção:"); // fim do menu
	
	scanf("%d", &opcao);  //Scanf("%d", &opção); :é a pausa do programa enquanto n chega no objetivo no caso na escolha // armazenando a escolha do usuario
	
	system("cls"); // system("cls"); :função limpar tela 
	
    switch(opcao)
    {
    	case 1:	
	    registro(); // chamada de funções 
		break; // parar o sistema 
		
		case 2:
	    consulta();  
        break; 
        
        case 3:
        deletar(); 
		break;
		
		default:
		printf("Essa opção não está disponivel! ");
		system("pause");
		break;
	}
    }  
}

