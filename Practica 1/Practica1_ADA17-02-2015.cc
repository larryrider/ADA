// Lawrence Arthur Rider Garcia
// ./burbuja > tablatiempos

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
	return( (long double) usage.ru_utime.tv_sec + (long double) usage.ru_utime.tv_usec/1e6);
}
                                
/******************************************************************
burbuja(int * v, unsigned long talla){

Algoritmo de ordenación burbuja sin ninguna mejora             
*******************************************************************/
void burbuja(int * v, unsigned long talla){
	int aux;
                                    
	for (unsigned long i=1; i<talla; i++){
		for (unsigned long j=0; j<talla-i; j++){
			if (v[j]>v[j+1]){  /*swap*/
				aux=v[j]; 
				v[j]=v[j+1]; 
				v[j+1]=aux;
			}
		}
	}
}

int main(){
	long double t1,t2,tiempototal;
	long talla;
	int * vector;
	
	srand(getpid()+time(0));
	
	for (int i=8; i<17;i++){
		talla=pow(2,i);
		vector= new int [talla];
		for (int j=0;j<talla;j++){
			vector[j]=rand();
		}
		if (vector!=NULL){
			t1=tiempo();
			burbuja(vector, talla);
			t2=tiempo();
			tiempototal=t2-t1;
			cout<<talla<<" "<<tiempototal<<endl;
			delete[] vector;
		}
	}
	return 0;
}














