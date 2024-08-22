#include <stdio.h>
#include <math.h>

void defVetor(int n, int vx[], int vy[]) {
	int i;
	for(i=0; i<n; i++) {
		vx[i] = rand()%100;
		vy[i] = rand()%100; 
	}	
}

void mostraVetor(int n, int vx[], int vy[]){
	int i;
	printf("\n");
	for(i=0; i<n; i++){
		printf("x = %d y =  %d; ", vx[i], vy[i]);
	}
}

void converteVetorPolig(int n, int vx[], int vy[], int vvx[], int vvy[]) {
	int i = 0;
	while(i<n) {
		vvx[i] = vx[(i+1)%n] - vx[i]; //nessa etapa eu calculei o vetor, ou seja V1 menos V0, sendo que o V1 vai ser sempre o vertice aanterior mais um
		vvy[i] = vy[(i+1)%n] - vy[i];
		i++;		
	}
}
int convexo (int i, int j, int a[], int b[]){
	int w;
	w = (a[i]*b[j]) - (a[j]*b[i]);  //
	return w //retornar o valor inteiro

}

void analiseConvex(int n, int vvx[],int vvy[]) { //para analisar vou verificr se o angulo e maior q 180 graus
	int i = 0, w ;
	while (i<n) {
		w = convexo(i,(i+1)%n, vvx,vvy);
//		w = vvx[i], vvx[i+1]%n
		if (w<0) //quando o if so tem uma linha nao precisa de chaves, em situacoes que precisa de igual rivera nao gosta prefere q use uma letra e o programa reconheca se e verdadeiro ou falso
		printf("\n\n vertice %d e concavo \n", i);
		else printf("\n\n vertice %d e convexo \n", i)
		i++;
			}
}

	//convexo
	//int Convexo(a,b)
	//a = (vvx, vvy)
	//b = (vx, vy)

	//xa.yb - xb ya(produto vetorial bidimensional)

void main(void) {
	int n;
	int vx[99], vy[99];
	int vvx[99], vvy[99]; //sao dois vetores, esse segundo seria o vetor do vertice do poligono, o vetor das arestas
	printf("\n Digite val de n: ");
	scanf("%d", &n);
	defVetor(n, vx, vy);
	printf("\n Vertices do poligono \n");
	mostraVetor(n, vx, vy);
	converteVetorPolig(n, vx, vy, vvx, vvy);
	printf("\n Arestas do poligono \n");
	mostraVetor(n, vvx, vvy);
	analiseConvex(n, vx, vy);
}