/*
RAL:
"*" celda virgen
"#" celda libre?
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
    //limpiar_contadores();

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

    encabezado();
    printf("\t\t       Comparacion de estructuras       \n"
           "\t\t       --------------------------       \n");
    //lectura_archivo_operaciones();

    encabezado();
    printf("\t\t       Comparacion de estructuras       \n"
           "\t\t\tTotal de Articulos: %d\n"
           "\t\t       --------------------------       \n"

           "\n Cant. de Altas:\t\tABB: %d \tLI: %d "
           "\n Cant. de Bajas:\t\tABB: %d \tLI: %d "
           "\n Cant. de Evocaciones-Exito:\tABB: %d \tLI: %d "
           "\n Cant. de Evocaciones-Fracaso:\tABB: %d \tLI: %d\n",
           0,
           0, 0,
           0, 0,
           0, 0,
           0, 0);

    printf("\n Costos de Altas:"
           "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%.2f"
           "\n LI:\t%.2f\t\t%.2f",
           0/(float)0,0,
           0/(float)0, 0);

    printf("\n\n Costos de Bajas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%.2f"
           "\n LI:\t%.2f\t\t%d",
           0/(float)0, 0,
           0/(float)0, 0);

    printf("\n\n Costos de Evocaciones Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%d"
           "\n LI:\t%.2f\t\t%d",
           (float)0/(float)0, 0,
           (float)0/(float)0, 0);

    printf("\n\n Costos de Evocaciones NO Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%d"
           "\n LI:\t%.2f\t\t%d \n\n",
           (float)0/(float)0,0,
           (float)0/(float)0, 0);

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
