#include <stdio.h> //biblioteca de comuni��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cri��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cri��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" � para "write"
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //adiciona o arquivo e o "a" � para "append" (acrescentar)
	fprintf(file, ","); //adiciona uma virgula no arquivo apontado
	fclose(file); //fecha o arquivo apontado
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" � para "append" (acrescentar)
	fprintf(file,nome); //adiciona o nome digitado ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" � para "append" (acrescentar)
	fprintf(file, ","); //adiciona uma v�rgula ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string (sobrenome)
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" � para "append" (acrescentar)
	fprintf(file,sobrenome); //adiciona o sobrenome digitado ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" � para "append" (acrescentar)
	fprintf(file, ","); //adiciona uma v�rgula ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string (cargo)
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" � para "append" (acrescentar)
	fprintf(file,cargo); //adiciona uma v�rgula ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	system("pause"); //faz uma pausa para que o usu�rio possa ler a informa��o
}

int consulta() //fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a Linguagem
	
	//in�cio cri��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final cri��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s se refere � string (cpf)
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //l� o arquivo "r for read"
	
	if(file == NULL) //definindo condi��o
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); //comunicando com o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //"while / enquanto" equanto o arquivo trouxer algo que n seja nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //comunica as informa��es
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // faz uma pausa para que o usu�rio leia
}

int deletar() //fun��o respons�vel por deletar
{
	char cpf[40]; //definindo string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //se referindo � string
	
	remove(cpf); //removendo o arquivo especificado
	
	FILE * file; //cria um arquivo
	file = fopen(cpf,"r"); //abre o arquivo e l�
	
	if(file == NULL) //definindo vari�vel, se nulo
	{
		printf("O usu�rio n�o se encontra no sistema!\n"); //transmitindo ao usu�rio
		system("pause"); //adiciona o sistema para o usu�rio poder ler a mensagem
	}
}

int main()
{
	int opcao=0; //definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a Linguagem

		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do meu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n");
		printf("Op�ao: "); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usu�rio

		system("cls"); //limpar tudo que veio na antes na tela
		
		switch(opcao) //in�cio da sele��o
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break; 
			//fim da sele��o
		}
	}
}
