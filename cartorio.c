#include <stdio.h> //biblioteca de comunição com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início crição de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final crição de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" é para "write"
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //adiciona o arquivo e o "a" é para "append" (acrescentar)
	fprintf(file, ","); //adiciona uma virgula no arquivo apontado
	fclose(file); //fecha o arquivo apontado
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" é para "append" (acrescentar)
	fprintf(file,nome); //adiciona o nome digitado ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" é para "append" (acrescentar)
	fprintf(file, ","); //adiciona uma vírgula ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string (sobrenome)
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" é para "append" (acrescentar)
	fprintf(file,sobrenome); //adiciona o sobrenome digitado ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" é para "append" (acrescentar)
	fprintf(file, ","); //adiciona uma vírgula ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //%s refere-se a string (cargo)
	
	file = fopen(arquivo, "a"); //adiciona ao arquivo e o "a" é para "append" (acrescentar)
	fprintf(file,cargo); //adiciona uma vírgula ao arquivo
	fclose(file); //fecha o arquivo apontado
	
	system("pause"); //faz uma pausa para que o usuário possa ler a informação
}

int consulta() //função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a Linguagem
	
	//início crição de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final crição de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s se refere à string (cpf)
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //lê o arquivo "r for read"
	
	if(file == NULL) //definindo condição
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n"); //comunicando com o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //"while / enquanto" equanto o arquivo trouxer algo que n seja nulo
	{
		printf("\nEssas são as informações do usuário: "); //comunica as informações
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // faz uma pausa para que o usuário leia
}

int deletar() //função responsável por deletar
{
	char cpf[40]; //definindo string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf); //se referindo à string
	
	remove(cpf); //removendo o arquivo especificado
	
	FILE * file; //cria um arquivo
	file = fopen(cpf,"r"); //abre o arquivo e lê
	
	if(file == NULL) //definindo variável, se nulo
	{
		printf("O usuário não se encontra no sistema!\n"); //transmitindo ao usuário
		system("pause"); //adiciona o sistema para o usuário poder ler a mensagem
	}
}

int main()
{
	int opcao=0; //definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a Linguagem

		printf("### Cartório da EBAC ###\n\n"); //Início do meu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n");
		printf("Opçao: "); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário

		system("cls"); //limpar tudo que veio na antes na tela
		
		switch(opcao) //início da seleção
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
			printf("Essa opção não está disponível\n");
			system("pause");
			break; 
			//fim da seleção
		}
	}
}
