#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pessoa.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int listarPessoas (Pessoa p [500], int q);
int salvarLista (Pessoa p[500], int q,FILE *a);
int localizarEditar (Pessoa p[500], int q);
int exibirDados (Pessoa p [500], int q);

int main(int argc, char *argv[]) {
	Pessoa pessoas[500];
	char continua='s';
	int opcao=0;
	int qt=0;
	float imc;
	FILE *arquivo;
	arquivo = fopen("pessoa.txt","r");
	
	
	while(fscanf(arquivo,"%d;%[^;];%f;%f;%d;%c;%f\n", 
					
						&pessoas[qt].idPessoa,
						&pessoas[qt].nome,
						&pessoas[qt].peso,
						&pessoas[qt].altura,
						&pessoas[qt].idade,
						&pessoas[qt].sexo,
					    &imc
	)!=EOF){
		qt++;
	}
	fclose(arquivo);
	
    while(continua =='s')	
	{
		printf("Digite 1 para cadastrar uma pessoa\n");
		printf("Digite 2 para listar todas as pessoas\n");
		printf("Digite 3 para salvar dados em disco\n");
		printf("Digite 4 para editar uma pessoa\n");
		printf("Digite 5 para exibir pessoas com mais de 60 anos\n");
		printf("Digite 6 para sair\n");
		setbuf (stdin,NULL);
		scanf("%d",&opcao);
		
		switch(opcao)
		{ 
			case 1:
				lerPessoa(&pessoas[qt]);
				qt++;
				break;
			case 2:
				listarPessoas(pessoas,qt);
				break;
			case 3:
				arquivo = fopen("pessoas.txt","w");
			    salvarLista(pessoas,qt,arquivo);
			    break;
			case 4:
				localizarEditar(pessoas,qt);
			    break;	
			case 5:	
				exibirIdosos(pessoas,qt);
				break;
			case 6:
			    continua='n';
			default:    
			    printf("Opcao invalida\n");
			    
		}
	}
	
	
	return 0;
}
int listarPessoas(Pessoa p[500], int q)
{
	int i;
	for(i=0;i<q;i++)
	{
		exibirPessoa(p[i]);
	}
}
int salvarLista(Pessoa p[500], int q,FILE *a)
{
	int i;
	for(i=0;i<q;i++)
	{
		fprintf(a,"%d;%s;%f;%f;%d;%c:%f\n",
		p[i].idPessoa,
		p[i].nome,
		p[i].peso,
		p[i].altura,
		p[i].idade,
		p[i].sexo,
		imcPessoa(p[i])
		
		);
	}
	fclose(a);	
}

int localizarEditar(Pessoa p[500], int q){
	
	int id;
	int i;
	int encontrado = 0;
	
	printf("Digite o id da pessoa que deseja editar:\n");
	scanf("%d",&id);
	setbuf(stdin, NULL);
	
	for(i=0; i<q; i++){
		
		if(p[i].idPessoa == id){
			
			printf("Pessoa encontrada");
		}
		else{
			
			lerPessoa(&p[encontrado]);
		}
	}
}

int exibirIdosos(Pessoa p[500], int q){
	
	int i;
	printf("\n Lista Idoso \n\n");
	for(i=0;i<q;i++){
		
		if(p[i].idade >= 60){
	
			exibirPessoa(p[i]);
		}
	}
}
