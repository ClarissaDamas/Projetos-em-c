#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* struct Books //vetores 
{
    float x;
    float y;
    
};

int main ()
{
    struct Books book; //aqui tenho uma estrtura composta, posso dividir para book.x e book.y e ambos vao fazer parte da estrutura book
    struct Books *bbook; //
    struct Books pagina;
    bbook = &book
}


//diferenca de estrutura com P  X ponteiro com P 

//armazena aqui 12
//para ordenadar um vetor por exemplo a gente modifica somente o endereco
//pp.x estaria errado se estou querendo apontar para um elemento em ponterio, preciso usar uma seta p->x OU *pp.x OU (*pp).x
//o ponteiro costuma ser melhor pq ocupa so 4 bytes, um normal para armazenar 2 precisaria de 4 bytes
*/
#include <stdio.h>
#include <stdlib.h>

// Função para calcular a média
float media(int n, float v[]) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

// Função para calcular a variância
float variancia(int n, float v[], float med) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += (v[i] - med) * (v[i] - med);
    }
    return soma / n;
}

int main(void) {
    float *v;
    float med, var;
    int i, n;
    
    // Entrada do número de elementos
    printf("Entre n e depois os valores:\n");
    scanf("%d", &n);

    // Alocar memória dinamicamente para armazenar 'n' floats
    v = (float *) malloc(n * sizeof(float));
    if (v == NULL) {
        printf("Falta memória\n");
        exit(1);  // Encerrar o programa se não houver memória suficiente
    }

    // Ler os valores
    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &v[i]);
    }

    // Calcular a média e a variância
    med = media(n, v);
    var = variancia(n, v, med);

    // Exibir os resultados
    printf("Média = %f Variância = %f\n", med, var);

    // Liberar a memória alocada
    free(v);

    return 0;
}


//ver todos q sao concavos e passar para convexo