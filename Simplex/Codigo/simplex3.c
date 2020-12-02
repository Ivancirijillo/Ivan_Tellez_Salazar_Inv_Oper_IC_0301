/**
*@file   simplex3.c
*@brief  Sección para las funciones del código.
*/
#include "simplex3.h"
/**
*@brief     Inserta 0 en toda la matriz.
*\details   Al ejecutarse llenara toda a matriz de 0.
*@param     m       Variable para la matriz.
*@param     f       Variable para el número de filas.
*@param     c       Variable para el número de columnas.
*\return    void.
*/
void insertar0(float m[][TAM],int f, int c){
	int i,j;
	for (i=0;i<f;i++){
		for (j=0;j<c;j++){
			m[i][j]=0;
		}
    } 
    m [f-1][0]=1; //Valor z
}
/**
*@brief     Imprime la cadena de dos dimesiones.
*\details   Al ejecutarse imprime la matriz en formato de tabla.
*@param     m       Variable para la matriz.
*@param     f       Variable para el número de filas.
*@param     c       Variable para el número de columnas.
*\return    void.
*/
void imprimir(float m[][TAM],int f, int c){
	int i,j;
   for (i=0;i<f;i++){
		for (j=0;j<c;j++){
			printf(" %f ",m[i][j]);
			if(j == c-1){
				printf("\n");
			}
		}
    }
}
/**
*@brief     Pide al usuario los datos de la función.
*\details   Al ejecutarse va a guardar los valores de la funcion en las variables "zx1" y "zx2".
*@param     m       Variable para la matriz.
*@param     f       Variable para el número de filas.
*\return    void.
*/
void introducir_funcion(float m[][TAM],int f){
	float zx1,zx2;
	printf("\n------Intruce la funcion a maximizar (Z)------\n");

	printf("Introduce la variable x1: ");
	scanf("%f", &zx1);
	zx1=zx1*-1;
	m [f-1][1]=zx1;
		
	printf("Introduce la variable x2: ");
	scanf("%f", &zx2);
	zx2=zx2*-1;
	m [f-1][2]=zx2;
}
/**
*@brief     Pide al usuario los valores de las restricciones.
*\details   Esta seccion contiene un for ya que se repetira segun elnumero de funciones de restriccion que el usuario introdujo.
*\details   Los datos de las funciones de restriccón se iran guardando en la matriz.
*@param     m       Variable para la matriz.
*@param     c       Variable para el número de columnas.
*@param     r       Variable para la cantidad de restricciones.
*\return    void.
*/
void introducir_restriccion(float m[][TAM],int c,int r){
	printf("\n------Introduce las %d funciones de restriccion------\n",r);
	int i;
	for(i=0;i<r;i++){
		printf("\nIntroduce x1 de la restriccion %d: ",i+1);
		scanf("%f", &m[i][1]);
		
	    printf("Introduce x2 de la restriccion %d: ",i+1);
	    scanf("%f", &m[i][2]);
		
	    printf("Introduce el resultado de la restriccion %d: ",i+1);
	    scanf("%f", &m[i][c-1]);		
		
		m[i][i+3]=1;
	} 
}
/**
*@brief     Busca cuál es la columna que tenga el dato de menor valor, esto para sacar el pivote.
*\details   El valor que se devuelva se usara para la función menorF.
*@param     m       Variable para la matriz.
*@param     f       Variable para el número de filas.
*@param     c       Variable para el número de columnas.
*\return    Regresa "noColumna" que es una variable de tipo entero la cual contiene el número de la columna con el dato menor.
*/
int menorC(float m[][TAM],int f,int c){
   float mC=m[f-1][0];
   int noColumna,i;
	for(i= 0; i<c-1; i++){
		if(m[f-1][i] < mC){
			mC = m[f-1][i];
			noColumna=i;
		}			
	}
	return (noColumna);
}
/**
*@brief     Busca cuál es la fila que tenga el dato de menor valor, esto para sacar el pivote.
*\details   Dentro de la funcion se hara una división de columnas se dividirá la columna actual entre los valores de la columna pivote.
*\details   Los valores que resulten de la división serán guardados en una matriz auxiliar, posteriormente se buscara cual es dato de menor valor.
*@param     m           Variable para la matriz.
*@param     f           Variable para el número de filas.
*@param     c           Variable para el número de columnas.
*@param     noColumna   Variable para almacenar el número de la columna con el valor menor.
*\return    Regresa "noFila" que es una variable de tipo entero la cual contiene el número de la fila con el dato menor.
*/
int menorF(float m[][TAM],int f,int c,int noColumna){
	float mF=m[0][c-1];
	int noFila,i;
	float matriz2[f][1];
	
	for(i=0;i<f-2;i++){
		matriz2[i][0]= m[i][c-1]/m[i][noColumna];
		if (matriz2[i][0]<mF){
			mF=matriz2[i][0];
			noFila=i;
		}
	}// Divide entre columna pivote
	return(noFila);
}
/**
*@brief     Divide todos los tados de la fila de menor valor entre el número pivote.
*\details   La fila con el menor valor es la fila obtenida de noFila().
*@param     m       Variable para la matriz.
*@param     c       Variable para el número de columnas.
*@param     noFila  Variable para almacenar el número de la fila con el valor menor.
*@param     piv     Variable para almacenar el número pivote.
*\return    void.
*/
void dividirentreP(float m[][TAM],int c, int noFila,int piv){
    	int i;
    	for(i=0;i<c;i++){
    		m[noFila][i]=m[noFila][i]/piv;
	}
}
/**
*@brief     Remplaza los valores de lla tabla para obtener el resultado final.
*\details   Remplaza los valores de todas las filas excepto el de la fila con menor valor, para eso al variable noFila.
*@param     m       Variable para la matriz.
*@param     noFila  Variable para almacenar el número de la fila con el valor menor.
*@param     noColumna   Variable para almacenar el número de la columna con el valor menor.
*@param     c       Variable para el número de columnas.
*@param     f           Variable para el número de filas.
*\return    void.
*/
void filanueva(float m[][TAM],int noFila,int noColumna,int c,int f){
	int i,j;
	for (i=0;i<noFila;i++){
    	float k=m[i][noColumna];
		for (j=0;j<c;j++){
			m[i][j]=m[i][j]-(k*m[noFila][j]);
			}
	}

    for (i=noFila+1;i<f;i++){
    	float k=m[i][noColumna];
		for (j=0;j<c;j++){
			m[i][j]=m[i][j]-(k*m[noFila][j]);
			}
	}	
}
