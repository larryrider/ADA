#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

void camino_mas_corto (int **lab, int filas, int columnas) {
  	int fila=0, columna=0,tamanyo=0;

  	if (lab[0][0]==0){
  		cout<<"\nCamino: Error de camino\nLongitud: ";
 	} else{
  		cout<<"\nCamino: ";
	  	while (fila<=row && columna<=col){
	  		if (lab[fila][columna]==1){
	  			cout<<"("<<fila<<","<<columna<<") ";
	  			fila++;
	  			columna++;
	  			tamanyo++;
	  		} else if (lab[fila+1][columna]==1){
	  			cout<<"("<<fila<<","<<columna<<") ";
	  			fila++;
	  			tamanyo++;
	  		} else if (lab[fila][columna+1]==1){
	  			cout<<"("<<fila<<","<<columna<<") ";
	  			columna++;
	  			tamanyo++;
	  		}
	  	}
	  	if (lab[row][col]==0){
	  		cout<<"No_encuentro_salida"<<endl;
	  	} else{
	  		cout<<"Longitud: "<<tamanyo;
	  	}
	}

	int row=0, col=0, longitud = 0;
	bool final = false;
	bool completo = false;
	
	while(final!=true && completo!=true) {
		if(lab[row][col]==0 && row == 0 && col == 0) {
			cout << "No_encuentro_salida" << endl;
			final = true;
		} else {
			if(row == 0 && col==0) {
				longitud++;
				cout << "(" << row+1 << "," << col+1 << ")";
			}
			
			if(lab[row+1][col+1] == 1) {
				row++;
				col++;
				longitud++;
				cout << "(" << row+1 << "," << col+1 << ")";
			} else if (lab[row][col+1] == 1){
				col++;
				longitud++;
				cout << "(" << row+1 << "," << col+1 << ")";
			} else if(lab[row+1][col] == 1) {
				row++;
				longitud++;
				cout << "(" << row+1 << "," << col+1 << ")";
			} else {
				final=true;
				cout << "No_encuentro_salida" << endl;
			}
			if(row==filas && col == columnas) {
				cout<< endl << "Longitud: "<< longitud << endl;
				completo = true;
			}
		}
	}	
}

int main (int argc, char *argv[]){
	ifstream is(argv[1]);

	if (!is){
		cerr << "Error en la apertura del fichero\n";

	} else{
		int rows,cols;

		is >> rows >> cols;

		int **lab = new int*[rows];

		for (int k=0;k<rows;k++){
			lab[k] = new int[cols];
		}

		for (int i=0;i<rows;i++){
			for (int j=0;j<cols;j++){
				is >> lab[i][j];
				//cout << lab[i][j];
			}
			//cout << endl;
		}
		camino_mas_corto(lab,rows-1,cols-1);
	}
	is.close();

	cout<<endl;
}
