#include <stdio.h>

#define MAX_LADOS 100  // Definindo um número máximo de lados para o polígono

void alterar_para_concavo(double angulos[], int num_lados) {
    for (int i = 0; i < num_lados; i++) {
        if (angulos[i] < 180.0) {
            angulos[i] = 181.0;  // Alterando um dos ângulos internos para ser maior que 180 graus
            break;
        }
    }
}

double soma_angulos_internos(int num_lados) {
    return (num_lados - 2) * 180.0;  // Fórmula da soma dos ângulos internos de um polígono
}

int main() {
    int num_lados;
    double angulos[MAX_LADOS];

    // Solicitando o número de lados do polígono
    printf("Digite o número de lados do polígono: ");
    scanf("%d", &num_lados);

    // Garantindo que o número de lados seja válido
    if (num_lados < 3) {
        printf("Um polígono deve ter pelo menos 3 lados.\n");
        return 1;
    }

    // Calculando e exibindo a soma dos ângulos internos
    double soma_angulos = soma_angulos_internos(num_lados);
    printf("Soma dos ângulos internos de um polígono convexo: %.2f graus\n", soma_angulos);

    // Inicializando todos os ângulos com um valor típico para um polígono convexo
    for (int i = 0; i < num_lados; i++) {
        angulos[i] = soma_angulos / num_lados;
    }

    // Exibindo os ângulos iniciais
    printf("Ângulos internos do polígono convexo:\n");
    for (int i = 0; i < num_lados; i++) {
        printf("Ângulo %d: %.2f graus\n", i + 1, angulos[i]);
    }

    // Alterando um ângulo para transformar o polígono em c
