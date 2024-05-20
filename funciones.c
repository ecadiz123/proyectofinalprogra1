/*Desarrolladores:
Cristobal Gomez
Eduardo Rosas
Esteban Cadiz
Asignatura: Taller de Programacion I*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define X 80 // tamaño horizontal grafico
#define Y 25 // tamaño vertical grafico
/*coordenadas importantes:
centro: [12][40]*/
/*informe:
marco teorico:  bibliotecas que usamos, math.h
describir problema: funciones en consola
metodologia de trabbajo: replit, DISCOR*/

void printmatriz(char n[Y][X]) // funcion para imprimir matriz
{
    int i, j;
    for (i = 0; i < Y; i++)
    {
        for (j = 0; j < X; j++)
        {

            printf("%c", n[i][j]); // caracter para poder usar caracteres al dibujar funciones.
        }
        printf("\n");
    }
}

void llenarmatrizconlineas(char n[Y][X]) // funcion que crea los ejes del grafico como matriz
{
    int i, j;

    for (i = 0; i < Y; i++)
    {
        for (j = 0; j < X; j++)
        {
            n[i][j] = ' ';
        }
    }

    for (i = 0; i < Y; i++)
    {
        n[i][40] = 197; // asigna │
    }
    for (i = 0; i < X; i = i + 2)
    {
        n[12][i] = 197; // asigna cruces horizontal
    }
    for (i = 1; i < X; i = i + 2)
    {
        n[12][i] = 196; // asigna ─ horizontal
    }
    n[12][40] = 197; // asigna ┼
}
int recta(char matriz[Y][X])//funcion para imprimir recta
{
    int i, j, x, y, cotainf, cotasup;
    printf("Ingrese cota inferior(-40 hasta 40)\n");

    scanf("%d", &cotainf);
    printf("Ingrese cota superior\n");

    scanf("%d", &cotasup);
    if (cotainf >= cotasup)
    {
        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }
    if (40 < cotasup)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    if (-40 > cotainf)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    // for para funcion f(x)=x
    for (y = -12; y < Y; y++) // coordenada filas
    {
        for (x = cotainf; x <= cotasup; x++) // coordenada columna
        {

            if (x == y) // Funcion f(x)=x
            {
                matriz[12 - y][40 + 2 * x] = 42; //(0,0)=[12][40]
            }
        }
    }
}
int cuadratica(char matriz[Y][X])//funcion para la cuadratica
{
    int i, j, x, y, cotasup, cotainf;
    float xf, yf;
    // funcion y su equivalente en grafico
    /*
    Formula base para corresponder
    Matriz[12-y][40+2*x] <- parte positiva
    ej:x=10 y=10 matriz[2][60]
    */

    printf("Ingrese cota inferior (del -3 al 3)\n");

    scanf("%d", &cotainf);
    printf("Ingrese cota superior (del %d al 3)\n", cotainf);

    scanf("%d", &cotasup);

    if (cotainf >= cotasup)
    {
        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }
    if (3 < cotasup)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    if (-3 > cotainf)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    for (y = -12; y < 12; y++) // for para los (x,y)
    {
        for (x = cotainf; x <= cotasup; x++)
        {

            if (y == pow(x, 2))
            {

                matriz[12 - y][40 + 2 * x] = 42;
                matriz[11 - y][40 + 2 * x] = 42;
                matriz[10 - y][40 + 3 * x] = 42;
                matriz[9 - y][40 + 3 * x] = 42;
            }
        }
    }

    matriz[9][40] = 197;
    matriz[10][40] = 197;
    matriz[11][40] = 197;
}
int cubica(char matriz[Y][X])//funcion para la cubica
{
    int i, j, x, y, cotainf, cotasup;
    // funcion y su equivalente en grafico
    /*
    Formula base para corresponder
    Matriz[12-y][40+2*x] <- parte positiva
    ej:x=10 y=10 matriz[2][60]
    */

    printf("Ingrese cota inferior(del 1 al 3, esta incluira su inverso)\n");

    scanf("%d", &cotainf);
    printf("Ingrese un numero del %d al 3 para representar en la grafica como cota superior\n", cotainf);

    scanf("%d", &cotasup);
    if ((cotainf >= cotasup) || (cotainf || cotasup) > 3 || 1 < (cotainf || cotasup))
    {
        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    if (cotainf >= cotasup)
    {
        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }
    if ( 3 < cotasup)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    if (1> cotainf)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    for (y = 1; y < Y; y++) // for para los (x,y)
    {
        for (x = cotainf; x <= cotasup; x++)
        {
     // if para  hacer las lineas
            /*Se usaron puntos especificos para poder completar el dibujo de mejor manera.*/
            // if ((x == 1 && (1 <= y && y < 4)) || (x == 2 && (4 <= y && y < 9)) || (x == 3 && (9 <= y && y < 12)) || (x == 4 && y == 12))
            if (pow(x, 2) <= y && y < pow(x, 2) + 2) // esta formula se obtuvo tras generalizar los puntos antes mencionados.
            {
                matriz[12 - y][40 + 2 * x] = 42;
                matriz[12 + y][40 - 2 * x] = 42;
            }
    }
}}
int logaritmica(char matriz[Y][X])//funcion para la logaritmica
{

    int i = 0, j = 0, x = 0, y = 0, cotainf, cotasup;

    // funcion y su equivalente en grafico
    /*
    Formula base para corresponder
    Matriz[12-y][40+2*x] <- parte positiva
    ej:x=10 y=10 matriz[2][60]
    */
    printf("Ingrese cota inferior(del 0 al 16)\n");

    scanf("%d", &cotainf);
    if (cotainf == 0)
    {
        /*Este for es para que siempre esten los puntos
        de la asintota ya que es cuando se incluye todo del 0 al 1*/
        for (i = 0; i <= 6; i++)
        {

            matriz[12 + (2 * i + 1)][41] = 42;
        }
    }
    printf("Ingrese cota superior\n");

    scanf("%d", &cotasup);

    if (cotainf >= cotasup)
    {
        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }
    if (16 < cotasup)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    if (0 > cotainf)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    for (y = -12; y <= 12; y++) // for para los (x,y)
    {
        for (x = cotainf; x <= cotasup; x++)
        {
            // funcion log2
            if (y == log2(x))
            {
                matriz[12 - y][40 + 2 * x] = '*';
            }
            matriz[8][24] = ' ';
        }
    }
}
int seno(char matriz[Y][X])//funcion para el seno
{
    float xf = 0, yf = 0;
    int i = 0, j = 0, x = 0, y = 0, xi = 0, yi = 0, cotainferior = 0, cotasuperior = 0;

    /*
    Formula base para corresponder x,y a grafico correctamente
    Matriz[12-y][40+2*x]
    ej:x=10 y=10 matriz[2][60]

    Se va a trabajar con las formulas x*pi/36, ya que 36 es el
    minimo comun multiplo entre los senos de los angulos 30°,45°,60°
    multiplicado por 3 para que corresponda con los 40 x que hay en el grafico

    */
    printf("En este caso pi=18\n");
    printf("Ingrese cota inferior(de -36 a 36)\n");
    scanf("%d", &cotainferior);

    printf("Ingrese cota superior\n");
    scanf(" %d", &cotasuperior);

    if (cotainferior >= cotasuperior)
    {
        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }
    if (36 < cotasuperior)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    if (-36 > cotainferior)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    for (y = -12; y < 12; y++) // for para los (x,y)
    {
        for (x = cotainferior; x <= cotasuperior; x++)
        {
            /*se pasa de entero a flotante ya que la formula esta echa para
            numeros racionales, y despues se vuelve a int para ponerlo
            como posicion de matriz.*/
            xf = ((x * M_PI) / 36);
            yf = sin(xf) * 10; // se multiplica por 10 para obtener numeros que esten en el grafico.

            yi = yf;

            xi = 11 * xf; // valor 11 conseguido por tanteo para ampliar la funcion horizontalmente

            /*xi y yi son versiones enteras de x e y una vez entran en la formula.*/
            matriz[12 - (yi)][40 + (xi)] = 42;
        }
    }
}
int coseno(char matriz[Y][X])//funcion para coseno
{
    float xf = 0, yf;
    int i = 0, j = 0, x = 0, y = 0, xi = 0, yi = 0, cotasuperior, cotainferior;

    /*
     Formula base para corresponder x,y a grafico correctamente
     Matriz[12-y][40+2*x]
     ej:x=10 y=10 matriz[2][60]


    Se va a trabajar con las formulas x*pi/36, ya que 36 es el
    minimo comun multiplo entre los senos de los angulos 30°,45°,60°
    multiplicado por 3 para que corresponda con los 40 x que hay en el grafico
     */
    printf("En este caso pi=18\n");
    printf("Ingrese cota inferior(de -36 a 36)\n");
    scanf("%d", &cotainferior);

    printf("Ingrese cota superior\n");
    scanf(" %d", &cotasuperior);

    if (cotainferior >= cotasuperior)
    {
        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }
    if (36 < cotasuperior)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    if (-36 > cotainferior)
    {

        printf("Error se ingreso cotas no validas.");

        return EXIT_FAILURE;
    }

    for (y = -12; y < 12; y++) // for para los (x,y)
    {
        for (x = cotainferior; x <= cotasuperior; x++)
        {
            // xf= x en flotante
            xf = ((x * M_PI) / 36);
            yf = cos(xf) * 10;

            yi = yf;

            xi = 11 * xf;

            matriz[12 - (yi)][40 + (xi)] = 42;
        }
    }
}
int main(void)
{
    int input, j;
    char matriz[Y][X]; // el grafico será representado mediante matriz.
    /*Primero se imprime el menu para dar las opciones*/
    printf("INGRESE NUMERO FUNCION \n\n");

    printf("1.Recta\n");
    printf("2.Cuadratica\n");
    printf("3.Cubica\n");
    printf("4.Logaritmica\n");
    printf("5.Seno\n");
    printf("6.Coseno\n");
    scanf("%d", &input);
    /*luego se llena una matriz con el grafico*/
    llenarmatrizconlineas(matriz);

    switch (input) // switch para el menu basado en el input
    {
    case 1:
        if (recta(matriz) == 1) // if que se repite en todos los casos: si ocurre error en la funcion, programa termina sin imprimir.
        {
            return EXIT_FAILURE;
        }
        else
            printmatriz(matriz);
        break;

    case 2:
        if (cuadratica(matriz) == 1)
        {
            return EXIT_FAILURE;
        }
        else
            printmatriz(matriz);
        break;
    case 3:

        if (cubica(matriz) == 1)
        {
            return EXIT_FAILURE;
        }
        else

            printmatriz(matriz);
        break;
    case 4:
        if (logaritmica(matriz) == 1)
        {
            return EXIT_FAILURE;
        }
        else
            printmatriz(matriz);
        break;
    case 5:
        if (seno(matriz) == 1)
        {
            return EXIT_FAILURE;
        }
        else
            printmatriz(matriz);
        break;
    case 6:
        if (coseno(matriz) == 1)
        {
            return EXIT_FAILURE;
        }
        else
            printmatriz(matriz);
        break;
    default:
        printf("Ingrese numero que corresponda a una funcion valida");
        return EXIT_FAILURE;
        break;
    }

    return 0;
}