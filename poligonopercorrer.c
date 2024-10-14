#include <stdio.h>
#include <math.h>

// Função para definir os vértices do polígono
void defVetor(int n, float vx[], float vy[]) {
	vx[0] = 10; vy[0] = 5;
	vx[1] = 9; vy[1] = 8;
	vx[2] = 6; vy[2] = 9;
	vx[3] = 3; vy[3] = 12;
	vx[4] = 2; vy[4] = 7;
	vx[5] = 5; vy[5] = 6;
	vx[6] = 7; vy[6] = 4;
}

// Função para mostrar os vértices do polígono
void mostraVetor(int n, float vx[], float vy[]) {
	for (int i = 0; i < n; i++) {
		printf("(%6.2f, %6.2f) ", vx[i], vy[i]);
	}
	printf("\n");
}

// Função para calcular o produto vetorial entre dois vetores (determinante 2D)
float produtoVetorial(float vx1, float vy1, float vx2, float vy2) {
	return (vx1 * vy2) - (vy1 * vx2);
}

// Função para verificar se o vértice forma um ângulo côncavo
int verificarConcavidade(float vx[], float vy[], int n) {
	int concavo = -1;
	for (int i = 0; i < n; i++) {
		// Pega os vértices consecutivos no polígono
		float vx1 = vx[(i + 1) % n] - vx[i];  // Vetor A->B
		float vy1 = vy[(i + 1) % n] - vy[i];
		float vx2 = vx[(i + 2) % n] - vx[(i + 1) % n];  // Vetor B->C
		float vy2 = vy[(i + 2) % n] - vy[(i + 1) % n];

		float cross = produtoVetorial(vx1, vy1, vx2, vy2);

		// Se o produto vetorial for negativo, o vértice é côncavo
		if (cross < 0) {
			concavo = i;
			break;
		}
	}
	return concavo;
}

// Ajusta o vértice côncavo para torná-lo convexo
void ajustarVertice(float vx[], float vy[], int n, int indiceConcavo) {
	int iAnterior = (indiceConcavo - 1 + n) % n;
	int iProximo = (indiceConcavo + 1) % n;

	// Ajusta o vértice côncavo movendo-o para a média dos vizinhos
	vx[indiceConcavo] = (vx[iAnterior] + vx[iProximo]) / 2;
	vy[indiceConcavo] = (vy[iAnterior] + vy[iProximo]) / 2;
}

// Função principal que corrige os vértices côncavos
void corrigirPoligono(float vx[], float vy[], int n) {
	int concavo = verificarConcavidade(vx, vy, n);

	// Enquanto houver vértices côncavos, ajusta
	while (concavo != -1) {
		printf("\nVértice %d é côncavo. Ajustando...\n", concavo);
		ajustarVertice(vx, vy, n, concavo);
		concavo = verificarConcavidade(vx, vy, n);
	}
}

int main(void) {
	int n;
	float vx[99], vy[99];

	printf("\nDigite o valor de n: ");
	scanf("%d", &n);

	// Definir os vértices
	defVetor(n, vx, vy);

	printf("\nVértices do polígono inicial:\n");
	mostraVetor(n, vx, vy);

	// Corrigir vértices côncavos
	corrigirPoligono(vx, vy, n);

	printf("\nVértices do polígono corrigido (convexo):\n");
	mostraVetor(n, vx, vy);

	return 0;
}
