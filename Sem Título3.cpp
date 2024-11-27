
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Elem { 
    char c;     // caractere 
	int  f;    // frequência do caractere
	int i;     // posição do elemento da lista
	int ind;   //vínculo filho e pai (0,1)
	struct Elem *next, *pai, *filhoE, *filhoD;
} stElem;

typedef struct Lst 
{  
	int  n;
	stElem *first;
} stLst;

stElem *buscaAtualiza(stLst *lst, char cc, int *sw){
      stElem *noAnt=NULL, *no;
      no = lst->first;
      while(no) {
      if(no->c == cc) {
      no->f += 1;
      *sw = 1;
      break;
    }
    else{
    if(no-> c < cc){
    noAnt = no;
    no = noAnt->next;
   }
     else{
     break;
   }
 }
}
 return (noAnt);
}
void insereLista (stLst *lst, char cc)
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
void ordenaPorFrequencia(stLst *lst) {
    int trocou;
    stElem *atual, *prev = NULL, *fim = NULL;

    do {
        trocou = 0;
        atual = lst->first;

        while (atual->next != fim) {
            if (atual->f < atual->next->f) {  // Se a frequência é menor, troca os nós
                // Troca os valores dos nós
                char tempC = atual->c;
                int tempF = atual->f;

                atual->c = atual->next->c;
                atual->f = atual->next->f;
                atual->next->c = tempC;
                atual->next->f = tempF;

                trocou = 1;
            }
            atual = atual->next;
        }
        fim = atual;
    } while (trocou);
}
void mostraList(stLst *lst){
	stElem *node;
	node = lst->first; 
	while (node) {
		printf("\n ( %c: %d )", node->c,node->f);
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
//stList *geraArvoreHauff(stLst *lst)

	
void criaArvore(stLst *lst){
    while(lst->n > 1){
        stElem *atual = lst->first;        //pega os 2 primeiros com menor freq
        stElem *proximo = atual->next;

        stElem noPai = (stElem) malloc(sizeof(stElem));
        noPai->f = atual->f + proximo->f;
        noPai->filhoE = atual; 
        noPai->filhoD = proximo; 
        noPai->next = NULL;
        atual->pai=noPai;
        proximo->pai=noPai;

        
        if(atual) {atual = lst->first;
        stElem *anterior = NULL;
        }
        else{
        while(atual && atual->f < noPai->f){
            anterior=atual;
            atual=atual->next;
        }
        if(anterior){
            anterior->next=noPai;
        }else{
            lst->first = noPai;
        }
        noPai->next = atual;
        lst->n = lst->n +1; //um no a mais na lista
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
		insereLista(&lst, alf);
		
	}
	fclose(pArq);
	
	ordenaPorFrequencia(&lst);
	mostraList(&lst);
	
	criaArvore(&lst);

	printf("\nLista depois de ordenar: ");
	mostraLista(&lst);
	
	eliminaLista(&lst);
	
	return 0;
}









