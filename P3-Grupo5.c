/* -- Grupo 5: Medina, Guadalupe
               Montenegro, Luis

                                    Practico de maquina 3 - Rebalse Abierto Lineal , Rebalse Separado.

  -- Estructura elegida:

  * Comparando los costos del "Operaciones.txt":
Segun los resultados que devuelve la comparación de estructuras, los costos de evocacion a posteriori son levementes mejor el RAL, en evocaciones exitosas y
no existoas, en maximos de evocaciones exitosas tambien. A excepcion de Maximos de evocaciones que fracasan los costos son iguales entre RS y RAL

  * Observando caracteristicas de cada estructura:
El RS, tiene algunas caracteristicas que nos parecen mas "personalizables" y segun el problema a resolver, podriamos elegir distinas variantes, como por ejemplo
las ranuras de cada balde, si bien son nodos de una lista vinculada desordenada, podrian ser una lista vinculada ordenada, incluso arboles binarios, o cualquier
otra estructura que se pueda adaptar.
Otro aspecto a tener en cuenta, es que los elementos a dar de alta, en el RAL compiten por un lugar en las listas, en cambio en el RS los elementos a dar de alta
van siempre a donde en realidad pertenecen, ya que las listas crecen de manera dinamica cuando la estructura lo necesite.


    El Siguiente cuadro indica que estructura es mejor en costos cada caso (alta,baja considerando corrimientos) y (evocacion) siendo la primera la mejor.

m: medio
M: máximo      _____________________ ______________________ ________________________ _______________________
              |               (m/M) |                (m/M) |                (m) (M) |               (m) (M) |
              | Altas:MEJOR--> RAL  | Bajas: MEJOR--> RAL  | EvoE: MEJOR--> RAL RAL | EvoF:MEJOR--> RAL  =  |
              |                R.S  |                 R.S  |                R.S R.S |               R.S  =  |
              |                     |                      |                        |                       |
              |_____________________|______________________|________________________|_______________________|

  -- Funciones de costos:
                         - Evocaciones RAL -> Cantidad de celdas consultadas
                         - Evocaciones R.S -> Cantidad de celdas consultadas + cantidad de consultas a lo apuntado por el puntero contenido en la celda



 ------------------------------------------ NOTAS y ACLARACIONES: ------------------------------------------

 * M = N/p, N=170, p=0.7, como M tomo el numero primo mas proximo al techo del resultado de la division
  M = techo(170/0.7)= 243, entonces M = 251.

 * Utilizamos un parametro extra en la funcion Localizar llamado "conCosto", el cual si es 1(cuando
es llamado por evocar) voy a contar las celdas consultadas.

-- estructuras.h:
 * Se encuentran definiciones de constantes, variables y estructuras.
 * Tambien estan las funciones comunes a ambas estructuras (memorizacion previa, codigo operaciones, limpiar contadores, etc).

-- RAL:

 * "*" celda virgen.
 * "#" celda libre (antes ocupada, ahora libre).
 * Inicializo el RAL poniendo "*" en el campo codigo.

-- RS:

 * Se inicializan los "baldes" (cabeceras de listas) en la funcion "limpiarContadores", la cual se ejecuta cuando se ingresa al menu "Administracion de Estructuras"
y "Comparacion de Estructuras"
 * Las altas se realizan, insertando el nodo al comienzo de la lista(Ranura) correspondiente, perteneciente al balde que devolvio la funcion de hashing


 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#include "RAL.h"
#include "RS.h"

int opcion = -1;

void encabezado()
{
    system("cls");
    printf("\n\t\t****************************************\n"
             "\t\t*** ESTRUCTURA DE DATOS Y ALGORITMOS ***\n"
             "\t\t****************************************\n");
}

// -- MENU ADMINISTRACION
void administracion()
{
    limpiar_contadores();

    while (opcion !=0)
    {
        encabezado();
        printf("\n\t\t      Administracion de estructuras      \n"
                 "\t\t      -----------------------------      \n"
                "\n[1] Rebalse Abierto Lineal (R.A.L.)"
                "\n[2] Rebalse Separado (R.S.)"
                "\n\n[0] Volver\n"
                "\nElija una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 0: break;
            case 1: menu_RAL(&opcion); break;
            case 2: menu_RS(&opcion); break;
        }
    }
    opcion = -1;
}

// -- MENU COMPARACION
void comparacion()
{
    limpiar_contadores();

    encabezado();
    printf("\t\t       Comparacion de estructuras       \n"
           "\t\t       --------------------------       \n");
    lectura_archivo_operaciones();

    encabezado();
    printf("\t\t       Comparacion de estructuras       \n"
           "\t\t\tTotal de Articulos: %d  %d\n"
           "\t\t       --------------------------       \n"

           "\n Cant. de Altas:\t\tRAL: %d \tRS: %d "
           "\n Cant. de Bajas:\t\tRAL: %d \tRS: %d "
           "\n Cant. de Evocaciones-Exito:\tRAL: %d \tRS: %d "
           "\n Cant. de Evocaciones-Fracaso:\tRAL: %d \tRS: %d\n",
           cant_RS, cant_RAL,
           altas_RAL, altas_rs,
           bajas_RAL, bajas_rs,
           evoE_RAL, evoE_rs,
           evoF_RAL, evoF_rs);

    printf("\n\n Costos de Evocaciones Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n RAL:\t%.2f\t\t%d"
           "\n RS:\t%.2f\t\t%d",
           (float)consultas_evoE_RAL/(float)evoE_RAL, max_evoE_RAL,
           (float)nodosConsE_rs/(float)evoE_rs, Max_EvoE_rs);

    printf("\n\n Costos de Evocaciones NO Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n RAL:\t%.2f\t\t%d"
           "\n RS:\t%.2f\t\t%d \n\n",
           (float)consultas_evoF_RAL/(float)evoF_RAL, max_evoF_RAL,
           (float)nodosConsF_rs/(float)evoF_rs,Max_EvoF_rs);

    system("pause");
}

// -- MENU PRINCIPAL
void principal()
{
    encabezado();
    printf("\n[1] Administracion de estructuras");
    printf("\n[2] Comparacion de estructuras");
    printf("\n\n[0] Salir\n");
    printf("\nElija una opcion: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
        case 0: break;
        case 1: administracion(); break;
        case 2: comparacion(); break;
    }
}

int main()
{

// -- MENU PRINCIPAL
    while (opcion != 0)
    {
        principal(&opcion);
    }
    return 0;
}
