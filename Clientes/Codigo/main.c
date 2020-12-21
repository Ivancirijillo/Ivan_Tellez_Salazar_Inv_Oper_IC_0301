/**
*@file      main.c 
*@brief     Sección principal del código.
*@author    Iván Téllez Salazar.
*@date      19-12-2020 (código).
*@date      21-12-2020 (documentación).
*@todo      Modificar impresion de hora.
*
*@param     i               Variable auxiliar para estructura "for".
*@param     nHoras          Es para establecer cuantos horarios hay. 
*@param     capacidad       La capacidad de atender clientes.
*@param     mHoras          En esta matriz de 2 columnas se guardara la hora de inicio y final de cada horario.
*@param     tablaClientes   En essa matriz se guardaran los datos que el usuario introduzca y se guardaran los calculos posteriores.
*/
#include <stdio.h>
#include <stdlib.h>
#include "clientesTab.h"

int main(int argc, char *argv[]) {
	int nHoras, capacidad,i;
	
	printf("Introduzca el numero de horarios: ");
	scanf("%d", &nHoras);
	int mHoras [nHoras][2], tablaClientes [7][nHoras];

	llenadoDatos(nHoras,mHoras,tablaClientes);
	
	printf("Introduzca la capacidad de atencion de clientes: ");
	scanf("%d", &capacidad);

	printf("\n------------");
    for (i=0;i<nHoras;i++){
		printf("--------");
    }
	printf("\n|       Hora      | ");
	for (i=0;i<nHoras;i++){
		printf("%d-%d\t",mHoras[i][0],mHoras[i][1]);
    }
	printf("\n------------");
    for (i=0;i<nHoras;i++){
		printf("--------");
    }
    
	capacidadSalida(nHoras,capacidad,tablaClientes);
	salidaClientes(nHoras,tablaClientes);
	input(nHoras,tablaClientes);
	output(nHoras,tablaClientes);

	imprimir(nHoras,tablaClientes);
	recomendacion(nHoras,tablaClientes,capacidad);
	printf("\a");
	return 0;
}
