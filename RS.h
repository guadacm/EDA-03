#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED

char c[8];
Articulo temp;

void menu_RS(int *op)
{


    while (*op != 0)
    {
        encabezado();
        printf("\n\t\t           Rebalse Separado             \n"
                 "\t\t           ----------------             \n");
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
                printf("\n\t\t           Rebalse Separado             \n"
                         "\t\t           ----------------             \n");
                Articulo nuevo;
                printf("\n[1] Nuevo articulo"
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
                /*if(alta_ABB(nuevo) == 1) printf("\n El articulo fue agregado con exito\n\n");
                else printf("\nError, el codigo %s ya existe \n\n",nuevo.codigo);*/
                system("pause");
                break;
            }
        case 2: // Baja
            {
                encabezado();
                printf("\n\t\t           Rebalse Separado             \n"
                         "\t\t           ----------------             \n");

                printf("\n[2] Eliminar articulo"
                       "\n\n Codigo: \t");
                fflush(stdin);
                scanf("%s",c);
                strupr(c);
                /*if(baja_ABB(c,0)==1) printf("\nEl articulo %s fue eliminado con exito\n\n",c);
                else printf("\nEl articulo %s no fue eliminado o no existe\n\n",c);*/
                system("pause");
                break;
            }
        case 3: // Consulta
            {
                encabezado();
                printf("\n\t\t           Rebalse Separado             \n"
                         "\t\t           ----------------             \n");
                printf("\n[3] Consultar articulo\n"
                       "\n\n Codigo: \t");
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
            }
        case 4: // Mostrar
            {
                encabezado();
                printf("\n\t\t           Rebalse Separado             \n"
                         "\t\t           ----------------             \n");
                int ord;
                printf("\n[4] Mostrar Estructura\n");
                /*if (ABB == NULL) printf("\n\t Estructura VACIA...\n");
                printf("\n\tTotal de Articulos: %d\n",cant_ABB);*/
                system("pause");
                break;
            }
        case 5: // Memorizacion
            {
                encabezado();
                printf("\n\t\t           Rebalse Separado             \n"
                         "\t\t           ----------------             \n");
                printf("\n[5] Memorizacion Previa\n");
                /*memorizacion_previa(1);*/
                system("pause");
                break;
            }
        }
    }
    *op = -1;
}

int localizar_LVD (pNodo Lista, char codArt[], pNodo *anterior){
    pNodo actual = Lista;
    (*anterior) = Lista;
    while(actual!=NULL && strcmp(codArt,actual->a.codigo)!=0){
        (*anterior)=actual;
        actual=actual->sig;
    }
    return (actual!=NULL);
}

int localizar_RS(char codArt[], pNodo *actual, pNodo *anterior){
    int h,exito;
    h=3;/*hashing(codArt);*/
    exito=localizar_LVD(RS[h],codArt,&(*anterior));
    (*actual)=(*anterior)->sig;
    return exito;
}

int alta_RS(Articulo nuevo){
    int exito;
    pNodo actual, anterior, aux;
    exito=localizar_RS(nuevo.codigo, &actual, &anterior);
    if(exito) return 0;
    else{
        aux = (pNodo)malloc(sizeof(nodo));
        aux->sig = anterior->sig;
        anterior->sig = aux;
        aux->a = nuevo;
        return 1;
    }
}

int baja_RS(char codArt[]){

}

void modificar_RS(char codArt[]){

}

Articulo evocar_RS(char codArt[]){

}

#endif // RS_H_INCLUDED
