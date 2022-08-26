#include<stdio.h>
#include<windows.h>


#define color SetConsoleTextAttribute


void Color(int colorTexto)
{     // los colores van del 0 al 255 por eso se multiplica por 16
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   // referenciamos a la consola.
    color(hConsole, colorTexto); 
}

/*
BLACK	        0	Negro	Ambos
BLUE	        1	Azul	Ambos
GREEN	        2	Verde	Ambos
CYAN	        3	Cían	Ambos
RED	            4	Rojo	Ambos
MAGENTA	        5	Magenta	Ambos
BROWN	        6	Marrón	Ambos
LIGHTGRAY	    7	Gris Claro	Ambos
DARKGRAY	    8	Gris Oscuro	Sólo para texto
LIGHTBLUE	    9	Azul Claro	Sólo para texto
LIGHTGREEN  	10	Verde Claro	Sólo para texto
LIGHTCYAN	    11	Cían Claro	Sólo para texto
LIGHTRED	    12	Rojo Claro	Sólo para texto
LIGHTMAGENTA	13	Magenta Claro	Sólo para texto
YELLOW	        14	Amarillo	Sólo para texto
WHITE	        15	Blanco	Sólo para texto
BLINK	        128	Parpadeo	Sólo para texto
*/