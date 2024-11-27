#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Elem { 
    char c; 
	int  f;
	struct Elem *next;
} stElem;

typedef struct Lst 
{  
	int  n;
	stElem *first;
} stLst;

typedef struct tamanho {
    Elemento elementos[30]; // Tamanho máximo definido como 30
    int tamanho;
} sttamanho;


stElem *buscaAtualiza(stLst *lst,char cc, int *sw){

	stElem *prev = NULL;
    stElem *current = lst->first;
    while (current) {
        if (current->c == cc) {
            current->f += 1;
            *sw = 1;
            return prev;
        }
        prev = current;
        current = current->next;
    }
    *sw = 0;
    return prev;
}

void insereList (stLst *lst, char cc)
{
	stElem *noA, *noNovo;
	int sw=0;
	
	noA = buscaAtualiza(lst,cc,&sw);
	if(sw==0){
		noNovo = (stElem*) malloc(sizeof(stElem));
		noNovo->c = cc;
		noNovo->f = 1;
		lst->n +=1;
		if(noA){
			noNovo->next = noA->next;
			noA->next = noNovo;
		}
		else {
			noNovo->next = lst->first;
			lst->first = noNovo;
		}
	}
}

void mostraList(stLst *lst){
	stElem *node;
	node = lst->first; 
	while (node) {
		printf("\n %c: %d ", node->c,node->f);
		node = node->next;
	}
}

void eliminaLista(stLst *lst) {
	stElem *node;
	while (lst->first) {
		node = lst->first;
		lst->first = node->next;
		free(node);
		lst->n -= 1;
	}
}

int main (void)
{
	FILE *pArq;           // declaração de váriavel de ponteiro de Arquivo
	stLst lst;
	char alf;            // declara uma lista não inicializada
	lst.n = 0;            // cria e inicializa lista como vazia
	lst.first = NULL;     // nulo
	
	pArq = fopen("textoProg2lista.txt","r");
	if(!pArq){
		printf("\n Arquivo com problema ... \n");
		exit(1);
	}				
	
	while(fscanf(pArq, "%c", &alf) != EOF) {
		insereList(&lst, alf);
		
	}
	fclose(pArq);
	
	mostraList(&lst);
	
	eliminaLista(&lst);
	
	return 0;
}