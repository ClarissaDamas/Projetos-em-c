#include <stdio.h>
#include <string.h>

// Definindo a estrutura para armazenar um caractere e seu valor
typedef struct {
    char caractere;
    int valor;
} Elemento;

// Função para ordenar a lista usando Bubble Sort (ordem decrescente)
void bubbleSort(Elemento lista[], int tamanho) {
    int i, j;
    Elemento temp;

    // Algoritmo Bubble Sort para ordem decrescente
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            // Comparação dos valores para ordem decrescente
            if (lista[j].valor < lista[j + 1].valor) {
                // Troca dos elementos se o valor atual for menor que o próximo
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Array contendo os dados fornecidos
    Elemento lista[] = {
        {'A', 1}, {' ', 104}, {'c', 44}, {'i', 45}, {'e', 67},
        {'n', 29}, {'a', 81}, {'d', 32}, {'o', 65}, {'m', 24},
        {'p', 29}, {'u', 22}, {'t', 38}, {'b', 5}, {'s', 55},
        {'r', 30}, {'f', 5}, {' ', 9},  {'v', 2},  {',', 9},
        {'g', 5}, {'l', 14}, {'.', 4},  {'N', 2},  {'x', 2},
        {'z', 1}, {'M', 1},  {'q', 2},  {'Ú', 1}
    };
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    // Imprimindo a lista antes de ordenar
    printf("Lista antes de ordenar:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%c: %d\n", lista[i].caractere, lista[i].valor);
    }
    printf("\n");

    // Ordenando a lista usando Bubble Sort (ordem decrescente)
    bubbleSort(lista, tamanho);

    // Imprimindo a lista após ordenar
    printf("Lista após ordenar (do maior para o menor):\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%c: %d\n", lista[i].caractere, lista[i].valor);
    }

    return 0;
}