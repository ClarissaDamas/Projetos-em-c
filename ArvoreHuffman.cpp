#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


typedef struct Elem {
	char c; //caractere
	int  f; //frequencia do caractere
	int i; //posiçao do elemento
	int ind; //vinculo pai e filho(0,1)
	struct Elem *next, *pai, *filhoE, *filhoD;
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

void eliminaLista(stLst *lst) {
	stElem *node;
	while (lst->first) {
		node = lst->first;
		lst->first = node->next;
		free(node);
		lst->n -= 1;
	}
}

void ordenaLista(stLst *lst) {
    if (lst->first == NULL) {
        printf("Lista vazia\n");
        return;
    }
    if (lst->first->next == NULL) {
        printf("Lista com um elemento\n");
        return;
    }

    int trocou;
    int auxF;
    char auxC;

    do{
        trocou = 0;
        stElem *atual = lst->first;
        stElem *proximo = atual->next;

        while (proximo != NULL) {
            if (atual->f > proximo->f) {

                auxF = atual->f;
                atual->f = proximo->f;
                proximo->f = auxF;

                auxC = atual->c;
                atual->c = proximo->c;
                proximo->c = auxC;

                trocou = 1;
            }
            atual = proximo;
            proximo = proximo->next;
        }

    }while (trocou);
}




void criaArvore(stLst *lst){
    while(lst->n > 1){
        stElem *atual = lst->first;        //pega os 2 primeiros com menor freq
        stElem *proximo = atual->next;

        stElem noPai = (stElem) malloc(sizeof(stElem));
        noPai->c = '\0'; //nao tem caractere
        noPai->f = atual->f + proximo->f;
        noPai->filhoE = atual; // Filho esquerdo
        noPai->filhoD = proximo; // Filho direito
        noPai->next = NULL;

        //filhos apontando pro pai
        atual->pai=noPai;
        proximo->pai=noPai;

        //remover da lista
        lst->first = proximo->next;
        lst->n = lst->n - 2;

        //coloca o pai na lista
        atual = lst->first;
        stElem *anterior = NULL;
        while(atual && atual->f < noPai->f){
            anterior=atual;
            atual=atual->next;
            //for(int i; i<lst->n; i++){
            printf("inserindo noPai com f = %d\n", noPai->f);
            //}
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
    setlocale(LC_ALL, "Portuguese");
	FILE *pArq;			// declarcao de variavel de ponteiro dearquivo
	stLst lst;   		// declara uma lista não inicializada
	char alf;
	lst.n = 0;   		// cria e inicializa lista como vazia
	lst.first = NULL;  	// nulo

	pArq = fopen("textoProg2lista.txt","r");
	if(!pArq){
		printf("\n arquivo en referenica com problema...");
		exit(1);
	}

	while(!feof(pArq)) {
		fscanf(pArq, "%c ", &alf); printf("%c", alf);
		insereLista(&lst, alf);
	}
	fclose(pArq);

    printf("\nlista antes da ordenacao: ");
	mostraLista(&lst);

	ordenaLista(&lst);

	criaArvore(&lst);

	printf("\nLista depois de ordenar: ");
	mostraLista(&lst);

	eliminaLista(&lst);

	return 0;
}
