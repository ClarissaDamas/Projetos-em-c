#include <stdio.h>
 
int main(void) {
  
  int idade;
  unsigned char sexo;
  float altura;
  _Bool fazfaculdade;

  printf("qual sua idade");
  scanf("%d", &idade);

  printf("qual sua altura");
  scanf("%f", &altura);
 
  printf("qual o seu sexo");
  scanf(' %c', &sexo);

  printf("Voce faz faculdade?");
  scanf("%d", &fazfaculdade);
 
  printf("Idade: %d\nAltura: %f\nSexo: %c\nFaz faculdade: %d\n", idade, altura, sexo, fazfaculdade);
 
  return 0;
}