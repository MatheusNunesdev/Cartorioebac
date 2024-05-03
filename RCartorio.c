#include <stdio.h> // Biblioteca de comunica��o de usu�rio
#include <stdlib.h>// Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>// Biblioteca de alica��o de texto por regi�o
#include <string.h>// Biblioteca respons�vel das strings


//fun��es de uso para o menu
int registro()
{
	setlocale(LC_ALL, "Portuguese");
// Definindo o texto para Portugu�s
	char arquivo[60];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o n�mero de CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// respos�vel por copiar os valores das Strings
	 
	FILE *file;   //acessa o FILE / Cria um arquivo.(nesse caso o arquivo se chama "file") 
	file = fopen(arquivo, "w");   // O file vai abrir um arquivo, escreva, e cria o arquivo novo
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo,"a");	// "a" � usado para atualizar o arquivo
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
	
	system("pause");	// maneira de pausar o programar e continuar a desejo do usu�rio.
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o Cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	// "r" ler o que esta no banco de dados e verificar se h� um arquivo dado pelo cpf escrito pelo usu�rio.
	
	if(file == NULL)// Caso o cpf n�o esteja registrado.
	{
		printf("Arquivo n�o localizado!\n");
	}
	else
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)	// la�o para extrair o arquivo e exibir para o usu�rio.
	{
		printf( "%s", conteudo);
	}
	fclose(file);
	system("pause");
}

int deletar()
{	
	char cpf[40];
	
	printf("Digite o CPf do usu�rio a ser deletado: \n");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)	// Caso o CPF n�o esteja cadastrado ira avisar ao usu�rio.
	{
		printf("O CPF n�o se encontra no sistema.\n\n");
	}
	else
		printf("tem Certeza que deseja deletar o Usu�rio? \n\nDigite para confirmar 'S' para sim ou 'N' para n�o!\n");
		getchar(); // Fun��o para coletar oq foi digitado pelo usu�rio
		char escolha;
		escolha = getchar(); // variavel com resultado da escolha do usu�rio
	
	fclose(file);

	if(escolha == 's' || escolha == 'S') // fun��o que ir� deletar o arquivo.
	{
		if(remove(cpf) == 0)	// remove o arquivo e verifica se obteve sucesso na remo��o.( OBS:"remove"n�o funciona se o arquivo estiver aberto)
		{
			printf("Usu�rio foi deletado com sucesso!\n");
		}
	}
	else
			printf("\nRetorne para o menu!\n");

	system("pause");
}

//fun��o de uso para o menu
int main()
{
	int opcao=0;
	int laco=1;
//Definindo Vari�veis de uso
	for (laco=1;laco=1;)
// repeti��o do programa
	{
		setlocale(LC_ALL, "Portuguese");
// Definindo o texto para Portugu�s		
		system("cls");
//limpeza		
		printf("\t### Cart�rio da EBAC ###\n\n");
		printf("- Escolha a op��o desejada do menu:\n\n");
// In�cio do menu
		printf("\t1 - Registrar Nomes\n\t2 - Consultar Nomes\n\t3 - Deletar Nomes\n\n");
		printf("- Digite sua Op��o:");
		scanf("%d", &opcao);
//Armazena op��o de escolha do usu�rio
	
		system("cls");//limpeza
	
		switch(opcao)
// Inicio da sele��o, avaliando a variavel.
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
    		default:
    			printf("Esse op��o n�o estar dispon�vel!\n");
				system("pause");
				break;
		}
//fim da sele��o.
	}
}


