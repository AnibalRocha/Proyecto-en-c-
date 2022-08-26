## Descripción
       Este proyecto es un juego el cual permite al usuario eliminar el aburrimiento que tenga en ese momento, mejorando a la vez sus reflejos y habilidades de percepcion del entorno.

## Estado del proyecto
        El proyecto se encuentra completo y tiene finalizada la etapa de programación de funcionamiento de la nave y los menus de seleccion. En un futuro se podrian mejorar algunos aspectos y añadir mas mecanicas pero por el momento cumple para lo que fue diseñado ser un medio de entretenimiento ligero y facil de usar que permitan al usuario eliminar el aburrimiento y a su vez mejorar en sus reflejos junto con la velocidad de percepcion del entorno.

## ¿Cómo instalar/ejecutar Spaceball?
        Se debe utilizar el siguiente link para obtener el juego y poderlo instalar:
		https://github.com/AnibalRocha/Proyecto-en-c-.git

## ¿Cómo funciona el Menu de Spaceball?
  	Primero para empezar a programar usamos las siguientes librerias:
		#include <stdio.h>
		#include <iostream>
		#include <conio.h>
		#include <windows.h>
	Siendo estas librerias del compilador, pero ademas tenemos librerias propias creadas por nosotros.
		#include "../lib/menu.cpp" 
		#include "../lib/ComoJugarcopy.h"
		#include "../lib/Colores.h"
		#include "../lib/Titulo.h"
		
	Lo primero que se tuvo que hacer es crear una variable de tipo char llamada Nickname la cual va a almacenar el alias del jugador.
	Una vez con eso podemos crear lo que seria el Titulo de nuestro juego para darle una mejor estetica el cual se encuentra en la libreria Titulo.h.
	
	Ahora si vamos a crear una barra de carga para que de la sensacion de un videojuego. Se llamo a esta funcion "void barrita()":
	------------------------------------------------------------------------------------------
	void barrita(){
    for(int i=0; i<40; i++){
        
        printf("\n\n\n\t\t\t\tCargando...\n");
        printf("\t\t========================================\n");
        printf("\t\t");
        for (int j = 0; j < i; j++){
            printf("X");
            
        }
        printf("\n\t\t========================================\n");
        retardado();
        system("cls");
    }
	------------------------------------------------------------------------------------------
	Dentro de este void se usa un "void retardado()" el cual nos permite darle tiempo de duracion a la barra de carga:
	------------------------------------------------------------------------------------------
	void retardado(){
    for(int i=0; i<5000;i++){
        for(int j=0; j<5000;j++){
        }
    }
	
	Ahora se procede a crear el procedimiento "void MENU()" el cual contiene a una funcion de la libreria llamada "Menu" la que a su vez contiene deiferentes void  con los nombres de las naves a elegir. Cada una de estas naves funciona con una libreria diferente para que no haya ningun error al momento de ejecutar. El codigo base de estas naves se explicara mas adelante.
	
	En el menu ademas tenemos dos opciones que muestran instrucciones y funcionalidad del juego. 
	La primera se llama "void INDICACIONES()" en la que esta contenido un proceso de la libreria "Comojugarcopy.h" el proceso en cuestion se llama "Comojugar" y funciona con un parametro llamado Nickname, el cual explicamos al inicio. Este proceso consta ademas de un int x el cual nos va a servir para seleccionar con una funcion "switch" una opcion la cual nos envia al menu de naves. Es un proceso sencillo que usa la funcion "printf()" para indicar el mensaje solicitado y no tiene complicacione.
	La segunda se llama "void Controles()"no voy a explicar mucho sobre este proceso ya que es identico al anterior solo que presenta un mensaje diferente.
	
	Y por ultimo pero no menos importante "Salir" el cual no es un void como tal sino una parte del switch que contiene a todo el menu, si lo seleccionamos con el numero 4 simplemente se cerrara el programa.
---------------------------------------------------------------------------------------------
## Posibles Fallos
        Existe la posibilidad de que en el registro se ingrese un nuevo usuario con la información en distinto orden al establecido, lo que puede producir un error al leer los datos.

        Un posible error, se puede dar al cambiar de dirección el archivo "base.txt".

        Un bug consciente en este proyecto, es la ausencia de un bloqueo luego del 3er intento erroneo del PIN, ya que se puede volver a ingresar al policajero e intentar 3 veces más.
        
        
        
        #SpaceBall
El juego esta diseñado de un juego de naves programado en c++, en el cual se utilizarán bucles del tipo for, y while, además se hará uso de las clases, funciones.

Primero se crearon las funciones para el escenario, posteriormente se crearon clases para cada objeto del juego, que serían: Nave, asteroide, disparo, vidas. Cada clase tiene sus respectivas funciones y métodos que posterior mente fueron llamados en la rutina principal, en la cual mediante condiciones se logra dar vida al juego.
##Juego de la Nave

- Se ha utilizado las siguientes librerias para el uso y control de la NAVE ,#include <windows.h>, #include <iostream>, #include <conio.h>
 1. *Declaracion de la coordenas de la nave*
 -Se ha utilizado el gotoxy para las posiciones de las naves, al igual con un printf se presenta la nave con caracteres especiales, para la creacion de dicha Nave. 
 ```c
 gotoxy4(ix4,iy4);   printf("  %c  ", 202);
    gotoxy4(ix4,iy4+1); printf(" %c%c%c  ",204, 206, 185);
    gotoxy4(ix4,iy4+2); printf("%c%c %c%c",200, 205, 202, 205, 188);
 ```
 2. *Animacion de la nave*
 -Consiste en desarrollar la animación cuando topa un objeto, la nave procedera a explotar. Se ha creado una declaración con un *char explocion_l1* y *char explocion_r1*, la finalidad de esta declaracion es de almacenar todos los caracter presentando en una sola linea de codigo.
 ```c
 char explocion_l14[]={' ',' ','+','+','*',' ',' ',0};
char explocion_l24[]={' ','-','-','-','-','-',' ',0};
char explocion_l34[]={' ',' ','+','+','*',' ',' ',0};
```
```c
char explocion_r14[]={' ',' ','+','+','*',' ',' ',0};
char explocion_r24[]={' ','+','+','+','+','*',' ',0};
char explocion_r34[]={' ',' ','+','+','*',' ',' ',0};
 ```
 3. *Declaración para borrar el avion*
 -Tiene como finalidad de presentar solo una linea de codigo con la finalidad de borrar la nave en la posicion que se encuentre del eje x, eje y. Eliminando la posición de la nave.
 ```c
 char borrar_avion4[]={' ',' ',' ',' ',' ',' ',' ',0};
 ```
 4. *Declaración para la animacion de vida y coordenas de limites de la nave*
 -Se deberea declarar en posiciones de coordenas, marcando limites del juego, ademas, se añadira la declaración de la vida y corazones que nos servira en la interacción del juego.
 ### Contador de vidas
 ```c
 int Num_vidas4 = 3;
int Corazones4 = 3;
int ix4 = 40;
int iy4 = 19;
 ```
 ### Cordenas de posición
  ```c
int y4 = 8 , x4 = 12;
int yy4 =12 , xx4 = 17;
int x14 = 58 , y14 = 6; 
int x24 = 70 , y24 = 9;
 ```
  ```c
int i4,v4;
 ```
  ```c
int dd4=0;
bool disparo4 = false;
int xb4;
 ```
 ## void gotoxy(int x, int y)
 Esta función tiene como finalidad de marcar las posiciones de la nave.
 - *HANDLE* .-El recurso utilizado cuando un programa hace referencia a bloques de memoria u objetos que son administrados
 - "COORD" .- Define las coordenadas de una celda de carácter en un buffer de pantalla de consola
```c
HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
```
### void vidas();
-Su finalidad es de que la función cumpla en la posicion que deseemos, ademas, se ha declarado  en un mensaje de representacion de la vida.
```c
gotoxy4(2,1); printf("VIDAS %d",vi4);
```
 ### void jugar();
 -Tiene como objetivo dar toda la animacion, accion y con lleva toda la interfaz del juego, comenzando en el desarrollo:
 	-Disparo
	```c
	if(!disparo4) xb4 = ix4;
    gotoxy4(xb4 + 3 , iy4 + dd4); printf("W");
 	```
	-Rutinas de disparo
	```c
	gotoxy4(xb4 + 3 , iy4 + dd4); printf(" ");
    if(disparo4 == true) dd4--;
    if (iy4 + dd4 < 5) 
    {
        dd4 = 0;
        disparo4 = false;
    }
	```
	
	* Asteroidos
	-Tiene como finalidad en caer en una posicion de la coordenada del eje y, ademas de eso vuelve a aparecen, pero apareciendo en la +4 posicion en el eje x, entrando a una rutina.
	```c
	if (y4 > 20 || x4 == xb4 + 3 && iy4 + dd4 <= y4)
    {
        y4 = 4;
        x4 = (rand()% 70) +6;

        if (y4==4)
            condicion4 =false;
    }
	:
	:
	```
	* Movimiento de la nave
-Se procede en entrar a una condicional de if y swicht
- El proceso es de que la nave pueda desplazarse dentro del swicht pueda moverse de izquierda y derecha
-Ademas se crea un case, cuando el jugador presione una letra S, la nave dispare su Bala.
```c
 if(kbhit())
    {
        unsigned char tecla4 = getch();
        
        switch(tecla4)
        {
            case IZQUIERDA4:

                if ( x4 > 4)
                {
                    gotoxy4(ix4,iy4); puts(borrar_avion4);
                    gotoxy4(ix4,iy4+1); puts(borrar_avion4);
                    gotoxy4(ix4,iy4+2); puts(borrar_avion4);

                    ix4 -=2; //ix = ix-2;

                    gotoxy4(ix4,iy4);   printf("  %c  ", 202);
                    gotoxy4(ix4,iy4+1); printf(" %c%c%c  ",204, 206, 185);
                    gotoxy4(ix4,iy4+2); printf("%c%c %c%c",200, 205, 202, 205, 188);
                }
                break;

            case DERECHA4:

               if ( ix4 < 78)
                {
                    gotoxy4(ix4,iy4); puts(borrar_avion4);
                    gotoxy4(ix4,iy4+1); puts(borrar_avion4);
                    gotoxy4(ix4,iy4+2); puts(borrar_avion4);

                    ix4 +=2; //ix = ix+2;

                    gotoxy4(ix4,iy4);   printf("  %c  ", 202);
                    gotoxy4(ix4,iy4+1); printf(" %c%c%c  ",204, 206, 185);
                    gotoxy4(ix4,iy4+2); printf("%c%c %c%c",200, 205, 202, 205, 188);
                } 
                break;

            case 's':
                disparo4 = true;
                break;
                
        } //switch
    }
```

Como finalidad se tiene el la escrtuctura madre para el momento de ejecutarse.
```c
void ejecutar4(char nickname[]){
    
    vidas4(Num_vidas4);
    Barra_salud4(Corazones4);
    gotoxy4(35,1); printf("NIVEL %i", nivel4);

    gotoxy4(ix4,iy4);   printf("  %c  ", 202);
    gotoxy4(ix4,iy4+1); printf(" %c%c%c  ",204, 206, 185);
    gotoxy4(ix4,iy4+2); printf("%c%c %c%c",200, 205, 202, 205, 188);
    //Explocion();
    while(Num_vidas4 > 0 && nivel4 <= 6)
        jugar4();

    if (Num_vidas4 == 0)
    {
        gotoxy4(20,15); printf("Game Over");
    }
    else if (Num_vidas4 > 0 && nivel4 == 7)
    {
        gotoxy4(20,15); printf("%s Has ganado!!!!",nickname);
    }
    Sleep(200);
    getch();
}

```

##Conclusion y recomendaciones.
Como resultado final se tiene un juego de naves, que se logró mediante animaciones simples que en realidad son bucles, concluyendo que se puede lograr un juego mediante conceptos básicos de programación, se rescata como aprendizaje que a la hora de hacer el código verificar bien los signos manteniendo un orden, ya que un mínimo error conlleva a que no se pueda compilar el juego, y en el peor de los casos como pasó en la elaboración de este proyecto, que se compile y haya una ejecución defectuosa del juego.
