#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int main ()
{
	float matriz1[2][2];
	float max = matriz1[2][2]; 
	float min = matriz1[2][2];
	float suma=0, prom=0;
	int fila,columna;

	for (fila=0; fila<2; fila++)
	for(columna=0; columna<2; columna++)
	{
		cout << "Digite un numero [" << fila << "][" << columna << "]: ";
		cin>>matriz1[fila][columna];
		suma = suma + matriz1[fila][columna];
		prom = 4;
		
		for(int fila=0; fila<2; fila++)
		for(int columna=0; columna<2; columna++)
		{
					
			if(matriz1[fila][columna]>max) {
				max=matriz1[fila][columna];
			}
			
			if(matriz1[fila][columna]<min) {
				min=matriz1[fila][columna];
			}
			
		}
		
	}

	cout<<"La matriz 1 es: "<<endl;
	for (fila=0; fila<2; fila++)
	{
		for(columna=0; columna<2; columna++)
		cout<<matriz1[fila][columna]<<"   ";
		cout<<endl;
	}	
		cout<<"El promedio es: \n"<<endl;
		cout<< suma/prom<<"\n"<<endl;
		cout<<"Mayor: \n"<<endl;
		cout<<max<<"\n"<<endl;
		cout<<"Menor: \n"<<endl;
		cout<<min<<"\n"<<endl;

}
