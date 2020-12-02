/**
*@file   principalruta.c
*@brief  Sección principal.
*@author Iván Téllez Salazar.
*@date   20-10-2020 (código).
*@date   02-10-2020 (documentación).
*@todo   Mejorar la sección principal del código. 
*
*@param     nodos       Guarda el número de nodos del grafo.
*@param     adya        Guarda el número de adyacencias del grafo.
*@param     filcol      Se puede omitir el uso de esta variable ya que el contenido es igual a la variable nodos, se usa para evitar confusiones. 
*@param     a           Para alojar el punto "A" de la ruta.
*@param     b           Para alojar el punto "B" de la ruta.
*@param     matriz      Área para representar el grafo en forma de tabla (matriz principal).
*@param     grafo       Matriz auxiliar para el uso de recursividad      (matriz secundaria).
*@param     aux         Variable auxiliar para la función recursiva.
*@param     r           Se guarda el resultado de la funcion de recursividad.
*@param     r2          Sirve para el uso de una estructura de repetición.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ruta.h"

int main(){
			
	int a,b,filcol,nodos,adya,r,r2=0,aux=0;
    int matriz [TAM][TAM]; 
    int grafo [TAM][2];
	
	printf("============Existe una ruta?============\n");	
	printf("Introduce el numero de nodos que hay: ");
	scanf("%d", &nodos);
	
	filcol=nodos;
	imprimir(matriz,filcol);
	insertar0(matriz,filcol);	//rellenar 0
	printf("\n----------Cuantas adyacencias hay?----------\n");
	scanf("%d", &adya);
	introducir_adya(grafo,matriz,adya); 
	imprimir(matriz,filcol);   
	  
	while(r2==0){//inicio while 
	printf("\n-----------Que ruta desea buscar?-----------\n");
	printf("Punto A: ");
	scanf("%d", &a);
	printf("Punto B: ");
	scanf("%d", &b);
	
	r=buscar(grafo,matriz,a,b,filcol,aux);
	if (r==1){
		printf("\n------->SI hay ruta");
	}
	else {
		printf("\n------->NO hay ruta");
	}
	printf("\n\nPara buscar otra ruta oprima 0\nSi desea salir oprima 1:\n\a");
	scanf("%d", &r2);
	}	//fin while 
	printf("\n\n============Ok Vuelva pronto uwu============\a");
	
return 0;
}
