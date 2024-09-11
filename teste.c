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
