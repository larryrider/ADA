#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

int recursivoSinAlmacen (int **lab,int rows,int cols){
	if (lab[rows][cols]==0){
		return 0;
	}

	if (rows==0 && cols==0){
		return 1;
	}

	if (rows==0){
		return recursivoSinAlmacen(lab,rows,cols-1);
	}

	if (cols==0){
		return recursivoSinAlmacen(lab,rows-1,cols);
	}

	return recursivoSinAlmacen(lab,rows-1,cols) + recursivoSinAlmacen(lab,rows,cols-1) + recursivoSinAlmacen(lab,rows-1,cols-1);
}

int recursivoConAlmacen (vector<vector<int> > &almacen, int **lab, int rows, int cols){
	
	if (almacen[rows][cols]!=-1){
		return almacen[rows][cols];
	}

	if (lab[rows][cols]==0){
		almacen[rows][cols] = 0;
		return 0;
	}

	if (rows==0 && cols==0){
		almacen[rows][cols] = 1;
		return 1;
	}

	if (rows==0){
		almacen[rows][cols] = recursivoConAlmacen(almacen,lab,rows,cols-1);
		return almacen[rows][cols];
	}

	if (cols==0){
		almacen[rows][cols] = recursivoConAlmacen(almacen,lab,rows-1,cols);
		return almacen[rows][cols];
	}

	almacen[rows][cols] = recursivoConAlmacen(almacen,lab,rows-1,cols) + recursivoConAlmacen(almacen,lab,rows,cols-1) + recursivoConAlmacen(almacen,lab,rows-1,cols-1);
	return almacen[rows][cols];
}

int iterativoConAlmacen (vector<vector<int> > &almacen, int **lab, int rows, int cols){
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){

			if (lab[i][j]==0){
				almacen[i][j]=0;
			}
			else if (i==0 && j==0){
				almacen[i][j]=1;
			}
			else if (i==0){
				almacen[i][j] = almacen[i][j-1];
			}
			else if (j==0){
				almacen[i][j] = almacen[i-1][j];
			}
			else{
				almacen[i][j] = almacen[i-1][j] + almacen[i][j-1] + almacen[i-1][j-1];
			}
		}
	}
	return almacen[rows-1][cols-1];
}

int iterativoConVector (int **lab, int rows, int cols){
	vector<int> v1 (cols);
	vector<int> v2 (cols);

	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){

			if (lab[i][j]==0){
				v2[j]=0;
			}
			else if (i==0 && j==0){
				v2[j]=1;
			}
			else if (i==0){
				v2[j] = v2[j-1];
			}
			else if (j==0){
				v2[j] = v1[j];
			}
			else{
				v2[j] = v1[j] + v2[j-1] + v1[j-1];
			}
		}
		swap(v1,v2);
	}
	return v1[cols-1];
}

void mostrarAlmacen (const vector<vector<int> > &almacen, int rows, int cols){
	for (int i=0;i<rows;i++){
		cout <<endl;
		for (int j=0;j<cols;j++){
			cout<<almacen[i][j]<<"\t";
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
		vector<vector<int> > almacen (rows, vector<int> (cols, -1));
		vector<vector<int> > almacen2 (rows, vector<int> (cols, -1));

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
		
		int resultado = recursivoSinAlmacen(lab,rows-1,cols-1);
		cout<<"\nRecursivo sin almacen (ineficiente): "<<resultado;

		resultado = recursivoConAlmacen(almacen,lab,rows-1,cols-1);
		cout<<"\nRecursivo con almacen (memoizacion): "<<resultado;

		resultado = iterativoConAlmacen(almacen2,lab,rows,cols);
		cout<<"\nIterativo con almacen (tabla): "<<resultado;

		resultado = iterativoConVector(lab,rows,cols);
		cout<<"\nIterativo con almacen (vector): "<<resultado;

		cout << "Tabla de resultados parciales (recursivo): ";
		mostrarAlmacen (almacen,rows,cols);
		cout << "\nTabla de resultados parciales (iterativo): ";
		mostrarAlmacen (almacen2,rows,cols);
	}
	is.close();

	cout<<endl;
}
