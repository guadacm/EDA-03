#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED

char c[8];
Articulo temp;
pNodo prueba;


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
                if(alta_RS(nuevo) == 1) printf("\n El articulo fue agregado con exito\n\n");
                else printf("\nError, el codigo %s ya existe \n\n",nuevo.codigo);
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
                if(baja_RS(c,0)==1) printf("\nEl articulo %s fue eliminado con exito\n\n",c);
                else printf("\nEl articulo %s no fue eliminado o no existe\n\n",c);
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
                temp=evocar_RS(c,&aux);
                if (aux==1)
                {
                    imprimirArt(temp);
                }
                else printf("\n\t El articulo %s no existe\n\n",c);
                system("pause");
                break;
            }
        case 4: // Mostrar
            {
                encabezado();
                int ord;
                printf("\n\t\t           Rebalse Separado             \n"
                         "\t\t           ----------------             \n");
                printf("\n[4] Mostrar Estructura\n");
                //if (cant_RS==0) printf("\n\t Estructura VACIA...\n");
                encabezado();
                printf("Opciones de Mostrar Estructura del RS: \n");
                printf("_________________________\n");
                printf("\n [1] Como lo sugiere el Practico.");
                printf("\n [2] Solo articulos de la estructura.");
                printf("\n\n Elija una Opcion: ");
                fflush(stdin);
                scanf("%d",&ord);
                encabezado();
                printf("\n-------------------------- LISTA DE ARTICULOS --------------------------\n");
                switch(ord){
                     case 1:
                        printf("     \t\t(Mostrar: como lo sugiere el Practico)");
                        mostrar_RS();
                        break;

                    case 2:
                        printf("\t Mostrar: Solo articulos (sin lugares vacios)\n");
                        mostrarSoloElementos_RS();
                        break;
                    }
                printf("\n\tTotal de Articulos: %d\n",cant_RS);
                system("pause");
                break;
            }
        case 5: // Memorizacion
            {
                encabezado();
                printf("\n\t\t           Rebalse Separado             \n"
                         "\t\t           ----------------             \n");
                printf("\n[5] Memorizacion Previa\n");
                memorizacion_previa(2);
                system("pause");
                break;
            }
        }
    }
    *op = -1;
}

int localizar_LVD(pNodo Lista, char codArt[],pNodo *actual, pNodo *anterior){
    (*anterior) = (*actual) = Lista;
    while((*actual)!=NULL && strcmp(codArt,(*actual)->a.codigo)!=0){
        (*anterior)=(*actual);
        (*actual)=(*actual)->sig;
    }
    return (*actual!=NULL);
}

int localizar_RS(char codArt[], pNodo *actual, pNodo *anterior, int *h){
    //int exito;
    *h=hashing(codArt);
    return localizar_LVD(RS[*h],codArt,&(*actual),&(*anterior));
}

int alta_RS(Articulo nuevo){
    int exito,h;
    pNodo actual, anterior, aux;
    exito=localizar_RS(nuevo.codigo, &actual, &anterior, &h);
    if(exito) return 0;
    else{
        aux = RS[h];                            // a aux le doy el acceso(cabecera) de la lista que esta en la posicion h
        RS[h] = (pNodo)malloc(sizeof(nodo));    // pido memoria para el nuevo nodo, al comienzo de la lista (inserto en la cabeza)
        RS[h]->a = nuevo;                       // coloco la informacion de la n-upla (datos del articulo) en el nodo
        RS[h]->sig = aux;                       // al nuevo nodo-> le doy el resto de la lista que habia antes
        cant_RS++;
        return 1;
    }
}

int baja_RS(char codArt[],int tipo){
    int exito,h;
    char c = 'S';
    pNodo actual, anterior;
    exito=localizar_RS(codArt, &actual, &anterior, &h);
    if(!exito) return 0;
    else{
        if(tipo == 0) c = confirmacion_baja(actual->a);
        if(c == 'N' || c == 'n' ) return 0;

        if(strcmp(anterior->a.codigo,actual->a.codigo)==0){
            RS[h]=actual->sig;
            free(actual);
            printf("\n Caso de baja 1");
        }
        else{
            anterior->sig = actual->sig;
            free(actual);
            printf("\n Caso de baja 2");
        }
    cant_RS--;
    return 1;
    }
}

void modificar_RS(char codArt[]){

}

void mostrar_RS(){
    int i,j;
    j=0;
    for(i=0;i<M;i++){
        if(RS[i]!=NULL){
            printf("\nPosicion [%d]:",i);
            mostrar_LVD(RS[i]);
            if ((j % 5) == 0){system("\n pause");}j++;  //Limitador de articulos a mostrar
        }
        else printf("\nPosicion [%d]: Vacio.",i);
    }
}

void mostrarSoloElementos_RS(){
    int i,j;
    j=0;
    for(i=0;i<M;i++){
        if(RS[i]!=NULL){
            printf("\nPosicion [%d]:",i);
            mostrar_LVD(RS[i]);
            if ((j % 5) == 0){system("\n pause");}j++;  //Limitador de articulos a mostrar
        }
    }
}

void mostrar_LVD(pNodo Lista){
    pNodo L = Lista;
    while(L!=NULL) {
        imprimirArt(L->a);
        L=L->sig;
    }
}

Articulo evocar_RS(char codArt[],int *exito){
    int h;
    Articulo temp;
    pNodo actual, anterior;
    *exito=localizar_RS(codArt, &actual, &anterior, &h);
    if(*exito){
        return actual->a;
    }
    else{
        return temp;
    }
}

#endif // RS_H_INCLUDED
