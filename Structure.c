#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Books //vetores 
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