/**
*@file   clientesTab.h
*@brief  Sección para las llamadas de las funciones.
*/
#ifndef __clientesTab_h
#define __clientesTab_h
#define TAM 24
#include <stdio.h>
/**
*@brief     Imprime la matriz en forma de tabla.
*\details   Al ejecutarse imprimira fila por fila la tabla.
*@param     horas     Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en los ciclos "for".
*@param     matriz    En esa matriz estan guardados los datos que el usuario introdujo y los que se añadieron con los calculos.
*\return    void.
*/
void imprimir(int horas,int matriz[7][TAM]);
/**
*@brief     Solicita el usuario los datos de hora de inicio-fin, el número de cajas y el número de clientes en espera.
*\details   Esta seccion contiene un for ya que se repetira segun elnumero de horarios que introdujo el usuario con anterioridad en la sección main.
*@param     horas          Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en el cliclo "for".
*@param     horasMatriz    En esta matriz se iran guardando los datos de la hora de inicio y fin.
*@param     matriz         En esta matriz se guardaran los datos de los clientes y el numero de cajas.
*\return    void.
*/
void llenadoDatos(int horas, int horasMatriz[][2],int matriz[7][TAM]);
/**
*@brief     Se realiza el calculo correspondiente a la capcidad de salida.
*\details   Al ejecutarse llenara la sección matriz[2[[i].
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en ciclo "for".
*@param     capaciad   En esta variable se guarda cual es la capacidad de atender clientes.
*@param     matriz     Con esta matriz se realizarn los calculos para la capcidad de salida con los valores introducidos en llenadoDatos().
*\return    void.
*/
void capacidadSalida(int rango, int capaciad, int matriz[7][TAM]);
/**
*@brief     Se realiza el calculo correspondiente a la salida de clientes y a la cola de espera.
*\details   Al ejecutarse llenara la sección matriz[3][i] y matriz[4][i].
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en ciclo "for".
*@param     matriz     Se utilizan los datos de la matriz para obtener nuevos datos e irlos guardando.
*\return    void.
*/
void salidaClientes(int rango, int matriz[7][TAM]);
/**
*@brief     Se realiza el calculo correspondiente para Input.
*\details   Al ejecutarse llenara la sección matriz[5][i].
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en los cliclos "if" y "for".
*@param     matriz     Se utilizan los datos de la matriz para obtener nuevos datos e irlos guardando.
*\return    void.
*/
void input(int rango, int matriz[7][TAM]);
/**
*@brief     Se realiza el calculo correspondiente para Output.
*\details   Al ejecutarse llenara la sección matriz[6][i].
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en los cliclos "if" y "for".
*@param     matriz     Se utilizan los datos de la matriz para obtener nuevos datos e irlos guardando.
*\return    void.
*/
void output(int rango, int matriz[7][TAM]);
/**
*@brief     Con los datos obtenidos de Input y Output se realiza una recomendación.
*\details   Al ejecutarse hara un calculo para determinar cuantas cajas se necesitan para atender a todos los clientes que faltaron (si es que faltaron) y en que horario seria correcto ponerlas.
*           El horario en el que se recomienda colocar la caja es en el cual habia una cola de espera más grande.
*@param     rango      Tiene guardado el número de horarios que hay por lo que se utiliza como un rango en los cliclos "if" y "for".
*@param     matriz     Esta matriz es utilizada para determinar si se necesitan caajs extra.
*@param     capaciad   En esta variable se guarda cual es la capacidad de atender clientes.
*\return    void.
*/
void recomendacion(int rango, int matriz[7][TAM],int capaciad);

#endif
