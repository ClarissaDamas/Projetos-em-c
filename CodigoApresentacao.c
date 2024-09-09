#include <stdio.h>
#include <math.h>

void defVetor(int n, float vx[], float vy[]) {
	/*int i;
	for(i=0; i<n; i++) {
		vx[i] = rand()%10;
		vy[i] = rand()%10; 
	}*/	

	vx[0] = 10; vy[0]=5;
	vx[1] = 9; vy[1]=8;
	vx[2] = 6; vy[2]=9;
	vx[3] = 3; vy[3]=12;
	vx[4] = 2; vy[4]=7;
	vx[5] = 5; vy[5]=6;
	vx[6] = 7; vy[6]=4;

}

void mostraVetor(int n, float vx[], float vy[]){
	int i;
	printf("\n");
	for(i=0; i<n; i++){
		printf("(%6.2f, %6.2f)", vx[i], vy[i]);
	}
}

void converteVetorPolig(int n, float vx[], float vy[], float vvx[], float vvy[]) {
	int i = 0;
	while(i<n) {
		vvx[i] = vx[(i+1)%n] - vx[i];
		vvy[i] = vy[(i+1)%n] - vy[i];
		i++;		
	}
}

int convexo (int i, int j, float a[], float b[]){
	int w;
	w = a[i]*b[j] - a[j]*b[i];
	return w;	
}

void AnaliseConvesidade (int n, float vvx[], float vvy[]) {
	int i = 0;
	int w;
	while (i<n) {
		w = convexo(i, (i+1)%n, vvx, vvy);
		if(w<0)
			printf("\n\n vertice %d is concavo \n", i);
		else
			printf("\n\n Vertice %d is convexo \n", i);
		i++;
	}
}

float prodVetor(float ax, float ay, float bx, float by){
	return(ax*bx + ay*by);
}
/*
CalCentro(int n, int vx[], int vy[], float *cx, float *cy){
	int i;
	*cx = *cy =0.0f;
	for(i=0; i<n; i++) {
		*cx += vx[i];
		*cy += vy[i]; 
	}
	cx /= n;
	cy /= n;
}
*/
void geraPoliRegular(int n, float vx[], float vy[], float va[]) {
	int i;
	float ccx, ccy,cosAng, normaB, arcos;
	float ax = 1.0f; float ay = 0.0f; 
	
	// calcula centro
	//calcCentro(n, vx, vy, &ccx, &ccy);
	ccx = ccy =0.0f;
	for(i=0; i<n; i++) {
		ccx += vx[i];
		ccy += vy[i]; 
	}
	ccx /= n;
	ccy /= n;	
	// translacao de pontos
	for(i=0; i<n; i++) {
		vx[i] -= ccx;
		vy[i] -= ccy; 
	}
	// calcula angulos
	
	for(i=0; i<n; i++) {
		cosAng = prodVetor(ax, ay, vx[i], vy[i]);
		normaB = prodVetor(vx[i], vy[i], vx[i], vy[i]);
		normaB = sqrt(normaB);
		cosAng /= normaB;
		arcos = acos(cosAng);  
		// correcao
		arcos = arcos * 180/M_PI; 
		if(vy[i] < 0.0f)
			arcos = 360 - arcos;
		va[i] = arcos;	
	}
	
}

void mostraAngulo(int n, float vetorAngulo[]){
	int i;
	printf("\n Angulos \n");
	for(i=0; i<n; i++){
		printf(" %6.2f ", vetorAngulo[i]);
	}	
}

/*void ordenacao(angulo,vy,vx,temp,)
angulo ordenar o vertice
verifica se vai ser maior ou menor

   while (organiza) {
        organiza = 0;
        for (i = 0; i < n - 1; i++) {
            if (angulo[i] > angulo[i + 1]) {
                temp = angulo[i];
                angulo[i] = angulo[i + 1];
                angulo[i + 1] = temp;
                temp = vx[i];
                vx[i] = vx[i + 1];
                vx[i + 1] = temp;
                temp = vy[i];
                vy[i] = vy[i + 1];
                vy[i + 1] = temp;
                organiza = 1;
            }
        }
    }
    free(angulo);
    }

*/

void main(void) {
	int n;
	float vx[99], vy[99], vvx[99], vvy[99];
	float va[99];
	
	printf("\n Digite val de n: ");
	scanf("%d", &n);
	defVetor(n, vx, vy);
	printf("\n Vertices do poligono \n");
	mostraVetor(n, vx, vy);

	geraPoliRegular(n, vx, vy, va);
	printf("\n Vertices do poligono REGULAR \n");
	mostraVetor(n, vx, vy);
	mostraAngulo(n, va);
//	ordenaAngulos(n, vx, vy, va);

	converteVetorPolig(n, vx, vy, vvx, vvy);
//	printf("\n Arestas  do poligono \n");
//	mostraVetor(n, vvx, vvy);
	printf("\n Antes de Analise \n");
	AnaliseConvesidade(n, vvx, vvy);
}