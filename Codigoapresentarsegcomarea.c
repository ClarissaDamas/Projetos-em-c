#include <stdio.h>
#include <math.h>

void defVetor(int n, float vx[], float vy[]) {
	int i;

/*
	for(i=0; i<n; i++) {
		vx[i] = rand()%10;
		vy[i] = rand()%10; 
	}	
*/	
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
	//a =(x0,y0), b = (x1,y1); Vetor AB (x1 - x0, y1 - y0)
	while(i<n) {
		vvx[i] = vx[(i+1)%n] - vx[i];
		vvy[i] = vy[(i+1)%n] - vy[i];
		i++;
	}
}

int calculaProdutoVetorial(int i, int j, float a[], float b[]){
    int w;
    w = (a[i] * b[j]) - (a[j] * b[i]);
    return w;
}

void CalCentro(int n,float vx[],float vy[], float *ccx, float *ccy){
	int i = 0;
	for(i = 0; i < n;i++){
		*ccx += vx[i];
		*ccy += vy[i];
	}
	*ccx/= n;
	*ccy/= n;
}


int convexo (int i, int j, float a[], float b[]){
	int w;
	w = a[i]*b[j] - a[j]*b[i];
	return w;	
}

void AnaliseConvesidade (int n, float vvx[], float vvy[], float convex[]) {
	int i = 0;
    int w = 0;
    while(i<n){
        w = calculaProdutoVetorial(i ,(i+1)%n,vvx,vvy);

        if(w < 0){
            printf("\nvertice %d eh concavo !",i+1);
            convex[i] = 0;
        }else{
            printf("\nvertice %d eh convexo !",i+1);
            convex[i] = 1;
        }
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

void mostraAngulo(int n, float va[]){
	int i;
	printf("\n Angulos \n");
	for(i=0; i<n; i++){
		printf(" %6.2f ", va[i]);
	}	
}

void coverteConcavoConvex(int n, float vx[], float vy[], float vvx[], float vvy[], float convex[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (convex[i] == 0) {  // Se o v�rtice � c�ncavo
            //mover o v�rtice para um novo ponto baseado na m�dia dos vizinhos
            printf("\n\n X posterior: %f e anterior: %f ", vx[(i+1)%n],vx[((i-1)+n)%n ]);
            printf("\n\n Y posterior: %f e anterior: %f \n", vy[(i+1)%n],vy[((i-1)+n)%n ]);

            float n_vx = (vx[(i+1)%n] + vx[(i-1+n)%n]) / 2;
            float n_vy = (vy[(i+1)%n] + vy[(i-1+n)%n]) / 2;

            vx[i] = n_vx;  // Atualiza a posi��o do v�rtice c�ncavo
            vy[i] = n_vy;
        }
    }
    // Depois disso, recalcula as arestas
    converteVetorPolig(n, vx, vy, vvx, vvy);
}

float AreaPoligono(float vx[], float vy[], int n) {
    int sum = 0;
	//float area;

	for (int i = 0; i < n; i++) {
    	sum += (vx[i] * vy[(i+1)%n]) - (vx[(i+1)%n] * vy[i]);
		//printf("%d",i);
		//printf("%f", area);
		//area = (sum) / 2.0;
    }
	//printf("%d",i);

    return (sum) / 2.0;
}


void main(void) {
	int n;
	//float area = 0;
	float vx[99], vy[99], vvx[99], vvy[99];
	float va[99], convex[99];;
	
    printf("\n Digite val de n: ");
	scanf("%d", &n);
	defVetor(n, vx, vy);
	printf("\n Vertices do poligono \n");
	mostraVetor(n, vx, vy);

	converteVetorPolig(n, vx, vy, vvx, vvy);

	// Imprime os v�rtices originais
	printf("\nV�rtices do pol�gono desorganizados:\n");
	mostraVetor(n, vx, vy);

	printf("\nArestas do pol�gono antes de regularizar:\n");
	mostraVetor(n, vvx, vvy);

    // Organiza os v�rtices do pol�gono para garantir que sejam inseridos de forma correta
	geraPoliRegular(n, vx, vy, va);

	// Recalcula as arestas agora com os v�rtices organizados
	converteVetorPolig(n, vx, vy, vvx, vvy);
	printf("\nArestas do pol�gono ap�s reorganiza��o:\n");
	mostraVetor(n, vvx, vvy);

    printf("\nV�rtices do pol�gono organizados:\n");
	mostraVetor(n, vx, vy);

    // An�lise de convexidade dos v�rtices antes
	printf("\nAn�lise de convexidade dos v�rtices antes da convers�o:\n");
	AnaliseConvesidade(n, vvx, vvy, convex);

	// Converte v�rtices c�ncavos em convexos
	coverteConcavoConvex(n, vx, vy, vvx, vvy, convex);
	converteVetorPolig(n, vx, vy, vvx, vvy);

	// Exibe as novas arestas ap�s a convers�o dos v�rtices c�ncavos
	printf("\n\nArestas do pol�gono ap�s convers�o dos v�rtices c�ncavos:\n");
	mostraVetor(n, vvx, vvy);

    // Mostra os novos v�rtices

	printf("\nV�rtices do pol�gono ap�s convers�o:\n");
	mostraVetor(n, vx, vy);

	// An�lise de convexidade dos v�rtices
	printf("\nAn�lise de convexidade dos v�rtices DEPOIS da convers�o:\n");
	AnaliseConvesidade(n, vvx, vvy, convex);

	float area = AreaPoligono(vx, vy, n);
    printf("\nA área do polígono é: %.2f\n", area);

}