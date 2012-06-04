/*Programa que resuelve un sistema de ecuaciones de 2x2 o 3x3, mediante el uso de la regla de Cramer.
*Creado por: Andrés de Jesús Hernández Martínez
*Grupo: 7ITI1
*Fecha de creación: 27 mayo de 2012
*Fecha de la última modificación: 29 mayo de 2012
*/

//Declaracion de librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//Declaración de variables globales
int f, c;

//Declaración de funciones
void calcula(int dim, float ar[f][c]);
int error(int tmp);
int valida(char array[]);
//Validación de números flotantes y enteros (+,-)
int validaFE(char array[])
{
    //Declaración de variables locales
    int i, val=0, cont=0,tam=0;
    while(array[tam]!='\0')//Calcula el tamaño del array
        tam++;
    if((array[0]!='.')&&(array[0]!=13)&&(array[tam]!='.')&&tam<=5)//Valida que al inicio y al final del array no contenga un punto y que el número maximo de dígitos sea 5
    {
        for(i=0; i<tam; i++)
        {

            if(array[0]=='-')//Valida signo negativo en los numeros
            {

                if(((array[i]<=57)&&(array[i]>=48)&&(cont<=1))||(array[i]=='.'))//Valida que el array sea un numero flotante o entero
                {
                    if(array[i]=='.')
                    {
                        cont++;
                    }

                    val=1;

                }
                else
                {
                    if(i!=0)
                    {
                        val=0;
                        break;
                    }

                }
            }
            else//Signo positivo en los numeros
            {
                if(((array[i]<=57)&&(array[i]>=48)&&(cont<=1))||(array[i]=='.'))//Valida que el array sea un numero flotante o entero
                {

                    if(array[i]=='.')
                    {
                        cont++;
                    }

                    val=1;

                }
                else
                {

                    val=0;
                    break;


                }
            }
        }
    }

    return val;

}
//Validación de error de entrada de datos
int error(int tmp)
{
    if(tmp>0)
    {
        system("cls");
        printf("\nEntrada de datos incorrecta.(Presiona cualquier tecla para continuar)");
        getch();
        tmp=0;
    }
    else
    {
        tmp=0;
    }
    return tmp;

}
//Función encargada de  mostrar en consola, la petición
//de variables para resolver el sistema de ecuaciones
void ingresa(void)
{
    //Declaración de variables locales
    int dim,i,j,tmp=0,val;
    float ar[f][c];

    //Declaración de arreglo estatico
    char letra[5]= {'a','b','c','d','\0'};
    char arr[10];

    //Declaración de la dimensión de la matriz
    dim=f*c;

    //Llena el arreglo dinamico
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            //Valida que solo se ingresen numeros

            do
            {
                tmp=error(tmp);//Llamada a la función validar entrada
                system("cls");//Limpia la pantalla de consola
                printf("Introduce el valor(máximo 5 dígitos #.###,#####,-#.## o -####) de la variable %c%d: ", letra[j],i+1 );
                fflush (stdin);//Limpia el buffer de entrada
                gets(arr);//Recibe la entrada del teclado y al almacena en el array
                val=validaFE(arr);//Llama a la funcion validar numeros
                if(val==1)//Verificador de entero o flotante
                {
                    ar[i][j]=atof(arr);//Convierte el array en un numero flotante
                }
                tmp++; //Verificador de error
            }
            while(val==0);   //Si = 0 entonces el caracter ingresado no es un numero
            tmp=0;
        }
    }

    //Imprime la matriz ordenada
    puts("\nMatriz ordenada.\n");
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("%.2f  ", ar[i][j]);
        }
        puts("\n");//Imprime un salto de linea y da un retorno de carro
    }

    printf("\nPresiona cualquier tecla para continuar.");
    getch();//Espera hasta que una tecla es pulsada

    //Lamada a la función calcula, pasando parametros
    calcula(dim, ar);
}

//Función encargada de calcular el sistema de ecuaciones 2x2 y 3x3
void calcula(int dim, float ar[f][c])
{
    //Declaración de variables locales
    float delta,x=0,y=0,z=0;

    //Limpia la pantalla de la consola
    system("cls");

    //Resuelve el sistema 2x2
    if(dim==6)
    {
        printf("Solución al sistema de ecuaciones 2x2.\n\n");
        //Determina valor delta
        delta=ar[0][0]*ar[1][1]-ar[0][1]*ar[1][0];
        //Valida división por cero
        if(delta!=0)
        {
            //Resolución por metodo de Cramer
            x=(ar[0][2]*ar[1][1]-ar[0][1]*ar[1][2])/delta;
            y=(ar[0][0]*ar[1][2]-ar[0][2]*ar[1][0])/delta;
            //Imprime resultados
            printf("\nx =  %.2f", x);
            printf("\ny =  %.2f", y);
        }
        else
        {

            printf("\nEl sistema de ecucaciones no tiene solución.");

        }
    }
    //Resuelve el sistema 3x3
    else
    {
        printf("Solución al sistema de ecuaciones 3x3.\n\n");
        //Determina valor delta
        delta=ar[0][0]*ar[1][1]*ar[2][2]+ar[0][1]*ar[1][2]*ar[2][0]+ar[0][2]*ar[1][0]*ar[2][1]-ar[0][2]*ar[1][1]*ar[2][0]-ar[0][1]*ar[1][0]*ar[2][2]-ar[0][0]*ar[1][2]*ar[2][1];
        //Valida división por cero
        if(delta!=0)
        {
            //Resolución por metodo de Cramer
            x=(ar[0][3]*ar[1][1]*ar[2][2]+ar[0][1]*ar[1][2]*ar[2][3]+ar[0][2]*ar[1][3]*ar[2][1]-ar[0][2]*ar[1][1]*ar[2][3]-ar[0][1]*ar[1][3]*ar[2][2]-ar[0][3]*ar[1][2]*ar[2][1])/delta;
            y=(ar[0][0]*ar[1][3]*ar[2][2]+ar[0][3]*ar[1][2]*ar[2][0]+ar[0][2]*ar[1][0]*ar[2][3]-ar[0][2]*ar[1][3]*ar[2][0]-ar[0][3]*ar[1][0]*ar[2][2]-ar[0][0]*ar[1][2]*ar[2][3])/delta;
            z=(ar[0][0]*ar[1][1]*ar[2][3]+ar[0][1]*ar[1][3]*ar[2][0]+ar[0][3]*ar[1][0]*ar[2][1]-ar[0][3]*ar[1][1]*ar[2][0]-ar[0][1]*ar[1][0]*ar[2][3]-ar[0][0]*ar[1][3]*ar[2][1])/delta;
            //printf("\nd =  %.2f", delta);
            //Imprime resultados
            printf("\nx =  %.2f", x);
            printf("\ny =  %.2f", y);
            printf("\nz =  %.2f", z);
        }
        else
        {

            printf("\nEl sistema de ecucaciones no tiene solución.");

        }

    }

    printf("\n\nPresiona cualquier tecla para continuar.");
}

int main()
{
    //Declaración de variables locales
    int op;
    //Despliega el menú de la aplicación
    do
    {
        system("cls");//Limpia la pantalla de la consola
        printf("Programa para resolver conjuntos de ecuaciones 2x2 y 3x3 (Regla de Cramer).\n\n");
        printf("Selecciona una opción del menú:\n");
        printf("\t1 Resolver conjunto de ecuaciónes 2x2.\n");
        printf("\t2 Resolver conjunto de ecuaciónes 3x3.\n");
        printf("\t3 Salir.\n");
        printf("\nIngresa la opción: ");
        fflush (stdin);//Limpia el buffer de entrada
        scanf("%i", &op);//Recibe el caracter de entrada
        //Permite seleccionar alguna de las opciones del menú
        switch(op)
        {
            //Opción 1 "Resolver sistemas 2x2"
        case 1:
            system("cls");
            //Determina No. de columnas y filas en matriz
            c=3;
            f=2;
            ingresa();
            getch();//Espera hasta que una tecla es pulsada
            break;
            //Opción 2 "Resolver sistemas 3x3"
        case 2:
            system("cls");
            //Determina No. de columnas y filas en matriz
            f=3;
            c=4;
            ingresa();
            getch();//Espera hasta que una tecla es pulsada
            break;
        case 3:
            system("cls");
            //Finaliza la ejecución de la aplicación
            return(0);
            break;
            //Evalua las opciones no validas
        default:
            printf("\nOpción incorrecta.(Presiona cualquier tecla para continuar)");
            getch();
            break;
        }
    }
    while(op!=3); //Mientras la opcion seleccionada sea diferente de 3 el menú se vuelve a desplegar en pantalla
    system("cls");
    //Finaliza la ejecución de la aplicación
    return 0;
}
