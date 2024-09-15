#include <stdio.h>

//Programa para deixar registrado tudo que aprendi em C.

int fatorial(int x){
	if(x<=0)
		return 1;
	else
		return x*fatorial(x-1);
//Função recursiva com fatoral.
//if e else com uma linha depois do comando não precisa de {}.
}

struct aniv{
	char nome[20];
	int mes, dia;
};
//Criação de registro! Pode conter varáveis de tipos diferentes.
//Coisa que o vetor e matriz não conseguem fazer.

int soma(int n){
	if(n==1)
		return 1;
	else
		return n+soma(n-1);
//soma recursiva.
}

int main(){
	
/*
%d, %i == inteiro == int
%f == float == float/double
%c == caractere == char
%s == string == char
outros símbolos importantes para comparação:
   ==, <=, >=, !=, <, >.
*/

	//fatorial:
	int a,b, n, m;
	printf("Informe um valor:");
	scanf("%d", &a);
	b= fatorial(a);
	printf("Fatoriado, o resultado fica:%d",b);
	
	//registro:
	for(int i=0; i<3; i++){
		struct aniv aluno[3];     //chamada do registro
		printf("\nInforme nome, mes e dia de aniversário:\n");
		scanf("%s", & aluno[i].nome[20]);
		scanf("%d", & aluno[i].mes);
		scanf("%d", & aluno[i].dia);
	}
	
	//soma recursiva:
	printf("\nFale um valor:");
	scanf("%d", &m);
	n= soma(m);
	printf("\nValor de n= %d", n);
	
	//Ponteiros:
	int *pn;
	pn= &n;
	
	printf("\nEndereco n=%d \nValor n=%d", pn, *pn);
	
}
