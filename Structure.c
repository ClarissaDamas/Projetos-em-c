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
int main ( void )
{
    float *v;
    float med, var;
    int i,n;
    printf("Entre n e depois os valores\n");
    scanf("%d",&n);
    v = (float *) malloc(n*sizeof(float));
    if (v==NULL) { printf(“Falta memoria\n”); exit(1); }
    for ( i = 0; i < n; i++ )
    scanf("%f", &v[i]);

    med = media(n,v);
    var = variancia(n,v,med);

    printf ( "Media = %f Variancia = %f \n", med, var);
    free(v);
    return 0;
}

//ver todos q sao concavos e passar para convexo