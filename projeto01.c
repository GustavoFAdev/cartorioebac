#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> //biblioteca de strings
int quebra()
{
	return (0);
}

int registro()
{
	char arquivo[10];
	char cpf[10];
	char nome[40];
	char sobrenome[40];
	char cargo[20];
	int p=0;
	
	
	printf ("digite o CPF a serregistrado \n");
	scanf ("%s", cpf); //armazena valor de uma string
	
	strcpy (arquivo, cpf);
	
	FILE *file; // abre arquivo. FILE ja esta no pc(como se tivesse falando para o pc abrir uma pasta ja existente e criar outra)
 	
	file = fopen(arquivo,"w"); // "w" escrita no arquivo aberto. (fopen. arquivo esta aberto)
	fprintf (file,cpf); //salva valor da variavel (fprintf* como o printf mas para dentro do arquivo. No caso printf no arquivo. oque esta sendo escrito nele? a scanf de cpf) 
	fclose(file); //fachar arquivo aberto
	
	file = fopen (arquivo,"a"); //A de atualização (
	fprintf(file, ","); //em file esta sendo escrito uma virgula(diferente de antes nao esta puxando informacaode uma variavel)
	fclose (file);
	
		switch (p)	
		{
			case 3:
				{
					quebra();
					break;
				}
		}	
		
	printf("digite o nome: \n");
	scanf ("%s", nome);
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen ( arquivo, "a");
	fprintf (file, "\t");
	fclose (file);
		
	printf ("digite o sobrenome: \n");
	scanf("%s", sobrenome);
	file = fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	printf ("digite o cargo: \n");
	scanf ("%s", cargo);
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
	
	system ("pause");
	
}

int pesquisa()
{
	setlocale(LC_ALL,"portuguese");
	
	char cpf [10];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado:\t");
	scanf ("%s",cpf);
	
	FILE *file;
	file = fopen (cpf,"r");// "r" ler oque tem no.
	
	if (file == NULL)
	{
		printf("\t arquivo não localisado! \n\n");
		system ("pause");
		return (0);
	}
	
	while (fgets(conteudo,200,file)!=NULL);//"while" enqunato* tal coisa. No caso, enquanto variavel conteudo que esta olhando "file" for diferente de nulo dentre os caracteres da string
	{
		printf ("\n\t\t informações de usuario \n\n");
		printf ("%s",conteudo);
		printf ("\n\n");
		system("pause");
	}
}

int excluir()
{
	char cpf[10];
	
	
	printf ("quais nomes deseja excluir?:\n");
	scanf ("%s",cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	
	if (file ==NULL)
	{
		printf ("\t usuario não encontrado!\n\n");
		system ("pause");
	}
	
	else
	{
		printf ("\t usuario deletado!\n");
		system ("pause");
	}
	
}
int main()
{
	int op=0;
	int x=1;
	for (x=1;x=1;)
	{
	
	system("cls");
	
		setlocale(LC_ALL,"portuguese");
		
		printf ("\t\t\t LISTA DE ALUNOS\n\n\n");
		printf ("\t\t escolha uma opção\n\n");
		printf ("\t 1. registrar de nomes \n");
		printf ("\t 2. consultar nomes \n");
		printf ("\t 3. excluir inscrição\n\n\n");
		printf ("=============================================================== \n");
		printf ("escolha uma opção:");
		
		
		scanf("%d", &op);
	
		system ("cls");
	    
	    switch (op)
		{
	
			case 1:
				registro();
				break;
				
			case 2:
				pesquisa();
				break;
				
			case 3:
				excluir();
				break;
				
			default:
				printf("\t não há opções validas: \n");
				system ("pause");
				break;
		}
	}
}
