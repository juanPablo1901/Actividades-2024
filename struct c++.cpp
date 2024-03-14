#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
}*primero, *ultimo;

void insertarNodo();
void BuscarNodo();
void ModificarNodo();
void EliminarNodo();
void mostrarNodo();
void calcularMayorMenor();
/* nodo * */



int main (){
	int opcion=0;
	
	do{
	cout<<"\n|---------------------------------------------|";
	cout<<"\n|     *LISTA CIRCULAR SIMPLE*                 |";
	cout<<"\n|---------------------------------------------|";
	cout<<"\n|   1.Insertar   |   4.Eliminar   |  7.salir  |";
	cout<<"\n|   2.Buscar     |   5.Mostrar    |           |";
	cout<<"\n|   3.Modificar  |   6.Mayor&Meor |           |";
	cout<<"\n|---------------------------------------------|";
	cout<<"\n Escoja una Opcion: ";
	cin>>opcion;
	switch (opcion) {
            case 1:
                cout << "\n Insertar en un Nodo \n";
                insertarNodo();
                break;
            case 2:
            	cout<<"\n Buscar un Nodo \n";
                BuscarNodo();
                break;
            case 3:
                cout << "\n Modificar un Nodo \n";
                ModificarNodo();
                break;
            case 4:
                cout << "\n Eliminar Nodo \n" << endl;
                EliminarNodo();
                break;
            case 5:
                cout << "\n Mostrar Struct \n" << endl;
                mostrarNodo();
                break;
            case 6:
                cout << "\n Mostrar mayor y menor \n" << endl;
                calcularMayorMenor();
                break;
            case 7:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
	
}while(opcion!=7);
	
	return 0;	
}


void insertarNodo(){
	nodo *nuevo_nodo = new nodo();
	cout<<"\n Dato: "<<endl;
    cin>>nuevo_nodo->dato;
   	if( primero==NULL){
   		primero=nuevo_nodo;
   		primero->siguiente=primero;
   		ultimo = primero;
	   } else{
	   	ultimo->siguiente = nuevo_nodo;
	   	nuevo_nodo->siguiente = primero;
	   	ultimo = nuevo_nodo;
	   	
	   }
	   cout<<"\n Nodo creado"<<endl;
}
	   

void BuscarNodo(){
	nodo *actual = new nodo;
    actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout<<"\n Nodo a Buscar: \n"<<endl;
	cin>>nodoBuscado;
	if(primero!=NULL){
		
		do{
			if(actual->dato==nodoBuscado){
				cout<< "El nodo con el dato < "<<nodoBuscado<<" > Encontrado \n"<<endl;
				encontrado = true;
			}
			actual = actual->siguiente;
	
		}while (actual != primero && encontrado != true);
		if (!encontrado){
			cout<<"\n Nodo no Encontrado \n"<<endl;
		}
	}else{
		cout<<"\n La lista esta vacia"<<endl;
	}
	
}

void ModificarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado=0, encontrado=0;
	cout<<"\n Ingrese el valor del nodo a buscar para modificarlo: ";
	cin>>nodoBuscado;
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				cout<<"\n Nodo con el dato "<<nodoBuscado<<" \n encontrado";
				cout<<"\n Ingrese el nuevo dato para este Nodo: ";
				scanf ("%d", &actual->dato);
				cout<<"\n Nodo modificado con exito \n";
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual!=primero && encontrado!=1);
		
		if(encontrado==0){
			cout<<"\n Nodo no encontrado ";
		}
		
	}else{
		cout<<"\n La lista se encuentra vacia \n";
	}
	
}

void EliminarNodo(){
	nodo *actual = (nodo*)malloc(sizeof(nodo));
    actual = primero;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	cout<<"\n Ingrese el valor de nodo a buscar para Eliminar: \n"<<endl;
	cin>>nodoBuscado;
	if(primero!=NULL){
		do{
			if(actual->dato==nodoBuscado){
				cout<< "El nodo con el dato < "<<nodoBuscado<<" > Encontrado \n"<<endl;
				if(actual==primero){
					primero = primero->siguiente;
					ultimo->siguiente=primero;
				}else if(actual==ultimo){
					anterior->siguiente=primero;
					ultimo=anterior;
				}else{
					anterior->siguiente=actual->siguiente;
				}
				cout<<"\n Nodo Eliminado \n";
				encontrado = 1;
			}
			anterior=actual;
			actual=actual->siguiente;
	
		}while (actual != primero && encontrado != 1);
		if (encontrado==0){
			cout<<"\n Nodo no Encontrado \n"<<endl;
		}else{
			free(anterior);
		}
	}else{
		cout<<"\n La lista esta vacia"<<endl;
	}
	
}

void mostrarNodo() {
    nodo *actual = new nodo;
    actual = primero;
	if(primero!=NULL){
		
		do{
		cout << " [" << actual->dato << "] ";
        actual = actual->siguiente;
        
		}while (actual != primero); 
		
	}else{
		cout<<"\n La lista esta vacia"<<endl;
	}
}

void calcular(){
	int suma = 0, prom;
	nodo *actual = new nodo;
	aux->siguiente=aux;
    	actual = primero;
	while(primero!=){
		
	}
	
}

void calcularMayorMenor(){
	int mayor = 0, menor=9999;
	nodo *actual = new nodo;
    	actual = primero;
	while(primero!=ultimo){
		if((primero->dato) > mayor){
			mayor = primero->dato;
		}
		if((actual->dato)<menor){
			menor = actual->dato;
		}
		actual = actual->siguiente;
	}
	
	cout<<"\n El mayor es: "<<mayor<<endl;
	cout<<"\n El menor es: "<<menor<<endl;
}

/*
void OrdenarPorBurbuja();{

	nodo*actual, *primero, *ultimo;
	if(nodo!=NULL){
		actual = nodo;
		do{
		
		primero=actual->siguiente;
		while(siguiente!=nodo){
			if(actual->)
		}
		
		
			
		}
	}
	*/
