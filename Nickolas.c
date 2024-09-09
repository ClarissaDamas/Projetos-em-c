#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*void defVetor(int n, int vx[], int vy[]) {
    //Cria os vértices do polígono.
    int i;
    for(i = 0; i < n; i++) {
        vx[i] = rand() % 201 - 100;
        vy[i] = rand() % 201 - 100;
    }    
}
*/

void defVetor(int n, int vx[], int vy[]) {
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

void mostraVetor(int n, int vx[], int vy[]) {
    //Mostras as coordenadas do vetor.
    int i;
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("(%d, %d)", vx[i], vy[i]);
    }
}

void converteVetorPolig(int n, int vx[], int vy[], int vvx[], int vvy[]) {
    //Liga os vértices do polígono através de vetores.
    int i = 0;
    while (i < n) {
        vvx[i] = vx[(i + 1) % n] - vx[i];
        vvy[i] = vy[(i + 1) % n] - vy[i];
        i++;
    }
}
int convexo(int i, int j, int a[], int b[]) {
    int w;
    w = a[i] * b[j] - a[j] * b[i];
    return w;
}
void mostraConvexidade(int n, int vc[]) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (vc[i] == 1 || vc[i] == 0) {
            printf("\nVertice %d é convexo", i+1);
        } else {
            printf("\nVertice %d é côncavo", i+1);
        }
    }
}

int analiseConvexidade(int n, int vvx[], int vvy[], int vc[], int vx[], int vy[]) {
    //Analisa a convexidade de um vértice através do produto vetorial.
    int i = 0;
    int colinear = 0;
    int concavo = 1;
    int w;
    for(i=0;i<n;i++){
        w = convexo(i, (i + 1) % n, vvx, vvy);
        if (i==n-1){
            if (w < 0) {
            vc[0] = 2;
        } else if (w > 0) {
            vc[0] = 1;
        } else {
            vc[0] = 0;
        }
        } else{
        if (w < 0) {
            vc[i+1%n] = 2;
        } else if (w > 0) {
            vc[i+1%n] = 1;
        } else {
            vc[i+1%n] = 0;
        }
        }
    }
    for (i=0;i<n;i++){
        if (vc[i] == 1) colinear++;
        if (vc[i] == 2) colinear =+ 2;
    }
    if (colinear == n){
        return 2;
    } else if (colinear == 0){
    printf("\nNão é possível formar um polígono com vetores colineares.");
    return 0;
    } else {
        return 1;
    }
}

int GeraPoliConvexo(int *n, int vc[],int vx[],int vy[],int vvx[], int vvy[]){
    //Liga o vértice antecessor ao sucessor caso o vértice atual possua curva côncova.
    int i = 0;
    int Fvertices = *n;
    int convexidade = 1;
    while (convexidade == 1){
    i=0;
    while (i<Fvertices){
        if (vc[i] == 2){
            if(i==0){
                vvx[Fvertices-1] += vvx[i];
                vvy[Fvertices-1] += vvy[i];
            } else {
            vvx[i-1] += vvx[i];
            vvy[i-1] += vvy[i];
            }
            
            for (int c = i;c<Fvertices - 1;c++){
                vvx[c] = vvx[c+1];
                vvy[c] = vvy[c+1];
                vx[c] = vx[c+1];
                vy[c] = vy[c+1];
                vc[c] = vc[c+1];
            }
            vvx[Fvertices-1] = 0;
            vvy[Fvertices-1] = 0;
            vx[Fvertices-1] = 0;
            vy[Fvertices-1] = 0;
            vc[Fvertices-1] = 0;
            Fvertices--;
            vx = realloc(vx, Fvertices * sizeof(int));
            vy = realloc(vy, Fvertices * sizeof(int));
            vvx = realloc(vvx, Fvertices * sizeof(int));
            vvy = realloc(vvy, Fvertices * sizeof(int));
            vc = realloc(vc, Fvertices * sizeof(int));
            convexidade = analiseConvexidade(Fvertices, vvx, vvy, vc, vx, vy);
    } else i++;
    }
    }
    *n = Fvertices;
}

void organizaPoli(int n, int vx[], int vy[]) {
    //Organiza a lista de vetores usando método bubble sort.
    printf("\n");
    double *vetorAngulo, temp;
    vetorAngulo = (double*)malloc(n * sizeof(double));
    int i, loop = 1, organiza = 1;
    for (int i = 0; i < n; i++) {
        vetorAngulo[i] = atan2(vy[i], vx[i]) * 180.0 / M_PI;
        if (vetorAngulo[i] < 0) {
            vetorAngulo[i] += 360;
        }
    }
    while (organiza) {
        organiza = 0;
        for (i = 0; i < n - 1; i++) {
            if (vetorAngulo[i] > vetorAngulo[i + 1]) {
                temp = vetorAngulo[i];
                vetorAngulo[i] = vetorAngulo[i + 1];
                vetorAngulo[i + 1] = temp;
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
   printf(" %6.2f ", vetorAngulo[i]);
    }

/*void mostraAngulo(int n, float angulo[]){
	int i;
	printf("\n Angulos \n");
	for(i=0; i<n; i++){
		printf(" %6.2f ", angulo[i]);
	}	
}
*/

int main() {
    int n, i;
    int *vx, *vy, *vvx, *vvy, *vc;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    vx = (int*)malloc(n * sizeof(int));
    vy = (int*)malloc(n * sizeof(int));
    vvx = (int*)malloc(n * sizeof(int));
    vvy = (int*)malloc(n * sizeof(int));
    vc = (int*)malloc(n * sizeof(int));
    defVetor(n, vx, vy);
    printf("\nPontos do polígono:");
    mostraVetor(n, vx, vy);
    organizaPoli(n, vx, vy);
    printf("\nVertices do polígono:");
    mostraVetor(n, vx, vy);
    converteVetorPolig(n, vx, vy, vvx, vvy);
    printf("\nArestas do polígono:");
    mostraVetor(n, vvx, vvy);
    printf("\nConvexidade do polígono:");
    int naoColinear = analiseConvexidade(n, vvx, vvy, vc, vx, vy);
    if (naoColinear){
        //Não executará caso os pontos sejam colineares.
        mostraConvexidade(n, vc);
        int Fvertices = GeraPoliConvexo(&n, vc, vx, vy, vvx, vvy);
        printf("\n\nVértices do poligono convexo:");
        mostraVetor(n, vx, vy);
        printf("\nArestas do poligono convexo:");
        mostraVetor(n, vvx, vvy);
        printf("\n");
        printf("\nConvexidade do polígono convexo: ");
        mostraConvexidade(n, vc);
        //mostraAngulo(n, angulo);
    }
    free(vx);
    free(vy);
    free(vvx);
    free(vvy);
    free(vc);
    
    return 0;
    }