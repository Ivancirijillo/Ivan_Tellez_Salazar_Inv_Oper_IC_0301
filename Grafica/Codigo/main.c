/**
*@file      main.c
*@author    Iván Téllez Salazar.
*@date      24-11-2020 (código).
*@date      24-11-2020 (documentación).
*
*@brief     Sección principal del código.
*\details "Este software utiliza la biblioteca gnuplot_i escrita por N.Devillard <ndevilla@free.fr>"
*
*\details Mi trabajo esta incluido en las lineas 36 de gnuplot_i.h y 72 gnuplot_i.c
*
*@param     m        Guarda el dato "m" de la funcion.
*@param     b        Guarda el dato "r" de la funcion.
*@param     r1       Para alojar el rango inferior o izquierdo. 
*@param     r2       Para alojar el rango superior o derecho.
*@param     tiempo   Permite al usuario elegir cuanto tiempo puede ver la grafica.
*
*@todo      Mejorar el aspecto de la tabla generada por el programa
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "gnuplot_i.h"

int main() {
	int m,b,r1,r2,tiempo;
	    
    printf("======Grafica de una funcion y=mx+b======\a\n");
    printf("Ingresa el valor m: ");
	scanf("%d", &m);
	printf("Ingresa el valor b: ");
	scanf("%d", &b);
	printf("Rango inicial (en eje x): ");
	scanf("%d", &r1);
	printf("Rango final (en eje x): ");
	scanf("%d", &r2);
	printf("Introduce un tiempo de visualizacion del grafico (seg): ");
	scanf("%d", &tiempo);
		
	tablaC(r1,r2,m,b);
	graficar(r1,r2,m,b,tiempo);
	
	printf("\n\n============Vuelva pronto uwu============\a");
	return 0;
}
