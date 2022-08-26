#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "../lib/menu.cpp"
#include "../lib/ComoJugarcopy.h"
#include "../lib/Colores.h"
#include "../lib/Titulo.h"


using namespace std;
int opcion;
char nickname[30];


//************************************************************************************************

void retardado(){
    for(int i=0; i<5000;i++){
        for(int j=0; j<5000;j++){
        }
    }
}

//************************************************************************************************
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
}
//************************************************************************************************
void MENU()
{
    system("cls");
    Menu(nickname);
}
//************************************************************************************************
void INDICACIONES()
{
    do
    {
        system("cls");
        Comojugar(nickname);
        switch (o)
        {
        case 1:
            MENU();
            printf("\n");
            break;
        default:
            system("cls");
            printf("\n\n\t\t%s digita la unica opcion valida por favor" ,nickname);
            system("pause>nul");
            break;
        }
    } while (x != 1);
     
}
//************************************************************************************************

int main ()
{
    Color(12);
    titulo();

    Color(2);
    bool repeat = true;
    barrita();
    
    system("cls");
    //system("color 4C");
    //txtcolor(BLUE);
    //rectangle(0, 0, 180, 80);
    //gotoxy(5,5);

    cout << "\n\n\n\n\t\t\tIngresa tu apodo: ";
    //cin >> nickname;
    fgets(nickname, 30, stdin);
    nickname[strlen(nickname)-1] = '\0';

    do
    {
        

        system("cls");

        HANDLE hConsole =GetStdHandle( STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,7);
        cout <<"\t\t\tSpaceBall  \n"<<endl;

        SetConsoleTextAttribute(hConsole,7);
    Color(14);
    cout <<"\tWelcome\n\n"<<endl;
    Color(3);
    cout <<"\t1.Menu de Juegos  \n\n"<<endl;
    Color(10);
    cout <<"\t2.Indicaciones \n\n"<<endl;
    Color(5);
    cout <<"\t3.Controles \n\n"<<endl;
    Color(4);
    cout <<"\t4.Salir \n\n"<<endl;
    Color(15);

        cout << "\t" << nickname <<" ingresa que quieres hacer: ";
        cin >> opcion;


            switch(opcion)
    {
        case 1:
        MENU();
        break;

        case 2:
        Color(10);
        INDICACIONES();
        Color (15);
        break;
        
        case 3:
        Color(9);
        Controles;
        Color (15);
        case 4:
        getchar();
    
    } 

    }while(repeat);

    return 0;

}
    