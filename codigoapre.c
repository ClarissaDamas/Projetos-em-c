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
		printf("\n ( caractere %c   frequencia %d )", node->c,node->f);
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

stElem *ReordenaArvoreHuffman(stLst *lst) {
    while (lst->n > 1) { //Número de elementos na lista
        // Pegue os dois primeiros nós com menor frequência
        stElem *primeiro = lst->first; //Ponteiro para o primeiro elemento da lista
        stElem *segundo = primeiro->next;

        // Crie um novo nó pai
        stElem *novo = (stElem *)malloc(sizeof(stElem));
        novo->c = '+'; // Este nó representa um nó interno na árvore de Huffman, marcado com o caractere especial 
        novo->f = primeiro->f + segundo->f;
        novo->filhoE = primeiro;
        novo->filhoD = segundo;
        novo->next = NULL;

        // Decremento da lista
        lst->first = segundo->next; 
        lst->n -= 2; 

        // compara frequencia dos NOS com a existente do novo NO e coloca na posicao certa
        stElem *encontrapos = lst->first, *prev = NULL; //Enquanto a frequência de aux nao for nula, ainda precisa ver os NOS
        while (encontrapos && encontrapos->f < novo->f) {
            prev = encontrapos;
            encontrapos = encontrapos->next;
        }
        if (prev) {
            prev->next = novo;
        } else {
            lst->first = novo;
        }
        novo->next = encontrapos;

        lst->n += 1;
    }
    return lst->first; // Retorna a raiz da árvore
}
// Função para gerar os códigos de Huffman
void geraCodigosHuffman(stElem *raiz, char *valorcode, int seta) {
    if (!raiz) return;

    // Nó folha
    if (!raiz->filhoE && !raiz->filhoD) {
        valorcode[seta] = '\0';
        printf("VALOR %s\n '%c':" , valorcode, raiz->c);
        return;
    }

    // Recorre para os filhos
    valorcode[seta] = '0';
    geraCodigosHuffman(raiz->filhoE, valorcode, seta + 1); //se ela segue o esquerdo adiciona 

    valorcode[seta] = '1';
    geraCodigosHuffman(raiz->filhoD, valorcode, seta + 1);
}
void printarvorehuffman(stElem *raiz, int nivel) { //nessa funcao primeiro percorre direito depois esquerdo
    if (!raiz) return;

    // Percorre a subárvore direita primeiro (para mostrar invertida)
    printarvorehuffman(raiz->filhoD, nivel + 1);

    // Imprime o nível atual
    for (int i = 0; i < nivel; i++) 
        printf("    "); // O nível do nó é indicado por 4 espaços
    if (raiz->c == '+') // Nó interno
        printf("* (%d)\n", raiz->f);
    else // Se o nó não tiver filhos (filhoE e filhoD são nulos), é um nó folha
        printf("%c (%d)\n", raiz->c, raiz->f);

    // Percorre a subárvore esquerda
    printarvorehuffman(raiz->filhoE, nivel + 1);
}
// Função para liberar a memória da árvore
void liberaArvore(stElem *raiz) {
    if (!raiz) return;
    liberaArvore(raiz->filhoE);
    liberaArvore(raiz->filhoD);
    free(raiz);
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
	
	//ORDENACAO
	ordenaPorFrequencia(&lst);
	printf("Lista de Frequência:\n");
	mostraList(&lst);
	
	
	//ARVORE HUFFMAN
    raiz = ReordenaArvoreHuffman(&lst);
    printf("\n ARVORE HUFFMAN \n");
    printarvorehuffman(raiz, 0);
    char codigo[256];
    geraCodigosHuffman(raiz, codigo, 0);

    liberaArvore(raiz);

	eliminaLista(&lst);
	
	return 0;
}