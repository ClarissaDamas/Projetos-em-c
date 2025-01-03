#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Elem { 
    char c;     // caractere 
	int  f;    // frequ�ncia do caractere
	int i;     // posi��o do elemento da lista
	int ind;   //v�nculo filho e pai (0,1)
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
            if (atual->f < atual->next->f) {  
                
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

void geraCodigosHuffman(stElem *raiz, char *codigo, int profundidade) {
    if (!raiz) return;

    // N� folha
    if (!raiz->filhoE && !raiz->filhoD) {
        codigo[profundidade] = '\0';
        printf("Caractere '%c': C�digo %s\n", raiz->c, codigo);
        return;
    }

    // Recorre para os filhos
    codigo[profundidade] = '0';
    geraCodigosHuffman(raiz->filhoE, codigo, profundidade + 1);

    codigo[profundidade] = '1';
    geraCodigosHuffman(raiz->filhoD, codigo, profundidade + 1);
}
void imprimeArvore(stElem *raiz, int nivel) {
    if (!raiz) return;

    // Percorre a sub�rvore direita primeiro (para mostrar invertida)
    imprimeArvore(raiz->filhoD, nivel + 1);

    // Imprime o n�vel atual
    for (int i = 0; i < nivel; i++) 
        printf("    "); // Adiciona 4 espa�os por n�vel
    if (raiz->c == '*') // N� interno
        printf("* (%d)\n", raiz->f);
    else // N� folha
        printf("%c (%d)\n", raiz->c, raiz->f);

    // Percorre a sub�rvore esquerda
    imprimeArvore(raiz->filhoE, nivel + 1);
}
// Fun��o para liberar a mem�ria da �rvore
void liberaArvore(stElem *raiz) {
    if (!raiz) return;
    liberaArvore(raiz->filhoE);
    liberaArvore(raiz->filhoD);
    free(raiz);
}


	
int main (void)
{
	FILE *pArq;           // declara��o de v�riavel de ponteiro de Arquivo
	stLst lst;
	stElem *raiz;
	char alf;            // declara uma lista n�o inicializada
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
	printf("Lista de Frequ�ncia:\n");
	mostraList(&lst);
	
    // Gera a �rvore de Huffman
    raiz = geraArvoreHuffman(&lst);
    
    // Mostra a estrutura da �rvore
    printf("\n�rvore de Huffman:\n");
    imprimeArvore(raiz, 0);
	
	// Mostra os c�digos de Huffman
    char codigo[256];
    printf("\nC�digos de Huffman:\n");
    geraCodigosHuffman(raiz, codigo, 0);

    // Libera mem�ria
    liberaArvore(raiz);

	eliminaLista(&lst);
	
	return 0;
}
