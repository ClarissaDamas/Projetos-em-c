//cap 4 Arquivo Ponto c

#incluse <stdlib.h>
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



