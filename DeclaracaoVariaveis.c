#include <stdio.h>
 
int main(void) {
  // Declara uma variável inteira chamada "idade" e atribui o valor 25
  int idade;
  printf("qual sua idade");
  scanf("%d", &idade);
 
  // Declara uma variável de ponto flutuante chamada "altura" e atribui o valor 1.80
  float altura = 1.80;
 
  // Declara uma variável de caractere chamada "sexo" e atribui o valor 'M'
  char sexo = 'M';
 
  // Declara uma variável booleana chamada "casado" e atribui o valor verdadeiro
  _Bool fazfaculdade = 1;
 
  printf("Idade: %d\nAltura: %f\nSexo: %c\nFaz faculdade: %d\n", idade, altura, sexo, fazfaculdade);
 
  return 0;
}