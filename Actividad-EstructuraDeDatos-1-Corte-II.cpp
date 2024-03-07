#include <iostream>
#include <conio.h>
using namespace std;



int main()
{
	int n;
	int temp;   
	int arreglo[n];
	int i, p, pos, aux, max, min, mitad;
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
    cin >> arreglo[i];
	}
			
	for (int i=0; i<n; i++){
        /*comparación*/
        for(int j=i+1; j<n; j++){
        /*intercambiar datos*/
        if (arreglo[i]>arreglo[j]){
            int temp = arreglo[j]; 
            arreglo[j]=arreglo[i];
            arreglo[i]=temp;
        	}
    	}
	}

	for(i=0; i<n; i++){
	
	pos = i;
	aux = arreglo[i];
	
	while((pos>0) && (arreglo[pos-1] > aux)){
		arreglo[pos] = arreglo[pos-1];
		pos--;
	
		}
	
	arreglo[pos] = aux;
	}

	cout<<"Salida Burbuja: "<<endl;
    for(int i=0; i<n;i++){
    	cout<<"[ "<<arreglo[i]<<" ]";
	}
	
		cout<<"\n Salida Ordenamineto por insercion: "<<endl;
    for(int i=0; i<n;i++){
    	cout<<"[ "<<arreglo[i]<<" ]";
	}
	
	
		cout<<"\n ingrese el numero que desea buscar" <<endl;
	cin>>p;
	
	while(min <= max){
    	
		mitad=(min+max)/2;
		
		if(arreglo[mitad] == p){
			band = 'V';
			break;
		}
		
		if(arreglo[mitad] > p){
			max = mitad;
			mitad = (min+max)/2;
        
    	}
    	
    	if(arreglo[mitad] < p){
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
	
}

