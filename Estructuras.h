#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#define DIM 170
#define M 251   //Nº primo siguiente a M = 170/0.7 (N = 170, Ro = 0.7)

typedef struct Articulo{
	char codigo[8];
	char articulo[52];
	char marca[62];
	float valor;
	int cantidad;
	char club[72];
} Articulo;

/* VARIABLES */
// -- R.A.L
Articulo RAL[M];    //Definicion del Rebalse Abierto Lineal, de dimensión M.
int cant_RAL;

// -- R.S.

typedef struct Nodo{
    Articulo a;
    struct Nodo* sig;
} nodo;

typedef nodo* pNodo;

pNodo RS[M];        //Definicion del Rebalse Separado, de dimension M cabeceras de lista.

int cant_RS = 0;         // cantidad de articulos
int altas_rs = 0;        // total de altas
int bajas_rs = 0;        // total de bajas
int evoE_rs = 0;         // evocaciones Exitosas
int evoF_rs = 0;         // evocaciones Fracasan
int consultadas_rs = 0;  // celdas consultados dentro de localizar
float alta_nCorr_rs = 0; // numero de corrimientos en altas
float alta_MCorr_rs = 0; // Maximo de corrimientos en altas
float baja_nCorr_rs = 0; // numero de corrimientos en bajas
float baja_MCorr_rs = 0; // Maximo de corrimientos en bajas
int nodosConsE_rs = 0;   // Cantidad de nodos consultados en evocaciones Exitosas
int Max_EvoE_rs = 0;     // Maximo de nodos consultados en evocaciones Exitosas
int nodosConsF_rs = 0;   // Cantidad de nodos consultados en evocaciones de Fracaso
int Max_EvoF_rs = 0;     // Maximo de nodos consultados en evocaciones de Fracaso


/* FIN VARIABLES */


/* PROTOTIPOS */
void encabezado();
void borrar_salto(Articulo *art);
void limpiar_contadores();

// -- R.A.L
int localizar_RAL(char codArt[],int *h, int *pos);
int alta_RAL(Articulo nuevo);
int baja_RAL(char codArt[], int tipo);
void mostrar_RAL();

// -- R.S
int localizar_LVD(pNodo,char [],pNodo*,pNodo*/*,int**/);
int localizar_RS(char[], pNodo*, pNodo*,int*,int);

int alta_RS(Articulo);
int baja_RS(char[],int);
void mostrar_LVD(pNodo);
void mostrar_RS();
void mostrarSoloElementos_RS();
Articulo evocar_RS(char[],int*);


/* FIN PROTOTIPOS */

int hashing (char codArt[]){
    int longitud, i;
    int contador = 0;
    longitud = strlen(codArt);
    for(i=0;i<longitud;i++)
        contador += (((int)codArt[i]) * (i+1));
    return (contador % M);
}

void imprimirArt(Articulo Art)
{
    printf("\n Codigo: \t%s"
           "\n Articulo: \t%s"
           "\n Marca: \t%s"
           "\n Valor: \t$%.2f"
           "\n Cantidad: \t%d"
           "\n Club: \t\t%s\n",
            Art.codigo,
            Art.articulo,
            Art.marca,
            Art.valor,
            Art.cantidad,
            Art.club);
}

void limpiar_contadores()   // Inicializa todos los contadores usados en la comparacion de las estrcuturas.
{
    //Inicializacion R.S.
    int k;
    for(k=0;k<M;k++)RS[k]=NULL;

    //Variables R.S.
    cant_RS = 0;
    altas_rs = 0;
    bajas_rs = 0;
    evoE_rs = 0;
    evoF_rs = 0;
    alta_nCorr_rs = 0;
    altas_rs = 0;
    alta_MCorr_rs = 0;

    consultadas_rs = 0;
    nodosConsE_rs = 0;
    Max_EvoE_rs = 0;
    nodosConsF_rs = 0;
    Max_EvoF_rs = 0;


    //Variables R.A.L

}

void memorizacion_previa(int estr) // estr: 1.RAL || 2.RS
{
    Articulo nuevo;
    FILE *fp;

    if ((fp = fopen("Articulos.txt", "r")) == NULL)
        printf("\n\nERROR: no se pudo abrir el archivo\n\n");
    else
    {
        while(!(feof(fp)))
        {
            fgets(nuevo.codigo, 8, fp);
            strupr(nuevo.codigo);
            fgets(nuevo.articulo, 52, fp);
            fgets(nuevo.marca, 62, fp);
            fscanf(fp, "%f\n", &nuevo.valor);
            fscanf(fp, "%i\n", &nuevo.cantidad);
            fgets(nuevo.club, 72, fp);
            borrar_salto(&nuevo);

            switch(estr)
            {
                case 1:
                    //alta_RAL(nuevo);
                    break;
                case 2:
                    alta_RS(nuevo);
                    break;
            }
        }
        printf("\n\nLa memorizacion se ha llevado a cabo\n\n");
    }
    fclose(fp);
}

char confirmacion_baja(Articulo baja)
{
    char c;
    /*printf("\n Codigo: \t%s"
           "\n Articulo: \t%s"
           "\n Marca: \t%s"
           "\n Valor: \t$%.2f"
           "\n Cantidad: \t%i"
           "\n Club: \t\t%s",
           baja.codigo,
           baja.articulo,
           baja.marca,
           baja.valor,
           baja.cantidad,
           baja.club);*/
    imprimirArt(baja);
    printf("\n\nEsta seguro que quiere eliminar este articulo? S/N: ");
    fflush(stdin);
    scanf("%c", &c);
    while (!(c=='S' || c=='s' || c=='N' || c=='n')){
        printf("\nIntente de nuevo. Solo se admiten las letras ( S - s - N - n )\n");
        fflush(stdin);
        scanf("%c", &c);
        }
    return c;
}

void borrar_salto(Articulo *art) //Borra en '\n' que almacena fgets.
{
    int i = 0;
    for (i = 0; i < 8; i++) { //Codigo
        if ((*art).codigo[i] == '\n') {
            (*art).codigo[i] = '\0';
        }
    }
    for (i = 0; i < 52; i++) { //Articulo
        if ((*art).articulo[i] == '\n') {
            (*art).articulo[i] = '\0';
        }
    }
    for (i = 0; i < 62; i++) { //Marca
        if ((*art).marca[i] == '\n') {
            (*art).marca[i] = '\0';
        }
    }
    for (i = 0; i < 72; i++) { //Club
        if ((*art).club[i] == '\n') {
            (*art).club[i] = '\0';
        }
    }
}

void lectura_archivo_operaciones()
{
    int cod_op,aux;
    Articulo nuevo;
    FILE *fp;
    if((fp = fopen("Operaciones.txt", "r")) == NULL)
        printf("\n\nERROR: No se pudo abrir el archivo\n\n");
    else
    {
        while (!(feof(fp)))
        {
            fscanf(fp, "%d\n", &cod_op);
            if ((cod_op == 1) || (cod_op == 2)) // -- (1. Alta) (2. Baja)
            {
                fgets(nuevo.codigo, 8, fp);
                fgets(nuevo.articulo, 52, fp);
                fgets(nuevo.marca, 62, fp);
                fscanf(fp, "%f\n", &nuevo.valor);
                fscanf(fp, "%i\n", &nuevo.cantidad);
                fgets(nuevo.club, 72, fp);
            }
            else    // -- (3. Consulta)
                fgets(nuevo.codigo, 8, fp);

            strupr(nuevo.codigo);
            borrar_salto(&nuevo);

            switch(cod_op)
            {
                case 1:
                    //alta_RAL(nuevo);
                    alta_RS(nuevo);
                    break;
                case 2:
                    //baja_RAL(nuevo.codigo,1);
                    baja_RS(nuevo.codigo,1);
                    break;
                case 3:
                    //evocar_RAL(nuevo.codigo,&aux);
                    evocar_RS(nuevo.codigo,&aux);
                    break;

            }
        }
        printf("\n\nLa secuencia de operaciones ha finalizado\n\n");
        fclose(fp);
    }
    system("pause");
}


#endif // ESTRUCTURAS_H_INCLUDED
