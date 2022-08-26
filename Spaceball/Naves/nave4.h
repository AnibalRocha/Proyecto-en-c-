#include <windows.h>
#include <iostream>
#include <conio.h>

#define IZQUIERDA4 75
#define DERECHA4 77

char explocion_l14[]={' ',' ','+','+','*',' ',' ',0};
char explocion_l24[]={' ','-','-','-','-','-',' ',0};
char explocion_l34[]={' ',' ','+','+','*',' ',' ',0};

char explocion_r14[]={' ',' ','+','+','*',' ',' ',0};
char explocion_r24[]={' ','+','+','+','+','*',' ',0};
char explocion_r34[]={' ',' ','+','+','*',' ',' ',0};

char borrar_avion4[]={' ',' ',' ',' ',' ',' ',' ',0};

int Num_vidas4 = 3;
int Corazones4 = 3;
int ix4 = 40;
int iy4 = 19;

int y4 = 8 , x4 = 12;
int yy4 =12 , xx4 = 17;
int x14 = 58 , y14 = 6; 
int x24 = 70 , y24 = 9;

int i4,v4;

int dd4=0;
bool disparo4 = false;
int xb4;
// variables para rutinas de cambio de nivel
int repeticion4 = 0, nivel4 = 1;
bool condicion4 = false;

void gotoxy4(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void vidas4(int vi4)
{
    gotoxy4(2,1); printf("VIDAS %d",vi4);
}

void Barra_salud4(int n4)
{
    gotoxy4(72,1); printf(" ");
    gotoxy4(73,1); printf(" ");
    gotoxy4(74,1); printf(" ");

    for (v4=0 ;  v4 < n4 ; v4++)
    {
        gotoxy4(72+v4,1);
        printf("%c",3);//codigo asqui
    }
    
}

void Explocion4(void)
{
    gotoxy4(ix4,iy4); puts(explocion_l14);
    gotoxy4(ix4,iy4+1); puts(explocion_l24);
    gotoxy4(ix4,iy4+1); puts(explocion_l34);

    Sleep(380);   

    gotoxy4(ix4,iy4); puts(explocion_r14);
    gotoxy4(ix4,iy4+1); puts(explocion_r24);
    gotoxy4(ix4,iy4+2); puts(explocion_r34);

    Sleep(380);

    gotoxy4(ix4,iy4);   printf("  %c  ", 202);
    gotoxy4(ix4,iy4+1); printf(" %c%c%c  ",204, 206, 185);
    gotoxy4(ix4,iy4+2); printf("%c%c %c%c",200, 205, 202, 205, 188);
}

void jugar4(void)
{
    if(!disparo4) xb4 = ix4;
    gotoxy4(xb4 + 3 , iy4 + dd4); printf("W");
    //rutina de los asteroides
    //do{
    gotoxy4(x4,y4); printf("%c",2);
    gotoxy4(xx4,yy4); printf("%c",2);
    gotoxy4(x14,y14); printf("%c",2);
    gotoxy4(x24,y24); printf("%c",2);

    Sleep(70);

    gotoxy4(x4,y4); printf(" ");
    gotoxy4(xx4,yy4); printf(" ");
    gotoxy4(x14,y14); printf(" ");
    gotoxy4(x24,y24); printf(" ");

    //rutinas disparo
    gotoxy4(xb4 + 3 , iy4 + dd4); printf(" ");
    if(disparo4 == true) dd4--;
    if (iy4 + dd4 < 5) 
    {
        dd4 = 0;
        disparo4 = false;
    }
    // rutina asteroides
    if (y4 > 20 || x4 == xb4 + 3 && iy4 + dd4 <= y4)
    {
        y4 = 4;
        x4 = (rand()% 70) +6;

        if (y4==4)
            condicion4 =false;
    }
    if(yy4 > 20 || x4 == xb4 + 3 && iy4 + dd4 <= yy4)
    {
        yy4 = 4;
        xx4 = (rand()% 70) +6;
    }
    if(y14 > 20 || x4 == xb4 + 3 && iy4 + dd4 <= y14)
    {
        y14 = 4;
        x14 = (rand()% 70) +6;
    }
    if(y24 > 20 || x4 == xb4 + 3 && iy4 + dd4 <= y24)
    {
        y24 = 4;
        x24 = (rand()% 70) +6;
    }
    //rutina de movimiento de la nave
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
    } //if

    //rutina de los choques con los asteroides
    if( (x4 > ix4 && x4 < ix4 + 6 && y4 == iy4 -1) || (xx4 > ix4 && xx4<ix4 + 6 && yy4 == iy4-1) 
    ||(x14 > ix4 && x14 < ix4 + 6 && y14 == iy4 -1 ) || (x24 > ix4 && x24<ix4 +6 && y24 == iy4-1))     
    {
        Corazones4 --;
        Barra_salud4(Corazones4);
        printf("\a");
    }
    
    gotoxy4(ix4,iy4);   printf("  %c  ", 202);
    gotoxy4(ix4,iy4+1); printf(" %c%c%c  ",204, 206, 185);
    gotoxy4(ix4,iy4+2); printf("%c%c %c%c",200, 205, 202, 205, 188);

    if(!Corazones4)
    {
        Num_vidas4--;
        vidas4(Num_vidas4);
        Explocion4();
        Corazones4 = 3;

        Barra_salud4(Corazones4);
    }

    //rutina para cambio de nivel
    if (!condicion4)
    {
        repeticion4 ++;
        condicion4 = true;
    }
    //tiempo de nivel
    if (repeticion4 == 10)
    {
        nivel4++;
        gotoxy4(35,1);
        printf("NIVEL %i", nivel4);

        gotoxy4(ix4, iy4); puts(borrar_avion4);
        gotoxy4(ix4, iy4+1); puts(borrar_avion4);
        gotoxy4(ix4, iy4+2); puts(borrar_avion4);
    
        iy4 -= 2;

        gotoxy4(ix4,iy4);   printf("  %c  ", 202);
        gotoxy4(ix4,iy4+1); printf(" %c%c%c  ",204, 206, 185);
        gotoxy4(ix4,iy4+2); printf("%c%c %c%c",200, 205, 202, 205, 188);
    
        repeticion4 = 0;
    }
    
    
    y4++;
    yy4++;
    y14++;
    y24++;

    //}while(1);
}


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
