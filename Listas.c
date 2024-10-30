#include <stdlib.h>
#include <math.h>
//EXEMPLO DE LISTA ENCADEADA 

Typedef struct Elem {
    int info;
    struct Elem* prox;
} stElem;

typedef struct Lst  {
    int n;
    stElem* no;
}  stLst;


stLst* lst_cria(void) {  //esse vai ser o segundo, o endereco Lis
    stlst lis*
    //recomendado fazer a operacao abaixo para devolver, e pedir um espaco
    lis = (stlst*)malloc(sizeof(stLst)) //se nao tiver o numero de vezes vai ser o tamanho minimo
    //vou inicializar e adicionar n, para adicionar n a lista vou ter que usar a setinha
    lis -> n = 0;
    lis -> no = NULL;
    return (lis);
}

stElem* lst_insere(stLst *lst, int val){
    stElem *novo = (stElem*) malloc(sizeof(stElem));
    novo -> info = val;  //novo esta definido como ponteiro, entao para acessar ele preciso usar uma seta
    novo -> prox = lst -> no;
    lst -> n += 1;
    return novo;
}

void ls (stElem* lst) {
    stElem *node;

    //fazer while, enquanto for diferente de vazio for diferente de vazio 
    while (node){
        printf("\n %d", node->info);

    }
}

int main(void) {
//o primeiro elemento vai ser LST,inicialmente ele vai ter lixo
//como criei ele 
    stLst* lst;
    lst = lst_cria();
    lst->no = lst_insere(lst, 23);
    lst->no = lst_insere(lst, 45);
    lstMostraElem(lst);
    return 0 ;

}

//pegar como no o elemento, enquanto esse no for diferente do vazio devemos continuar
