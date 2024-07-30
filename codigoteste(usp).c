#include <stdio.h> // biblioteca standard de Input/Output
#include <stdlib.h> //Contém funções para conversão de números, alocação de memória 
//nao consigo executar as duas funcoes, elas separadamente funcionam, mas juntas da erro

void alfabeto() {

    char c;
    c = 's';
    printf("c");
    printf(" %c", c);
    scanf(" %c/n",&c);

}


void somando() {

    unsigned char j = 255;
    //int a = 2, b;
    j = j + 10;
    //b = a++ //a++ primeiro o B assume o valor de a, e depois spma
    //b = ++a //++a primeiro soma o valor de a, e esse vai ser o novo valor de b
    printf("%u", j);
  
}

void main() {

    somando();
    alfabeto();

}

 // fim main
