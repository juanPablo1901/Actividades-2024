#include <iostream>
#include <conio.h>
using namespace std;
int main (){
	int min, max, mitad, n, p, m, j;
 	int arreglo4[n];
 	char band = 'F';
 	
	min = 0;
	max = n;
	
	cout<<"Tamano de la tabla: "<<endl;
    cin>>n;
    	if(n<0){
    	cout<<"No se puede poner numeros negativos: "<<endl;
		}
	for (int i=0; i<n; i++) {
    cout <<"Numero "<<i+1<<" : "<<endl;
    cin >> arreglo4[i];
	}
	
	for (int i=0; i<n; i++){
        /*comparación*/
        for(int j=i+1; j<n; j++){
        /*intercambiar datos*/
        if (arreglo4[i]>arreglo4[j]){
            int temp = arreglo4[j]; 
            arreglo4[j]=arreglo4[i];
            arreglo4[i]=temp;
            
            }
        }
    }
	
	cout<<"Salida: "<<endl;
    for(int i=0; i<n;i++){
    	cout<<"[ "<<arreglo4[i]<<" ]";
	}

	cout<<"\n ingrese el numero que desea buscar" <<endl;
	cin>>p;
	
	while(min <= max){
    	
		mitad=(min+max)/2;
		
		if(arreglo4[mitad] == p){
			band = 'V';
			break;
		}
		
		if(arreglo4[mitad] > p){
			max = mitad;
			mitad = (min+max)/2;
        
    	}
    	
    	if(arreglo4[mitad] < p){
    		min = mitad;
    		mitad = (min+max)/2;
		}
}

if(band == 'V'){
	cout<<"El numero a sido encontrado en la posicion: "<<mitad<<endl;
}
else {
	cout<<"No se encontro el dato"<<endl;
}
	
	cout<<"Salida: "<<endl;
    for(int i=0; i<n;i++){
    	cout<<"[ "<<arreglo4[i]<<" ]";
	}
	
	 getch();
    return 0;
	
}
