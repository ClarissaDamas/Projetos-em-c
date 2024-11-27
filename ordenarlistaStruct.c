//menor frequencia primeiro e maior frequencia por ultimo

#include <stdio.h>
#include <string.h>

// Definindo a estrutura para armazenar um caractere e seu valor
typedef struct {
    char caractere;
    int valor;
} Elemento;

// Definindo a estrutura para armazenar a lista de elementos
typedef struct {
    Elemento elementos[30]; // Tamanho máximo definido como 30
    int tamanho;
} Lista;

// Função para ordenar a lista usando Bubble Sort (ordem decrescente)
void bubbleSort(Lista *lst) {
    int i, j;
    Elemento temp;

    // Algoritmo Bubble Sort para ordem decrescente
    for (i = 0; i < lst->tamanho - 1; i++) {
        for (j = 0; j < lst->tamanho - i - 1; j++) {
            // Comparação dos valores para ordem decrescente
            if (lst->elementos[j].valor < lst->elementos[j + 1].valor) {
                // Troca dos elementos se o valor atual for menor que o próximo
                temp = lst->elementos[j];
                lst->elementos[j] = lst->elementos[j + 1];
                lst->elementos[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Inicializando a lista de elementos
    Lista lst = {
        .elementos = {
            {'A', 1}, {' ', 104}, {'c', 44}, {'i', 45}, {'e', 67},
            {'n', 29}, {'a', 81}, {'d', 32}, {'o', 65}, {'m', 24},
            {'p', 29}, {'u', 22}, {'t', 38}, {'b', 5}, {'s', 55},
            {'r', 30}, {'f', 5}, {' ', 9},  {'v', 2},  {',', 9},
            {'g', 5}, {'l', 14}, {'.', 4},  {'N', 2},  {'x', 2},
            {'z', 1}, {'M', 1},  {'q', 2},  {'Ú', 1}
        },
        .tamanho = 30 // Tamanho atual da lista
    };

    // Imprimindo a lista antes de ordenar
    printf("Lista antes de ordenar:\n");
    for (int i = 0; i < lst.tamanho; i++) {
        printf("%c: %d\n", lst.elementos[i].caractere, lst.elementos[i].valor);
    }
    printf("\n");

    // Ordenando a lista usando Bubble Sort (ordem decrescente)
    bubbleSort(&lst);

    // Imprimindo a lista após ordenar
    printf("Lista após ordenar (do maior para o menor):\n");
    for (int i = 0; i < lst.tamanho; i++) {
        printf("%c: %d\n", lst.elementos[i].caractere, lst.elementos[i].valor);
    }

    return 0;
}
