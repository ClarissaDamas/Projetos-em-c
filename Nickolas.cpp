#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    char c[99];      // Caracter (string de at  99 caracteres)
    int f;           // Frequ ncia de caractere
    int i;           // Posi  o do elemento na lista
    int ind;         // V nculo filho e pai (0, 1)
    struct Elem *next, *pai, *filhoE, *filhoD;
} stElem;

typedef struct Lst {
    int n;           // N mero de elementos
    stElem *first;   // Ponteiro para o primeiro elemento da lista
} stLst;

stElem *buscaAtualiza(stLst *lst, char cc, char *sw) {
    stElem *noAnt = NULL, *no;
    no = lst->first;
    while (no) {
        if(no->c[0] == cc) {
            no->f += 1;
            *sw = 1;
            break;
        }
        else if(no->c[0] < cc) {
            noAnt = no;
            no = noAnt->next;
        }
        else {
            break;
        }
    }
    return (noAnt);
}

void insereLista(stLst *lst, char cc) {
    stElem *noA, *noNovo;
    char sw = 0;
    noA = buscaAtualiza(lst, cc, &sw);
    if(sw == 0) {
        noNovo = (stElem*) malloc(sizeof(stElem));
        noNovo->c[0] = cc;
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

void mostraLista(stLst *lst) {
    stElem *node;
    node = lst->first;
    while (node) {
        printf("\n ( %c: %d ) ", node->c[0], node->f);
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
    char auxC[1];
    stElem *i, *j;
    for (i = lst->first; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (j->f < i->f) {
                auxC[0] = i->c[0];
                i->c[0] = j->c[0];
                j->c[0] = auxC[0];

                int auxF = i->f;
                i->f = j->f;
                j->f = auxF;
            }
        }
    }
}

void insereNoOrdenado(stLst *lst, stElem *novo) {
    stElem *atual = lst->first;
    stElem *ant = NULL;

    while (atual && atual->f < novo->f) {
        ant = atual;
        atual = atual->next;
    }
    if (ant) {
        ant->next = novo;
    } else {
        lst->first = novo;
    }
    novo->next = atual;

    lst->n += 1;
}

void concatenaCaracteres(stElem *novo, stElem *filhoE, stElem *filhoD) {
    char i = 0, j = 0;

    // Copia os caracteres do filho esquerdo (filhoE)
    while (i < 99 && filhoE->c[i] != '\0') {
        novo->c[i] = filhoE->c[i];
        i++;
    }

    // Copia os caracteres do filho direito (filhoD)
    while (j < 99 && filhoD->c[j] != '\0') {
        novo->c[i] = filhoD->c[j];
        i++; j++;  // Avan a no vetor de novo->c e no vetor filhoD
    }

    // Garante que a string termine com '\0'
    novo->c[i] = '\0';
}

stElem *geraArvoreHuff(stLst *lst) {
    stElem *primeiro = lst->first;
    stElem *segundo = primeiro ? primeiro->next : NULL;
    stElem *novo;

    while (lst->n > 1) {
        if (primeiro != NULL && segundo != NULL) {
            novo = malloc(sizeof(stElem));  // Aloca mem ria para o novo n 

            if (novo) {
                novo->f = primeiro->f + segundo->f;
                novo->filhoE = primeiro;
                novo->filhoD = segundo;
                novo->pai = NULL;
                novo->next = NULL;


                primeiro->pai = novo;
                segundo->pai = novo;


                lst->first = segundo->next;
                lst->n -= 2;

                concatenaCaracteres(novo, primeiro, segundo);

                insereNoOrdenado(lst, novo);
            } else {
                printf("\nProblema na aloca  o...Na fun  o geraArvoreHuff\n");
                break;
            }
        }
        // Atualiza os ponteiros
        primeiro = lst->first;
        segundo = primeiro ? primeiro->next : NULL;
    }

    return lst->first;  // Retorna o n  raiz da  rvore
}

void imprimirArvore(stElem *raiz, char tam) {
    if (raiz == NULL) {
        return;
    }

    // Imprimir a string completa armazenada em raiz->c
    printf("\tRaiz: %s\n\tFrequencia: %d\tAltura: %d\n", raiz->c, raiz->f, tam);

    // Imprime os filhos (caso existam)
    imprimirArvore(raiz->filhoE, tam + 1);
    imprimirArvore(raiz->filhoD, tam + 1);
}

int main(void) {
    FILE *pArq;
    stLst lst;
    char alf;
    lst.n = 0;
    lst.first = NULL;

    pArq = fopen("textoProg2lista.txt", "r");
    if (!pArq) {
        printf("\nArquivo em refer ncia com problema...\n");
        exit(1);
    }

    while (!feof(pArq)) {
        fscanf(pArq, "%c", &alf);
        printf("\n %c ", alf);
        if (alf >= ' ' && alf <= '~') {
            insereLista(&lst, alf);
        }
    }
    fclose(pArq);

    printf("\n\n---ORDENADO POR CARACTERE---\n\n");
    mostraLista(&lst);

    printf("\n\n---ORDENADO POR FREQUENCIA---\n\n");
    ordenaLista(&lst);
    mostraLista(&lst);

    printf("\n\n---ARVORE---\n\n");
    stElem *arvore;
    arvore = geraArvoreHuff(&lst);
    imprimirArvore(arvore, 0);

    eliminaLista(&lst);

    return 0;
}
