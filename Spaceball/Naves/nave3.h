#include <windows.h>
#include <iostream>
#include <conio.h>

#define IZQUIERDA3 75
#define DERECHA3 77

char explocion_l13[]={' ',' ','+','+','*',' ',' ',0};
char explocion_l23[]={' ','-','-','-','-','-',' ',0};
char explocion_l33[]={' ',' ','+','+','*',' ',' ',0};

char explocion_r13[]={' ',' ','+','+','*',' ',' ',0};
char explocion_r23[]={' ','+','+','+','+','*',' ',0};
char explocion_r33[]={' ',' ','+','+','*',' ',' ',0};

char borrar_avion3[]={' ',' ',' ',' ',' ',' ',' ',0};

int Num_vidas3 = 3;
int Corazones3 = 3;
int ix3 = 40;
int iy3 = 19;

int y3 = 8 , x3 = 12;
int yy3 =12 , xx3 = 17;
int x13 = 58 , y13 = 6; 
int x23 = 70 , y23 = 9;

int i3,v3;

int dd3=0;
bool disparo3 = false;
int xb3;
// variables para rutinas de cambio de nivel
int repeticion3 = 0, nivel3 = 1;
bool condicion3 = false;

void gotoxy3(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void vidas3(int vi3)
{
    gotoxy3(2,1); printf("VIDAS %d",vi3);
}

void Barra_salud3(int n3)
{
    gotoxy3(72,1); printf(" ");
    gotoxy3(73,1); printf(" ");
    gotoxy3(74,1); printf(" ");

    for (v3=0 ;  v3 < n3 ; v3++)
    {
        gotoxy3(72+v3,1);
        printf("%c",3);//codigo asqui
    }
    
}

void Explocion3(void)
{
    gotoxy3(ix3,iy3); puts(explocion_l13);
    gotoxy3(ix3,iy3+1); puts(explocion_l23);
    gotoxy3(ix3,iy3+1); puts(explocion_l33);

    Sleep(380);   

    gotoxy3(ix3,iy3); puts(explocion_r13);
    gotoxy3(ix3,iy3+1); puts(explocion_r23);
    gotoxy3(ix3,iy3+2); puts(explocion_r33);

    Sleep(380);

    gotoxy3(ix3,iy3);   printf("  %c  ", 193);
    gotoxy3(ix3,iy3+1); printf(" %c%c%c  ",169, 124, 169);
    gotoxy3(ix3,iy3+2); printf("%c%c %c%c",221, 203, 203, 221);
}

void jugar3(void)
{
    if(!disparo3) xb3 = ix3;
    gotoxy3(xb3 + 3 , iy3 + dd3); printf("W");
    //rutina de los asteroides
    //do{
    gotoxy3(x3,y3); printf("%c",2);
    gotoxy3(xx3,yy3); printf("%c",2);
    gotoxy3(x13,y13); printf("%c",2);
    gotoxy3(x23,y23); printf("%c",2);

    Sleep(70);

    gotoxy3(x3,y3); printf(" ");
    gotoxy3(xx3,yy3); printf(" ");
    gotoxy3(x13,y13); printf(" ");
    gotoxy3(x23,y23); printf(" ");

    //rutinas disparo
    gotoxy3(xb3 + 3 , iy3 + dd3); printf(" ");
    if(disparo3 == true) dd3--;
    if (iy3 + dd3 < 5) 
    {
        dd3 = 0;
        disparo3 = false;
    }
    // rutina asteroides
    if (y3 > 20 || x3 == xb3 + 3 && iy3 + dd3 <= y3)
    {
        y3 = 4;
        x3 = (rand()% 70) +6;

        if (y3==4)
            condicion3 =false;
    }
    if(yy3 > 20 || x3 == xb3 + 3 && iy3 + dd3 <= yy3)
    {
        yy3 = 4;
        xx3 = (rand()% 70) +6;
    }
    if(y13 > 20 || x3 == xb3 + 3 && iy3 + dd3 <= y13)
    {
        y13 = 4;
        x13 = (rand()% 70) +6;
    }
    if(y23 > 20 || x3 == xb3 + 3 && iy3 + dd3 <= y23)
    {
        y23 = 4;
        x23 = (rand()% 70) +6;
    }
    //rutina de movimiento de la nave
    if(kbhit())
    {
        unsigned char tecla3 = getch();
        
        switch(tecla3)
        {
            case IZQUIERDA3:

                if ( x3 > 4)
                {
                    gotoxy3(ix3,iy3); puts(borrar_avion3);
                    gotoxy3(ix3,iy3+1); puts(borrar_avion3);
                    gotoxy3(ix3,iy3+2); puts(borrar_avion3);

                    ix3 -=2; //ix = ix-2;

                    gotoxy3(ix3,iy3);   printf("  %c  ", 193);
                    gotoxy3(ix3,iy3+1); printf(" %c%c%c  ",169, 124, 169);
                    gotoxy3(ix3,iy3+2); printf("%c%c %c%c",221, 203, 203, 221);
                }
                break;

            case DERECHA3:

               if ( ix3 < 78)
                {
                    gotoxy3(ix3,iy3); puts(borrar_avion3);
                    gotoxy3(ix3,iy3+1); puts(borrar_avion3);
                    gotoxy3(ix3,iy3+2); puts(borrar_avion3);

                    ix3 +=2; //ix = ix+2;

                    gotoxy3(ix3,iy3);   printf("  %c  ", 193);
                    gotoxy3(ix3,iy3+1); printf(" %c%c%c  ",169, 124, 169);
                    gotoxy3(ix3,iy3+2); printf("%c%c %c%c",221, 203, 203, 221);
                } 
                break;

            case 's':
                disparo3 = true;
                break;
                
        } //switch
    } //if

    //rutina de los choques con los asteroides
    if( (x3 > ix3 && x3 < ix3 + 6 && y3 == iy3 -1) || (xx3 > ix3 && xx3<ix3 + 6 && yy3 == iy3-1) 
    ||(x13 > ix3 && x13 < ix3 + 6 && y13 == iy3 -1 ) || (x23 > ix3 && x23<ix3 +6 && y23 == iy3-1))     
    {
        Corazones3 --;
        Barra_salud3(Corazones3);
        printf("\a");
    }
    
    gotoxy3(ix3,iy3);   printf("  %c  ", 193);
    gotoxy3(ix3,iy3+1); printf(" %c%c%c  ",169, 124, 169);
    gotoxy3(ix3,iy3+2); printf("%c%c %c%c",221, 203, 203, 221);

    if(!Corazones3)
    {
        Num_vidas3--;
        vidas3(Num_vidas3);
        Explocion3();
        Corazones3 = 3;

        Barra_salud3(Corazones3);
    }

    //rutina para cambio de nivel
    if (!condicion3)
    {
        repeticion3 ++;
        condicion3 = true;
    }
    //tiempo de nivel
    if (repeticion3 == 10)
    {
        nivel3++;
        gotoxy3(35,1);
        printf("NIVEL %i", nivel3);

        gotoxy3(ix3, iy3); puts(borrar_avion3);
        gotoxy3(ix3, iy3+1); puts(borrar_avion3);
        gotoxy3(ix3, iy3+2); puts(borrar_avion3);
    
        iy3 -= 2;

        gotoxy3(ix3,iy3);   printf("  %c  ", 193);
        gotoxy3(ix3,iy3+1); printf(" %c%c%c  ",169, 124, 169);
        gotoxy3(ix3,iy3+2); printf("%c%c %c%c",221, 203, 203, 221);
    
        repeticion3 = 0;
    }
    
    
    y3++;
    yy3++;
    y13++;
    y23++;

    //}while(1);
}


void ejecutar3(char nickname[]){
    
    vidas3(Num_vidas3);
    Barra_salud3(Corazones3);
    gotoxy3(35,1); printf("NIVEL %i", nivel3);

    gotoxy3(ix3,iy3);   printf("  %c  ", 193);
    gotoxy3(ix3,iy3+1); printf(" %c%c%c  ",169, 124, 169);
    gotoxy3(ix3,iy3+2); printf("%c%c %c%c",221, 203, 203, 221);
    //Explocion();
    while(Num_vidas3 > 0 && nivel3 <= 6)
        jugar3();

    if (Num_vidas3 == 0)
    {
        gotoxy3(20,15); printf("Game Over");
    }
    else if (Num_vidas3 > 0 && nivel3 == 7)
    {
        gotoxy3(20,15); printf("%s Has ganado!!!!",nickname);
    }
    
    Sleep(200);
    getch();
}
