#ifndef RAL_H_INCLUDED
#define RAL_H_INCLUDED

char c[8];
Articulo temp;

void menu_RAL(int *op)
{
    cant_RAL = 0;
    int i;
    for(i = 0; i < M; i++)
            strcpy(RAL[i].codigo, "******");


    while (*op != 0)
    {
        encabezado();
        printf(  "\t\t        Rebalse Abierto Lineal          \n");
        printf(  "\t\t      -------------------------         \n");
        printf("\n[1] Nuevo articulo");
        printf("\n[2] Eliminar articulo");
        printf("\n[3] Consultar articulo");
        printf("\n[4] Mostrar articulos");
        printf("\n[5] Memorizacion previa");
        printf("\n\n[0] Volver\n");
        printf("\nElija una opcion: ");
        scanf("%d", op);

        switch (*op)
        {
        case 0:
            break;

        case 1:
            encabezado();
            printf(  "\t\t        Rebalse Abierto Lineal          \n");
            printf(  "\t\t      -------------------------         \n");
            printf("\n[1] Nuevo articulo");
            Articulo nuevo;
            printf("\n\n Codigo: \t");
            fflush(stdin);
            scanf("%s", nuevo.codigo);
            strupr(nuevo.codigo);
            printf(" Articulo:\t");
            fflush(stdin);
            scanf(" %[^\n]",nuevo.articulo);
            printf(" Marca:\t\t");
            fflush(stdin);
            scanf(" %[^\n]",nuevo.marca);
            printf(" Club:\t\t");
            fflush(stdin);
            scanf(" %[^\n]",nuevo.club);
            printf(" Cantidad:\t");
            fflush(stdin);
            scanf("%d",&nuevo.cantidad);
            printf(" Valor($):\t");
            fflush(stdin);
            scanf("%f",&nuevo.valor);
            /*if(alta_ABB(nuevo) == 1) printf("\n El articulo fue agregado con exito\n\n");
            else printf("\nError, el codigo %s ya existe \n\n",nuevo.codigo);*/
            system("pause");
            break;

        case 2:
            encabezado();
            printf(  "\t\t        Rebalse Abierto Lineal          \n");
            printf(  "\t\t      -------------------------         \n");
            printf("\n[2] Eliminar articulo");
            printf("\n\n Codigo: \t");
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            /*if(baja_ABB(c,0)==1) printf("\nEl articulo %s fue eliminado con exito\n\n",c);
            else printf("\nEl articulo %s no fue eliminado o no existe\n\n",c);*/
            system("pause");
            break;

        case 3:
            encabezado();
            printf(  "\t\t        Rebalse Abierto Lineal          \n");
            printf(  "\t\t      -------------------------         \n");
            printf("\n[3] Consultar articulo\n");
            printf("\n\n Codigo: \t");
            int aux;
            Articulo temp;
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            /*temp=evocar_ABB(c,&aux);
            if (aux==1)
            {
                imprimirArt(temp);
            }
            else printf("\n\t El articulo %s no existe\n\n",c);*/
            system("pause");
            break;


        case 4:
            encabezado();
            int ord;
            printf(  "\t\t        Rebalse Abierto Lineal          \n");
            printf(  "\t\t      -------------------------         \n");
            printf("\n[4] Mostrar Estructura\n");
            /*if (ABB == NULL) printf("\n\t Estructura VACIA...\n");
            printf("\n\tTotal de Articulos: %d\n",cant_ABB);*/
            system("pause");
            break;

        case 5:
            encabezado();
            printf(  "\t\t        Rebalse Abierto Lineal          \n");
            printf(  "\t\t      -------------------------         \n");
            printf("\n[5] Memorizacion Previa\n");
            /*memorizacion_previa(1);*/
            system("pause");
            break;
        }
    }
    *op = -1;

}



#endif // RAL_H_INCLUDED
