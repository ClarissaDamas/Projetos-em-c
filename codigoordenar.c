#include <stdio.h>

void bubbleSort(int *array, int tamanho) {
    int i, j, temp;

    // Usando dois loops para percorrer o array
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            // Usando ponteiros para acessar e comparar os elementos
            if (*(array + j) > *(array + j + 1)) {
                // Troca de valores usando ponteiros
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

int main() {
    int lista[] = {5, 2, 9, 1, 5, 6};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int i;

    printf("Lista antes da ordenação:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", *(lista + i)); // Usando ponteiro para acessar o elemento
    }
    
    bubbleSort(lista, tamanho); // Ordenando a lista

    printf("\n\nLista depois da ordenação:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", *(lista + i)); // Usando ponteiro para acessar o elemento
    }

    return 0;
}
