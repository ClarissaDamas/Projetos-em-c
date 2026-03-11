typedef struct ponto Ponto;
//O ponto cria, ele cria e atribui, o correto seria uma funcao que cria ele vazio e outra que atribui
Ponto* Ponto_cria (float x , float y);
//libera um ponto
void Ponto_libera (Ponto* p);
//Acessa os valores "x" e "y" de um ponto
int Ponto_acessa(Ponto* p, float* x, float* y);
//atribui os valores "x" e "y" ao ponto
int Ponto_atribui (Ponto* p , float x, float y)
//calcula a distancia de 2 pontos
float Ponto_distancia(Ponto* p1, Ponto* p2);
