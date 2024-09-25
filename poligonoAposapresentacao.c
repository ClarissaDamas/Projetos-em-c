#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void defVetor(int n, float *vx, float *vy) {
	int i;
	vx = (float*)calloc(n,sizeof(float));
	vy = (float*)calloc(n,sizeof(float)); //pede um espaco de cinco posicoes(nesse caso o n foi 5, se o n for outro a quantidade de posicoes vai ser diferente)
	if(!vx){  //
		printf("\n não aloca"); exit(1);
	}
	
	for(i=0; i<n; i++) {
		vx[i] = rand()%99*1.0f; //pede um random, porem vou receber inteiro entao vai ser so multicplicar por 1.0 que vou ter  
		vy[i] = rand()%99*1.0f; 
	}	
/*
	vx[0] = 10; vy[0]=5;
	vx[1] = 9; vy[1]=8;
	vx[2] = 6; vy[2]=9;
	vx[3] = 3; vy[3]=12;
	vx[4] = 2; vy[4]=7;
	vx[5] = 5; vy[5]=6;
	vx[6] = 7; vy[6]=4;
*/	
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
	  for(i = 0; i < n; i++) {
        cosAng = prodVetor(ax, ay, vx[i], vy[i]);
        normaB = prodVetor(vx[i], vy[i], vx[i], vy[i]);
        normaB = sqrt(normaB);
        cosAng /= normaB;
        arcos = acos(cosAng);  
        arcos = arcos * 180 / M_PI; 
        if(vy[i] < 0.0f)
            arcos = 360 - arcos;
        va[i] = arcos;   
	

	}
	
}

void mostraAngulo(int n, float va[]){
	int i;
	for(i=0; i<n; i++){
		printf(" %6.2f ", va[i]);
	}	
}

// Função de ordenação por bublle sort
void OrganizaPoli(int n, float vx[], float vy[], float va[]) {
    int i, j;
    float temp;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0; // para verificar se houve troca na passagem
        for (j = 0; j < n - i - 1; j++) {
            if (va[j] > va[j + 1]) {
                // Troca de ângulos
                temp = va[j];
                va[j] = va[j + 1];
                va[j + 1] = temp;

                // Troca de coordenadas x
                temp = vx[j];
                vx[j] = vx[j + 1];
                vx[j + 1] = temp;

                // Troca de coordenadas y
                temp = vy[j];
                vy[j] = vy[j + 1];
                vy[j + 1] = temp;

                trocou = 1; // Indica que houve uma troca
            }
        }
        // Se não houve troca, a lista está ordenada
        if (!trocou) {
            break;
        }
    }
}

int main(void) {
	int n;
	float *vx, *vy, *vvx, *vvy;
	float *va;
	
	printf("\n Digite val de n: ");
	scanf("%d", &n);
	
	defVetor(n, vx, vy);
	printf("\n Vertices do poligono");
	mostraVetor(n, vx, vy);

	geraPoliRegular(n, vx, vy, va);
	printf("\n\n Vertices do poligono REGULAR");
	mostraVetor(n, vx, vy);
	printf("\n\n Angulos antes da organização\n");
	mostraAngulo(n, va);
    
    OrganizaPoli(n, vx, vy, va);
    printf("\n\n Ângulos após a organização:");
    mostraAngulo(n, va);
    
    converteVetorPolig(n, vx, vy, vvx, vvy);
    printf("\n\n Mostrando  quais vetores são convexos ou concavos");
    AnaliseConvesidade(n, vvx, vvy);
    printf("\n\n Arestas  do poligono já regularizado ");
	mostraVetor(n, vvx, vvy);
    free(vx);
    free(vy);
}