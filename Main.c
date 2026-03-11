#include <stdio.h>
#include <stdlib.h>
#include "estruturadados_1103_pontoH.c"

int main () {
	float d;
	Ponto *p , *q;
	p = Ponto_cria (10,21);
	q = Ponto_cria (7,25);
	d = Ponto_distancia (p,q);
	printf("distancia ente pontos: %f\n" , d);
	Ponto_libera (q);
	Ponto_libera (p);
	system ("pausa");
	return 0;
}
