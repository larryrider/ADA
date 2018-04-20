// Lawrence Arhur Rider Garcia
// gnuplot GraficoQuickshort.gnu


#include <sys/resource.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

/*****************************************************
Nombre funcion: tiempo(void)
Proposito: Calcular el tiempo de CPU de este proceso
(y sólo de este proceso)
Parametros de entrada: nada
Devuelve: El tiempo empleado en segundos
******************************************************/
long double tiempo(void){
 	struct rusage usage;
 	getrusage(RUSAGE_SELF,&usage);
 	return((long double) usage.ru_utime.tv_sec+(long double) usage.ru_utime.tv_usec/1e6);
}

/******************************************************************
quicksortCentral(int * v, long pi, long pf)

Algoritmo de ordenación Quicksort tomando como pivote el
elemento del vector que ocupa la posición central
*******************************************************************/
void quicksortCentral(int * v, long pi, long pf){
	long i,j;
	int pivote,aux; 
	if (pi<pf) {
		i=pi; j=pf;
		pivote=v[(i+j)/2];
		do {
			while (v[i]<pivote) i++;
			while (v[j]>pivote) j--;
			if (i<=j) {
				aux=v[i]; v[i]=v[j]; v[j]=aux;
				i++; j--;
			}
		} while (i<=j);
		if (pi<j) 
			quicksortCentral(v,pi,j);
		if (i<pf) 
			quicksortCentral(v,i,pf);
	}
}

int main(){
	long double t1,t2,tiempototal=0,media=0;
	long talla;
	int * vector;
	
	srand(getpid()+time(0));
	
	for (int i=12; i<23;i++){  //9 tamanyos
		talla=powl(2,i);
		vector= new int [talla];
		media=0;
		
		for (int j=0;j<30;j++){  //30 veces para el mismo tamanyo
			for (int k=0;k<talla;k++){ //rellenamos el vector cada vez
				vector[k]=rand();
			}
			if (vector!=NULL){
				t1=tiempo();
				quicksortCentral(vector,0, talla-1);
				t2=tiempo();
				tiempototal=t2-t1;
				media+=tiempototal; //guardamos en media el tiempo total de cada vez
			}
		}
		cout<<talla<<" "<<media/30<<endl;
		if (vector!=NULL){
			delete[] vector;
		}
	}
	return 0;
}
