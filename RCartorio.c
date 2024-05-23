#include <stdio.h> // Biblioteca de comunicação de usuário
#include <stdlib.h>// Biblioteca de alocação de espaço em memória
#include <locale.h>// Biblioteca de alicação de texto por região
#include <string.h>// Biblioteca responsável das strings


//funções de uso para o menu
int registro()
{
	setlocale(LC_ALL, "Portuguese");
// Definindo o texto para Português
	char arquivo[60];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o número de CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// resposável por copiar os valores das Strings
	 
	FILE *file;   //acessa o FILE / Cria um arquivo.(nesse caso o arquivo se chama "file") 
	file = fopen(arquivo, "w");   // O file vai abrir um arquivo, escreva, e cria o arquivo novo
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo,"a");	// "a" é usado para atualizar o arquivo
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: \n");
	scanf("%s" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");	// maneira de pausar o programar e continuar a desejo do usuário.
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o Cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	// "r" ler o que esta no banco de dados e verificar se há um arquivo dado pelo cpf escrito pelo usuário.
	
	if(file == NULL)// Caso o cpf não esteja registrado.
	{
		printf("Arquivo não localizado!\n");
	}
	else
	{
		printf("\nEssas são as informações do usuário: \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)	// laço para extrair o arquivo e exibir para o usuário.
	{
		printf( "%s", conteudo);
	}
	fclose(file);
	system("pause");
}

int deletar()
{	
	char cpf[40];
	
	printf("Digite o CPf do usuário a ser deletado: \n");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)	// Caso o CPF não esteja cadastrado ira avisar ao usuário.
	{
		printf("O CPF não se encontra no sistema.\n\n");
	}
	else
		printf("tem Certeza que deseja deletar o Usuário? \n\nDigite para confirmar 'S' para sim ou 'N' para não!\n");
		getchar(); // Função para coletar oq foi digitado pelo usuário
		char escolha;
		escolha = getchar(); // variavel com resultado da escolha do usuário
	
	fclose(file);

	if(escolha == 's' || escolha == 'S') // função que irá deletar o arquivo.
	{
		if(remove(cpf) == 0)	// remove o arquivo e verifica se obteve sucesso na remoção.( OBS:"remove"não funciona se o arquivo estiver aberto)
		{
			printf("Usuário foi deletado com sucesso!\n");
		}
	}
	else
			printf("\nRetorne para o menu!\n");

	system("pause");
}

//função de uso para o menu
int main()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo o texto para Português				
//Definindo Variáveis de uso
	int opcao = 0;
	int laco = 1;
	char senha[]="admin";
	int comparacao=1;
	int rep=3; // variavel para determinar o numero de tentativa do usuário
	
	while(comparacao != 0)  //Função para realizar o login de usuário
	{
		printf("\t### Cartório da EBAC ###\n\n");
		printf("Login de Administrador!\n\nDigite a senha: ");
		scanf("%s",senha);
	
		comparacao = strcmp(senha, "admin");
		
		system("cls"); //limpeza
		if(comparacao != 0)
		{
			rep -= 1;
			printf("Senha incorreta,tente novamente!\n");
			printf("Numero de tentativa restantes: %d\n\n", rep);
			
		}
		if(rep == 0)
		{
			printf("Numero de tentativa chegou ao limite!\n");
			break;
		}
			system("pause");
			system("cls"); //limpeza			
	}
	
	if (comparacao == 0)
	{
		for (laco=1;laco=1;) // função de de acesso ao menu
		{	
			system("cls");		
			printf("Escolha a opção desejada do menu:\n\n");
// Início do menu
			printf("\t 1 - Registrar Nomes\n\t 2 - Consultar Nomes\n\t 3 - Deletar Nomes\n\t 4 - Sair do Sistema\n\n");
			printf("Digite sua Opção:");
			scanf("%d", &opcao);
//Armazena opção de escolha do usuário
	
			system("cls");//limpeza
	
			switch(opcao)
// Inicio da seleção, avaliando a variavel.
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
    				printf("Obrigado por ultizar nosso Sistema!");
    				return 0;
    				break;
    			default: // caso não seja nenhuma opção especificada
    				printf("Esse opção não estar disponível!\n");
					system("pause");
					break;
			}
		}
	}
}
//fim da seleção.


