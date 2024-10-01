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
 //Mostras as coordenadas do vetor.
void mostraVetor(int n, float vx[], float vy[]){
	int i;
	printf("\n");
	for(i=0; i<n; i++){
		printf("(%6.2f, %6.2f)", vx[i], vy[i]);
	}
}
 //Liga os vértices do polígono através de vetores
void converteVetorPolig(int n, float vx[], float vy[], float vvx[], float vvy[]) {
	int i = 0;
	while(i<n) {
		vvx[i] = vx[(i+1)%n] - vx[i]; //nessa etapa eu calculei o vetor, ou seja V1 menos V0, sendo que o V1 vai ser sempre o vertice aanterior mais um
		vvy[i] = vy[(i+1)%n] - vy[i];
		i++;		
	}
}
//Analisa a convexidade do um vértice através do produto vetorial.
int convexo (int i, int j, float a[], float b[]){
	int w;
	w = a[i]*b[j] - a[j]*b[i];
	return w;	//retornar o valor inteiro
}

void AnaliseConvesidade (int n, float vvx[], float vvy[]) {
	int i = 0;
	int s = 0;
	int w;
	while (i<n) {
		w = convexo(i, (i+1)%n, vvx, vvy); 
		if(w<0) //quando o if so tem uma linha nao precisa de chaves
			printf("\n\n vertice %d é concavo \n", i);
			for (s=0; s<n; s++){   //tirar a concavidade do vertice para ter ele convexo
				p;
				}
		else
			printf("\n\n Vertice %d é convexo \n", i);
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
void geraPoliRegular(int n, float vx[], float vy[], float vetorAngulo[]) {
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
		vx[i] -= ccx; //diminui
		vy[i] -= ccy; 
	}
	// Primeiro calcular os ângulos, depois converter de radianos para graus
	
	for(i=0; i<n; i++) {
		cosAng = prodVetor(ax, ay, vx[i], vy[i]); 
		normaB = prodVetor(vx[i], vy[i], vx[i], vy[i]);
		normaB = sqrt(normaB); 
		cosAng /= normaB;
		arcos = acos(cosAng);  //arcocosseno
		// //corrigir, essa correcao vai ser descobrir em qual quadrante esta o vetor . Para fazer isso vou ver a positividade
		//do vetor
		arcos = arcos * 180/M_PI; 
		if(vy[i] < 0.0f)
			arcos = 360 - arcos;
		vetorAngulo[i] = arcos;	
	}
	
}
//a funcao abaixo mostra o angulo
void mostraAngulo(int n, float vetorAngulo[]){
	int i;
	printf("\n Angulos \n");
	for(i=0; i<n; i++){
		printf(" %6.2f ", vetorAngulo[i]); //6 elementos sendo 2 decimais
	}	
}

void ordenaAngulos(int n, float vx[], float vy[], float vetorAngulo[]) {
    //printf("\nFUNCIONA\n");
   float temporaria; //double é mais eficiente que float, especialmene em coisa cientifica q exige muitos dados
   int i, Varordenacao = 1;
   while (Varordenacao > 0) {    
        Varordenacao = 0;    
        for (i = 0; i < n - 1; i++) {   
            if (vetorAngulo[i] > vetorAngulo[i + 1]) { 
                temporaria = vetorAngulo[i]; //vetor inicial vai assumir valor da temporaria
                vetorAngulo[i] = vetorAngulo[i + 1]; //caso seja maior vai assumir o novo valor
                vetorAngulo[i + 1] = temporaria; //o valor vai ser reordenado para temporaria, enquanto nao ocorre novamente
                temporaria = vx[i];
				//printf("esse valor da NOVA TEMPORARIA %d",temporaria);
                vx[i] = vx[i + 1];
                vx[i + 1] = temporaria;
                temporaria = vy[i];
                vy[i] = vy[i + 1];
                vy[i + 1] = temporaria;
                Varordenacao = 1; //vai parar
            }
        }
}   }


//ver todos q sao concavos e passar para convexo


void main(void) {   //inicia com o main
	int n;
	float vx[99], vy[99], vvx[99], vvy[99];  //cria o vetor
	float va[99]; //sao dois vetores, esse segundo seria o vetor do vertice do poligono, o vetor das arestas
	
	printf("\n Qual o valor de n desejado? ");
	scanf("%d", &n);
	defVetor(n, vx, vy); //Cria os vértices do polígono
	printf("\n Vertices do poligono \n");
	mostraVetor(n, vx, vy);

	geraPoliRegular(n, vx, vy, va);
	printf("\n Vertices do poligono REGULAR \n");
	mostraVetor(n, vx, vy);
	mostraAngulo(n, va);
	ordenaAngulos(n, vx, vy, va);
	converteVetorPolig(n, vx, vy, vvx, vvy);
//	printf("\n Arestas  do poligono \n");
//	mostraVetor(n, vvx, vvy);
    printf("\n Apos a ordenacao os");
	mostraAngulo(n, va);
	printf("\n Vetores apos a ordenacao \n");
	mostraVetor(n, vx, vy);
	printf("\n Antes de Analise \n");
	AnaliseConvesidade(n, vvx, vvy);
}