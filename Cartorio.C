#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o              // system("pause") � para pausar na tela de escolha na qual ele foi selecionado 
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o responsavel por cadastar os usuarios no sistema
{
	    // inicio de cria��o de variaveis/strings
	    char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// final de cria��o da variavel/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario1/string
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //respons�vel por copiar os valores das string 
		
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
		printf(" N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)  // serve pra pausar enquannto ele estiver esperando na variavel ou no conteudo. 
	{
     printf("\nEssas s�o as informa��es dp usu�rio: ");
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
	   printf("O Usu�rio j� foi Deletado! ");
	}
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main() 
{
	int opcao=0; // definindo as variaveis 
	int x=1;  // variavel 
	
  	for(x=1;x=1;) // x � oq faz pra voltar pro inicio da tela 
	{
	
	system("cls");
	
	
	setlocale(LC_ALL, "portuguese"); // Definindo as linguagens 
	
	printf("\tCart�rio da EBAC \n\n"); //inicio do menu
	printf("Escolha a op��o desejada do menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("\t4 - Sair do Sistema\n");
	printf("\op��o:"); // fim do menu
	
	scanf("%d", &opcao);  //Scanf("%d", &op��o); :� a pausa do programa enquanto n chega no objetivo no caso na escolha // armazenando a escolha do usuario
	
	system("cls"); // system("cls"); :fun��o limpar tela 
	
    switch(opcao)
    {
    	case 1:	
	    registro(); // chamada de fun��es 
		break; // parar o sistema 
		
		case 2:
	    consulta();  
        break; 
        
        case 3:
        deletar(); 
		break;
		
		case 4:
		printf("Obrigado por usar o Cartorio da Ebac\n");
		return 0;
		break;	
		
		default:
		printf("Essa op��o n�o est� disponivel! ");
		system("pause");
		break;
	}
    }  
}

