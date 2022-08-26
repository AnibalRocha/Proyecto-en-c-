#include <windows.h>
#include <iostream>
#include <conio.h>

#define IZQUIERDA2 75
#define DERECHA2 77

char explocion_l12[]={' ',' ','+','+','*',' ',' ',0};
char explocion_l22[]={' ','-','-','-','-','-',' ',0};
char explocion_l32[]={' ',' ','+','+','*',' ',' ',0};

char explocion_r12[]={' ',' ','+','+','*',' ',' ',0};
char explocion_r22[]={' ','+','+','+','+','*',' ',0};
char explocion_r32[]={' ',' ','+','+','*',' ',' ',0};

char borrar_avion2[]={' ',' ',' ',' ',' ',' ',' ',0};

int Num_vidas2 = 3;
int Corazones2 = 3;
int ix2 = 40;
int iy2 = 19;

int y222 = 8 , x222 = 12;
int yy2 =12 , xx2 = 17;
int x12 = 58 , y12 = 6; 
int x22 = 70 , y22 = 9;

int i2,v2;

int dd2=0;
bool disparo2 = false;
int xb2;
// variables para rutinas de cambio de nivel
int repeticion2 = 0, nivel2 = 1;
bool condicion2 = false;

void gotoxy2(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void vidas2(int vi2)
{
    gotoxy2(2,1); printf("VIDAS %d",vi2);
}

void Barra_salud2(int n2)
{
    gotoxy2(72,1); printf(" ");
    gotoxy2(73,1); printf(" ");
    gotoxy2(74,1); printf(" ");

    for (v2=0 ;  v2 < n2 ; v2++)
    {
        gotoxy2(72+v2,1);
        printf("%c",3);//codigo asqui
    }
    
}

void Explocion2(void)
{
    gotoxy2(ix2,iy2); puts(explocion_l12);
    gotoxy2(ix2,iy2+1); puts(explocion_l22);
    gotoxy2(ix2,iy2+1); puts(explocion_l32);

    Sleep(380);   

    gotoxy2(ix2,iy2); puts(explocion_r12);
    gotoxy2(ix2,iy2+1); puts(explocion_r22);
    gotoxy2(ix2,iy2+2); puts(explocion_r32);

    Sleep(380);

    gotoxy2(ix2,iy2);   printf("  %c  ", 143);
    gotoxy2(ix2,iy2+1); printf(" %c%c%c  ",21, 205, 21);
    gotoxy2(ix2,iy2+2); printf("%c%c %c%c",178, 175, 174, 178);
}

void jugar2(void)
{
    if(!disparo2) xb2 = ix2;
    gotoxy2(xb2 + 3 , iy2 + dd2); printf("W");
    //rutina de los asteroides
    //do{
    gotoxy2(x222,y222); printf("%c",2);
    gotoxy2(xx2,yy2); printf("%c",2);
    gotoxy2(x12,y12); printf("%c",2);
    gotoxy2(x22,y22); printf("%c",2);

    Sleep(70);

    gotoxy2(x222,y222); printf(" ");
    gotoxy2(xx2,yy2); printf(" ");
    gotoxy2(x12,y12); printf(" ");
    gotoxy2(x22,y22); printf(" ");

    //rutinas disparo
    gotoxy2(xb2 + 3 , iy2 + dd2); printf(" ");
    if(disparo2 == true) dd2--;
    if (iy2 + dd2 < 5) 
    {
        dd2 = 0;
        disparo2 = false;
    }
    // rutina asteroides
    if (y222 > 20 || x222 == xb2 + 3 && iy2 + dd2 <= y222)
    {
        y222 = 4;
        x222 = (rand()% 70) +6;

        if (y222==4)
            condicion2 =false;
    }
    if(yy2 > 20 || x222 == xb2 + 3 && iy2 + dd2 <= yy2)
    {
        yy2 = 4;
        xx2 = (rand()% 70) +6;
    }
    if(y12 > 20 || x222 == xb2 + 3 && iy2 + dd2 <= y12)
    {
        y12 = 4;
        x12 = (rand()% 70) +6;
    }
    if(y22 > 20 || x222 == xb2 + 3 && iy2 + dd2 <= y22)
    {
        y22 = 4;
        x22 = (rand()% 70) +6;
    }
    //rutina de movimiento de la nave
    if(kbhit())
    {
        unsigned char tecla2 = getch();
        
        switch(tecla2)
        {
            case IZQUIERDA2:

                if ( x222 > 4)
                {
                    gotoxy2(ix2,iy2); puts(borrar_avion2);
                    gotoxy2(ix2,iy2+1); puts(borrar_avion2);
                    gotoxy2(ix2,iy2+2); puts(borrar_avion2);

                    ix2 -=2; //ix = ix-2;

                    gotoxy2(ix2,iy2);   printf("  %c  ", 143);
                    gotoxy2(ix2,iy2+1); printf(" %c%c%c  ",21, 205, 21);
                    gotoxy2(ix2,iy2+2); printf("%c%c %c%c",178, 175, 174, 178);
                }
                break;

            case DERECHA2:

               if ( ix2 < 78)
                {
                    gotoxy2(ix2,iy2); puts(borrar_avion2);
                    gotoxy2(ix2,iy2+1); puts(borrar_avion2);
                    gotoxy2(ix2,iy2+2); puts(borrar_avion2);

                    ix2 +=2; //ix = ix+2;

                    gotoxy2(ix2,iy2);   printf("  %c  ", 143);
                    gotoxy2(ix2,iy2+1); printf(" %c%c%c  ",21, 205, 21);
                    gotoxy2(ix2,iy2+2); printf("%c%c %c%c",178, 175, 174, 178);
                } 
                break;

            case 's':
                disparo2 = true;
                break;
                
        } //switch
    } //if

    //rutina de los choques con los asteroides
    if( (x222 > ix2 && x222 < ix2 + 6 && y222 == iy2 -1) || (xx2 > ix2 && xx2<ix2 + 6 && yy2 == iy2-1) 
    ||(x12 > ix2 && x12 < ix2 + 6 && y12 == iy2 -1 ) || (x22 > ix2 && x22<ix2 +6 && y22 == iy2-1))     
    {
        Corazones2 --;
        Barra_salud2(Corazones2);
        printf("\a");
    }
    
    gotoxy2(ix2,iy2);   printf("  %c  ", 143);
    gotoxy2(ix2,iy2+1); printf(" %c%c%c  ",21, 205, 21);
    gotoxy2(ix2,iy2+2); printf("%c%c %c%c",178, 175, 174, 178);

    if(!Corazones2)
    {
        Num_vidas2--;
        vidas2(Num_vidas2);
        Explocion2();
        Corazones2 = 3;

        Barra_salud2(Corazones2);
    }

    //rutina para cambio de nivel
    if (!condicion2)
    {
        repeticion2 ++;
        condicion2 = true;
    }
    //tiempo de nivel
    if (repeticion2 == 10)
    {
        nivel2++;
        gotoxy2(35,1);
        printf("NIVEL %i", nivel2);

        gotoxy2(ix2, iy2); puts(borrar_avion2);
        gotoxy2(ix2, iy2+1); puts(borrar_avion2);
        gotoxy2(ix2, iy2+2); puts(borrar_avion2);
    
        iy2 -= 2;

        gotoxy2(ix2,iy2);   printf("  %c  ", 143);
        gotoxy2(ix2,iy2+1); printf(" %c%c%c  ",21, 205, 21);
        gotoxy2(ix2,iy2+2); printf("%c%c %c%c",178, 175, 174, 178);
    
        repeticion2 = 0;
    }
    
    
    y222++;
    yy2++;
    y12++;
    y22++;

    //}while(1);
}


void ejecutar2(char nickname[]){
    
    vidas2(Num_vidas2);
    Barra_salud2(Corazones2);
    gotoxy2(35,1); printf("NIVEL %i", nivel2);

    gotoxy2(ix2,iy2);   printf("  %c  ", 143);
    gotoxy2(ix2,iy2+1); printf(" %c%c%c  ",21, 205, 21);
    gotoxy2(ix2,iy2+2); printf("%c%c %c%c",178, 175, 174, 178);
    //Explocion();
    while(Num_vidas2 > 0 && nivel2 <= 6)
        jugar2();

    if (Num_vidas2 == 0)
    {
        gotoxy2(20,15); printf("Game Over");
    }
    else if (Num_vidas2 > 0 && nivel2 == 7)
    {
        gotoxy2(20,15); printf("%s Has ganado!!!!",nickname);
    }

    Sleep(200);
    getch();
}
