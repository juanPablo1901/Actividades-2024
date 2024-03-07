#include <iostream>
#include <conio.h>
using namespace std;
int main (){
	int n;
	int arreglo3[n];
	int i, pos, aux;
	
	cout<<"Tamano de la tabla: "<<endl;
    cin>>n;
    	if(n<0){
    	cout<<"No se puede poner numeros negativos: "<<endl;
		}
	for (int i=0; i<n; i++) {
    cout <<"Numero "<<i+1<<" : "<<endl;
    cin >> arreglo3[i];
	}
	for(i=0; i<n; i++){
	
	pos = i;
	aux = arreglo3[i];
	
	while((pos>0) && (arreglo3[pos-1] > aux)){
		arreglo3[pos] = arreglo3[pos-1];
		pos--;
	
		}
	
	arreglo3[pos] = aux;
	}
	
	cout<<"Salida: "<<endl;
    for(int i=0; i<n;i++){
    	cout<<"[ "<<arreglo3[i]<<" ]";
	}
	
}
