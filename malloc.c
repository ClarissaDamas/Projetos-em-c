#include <stdlib.h>
#include <stdio.h>

float media(int n, float v[]){
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma/n;
}

int main(void) {
    float *v;
    float med;
    int i, n;

    //entrada de elementos
    printf("Entre n e depois os valores \n");
    scanf("%d",&n);

    //alocacao dinamica da memoria
    v = (float*) malloc(n*sizeof(float));
    if (v == NULL) {
        printf("falta memoria\n");
        exit(1);
    }

    //ler os valores
    for(i=0; i<n ;i++) {
        printf("Digite o valor %d", i+1);
        scanf("%f",&v[i]);

    }
    //chamar funcao
    med = media(n,v);

    //mostrar resultado ao usuario
     printf("Media = %f\n", med);

     //liberar memoria alocada
    free(v);

    return(0);
}



