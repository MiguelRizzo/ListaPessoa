//Biblioteca Pessoa

typedef struct {
	int idPessoa;
	char nome[50];
	float peso;
	float altura;
	int idade;
	char sexo;
			 
} Pessoa;

int lerPessoa(Pessoa* p)
{
	printf("Digite a identificacao:\n");
	scanf("%d",&p->idPessoa);
	setbuf(stdin,NULL);
	
	printf("Digite o nome:\n");
	scanf("%[^\n]",&p->nome);
	setbuf(stdin,NULL);
	
	printf("Digite o peso:\n");
	scanf("%f",&p->peso);
	setbuf(stdin,NULL);
	
	printf("Digite a altura:\n");
	scanf("%f",&p->altura);
	setbuf(stdin,NULL);
	
	printf("Digite a idade:\n");
	scanf("%d",&p->idade);
	setbuf(stdin,NULL);
	
	printf("Digite o sexo:\n");
	scanf("%c",&p->sexo);
	setbuf(stdin,NULL);
	
	return 0;
	
}

float imcPessoa(Pessoa p)
{
	float imc=p.peso/pow(p.altura,2);
	return imc;
}

int exibirPessoa(Pessoa p)
{
	
	printf("%4d ",p.idPessoa);
	printf("%-25s",p.nome);
	printf("%6.1f",p.peso);
	printf("%6.2f",p.altura);
	printf("%4d",p.idade);
	printf("%3c",p.sexo);
	printf("%6.2f\n",imcPessoa(p) );
	
	return 0;
}



