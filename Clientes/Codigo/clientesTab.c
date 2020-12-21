/**
*@file   clientesTab.c
*@brief  Sección para las funciones del código.
*/
#include "clientesTab.h"
/**
*@brief     Imprime la matriz en forma de tabla.
*\details   Al ejecutarse imprimira fila por fila la tabla.
*@param     horas     Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en los ciclos "for".
*@param     matriz    En esa matriz estan guardados los datos que el usuario introdujo y los que se añadieron con los calculos.
*\return    void.
*/
void imprimir(int horas, int matriz[7][TAM]){
	int i,j;   
	printf("\n|     Clientes    | ");
	for (i=0;i<horas;i++){
		printf("%d\t",matriz[0][i]);
    }
    
	printf("\n|      Cajas      | ");
    for (i=0;i<horas;i++){
		printf("%d\t",matriz[1][i]);
    }
    
	printf("\n|Capacidad salidas| ");
    for (i=0;i<horas;i++){
		printf("%d\t",matriz[2][i]);
    }
    
	printf("\n| Salida clientes | ");
    for (i=0;i<horas;i++){
		printf("%d\t",matriz[3][i]);
    }
    
	printf("\n| Cola de espera  | ");
	for (i=0;i<horas;i++){
		printf("%d\t",matriz[4][i]);
    }
    
    printf("\n|      Input      | ");
	for (i=0;i<horas;i++){
		printf("%d\t",matriz[5][i]);
    }
    
	printf("\n|      Output     | ");
	for (i=0;i<horas;i++){
		printf("%d\t",matriz[6][i]);
    }
    
    printf("\n------------");
    for (i=0;i<horas;i++){
		printf("--------");
    }
}
/**
*@brief     Solicita el usuario los datos de hora de inicio-fin, el número de cajas y el número de clientes en espera.
*\details   Esta seccion contiene un for ya que se repetira segun elnumero de horarios que introdujo el usuario con anterioridad en la sección main.
*@param     horas          Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en el cliclo "for".
*@param     horasMatriz    En esta matriz se iran guardando los datos de la hora de inicio y fin.
*@param     matriz         En esta matriz se guardaran los datos de los clientes y el numero de cajas.
*\return    void.
*/
void llenadoDatos(int horas, int horasMatriz[][2],int matriz[7][TAM]){
	int i;
	for(i=0;i<horas;i++){
		printf("\n***********Horario %d***********",(i+1));
		printf("\nIntroduzca la hora de inicio: ");
		scanf("%d", &horasMatriz[i][0]);
		
		printf("Introduzca la hora de fin: ");
		scanf("%d", &horasMatriz[i][1]);
		
		printf("Introduzca el numero de clientes: ");
		scanf("%d", &matriz[0][i]);
		
		printf("Introduzca el numero de cajas abiertas: ");
		scanf("%d", &matriz[1][i]);
	}
	printf("\n******************************\n");
}
/**
*@brief     Se realiza el calculo correspondiente a la capcidad de salida.
*\details   Al ejecutarse llenara la sección matriz[2[[i].
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en ciclo "for".
*@param     capaciad   En esta variable se guarda cual es la capacidad de atender clientes.
*@param     matriz     Con esta matriz se realizarn los calculos para la capcidad de salida con los valores introducidos en llenadoDatos().
*\return    void.
*/
void capacidadSalida(int rango, int capaciad, int matriz[7][TAM]){
	int i;
	for (i=0;i<rango;i++){
		matriz[2][i]=matriz[1][i]*capaciad;
    }
}
/**
*@brief     Se realiza el calculo correspondiente a la salida de clientes y a la cola de espera.
*\details   Al ejecutarse llenara la sección matriz[3][i] y matriz[4][i].
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en ciclo "for".
*@param     matriz     Se utilizan los datos de la matriz para obtener nuevos datos e irlos guardando.
*\return    void.
*/
void salidaClientes(int rango, int matriz[7][TAM]){
	int i;
	if(matriz[0][0]>=matriz[2][0]){
		matriz[3][0]=matriz[2][0];
		matriz[4][0]=matriz[0][0]-matriz[2][0];
	}
	else{
		matriz[3][0]=matriz[0][0];
		matriz[4][0]=0;		
	}
	
	if(rango>1){
		for(i=1;i<rango;i++){
			if(matriz[0][i]+matriz[4][i-1]>=matriz[2][i]){
				matriz[3][i]=matriz[2][i];
		        matriz[4][i]=(matriz[0][i]+matriz[4][i-1])-matriz[2][i];
			}
			else{
				matriz[3][i]=matriz[0][i]+matriz[4][i-1];
	        	matriz[4][i]=0;	
			}
		}
	}
}
/**
*@brief     Se realiza el calculo correspondiente para Input.
*\details   Al ejecutarse llenara la sección matriz[5][i].
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en los cliclos "if" y "for".
*@param     matriz     Se utilizan los datos de la matriz para obtener nuevos datos e irlos guardando.
*\return    void.
*/
void input(int rango, int matriz[7][TAM]){
	int i;
	matriz[5][0]=matriz[0][0];
	
	if(rango>1){
		for(i=1;i<rango;i++){
			matriz[5][i]=matriz[5][i-1]+matriz[0][i];
		}
	}
}
/**
*@brief     Se realiza el calculo correspondiente para Output.
*\details   Al ejecutarse llenara la sección matriz[6][i].
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en los cliclos "if" y "for".
*@param     matriz     Se utilizan los datos de la matriz para obtener nuevos datos e irlos guardando.
*\return    void.
*/
void output(int rango, int matriz[7][TAM]){
	int i;
	matriz[6][0]=matriz[3][0];
	
	if(rango>1){
		for(i=1;i<rango;i++){
			matriz[6][i]=matriz[6][i-1]+matriz[3][i];
		}
	}
}
/**
*@brief     Con los datos obtenidos de Input y Output se realiza una recomendación.
*\details   Al ejecutarse hara un calculo para determinar cuantas cajas se necesitan para atender a todos los clientes que faltaron (si es que faltaron) y en que horario seria correcto ponerlas.
*           El horario en el que se recomienda colocar la caja es en el cual esta la cola de espera más grande.
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en los cliclos "if" y "for".
*@param     matriz     Esta matriz es utilizada para determinar si se necesitan caajs extra.
*@param     capaciad   En esta variable se guarda cual es la capacidad de atender clientes.
*\return    void.
*/
void recomendacion(int rango, int matriz[7][TAM],int capaciad){
	int caja=0,i,mayor=0,posicion;
	printf("\n\nNOTA: ");
	if (matriz[5][rango-1]>matriz[6][rango-1]){
		
		for (i=0;i<rango;i++){
			if(matriz[4][i]>mayor){
				mayor=matriz[4][i];
				posicion=i+1;
			}
        }
		
		if ((matriz[5][rango-1]-matriz[6][rango-1])>capaciad){
			if((matriz[5][rango-1]-matriz[6][rango-1])%capaciad==0){
				caja=(matriz[5][rango-1]-matriz[6][rango-1])/capaciad;
				printf("Usted necesita %d extras en el horario numero %d.",caja,posicion);
			}
			else{
				caja=((matriz[5][rango-1]-matriz[6][rango-1])/capaciad)+1;
				printf("Usted necesita %d extras en el horario numero %d.",caja,posicion);
			}
		}
		else{
			printf("Usted necesita una caja extra en el horario numero %d.",posicion);
	    }
	}
	else{
		printf("No necesita ninguna caja extra.");
	}
}

