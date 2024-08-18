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

void operadorternario () {

    int a = 5, b = 6, c = 3, f;
    f = (a == b)?b:c;
    printf("%d",f);

    }


void vetor() {

    //int vet[10];
    int vet[10] = {2,34,5,87,9,10,55,6,2,1}; //eu so posso declarar assim com os valores quando estou declarando pela primeira vez
    printf("%d", vet[3]);

}

void acessarmatriz() {

    //para isso vou usar o FOR
    int vet[10] = {2,34,5,87,9,10,55,6,2,1}; //eu so posso declarar assim com os valores quando estou declarando pela primeira vez
    int i;
    for(i=0;i<10;i++){
        printf("%d ", vet[i]);
    }

}


void main() {

    //operadorternario();
    acessarmatriz();

}

 
