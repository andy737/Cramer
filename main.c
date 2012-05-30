/*Programa que resuelve un sistema de ecuaciones de 2x2 o 3x3, mediante el uso de la regla de Cramer.
*Creado por: Andr�s de Jes�s Hern�ndez Mart�nez
*Grupo: 7ITI1
*Fecha de creaci�n: 27 mayo de 2012
*Fecha de la �ltima modificaci�n: 29 mayo de 2012
*/

//Declaracion de librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

//Declaraci�n de variables globales
int f, c;

//Declaraci�n de funciones
void calcula(int dim, float ar[f][c]);

//Funci�n encargada de  mostrar en consola, la petici�n
//de variables para resolver el sistema de ecuaciones
void ingresa(void)
{
    //Declaraci�n de variables locales
    int dim,i,j ;
    char *letra[4]= {"a","b","c","d"};
    float ar[f][c];

    //Declaraci�n de la dimensi�n de la matriz
    dim=f*c;
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            //Valida que solo se ingresen numeros
            do
            {
                system("cls");
                printf("Introduce el valor de la variable %s%d :  ", letra[j],i+1 );
                fflush (stdin);
            }
            while(scanf("%f",  &ar [i][j])!=1);

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
        puts("\n");
    }

    printf("\nPresiona cualquier tecla para continuar.");
    getch();

    //Lamada a la funci�n calcula, pasando parametros
    calcula(dim, ar);
}

//Funci�n encargada de calcular el sistema de ecuaciones 2x2 y 3x3
void calcula(int dim, float ar[f][c])
{
    //Declaraci�n de variables locales
    float delta,x=0,y=0,z=0;

    //Limpia la pantalla de la consola
    system("cls");

    //Resuelve el sistema 2x2
    if(dim==6)
    {
        printf("Soluci�n al sistema de ecuaciones 2x2\n\n");
        delta=ar[0][0]*ar[1][1]-ar[0][1]*ar[1][0];
        x=(ar[0][2]*ar[1][1]-ar[0][1]*ar[1][2])/delta;
        y=(ar[0][0]*ar[1][2]-ar[0][2]*ar[1][0])/delta;
        printf("\nx =  %.2f", x);
        printf("\ny =  %.2f", y);
    }
    //Resuelve el sistema 3x3
    else
    {
        printf("Soluci�n al sistema de ecuaciones 3x3\n\n");
        delta=ar[0][0]*ar[1][1]*ar[2][2]+ar[0][1]*ar[1][2]*ar[2][0]+ar[0][2]*ar[1][0]*ar[2][1]-ar[0][2]*ar[1][1]*ar[2][0]-ar[0][1]*ar[1][0]*ar[2][2]-ar[0][0]*ar[1][2]*ar[2][1];
		//Valida divisi�n por cero
		if(delta!=0){
			x=(ar[0][3]*ar[1][1]*ar[2][2]+ar[0][1]*ar[1][2]*ar[2][3]+ar[0][2]*ar[1][3]*ar[2][1]-ar[0][2]*ar[1][1]*ar[2][3]-ar[0][1]*ar[1][3]*ar[2][2]-ar[0][3]*ar[1][2]*ar[2][1])/delta;
			y=(ar[0][0]*ar[1][3]*ar[2][2]+ar[0][3]*ar[1][2]*ar[2][0]+ar[0][2]*ar[1][0]*ar[2][3]-ar[0][2]*ar[1][3]*ar[2][0]-ar[0][3]*ar[1][0]*ar[2][2]-ar[0][0]*ar[1][2]*ar[2][3])/delta;
			z=(ar[0][0]*ar[1][1]*ar[2][3]+ar[0][1]*ar[1][3]*ar[2][0]+ar[0][3]*ar[1][0]*ar[2][1]-ar[0][3]*ar[1][1]*ar[2][0]-ar[0][1]*ar[1][0]*ar[2][3]-ar[0][0]*ar[1][3]*ar[2][1])/delta;
			//printf("\nd =  %.2f", delta);
			printf("\nx =  %.2f", x);
			printf("\ny =  %.2f", y);
			printf("\nz =  %.2f", z);
		}
		else{
		
		printf("\nEl sistema de ecucaciones no tiene soluci�n.");
		
		}
        
    }

    printf("\n\nPresiona cualquier tecla para continuar.");
}

//Funci�n encargada de liberar memoria usada por la matriz

int main()
{
    //Declaraci�n de variables locales
    char op[1];

    //Despliega el men� de la aplicaci�n
    do
    {
        //Limpia la pantalla de la consola
        system("cls");
        printf("Programa para resolver conjuntos de ecuaciones 2x2 y 3x3 (Regla de Cramer).\n\n");
        printf("Selecciona una opci�n del men�:\n");
        printf("\t1 Resolver conjunto de ecuaci�nes 2x2.\n");
        printf("\t2 Resolver conjunto de ecuaci�nes 3x3.\n");
        printf("\t3 Salir.\n");
        printf("\nIngresa la opci�n: ");
        scanf("%c", &op);
        //Permite seleccionar alguna de las opciones del men�
        switch(op[0])
        {
            //Opci�n 1 "Resolver sistemas 2x2"
        case '1':
            system("cls");
            c=3;
            f=2;
            ingresa();
            getch();
            break;
            //Opci�n 2 "Resolver sistemas 3x3"
        case '2':
            system("cls");
            f=3;
            c=4;
            ingresa();
            getch();
            break;

        }
    }
    while(op[0]!='3'); //Mientras la opcion seleccionada sea diferente de 3 el men� se vuelve a desplegar en pantalla
    //Finaliza la ejecuci�n de la aplicaci�n
    system("cls");
    return 0;
}
