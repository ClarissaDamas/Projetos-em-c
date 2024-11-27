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
        prev = NULL;

        while (atual->next != fim) {
            if (atual->f < atual->next->f) { // Troca os nós
                stElem *prox = atual->next;
                atual->next = prox->next;
                prox->next = atual;

                if (prev)
                    prev->next = prox;
                else
                    lst->first = prox;

                trocou = 1;
                prev = prox;
            } else {
                prev = atual;
                atual = atual->next;
            }
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
stElem *geraArvoreHauff(stLst *lst) {
    while (lst->n > 1) {
        // Pegue os dois primeiros nós com menor frequência
        stElem *primeiro = lst->first;
        stElem *segundo = primeiro->next;

        // Crie um novo nó pai
        stElem *novo = (stElem *)malloc(sizeof(stElem));
        novo->c = '*'; // Nó interno
        novo->f = primeiro->f + segundo->f;
        novo->filhoE = primeiro;
        novo->filhoD = segundo;
        novo->next = NULL;

        // Atualize a lista
        lst->first = segundo->next;
        lst->n -= 2;

        // Insira o novo nó na lista
        stElem *aux = lst->first, *prev = NULL;
        while (aux && aux->f < novo->f) {
            prev = aux;
            aux = aux->next;
        }
        if (prev) prev->next = novo;
        else lst->first = novo;
        novo->next = aux;

        lst->n++;
    }
    return lst->first; // A raiz da árvore
}
void imprimeArvoreECodigos(stElem *raiz, char *codigo, int profundidade, int nivel) {
    if (!raiz) return;

    // Percorre a subárvore direita (para mostrar a estrutura da árvore invertida)
    imprimeArvoreECodigos(raiz->filhoD, codigo, profundidade + 1, nivel + 1);

    // Mostra a árvore com indentação
    for (int i = 0; i < nivel; i++) 
        printf("    ");
    if (raiz->c == '*') // Nó interno
        printf("* (%d)\n", raiz->f);
    else // Nó folha
        printf("%c (%d)\n", raiz->c, raiz->f);

    // Se for folha, imprime o código correspondente
    if (!raiz->filhoE && !raiz->filhoD) {
        codigo[profundidade] = '\0';
        printf("Código para '%c': %s\n", raiz->c, codigo);
    }

    // Percorre a subárvore esquerda
    codigo[profundidade] = '0';
    imprimeArvoreECodigos(raiz->filhoE, codigo, profundidade + 1, nivel + 1);

    // Percorre a subárvore direita
    codigo[profundidade] = '1';
    imprimeArvoreECodigos(raiz->filhoD, codigo, profundidade + 1, nivel + 1);
}
int main (void)
{
	FILE *pArq;           // declaração de váriavel de ponteiro de Arquivo
	stLst lst;
	stElem *raiz;
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
	printf("Lista de Frequência:\n");
	mostraList(&lst);
	
	raiz = geraArvoreHauff(&lst);
	
	char codigo[256];
    printf("\nÁrvore de Huffman e Códigos:\n");
    imprimeArvoreECodigos(raiz, codigo, 0, 0);
	
	eliminaLista(&lst);
	
	return 0;
}
