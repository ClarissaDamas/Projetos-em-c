//cap 4 Arquivo Ponto c

#include <stdlib.h>
#include <math.h>
#include "Ponto.h" //inclui os prototipos
struct ponto{//definicao do tipo de dados
float x;
float y;
} ;

//Criando um ponto
Ponto* Ponto_cria (float x, float y){
  Ponto* p = (Ponto*) malloc (sizeof (Ponto)); //Nao entendi bem
if (p != NULL) {
  p -> x = x;
  p -> y = y;
}

return p;
}

//Destruindo um ponto

void Ponto_libera (Ponto* p) {
  free (p);
}

//Acessando conteudo de um ponto

int Ponto_acessa (Ponto* p, float* x, float* y) {
  if (p == NULL)
  return 0;
  *x = p -> x;
  *y = p -> y;
  return 1;
}

//atribuindo um valor ao ponto 

int Ponto_atribui (Ponto* p, float x, float y) {
  if(p == NULL)
  return 0;
  p -> x = x;
  p -> y = y;
  return 1;
}

//calculando a distancia dos pontos

float Ponto_distancia (Ponto* p1, Ponto* p2){  //por que float e nao int como os outros?
  if (p1 == NULL || p2 == NULL) //por que nao tem ponto e virgula?
    return -1;

  float dx = p1 -> x - p2 -> x;
  float dy  = p1 -> y - p2 -> y; 

  return sqrt(dx * dx + dy * dy);
}
    


