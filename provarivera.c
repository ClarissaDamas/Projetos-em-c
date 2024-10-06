#include <stdio.h>
#include <stdlib.h>

void Combina (int na, int *va, int nb, int *vb, int nc, int *vc)
{
	int i,j,k;
	i=na-1;
	j=nb-1;
	
	for(k=0;k<nc;k++)
	{
		if(i>=0 && j>=0)
		{
			if(va[i]>=vb[j])
			{
				vc[k]=va[i];
				i--;
			}
			else
			{
				vc[k]=vb[j];
				j--;
			}
		}
		else
		{
			if(i<0)
			{
				vc[k]=vb[j];
				j--;
			}
			else
			{
				vc[k]=va[i];
				i--;
			}
		}
	}
}

void Mostra (int tam, int* v)
{
	for(int i=0; i<tam;i++)
	{
		printf(" %d ", v[i]);
	}
}
int main (void)
{
	int na=5,nb=7,nc=na+nb;
	int va[]={5,8,12,20,40};
	int vb[]={1,7,9,11,12,15,40};
	
	int* vc= (int *) malloc(nc*sizeof(int));
	printf("Vetor A:\t");
	Mostra(na,va);
	printf("\nVetor B:\t");
	Mostra(nb,vb);
	printf("\nVetor C:\t");
	Combina(na,va,nb,vb,nc,vc);
	Mostra(nc,vc);
	free(vc);	
}