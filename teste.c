#include <stdio.h>

void pedirnumero(int x) {
    int *p;
    p = &x;
    //*p = 2;
    printf("O valor vai ser %d", x);
}

int main()
{
    int x;
    printf("Qual o numero?");
    scanf("%d",&x);
    pedirnumero(x);
}

/* variaveis dinamicas crescem como uma pilha inversa, ou seja crescem para baixo. Enquanto que as locais sao uma pilha de execucao que cresce para cima
video sobre alocacao de memoria para python https://www.youtube.com/watch?v=Iwe3AULLFHM
Para ter alocacao dinamica eu uso MALLOC ou CALLOC, isso vai criar uma variavel que pode ser eliminada depois usando FREE
se eu nao tenho espaco disponivel ele vai retornar NULL, se tiver ele vai indicar o espaco
*/

