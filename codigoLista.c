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

stElem *buscaAtualiza(stLst *lst, char cc, int *sw) {
	stElem *noAnt = NULL, *no;
	no = lst->first;
	while (no) {
		if(no->c == cc) {
			no->f +=1;
			*sw = 1;
			break;
		} 
		else
		if(no->c < cc) {
			noAnt = no;
			no = noAnt->next;
		}
		else {
			break;
		}
	}
	return (noAnt);
}

void insereLista (stLst *lst, char cc)
{
	stElem *noA, *noNovo;
	int sw=0;
	noA = buscaAtualiza(lst, cc, &sw);
	if(sw==0) {
		noNovo = (stElem*) malloc(sizeof(stElem));
		noNovo->c = cc;
		noNovo->f = 1;
		lst->n += 1;
		if(noA) {
			noNovo->next = noA->next;
			noA->next = noNovo;
		}
		else {
			noNovo->next = lst->first;
			lst->first = noNovo;
		}			
	}
}

void mostraLista(stLst *lst){
	stElem *node;
	node = lst->first; 
	while (node) {
		printf("\n ( %c: %d ) ", node->c, node->f);
		node = node->next;
	}
}

void ordenaLista(*lista, ){
	  int i, j, temp;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (*(lista + j) > *(lista + j + 1)) {
                // Troca de valores usando ponteiros
                temp = *(lista + j);
                *(lista + j) = *(lista + j + 1);
                *(lista + j + 1) = temp;
            }
        }
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
	FILE *pArq;			// declarcao de variavel de ponteiro dearquivo
	stLst lst;   		// declara uma lista não inicializada
	char alf;
	lst.n = 0;   		// cria e inicializa lista como vazia
	lst.first = NULL;  	// nulo
	
	pArq = fopen("prog2Texto.txt","r");
	if(!pArq){
		printf("\n arquivo en referencia com problema...");
		exit(1);
	}
	
	while(!feof(pArq)) {
		fscanf(pArq, "%c", &alf); printf("\n %c ", alf);
		insereLista(&lst, alf);
	}
	fclose(pArq);
    mostraLista(&lst);
    ordenaLista(&lst); //criar essa funcao
	
	mostraLista(&lst);
	
	eliminaLista(&lst);
	
	return 0;
}

