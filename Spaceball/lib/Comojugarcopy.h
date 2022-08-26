#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <windows.h>




using namespace std;
int o;

void Comojugar(char player[])
{
   
    printf("\t \t \t \t \t SPACEBALL                                         \r  \n");
    
    printf("Spaceball es un juego, donde para avanzar hasta la meta se necesita de unos grandes reflejos \n"); 
    printf("que han sido transmitidos desde los origenes de la humanidad, el jugador tendra que esquivar \n");
    printf("unos meteoritos que aparecen de la nada, si los golpea perdera una vida hasta que pierda el juego, \n");
    printf("pero si los esquiva bien avanzara al siguiente nivel hasta alcanzar la cuspide del universo. \n");

    printf("\n");
    
    
    printf("%s digita 1 para seleccionar tu nave: ", player);
    scanf("%i",&o);
    printf("\n");
}
void Controles(char player[])
{
    
    printf("\t \t \t \t \t Controles                                         \r  \n");
    
    printf("Con las flechas de direccion podras mover la nave para evitar los peligrosos asteroides \n"); 
    printf("Con %c podras moverte a la izquierda y con %c podras moverte a la derecha \n",27,26);
    printf("Con la tecla S podras eliminar los asteroides que se cruzen en tu camino evitando que pierdas una vida \n");
    printf("Lo mas importante de todo diviertete a lo grande. \n");

    printf("\n");
    
    
    printf("%s digita 1 para seleccionar tu nave o 2 para ir a indicaciones: ", player);
    scanf("%i",&o);
    printf("\n");
}


//main()
//{
//   Comojugar(); 
//   Seleccion(); 
//}