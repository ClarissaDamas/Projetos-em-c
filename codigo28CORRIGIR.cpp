#include <stdio.h>
#include <math.h>

void defVetor(int n, int vx[], int vy[]) {
//	int i;
//  for(i=0; i<n; i++) {
//  vx[i] = rand()%10;
//  vy[i] = rand()%10;
//	}
    vx[0] = 10; vy[0] = 5;
    vx[1] = 9; vy[1] = 8;
    vx[2] = 6; vy[2] = 9;
    vx[3] = 3; vy[3] = 12;
    vx[4] = 2; vy[4] = 7;
    vx[5] = 5; vy[5] = 6;
    vx[6] = 7; vy[6] = 4;

}

void mostraVetor(int n, int vx[], int vy[]){
	int i;
	printf("\n");
	for(i=0; i<n; i++){
		printf("(%d, %d)", vx[i], vy[i]);
	}
}

void converteVetorPolig(int n, int vx[], int vy[], int vvx[], int vvy[]) {
	int i = 0;
	while(i<n) {
		vvx[i] = vx[(i+1)%n] - vx[i];
		vvy[i] = vy[(i+1)%n] - vy[i];
		i++;
	}
}
int convexo (int i, int j, int a[], int b []){
    int w;
    w = a[i]*b[j] - a[j]*b[i];
    return w;
}

void analiseConvex(int n,int vvx[],int vvy[]){
    int i = 0;
    int w;
    while (i<n){
        w = convexo(i, (i+1)%n, vvx, vvy);
        if(w<0){
        printf("\n Vertice %d eh concavo\n", i);
        }
        else{
        printf("\n Vertice %d eh convexo\n", i);
        }
        i++;
    }
}

CalCentro(int n,int vx[],int vy[], float *cx,float *cy){ //quando eu uso variaveis, se eu nao passo o endereco ele copia o valor
//se o valor for copiado ele pode ser alterado, mas tambem pode ser perdido pois e uma variavel local. por isso, para n perder ele vou passar como
//ponteiro
	int i;
	*cx = *cy = 0.0f; //nessa linha coloquei 0.0 para os dois enderecos, de cx e cy
	for (i=0)
	
}

void geraPoliRegular(int n, in vx[],int vy[],){
	int i;
}

//na funcao abaixo sera calculado o angulado,

CalculaAngulo
	for(i=0;i<n;i++){
		cosAng = prodVetor(ax, ay, vx[i], vy[i]);
		normB = prodVetor(vx[i] //calcula norma de B
		sqrt() //calcular raiz
		
		//corrigir, essa correcao vai ser descobrir em qual quadrante esta o vetor . Para fazer isso vou ver a positividade
		//do vetor
		arcos = arcos*180/M_PI;
		if (vx[i] <0.0f){
			if (vy[i]<0.0f){
				arcos += 180;
			else
				arcos -= 180;
			}
			else
				if(vy[i]<0.0f)
					360 =- arcos; 
				
		}
		
	}
//a funcao abaixo mostra o angulo
printf("\n %6.2f", va[i]) //6 elementos sendo 2 decimais

void main(void) {
	int n;
	int vx[99], vy[99], vvx[99], vvy[99];
	printf("\n Digite o valor de n: ");
	scanf("%d", &n);
	defVetor(n, vx, vy);
	printf("\n Vertices do poligono \n");
	mostraVetor(n, vx, vy);
	converteVetorPolig(n, vx, vy, vvx, vvy);
	printf("\n Arestas do poligono \n");
	mostraVetor(n, vvx, vvy);
	analiseConvex(n, vvx, vvy);
}
