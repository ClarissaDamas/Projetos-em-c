#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void defVetor(int n, int vx[], int vy[]) {
    // Cria os vértices do polígono.
    for(int i = 0; i < n; i++) {
        vx[i] = rand() % 201 - 100;  // Gera coordenadas entre -100 e 100
        vy[i] = rand() % 201 - 100;
    }    
}

void mostraVetor(int n, int vx[], int vy[]) {
    // Mostra as coordenadas dos vértices.
    printf("\nVértices do polígono:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", vx[i], vy[i]);
    }
}

int main() {
    int n;
    printf("Digite o número de vértices: ");
    scanf("%d", &n);

    int vx[n], vy[n];

    defVetor(n, vx, vy);
    mostraVetor(n, vx, vy);

    return 0;
}
void organizaPoli(int n, int vx[], int vy[]) {
    // Organiza os vértices do polígono em sentido anti-horário.
    double angulos[n];
    for (int i = 0; i < n; i++) {
        angulos[i] = atan2(vy[i], vx[i]);  // Calcula o ângulo do ponto
    }

    // Bubble sort para organizar os pontos pelos ângulos
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (angulos[j] > angulos[j + 1]) {
                // Troca os ângulos
                double tempAngulo = angulos[j];
                angulos[j] = angulos[j + 1];
                angulos[j + 1] = tempAngulo;

                // Troca as coordenadas dos vértices
                int tempX = vx[j], tempY = vy[j];
                vx[j] = vx[j + 1];
                vy[j] = vy[j + 1];
                vx[j + 1] = tempX;
                vy[j + 1] = tempY;
            }
        }
    }
}

int main() {
    int n;
    printf("Digite o número de vértices: ");
    scanf("%d", &n);

    int vx[n], vy[n];

    defVetor(n, vx, vy);
    printf("\nVértices do polígono antes de organizar:");
    mostraVetor(n, vx, vy);

    organizaPoli(n, vx, vy);
    printf("\nVértices do polígono organizados em sentido anti-horário:");
    mostraVetor(n, vx, vy);

    return 0;
}
int verificaConvexidade(int n, int vx[], int vy[]) {
    int concavo = 0;  // Flag para verificar se há ângulo côncavo
    for (int i = 0; i < n; i++) {
        // Vértices consecutivos
        int x1 = vx[i], y1 = vy[i];
        int x2 = vx[(i + 1) % n], y2 = vy[(i + 1) % n];
        int x3 = vx[(i + 2) % n], y3 = vy[(i + 2) % n];

        // Vetores
        int v1x = x2 - x1, v1y = y2 - y1;
        int v2x = x3 - x2, v2y = y3 - y2;

        // Produto vetorial
        int crossProduct = v1x * v2y - v1y * v2x;

        if (crossProduct < 0) {
            concavo = 1;  // Se houver um ângulo côncavo, marca como 1
        }
    }
    return concavo;
}

int main() {
    int n;
    printf("Digite o número de vértices: ");
    scanf("%d", &n);

    int vx[n], vy[n];

    defVetor(n, vx, vy);
    organizaPoli(n, vx, vy);

    mostraVetor(n, vx, vy);

    int concavo = verificaConvexidade(n, vx, vy);
    if (concavo) {
        printf("\nO polígono tem pelo menos um ângulo côncavo.\n");
    } else {
        printf("\nTodos os ângulos do polígono são convexos.\n");
    }

    return 0;
}
