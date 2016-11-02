/*
RAL:
"*" celda virgen
"#" celda libre?
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
//#include "RAL.h"
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
            //case 1: menu_RAL(&opcion); break;
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
           "\t\t\tTotal de Articulos: %d\n"
           "\t\t       --------------------------       \n"

           "\n Cant. de Altas:\t\tRAL: d \tRS: %d "
           "\n Cant. de Bajas:\t\tRAL: d \tRS: %d "
           "\n Cant. de Evocaciones-Exito:\tRAL: d \tRS: %d "
           "\n Cant. de Evocaciones-Fracaso:\tRAL: d \tRS: %d\n",
           cant_RS,
           altas_rs,
           bajas_rs,
           evoE_rs,
           evoF_rs);

    /*printf("\n Costos de Altas:"
           "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n RAL:\t .2f\t\t .2f"
           "\n RS:\t%.2f\t\t%.2f",
           alta_nCorr_rs/(float)altas_rs,alta_MCorr_rs

           );

    printf("\n\n Costos de Bajas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n RAL:\t .2f\t\t .2f"
           "\n RS:\t%.2f\t\t%.2f",
           baja_nCorr_rs/(float)bajas_rs, baja_MCorr_rs

           );*/

    printf("\n\n Costos de Evocaciones Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n RAL:\t .2f\t\t d"
           "\n RS:\t%.2f\t\t%d",
           (float)nodosConsE_rs/(float)evoE_rs, Max_EvoE_rs

           );

    printf("\n\n Costos de Evocaciones NO Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n RAL:\t .2f\t\t d"
           "\n RS:\t%.2f\t\t%d \n\n",
           (float)nodosConsF_rs/(float)evoF_rs,Max_EvoF_rs

           );

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
