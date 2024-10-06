#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void MensagemInicial ()
{
	printf("Programa para Juntar dois vetores crescentes em um decrescente.\n");
}

void TamanhoVetor(int* tam_vet)
{
	do
	{
		printf("Digite o tamanho do vetor (menor que 100):\t");
		scanf("%d",tam_vet);
	} while (*tam_vet<1 || *tam_vet>100);
}

void DefinirVetor(int tam_vet,int* vet)
{
	int escolha,i;
	do
	{
		printf("Definir manualmente\t(1)\ndefinir aleatoriamente\t(2)\n");
		scanf("%d",&escolha);
		
		switch (escolha)
		{
			case 1:
				for (i=0;i<tam_vet;i++)
				{
					printf("Digite o valor da posição %d:\t",i);
					scanf("%d",&vet[i]);
				}
			break;
			
			case 2:
				for (i=0;i<tam_vet;i++)
				{
					vet[i]=rand()%11;	//checar aleatoriedade
				}
			break;
			
			default:
				printf("Número inválido, escolha 1 ou 2 novamente.\n\n");
		}
	} while (escolha<1 || escolha>2);
}

void MostrarVetor(int tam_vet,int* vet)
{
	int i;
	printf("\nVetor:\t");
	
	for (i=0;i<tam_vet;i++)
	{
		printf("%d ",vet[i]);
	}
	printf("\n");
}

int main (void)
{
	
}