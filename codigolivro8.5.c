#include <stdio.h>
#include <conio.h>

void exibe(int c, int x, int y) {
    _gotoxy(x,y);
    putchar(c);
}

void retangulo (int x1, int y1, int x2,int y2, int c) {
    int x, y;
    _textcolor(c);
    exibe(218, x1, y1); exibe(191, x2, y1);
    exibe(192,x1,y2); exibe(217,x2,y2);
    for (x = x1 +1; x<=x2-1;x++) {
        exibe(196,x,y1);
        exibe(196,x,y2);
}
for (y=y1+1;)