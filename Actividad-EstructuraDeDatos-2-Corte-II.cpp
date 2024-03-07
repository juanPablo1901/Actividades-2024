#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
/*burbuja*/
int n,temp;    
int arreglo [n];
	
    cout<<"Tamano de la tabla: "<<endl;
    cin>>n;
    	if(n<0){
    	cout<<"No se puede poner numeros negativos: "<<endl;
		}
	for (int i=0; i<n; i++) {
    cout <<"Numero "<<i+1<<" : "<<endl;
    cin >> arreglo[i];
	}
    /*ordenar*/
    for (int i=0; i<n; i++){
        /*comparación*/
        for(int j=i+1; j<n; j++){
        /*intercambiar datos*/
        if (arreglo[i]>arreglo[j]){
            temp = arreglo[j]; 
            arreglo[j]=arreglo[i];
            arreglo[i]=temp;
            
            }
        }
    } 
    cout<<"Salida: "<<endl;
    for(int i=0; i<n;i++){
    	cout<<"[ "<<arreglo[i]<<" ]";
	}
    getch();
    return 0;
}
