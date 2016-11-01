#ifndef RAL_H_INCLUDED
#define RAL_H_INCLUDED

char c[8];
Articulo temp;

void menu_RAL(int *op)
{
    cant_RAL = 0;
    int i;
    for(i = 0; i < M; i++)      // Inicializo el RAL con la marca de celda virgen
        strcpy(RAL[i].codigo, "*");


    while (*op != 0)
    {
        encabezado();
        printf("\n\t\t        Rebalse Abierto Lineal          \n"
               "\t\t        ----------------------          \n");
        printf("\n[1] Nuevo articulo"
               "\n[2] Eliminar articulo"
               "\n[3] Consultar articulo"
               "\n[4] Mostrar articulos"
               "\n[5] Memorizacion previa"
               "\n\n[0] Volver\n"
               "\nElija una opcion: ");
        scanf("%d", op);

        switch (*op)
        {
        case 0:
            break;

        case 1: // Alta
        {
            encabezado();
            printf("\n\t\t        Rebalse Abierto Lineal          \n"
                   "\t\t        ----------------------          \n");
            Articulo nuevo;
            printf("\n[1] Nuevo articulo"       // Ingreso de datos del nuevo articulo
                   "\n\n Codigo: \t");
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
            if(alta_RAL(nuevo) == 1) printf("\n El articulo fue agregado con exito\n\n"); // Alta exitosa
            else printf("\nError, el codigo %s ya existe \n\n", nuevo.codigo);          // Alta fracasa
            system("pause");
            break;
        }
        case 2: // Baja
        {
            encabezado();
            printf("\n\t\t        Rebalse Abierto Lineal          \n"
                   "\t\t        ----------------------          \n");
            printf("\n[2] Eliminar articulo"
                   "\n\n Codigo: \t"); // Ingreso codigo de articulo que quiero dar de baja
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            if(baja_RAL(c,0) == 1) printf("\nEl articulo %s fue eliminado con exito\n\n",c);
            else printf("\nEl articulo %s no fue eliminado o no existe\n\n",c);
            system("pause");
            break;
        }
        case 3: // Consulta
        {
            encabezado();
            printf("\n\t\t        Rebalse Abierto Lineal          \n"
                   "\t\t        ----------------------          \n");
            int aux;
            Articulo temp;
            printf("\n[3] Consultar articulo\n"
                   "\n\n Codigo: \t");
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            temp = evocar_RAL(c,&aux);
            if (aux==1)
            {
                imprimirArt(temp);
            }
            else printf("\n\t El articulo %s no existe\n\n",c);*/
            system("pause");
            break;
        }
        case 4: // Mostrar
        {
            encabezado();
            printf("\n\t\t        Rebalse Abierto Lineal          \n"
                   "\t\t        ----------------------          \n");
            printf("\n[4] Mostrar Estructura\n");
            mostrar_RAL();
            system("pause");
            break;
        }
        case 5: // Memorizacion
        {
            encabezado();
            printf("\n\t\t        Rebalse Abierto Lineal          \n"
                     "\t\t        ----------------------          \n");
            memorizacion_previa(1);
            system("pause");
            break;
        }
        }
    }
    *op = -1;
}

int localizar_RAL(char codArt[],int *h, int *pos) // en h guardo el valor que me da la funcion hashing, en pos, la posicion donde debe/deberia estar el elemento que busco
{
    *h = hashing(codArt);
    printf("\n**** Hash: %d\n", *h);

    if(cant_RAL > 0)
    {
        int i = *h;
        *pos = *h;
        int f = 0;
        while(strcmp(RAL[i].codigo, codArt) != 0 && strcmp(RAL[i].codigo, "*") != 0)
        {
            if(strcmp(RAL[i].codigo, "#") == 0 && f == 0)
            {
                *pos = i;
                f = 1;
            }
            i = (i + 1) % M;
        }
        if(strcmp(RAL[i].codigo, codArt) == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        *pos = *h;
        return 0;
    }
}

int alta_RAL(Articulo nuevo)
{
    int h, pos;
    if(cant_RAL < M)
    {
        if(localizar_RAL(nuevo.codigo, &h, &pos) == 0)
        {
            printf("\n**** Hash: %d\n", h);
            RAL[pos] = nuevo;
            cant_RAL++;
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int baja_RAL(char codArt[], int tipo) // tipo es para hacer o no la confirmacion de baja
{
    if(cant_RAL > 0)
    {
        int h, pos;
        char c = 'S';
        if(localizar_RAL(codArt, &h, &pos) == 1)
        {
            if(tipo == 0) c = confirmacion_baja(RAL[pos]);
            if(c == 'N' || c == 'n' ) return 0;

            strcpy(RAL[pos].codigo, "#");
            cant_RAL--;
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

Articulo evocar_RAL(char codArt[], int *exito)
{
    int h, pos;
    Articulo aux;
    strcpy(aux.codigo, "*");
    if(localizar_RAL(codArt, &h, &pos == 1)
    {
        aux = RAL[pos];
        /*if(max_evoE_LI < consultadas)
            max_evoE_LI = consultadas;

        consE_LI += consultadas;

        evoE_LI++;*/
        return aux;
    }
    else
    {
        /*if(max_evoF_LI < consultadas)
            max_evoF_LI = consultadas;

        consF_LI += consultadas;

        evoF_LI++;*/
        return aux;
    }
}

void mostrar_RAL()
{
    int i, j = 1, k = 1;    // j y k son para limitar las celdas que se muestran
    printf("\n\t----------LISTA DE ARTICULOS----------\n"
           "\n\t     Cantidad de articulos: %d\n", cant_RAL);
    for(i = 0; i < M; i++)
    {
        printf("\n Posicion: %d", i);
        if(strcmp(RAL[i].codigo, "*") == 0) // Celdaa virgen
        {
            printf("\t * Celda nunca usada\n");
            k++;
        }
        else
        {
            if(strcmp(RAL[i].codigo, "#") == 0) // Celda libre
            {
                printf("\t # Celda libre\n");
                k++;
            }

            else        // Celda ocupada
            {
                printf("\t - Celda ocupada por:");
                imprimirArt(RAL[i]);
                j++;    //Limitador de articulos a mostrar
            }
        }
        if(j % 5 == 0 || k % 10 == 0)
        {
            printf("\n");
            system("pause");
        }
    }
}

#endif // RAL_H_INCLUDED
