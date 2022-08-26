#include <windows.h>
#include <iostream>
#include <conio.h>


#define IZQUIERDA 75
#define DERECHA 77

char explocion_l1[]={' ',' ','+','+','*',' ',' ',0};
char explocion_l2[]={' ','-','-','-','-','-',' ',0};
char explocion_l3[]={' ',' ','+','+','*',' ',' ',0};

char explocion_r1[]={' ',' ','+','+','*',' ',' ',0};
char explocion_r2[]={' ','+','+','+','+','*',' ',0};
char explocion_r3[]={' ',' ','+','+','*',' ',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};

int Num_vidas = 3;
int Corazones = 3;
int ix = 40;
int iy = 19;

int y = 8 , x = 12;
int yy =12 , xx = 17;
int x1 = 58 , y1 = 6; 
int x2 = 70 , y2 = 9;

int i,v;

int dd=0;
bool disparo = false;
int xb;
// variables para rutinas de cambio de nivel
int repeticion = 0, nivel = 1;
bool condicion = false;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
void gotoxy(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void vidas(int vi)
{
    SetConsoleTextAttribute(hConsole, 2); 
    gotoxy(2,1); printf("VIDAS %d",vi);
    SetConsoleTextAttribute(hConsole, 15); 
}

void Barra_salud(int n)
{
    
    gotoxy(72,1); printf(" ");
    gotoxy(73,1); printf(" ");
    gotoxy(74,1); printf(" ");

    for (v=0 ;  v < n ; v++)
    {
        gotoxy(72+v,1);
        SetConsoleTextAttribute(hConsole, 4); 
        printf("%c",3);//codigo asqui
        SetConsoleTextAttribute(hConsole, 15); 
    }
    
}

void Explocion(void)
{
    
    SetConsoleTextAttribute(hConsole, 14); 
    gotoxy(ix,iy); puts(explocion_l1);// referenciamos a la consola.
    gotoxy(ix,iy+1); puts(explocion_l2);
    gotoxy(ix,iy+1); puts(explocion_l3);

    Sleep(380);   
   
    SetConsoleTextAttribute(hConsole, 4); 
    gotoxy(ix,iy); puts(explocion_r1);
    gotoxy(ix,iy+1); puts(explocion_r2);
    gotoxy(ix,iy+2); puts(explocion_r3);

    Sleep(380);
  
    SetConsoleTextAttribute(hConsole, 10); 
    gotoxy(ix,iy);   printf("  %c  ", 30);
    gotoxy(ix,iy+1); printf(" %c%c%c  ",40, 207, 41);
    gotoxy(ix,iy+2); printf("%c%c %c%c",30, 190, 190, 30);

    SetConsoleTextAttribute(hConsole, 15); 
}

void jugar(void)
{
   
    if(!disparo) xb = ix;
    gotoxy(xb + 3 , iy + dd); printf("W");
    //rutina de los asteroides
    //do{
    gotoxy(x,y); printf("%c",2);
    gotoxy(xx,yy); printf("%c",2);
    gotoxy(x1,y1); printf("%c",2);
    gotoxy(x2,y2); printf("%c",2);

    Sleep(70);

    gotoxy(x,y); printf(" ");
    gotoxy(xx,yy); printf(" ");
    gotoxy(x1,y1); printf(" ");
    gotoxy(x2,y2); printf(" ");

    //rutinas disparo
    gotoxy(xb + 3 , iy + dd); printf(" ");
    if(disparo == true) dd--;
    if (iy + dd < 5) 
    {
        dd = 0;
        disparo = false;
    }
    // rutina asteroides
    if (y > 20 || x == xb + 3 && iy + dd <= y)
    {
        y = 4;
        x = (rand()% 70) +6;

        if (y==4)
            condicion =false;
    }
    if(yy > 20 || x == xb + 3 && iy + dd <= yy)
    {
        yy = 4;
        xx = (rand()% 70) +6;
    }
    if(y1 > 20 || x == xb + 3 && iy + dd <= y1)
    {
        y1 = 4;
        x1 = (rand()% 70) +6;
    }
    if(y2 > 20 || x == xb + 3 && iy + dd <= y2)
    {
        y2 = 4;
        x2 = (rand()% 70) +6;
    }
    //rutina de movimiento de la nave
    if(kbhit())
    {
        unsigned char tecla = getch();
        
        switch(tecla)
        {
            case IZQUIERDA:

                if ( x > 4)
                {
                    gotoxy(ix,iy); puts(borrar_avion);
                    gotoxy(ix,iy+1); puts(borrar_avion);
                    gotoxy(ix,iy+2); puts(borrar_avion);

                    ix -=2; //ix = ix-2;
   
    SetConsoleTextAttribute(hConsole, 10); 
                    gotoxy(ix,iy);   printf("  %c  ", 30);
                    gotoxy(ix,iy+1); printf(" %c%c%c  ",40, 207, 41);
                    gotoxy(ix,iy+2); printf("%c%c %c%c",30, 190, 190, 30);
    SetConsoleTextAttribute(hConsole, 15);                    
                }
                break;

            case DERECHA:

               if ( ix < 78)
                {
                    gotoxy(ix,iy); puts(borrar_avion);
                    gotoxy(ix,iy+1); puts(borrar_avion);
                    gotoxy(ix,iy+2); puts(borrar_avion);

                    ix +=2; //ix = ix+2;
   
    SetConsoleTextAttribute(hConsole, 10); 
                    gotoxy(ix,iy);   printf("  %c  ", 30);
                    gotoxy(ix,iy+1); printf(" %c%c%c  ",40, 207, 41);
                    gotoxy(ix,iy+2); printf("%c%c %c%c",30, 190, 190, 30);
 
    SetConsoleTextAttribute(hConsole, 15);                     
                } 
                break;

            case 's':
                disparo = true;
                break;
                
        } //switch
    } //if

    //rutina de los choques con los asteroides
    if( (x > ix && x < ix + 6 && y == iy -1) || (xx > ix && xx<ix + 6 && yy == iy-1) 
    ||(x1 > ix && x1 < ix + 6 && y1 == iy -1 ) || (x2 > ix && x2<ix +6 && y2 == iy-1))     
    {
        Corazones --;
        Barra_salud(Corazones);
        printf("\a");
    }
   
    SetConsoleTextAttribute(hConsole, 10); 
    gotoxy(ix,iy);   printf("  %c  ", 30);
    gotoxy(ix,iy+1); printf(" %c%c%c  ",40, 207, 41);
    gotoxy(ix,iy+2); printf("%c%c %c%c",30, 190, 190, 30);
   
    SetConsoleTextAttribute(hConsole, 15); 
    if(!Corazones)
    {
        Num_vidas--;
        vidas(Num_vidas);
        Explocion();
        Corazones = 3;

        Barra_salud(Corazones);
    }

    //rutina para cambio de nivel
    if (!condicion)
    {
        repeticion ++;
        condicion = true;
    }
    //tiempo de nivel
    if (repeticion == 10)
    {
        nivel++;
        gotoxy(35,1);
        printf("NIVEL %i", nivel);

        gotoxy(ix, iy); puts(borrar_avion);
        gotoxy(ix, iy+1); puts(borrar_avion);
        gotoxy(ix, iy+2); puts(borrar_avion);
    
        iy -= 2;
  
    SetConsoleTextAttribute(hConsole, 10); 
        gotoxy(ix,iy);   printf("  %c  ", 30);
        gotoxy(ix,iy+1); printf(" %c%c%c  ",40, 207, 41);
        gotoxy(ix,iy+2); printf("%c%c %c%c",30, 190, 190, 30);

    SetConsoleTextAttribute(hConsole, 15);     
        repeticion = 0;
    }
    
    
    y++;
    yy++;
    y1++;
    y2++;

    //}while(1);
}


void ejecutar1(char nickname[]){
    
    vidas(Num_vidas);
    Barra_salud(Corazones);
    gotoxy(35,1); printf("NIVEL %i", nivel);
  
    SetConsoleTextAttribute(hConsole, 2); 
    gotoxy(ix,iy);   printf("  %c  ", 30);
    gotoxy(ix,iy+1); printf(" %c%c%c  ",40, 207, 41);
    gotoxy(ix,iy+2); printf("%c%c %c%c",30, 190, 190, 30);
;   
    SetConsoleTextAttribute(hConsole, 15);     
    //Explocion();
    while(Num_vidas > 0 && nivel <= 6)
        jugar();

    if (Num_vidas == 0)
    {
        gotoxy(20,15); printf("Game Over");
    }
    else if (Num_vidas > 0 && nivel == 7)
    {
        gotoxy(20,15); printf("%s Has ganado!!!!",nickname);
    }

    Sleep(200);
    getch();
}
