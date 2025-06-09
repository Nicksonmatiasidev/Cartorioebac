#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsavel pelos string
#include <windows.h> //biblioteca para acessar recursos do sistema operacional


int registro() //função responsavel para registrar usuarios no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria um arquivo 
	file = fopen(arquivo, "w");  //cria o arquivo, "w" para criar uma pasta nova, "a" mexer em uma que ja existe, "r" para ler o que tiver dentro do arquivo 
	fprintf(file, "%s", cpf); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessar um arquivo "a" significa acessar o arquivo e adicionar novas informações
	fprintf(file, ","); //botar uma , para separar cada informação
	fclose(file); //fechar o arquivo 
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	SetConsoleOutputCP(65001); //local para usar acentos
	setlocale(LC_ALL, "pt_BR.UTF-8");//local para usar acentos
	
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis/string
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //criar um arquivo
	file = fopen(cpf, "r"); //abrindo um arquivo "r" = abre um arquivo para leitura
	
	if(file == NULL) //se o arquivo não existir/não ter valor
	{
		printf("não foi possivel abrir o arquivo, não localizado! \n");//escrever que não foi possivel localizar
	}
	
	while(fgets(conteudo,200,file) != NULL) //se achar escrever o que esta dentro do arquivo até != (enquanto for diferente de NULL "nada") na variavel conteudo
	{
		printf("\nEssas são as informações do usuário: "); 
		printf("\n%s", conteudo); //escrever as informações do usuário que estão dentro da variavel conteudo
		printf("\n\n");
		
	}
	system("pause"); //pausar a tela para o usuário ler as informações
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);	
	
	if(remove(cpf) == 0){ //se remover o arquivo do usuário e o valor for nulo/0
		printf("Usuario deletado com sucesso!\n"); //escrever que foi deletado com sucesso
	} else {
		printf("Erro: Usuário não encontrado no sistema!\n"); //se o valor não for nulo escrever que o usuário não foi encontrado
	}
	
	system("pause"); //pausar o sistema para o usuário ler se foi um sucesso ou não 

}	

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		SetConsoleOutputCP(65001);
		setlocale(LC_ALL, "pt_BR.UTF-8"); //definindo a linguagem
	
	
		printf("\tCartório da EBAC\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("opção: ");//fim do menu
	
		scanf("%d", &opcao); //armazenando a escola do usuário 
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1: 
			registro(); //chamada da funções 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default: 
			printf("essa opção não esta disponivel!\n");
			system("pause");
			break; 
		} //fim da seleção do menu
	
	}	
}