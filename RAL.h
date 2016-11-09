#ifndef RAL_H_INCLUDED
#define RAL_H_INCLUDED

char c[8];
Articulo temp;
int contador; // Cuenta la cantidad de

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
            temp = evocar_RAL(c, &aux);
            if (aux == 1)
            {
                imprimirArt(temp);
                printf("\n");
            }
            else
                printf("\n\t El articulo %s no existe\n\n", c);
            system("pause");
            break;
        }
        case 4: // Mostrar
        {
            encabezado();
            printf("\n\t\t        Rebalse Abierto Lineal          \n"
                   "\t\t        ----------------------          \n");
            printf("\n[4] Mostrar Estructura\n");
            //if (cant_RAL==0) printf("\n\t Estructura VACIA...\n");    // CORRECCION
            //else
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
    consultas_RAL = 0;
    *h = hashing(codArt);
    *pos = *h;
    if(cant_RAL > 0)
    {
        int i = *h;
        int f = 0; // si esta en 1 me dice que ya guardo en pos una celda libre
        consultas_RAL++;
        while(strcmp(RAL[i].codigo, codArt) != 0 && strcmp(RAL[i].codigo, "*") != 0 && consultas_RAL < M)       // CORRECCION
        {
            if(strcmp(RAL[i].codigo, "#") == 0 && f == 0)
            {
                *pos = i;
                f = 1;
            }
            i = (i + 1) % M;
            consultas_RAL++;
        }
        if(consultas_RAL == M-1)    //CORRECCION
            return 0;
        if(strcmp(RAL[i].codigo, "*") == 0 && f == 0)
            *pos = i;
        if(strcmp(RAL[i].codigo, codArt) == 0)
        {
            *pos = i;
            return 1;
        }
        else
        {
            return 0;
        }

    }
    else
    {
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
            RAL[pos] = nuevo;
            cant_RAL++;
            altas_RAL++;
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
            bajas_RAL++;
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
    if(localizar_RAL(codArt, &h, &pos) == 1)
    {
        aux = RAL[pos];
        *exito = 1;
        evoE_RAL++;
        consultas_evoE_RAL += consultas_RAL;

        if(consultas_RAL > max_evoE_RAL)
            max_evoE_RAL = consultas_RAL;
    }
    else
    {
        *exito = 0;
        evoF_RAL++;
        consultas_evoF_RAL += consultas_RAL;

        if(consultas_RAL > max_evoF_RAL)
            max_evoF_RAL = consultas_RAL;
    }
    return aux;
}

void mostrar_RAL()
{
    int i, j = 1;    // j es para limitar las celdas que se muestran
    printf("\n\t----------LISTA DE ARTICULOS----------\n"
           "\n\t     Cantidad de articulos: %d\n", cant_RAL);
    for(i = 0; i < M; i++)
    {
        printf("\n Posicion: %d", i);
        if(strcmp(RAL[i].codigo, "*") == 0) // Celdaa virgen
        {
            printf("\t * Celda nunca usada\n");
            j++;
        }
        else
        {
            if(strcmp(RAL[i].codigo, "#") == 0) // Celda libre
            {
                printf("\t # Celda libre\n");
                j++;
            }

            else        // Celda ocupada
            {
                printf("\t - Celda ocupada por:");
                imprimirArt(RAL[i]);
                j++;    //Limitador de articulos a mostrar
            }
        }
        if(j % 8 == 0)
        {
            printf("\n");
            system("pause");
            j = 0;
        }
    }
}

#endif // RAL_H_INCLUDED
