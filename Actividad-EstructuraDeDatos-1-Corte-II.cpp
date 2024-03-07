#include <iostream>
#include <conio.h>
using namespace std;

void llenar_tabla(int arreglo[], int n);
void imprimir_tabla(int arreglo[], int n);
void Burbuja(int arreglo[], int n);
/*void Binario(int arreglo[], int n);
void Seleccion(int arreglo[],int n);*/



int main()
{
int n;
int temp; 
int opcion;
int M;   
int arreglo[n];
int tabla[M];

	cout<<"Tamano de la tabla: "<<endl;
    cin>>n;
    	if(n<0){
    	cout<<"No se puede poner numeros negativos: "<<endl;
		}

do {
        cout << "MENU:" << endl;
        cout << "1. Llenar tabla " << endl;
        cout << "2. Ver tabla " << endl;
        cout << "3. Ordenar por metodo burbuja" << endl;
       /* cout << "4. Ordenar por metodo Binario" << endl;
        cout << "5. Ordenamiento por seleccion" << endl;*/
		cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                llenar_tabla(tabla,M);
                break;
            case 2:
                imprimir_tabla(tabla,M);
                break;
            case 3:
            	Burbuja(tabla,M);
            	break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
    } while (opcion != 0);
	
    getch();
    return 0;
}

void llenar_tabla(int arreglo[], int n){
	
	for (int i=0; i<n; i++) {
    cout <<"Numero "<<i+1<<" : "<<endl;
    cin >> arreglo[i];
	}
}

void imprimir_tabla(int arreglo[], int n){
	cout<<"Salida: "<<endl;
    for(int i=0; i<n; i++){
    	cout<<"[ "<<arreglo[i]<<" ]";
	}
}

void Burbuja(int arreglo[], int n){
	
	    /*ordenar*/
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
	
}

/*
(){
	
	int arreglo3[] = {6,9,7,8,10};
	int i, pos, aux;
	
	for(i=0; i<5; i++){
	
	pos = i;
	aux = arreglo3[i];
	
	while((pos>0) && (arreglo3[pos-1] > aux)){
		arreglo3[pos] = arreglo3[pos-1];
		pos--;
	
		}
	
	arreglo3[pos] = aux;
	}
	
	cout<<"Salida: "<<endl;
    for(int i=0; i<5;i++){
    	cout<<"[ "<<arreglo3[i]<<" ]";
	}
	
}

*/


/* Binario

int min, max, mitad,v,p,m;
int arr[];
min arr = arr [m];
max arr = arr[p];
mitad = arr[(max-min)/2];

cin>>v;
while(v!=mitad){
    if(v>mitad){
        
    }
}
*/

