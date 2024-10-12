#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Pto { float x, y;} stPto;

/*
O CODIGO ABAIXO FAZ A MESMA COISA DO OUTRO, POREM O OUTRO USA STRUCT
void defVetor(int m,  float *v[]) {
	int i;
	float *vt;
	vt = (float *) malloc(m * sizeof(float));
	if(!vt) {
		printf("\n vetor nao definido \n");
		exit(1);
	}
	for(i=0; i<m; i++){
		vt[i] = rand()%100;
	}
	*v = vt;
}
*/

stPto* defVetorP(int m) {
	int i;
	stPto* vt; //ou stVtor *v 
	vt = (stPto*) malloc(m * sizeof(stPto));
	if(!vt) {
		printf("\n vetor nao definido \n");
		exit(1);
	}
	for(i=0; i<m; i++){
		vt[i].x = rand()%100;
		vt[i].y = rand()%100;
	}
	return(vt);
}
void mostraVetor(stVtor* v) //sempre que passo com aesterisco eu preciso usar a seta para indicar o endereco
{
	int i;
	printf("\n Vetor \n");
	for(i=0; i<n; i++){
		printf("\n i: %d ", i); 
		printf(" (%6.2f, %6.2f)", v[i].xy, v[i].xy);
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

void AnaliseConvesidade (int n, float *v) {
	int i = 0;
	int w;
	while (i<n) {
	//	w = convexo(i, (i+1)%n, *v);
	//	w = 
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

void  poligOrigemCentro (int n, stPto* v) {
	int i;
	stPto cc;
	
	// calcula centro
	//calcCentro(n, vx, vy, &ccx, &ccy);
	cc.x = cc.y =0.0f;
	for(i=0; i<n; i++) {
		cc.x += v[i].x;
		cc.y += v[i].y; 
	}
	cc.x /= n;
	cc.y /= n;	
	// translacao de pontos
	for(i=0; i<n; i++) {
		v[i].x -= cc.x;
		v[i].y -= cc.y; 
	}	
}

void ordenaVetorAng(int n, stPto *v, float angulos[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (angulos[i] > angulos[j]) {

                float auxAngulos = angulos[i];
                angulos[i] = angulos[j];
                angulos[j] = auxAngulos;

                float auxVX = v[i].x;
                v[i].x = v[j].x;
                v[j].x = auxVX;

                float auxVY = v[i].y;
                v[i].y = v[j].y;
                v[j].y = auxVY;
            }
        }
    }
}

void poligRegularEstrela(int n, stPto *v) {
	int i;
	float cosAng, normaB, arcos, *va;
	
	va = (float *) malloc(n*sizeof(float));
	// calcula angulos
	printf("\n");
	for(i=0; i<n; i++) {
		cosAng = prodVetor(1.0, 0.0, v[i].x, v[i].y);
		normaB = prodVetor(v[i].x, v[i].y, v[i].x, v[i].y);
		normaB = sqrt(normaB);
		cosAng /= normaB;
		arcos = acos(cosAng);  
		// correcao
		arcos = arcos * 180/M_PI; 
		if(v[i].y < 0.0f)
			arcos = 360 - arcos;
		va[i] = arcos;	
		
		printf(" %f6.2, ", va[i]);
	}
	ordenaVetorAng(n, v, va);
	free(va);
	
}

void mostraAngulo(int n, float va[]){
	int i;
	printf("\n Angulos \n");
	for(i=0; i<n; i++){
		printf(" %6.2f ", va[i]);
	}	
}

int main(void) {
	stVtor v;
	
	printf("\n Digite val de n: ");
	scanf("%d", &n); //pedi para guardar o valor de n no vetor v, se o usuario digita 10 por exemplo, vou ter na pilha v.n sendo 10
	 
	v.xy = defVetorP(v.n);
	
	printf("\n Vertices do poligono DEFINIDO \n");
	mostraVetor(n, v.xy);

//	geraPoliRegular(n, vx, vy);
	poligOrigemCentro (n, v.xy);  
	
	printf("\n Vertices do poligono Centro \n");
	mostraVetor(&v); //posso passar somente v ou posso passar v.n,,,,como meu v esta como stVtor eu teria que colocar na funcao stVtor se estivesse passando so um
	//mostraVetor(v) 

	poligRegularEstrela (n, vxy);

	printf("\n Arestas  do poligono ORDENADO \n");
	mostraVetor(n, vxy);
	printf("\n Antes de Analise \n");
	AnaliseConvesidade(n, vxy);

	free(v.xy); //eu so vou usar o free com o xy pq ele foi o unico q eu usei o malloc, para o n eu n usei. se eu uso free(v) vai dar errado pois em v eu tenho xy e n

	return 0;
}