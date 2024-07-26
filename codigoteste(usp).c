#include <stdio.h> // biblioteca standard de Input/Output
#include <stdlib.h> //Contém funções para conversão de números, alocação de memória 

int main(void) {
    int idade = scanf("Qual sua idade?");
    char nome = scanf("Qual o seu nome?");
    float peso = scanf("Qual o seu peso?");
    _Bool faz_faculdade = scanf("faz faculdade?");
    printf("%d %c %f %c", idade, nome, peso, faz_faculdade);
} // fim main
