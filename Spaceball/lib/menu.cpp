#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "../Naves/nave1.h"
#include "../Naves/nave2.h"
#include "../Naves/nave3.h"
#include "../Naves/nave4.h"

using namespace std;


void Wind(char wnikname[])
{
    system("cls");

    ejecutar1(wnikname);

}

void H4(char hnikname[])
{
    system("cls");

    ejecutar2(hnikname);    

}

void Diamatti(char dnikname[])
{
    system("cls");

    ejecutar3(dnikname);  

}

void Phoenix(char pnikname[])
{
    system("cls");

    ejecutar4(pnikname);  

}

void Menu(char player[])
{
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");
        
        // Categorias a elegir
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\n\t\t\t\t    CATEGORIAS" << endl;
        cout << "\t\t\t   \\\\\\----------------------///" << endl;
        SetConsoleTextAttribute(hConsole, 2);
        cout << "\n\t1. Wind" << endl;
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\t2. H4" << endl;
        SetConsoleTextAttribute(hConsole, 4);
        cout << "\t3. Diamatti" << endl;
        SetConsoleTextAttribute(hConsole, 5);
        cout << "\t4. Phoenix" << endl;
        SetConsoleTextAttribute(hConsole, 6);
        cout << "\t0. SALIR" << endl;
        SetConsoleTextAttribute(hConsole, 7);

        cout << "\n\t" << player << " digita el numero de la categoria a la que quieres ingresar: ";
        cin >> opcion;


        switch (opcion)
        {
        case 1:
            Wind(player);
            break;

        case 2:
            H4(player);
            break;

        case 3:
            Diamatti(player);
            break;

        case 4:
            Phoenix(player);
            break;

        case 0:
            repetir = false;
            break;
    
        }
    } while (repetir);
}


//int main()
//{
//    Menu();
//    return 0;
//}

