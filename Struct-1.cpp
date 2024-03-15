#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
}*primero, *ultimo;

void insertarNodo(int);
void mostrarNodo(nodo *);

int main (){
	nodo *list = NULL;
	int opcion=0;
	int m;
	
	do{
	cout<<"\n|------------------------------------|";
	cout<<"\n|      *LISTA CIRCULAR SIMPLE*       |";
	cout<<"\n|------------------------------------|";
	cout<<"\n|   1.Insertar   |   2.Mostrar       |";
	cout<<"\n|                |   0.cerrar        |";
	cout<<"\n|------------------------------------|";
	cout<<"\n Escoja una Opcion: ";
	cin>>opcion;
	switch (opcion) {
            case 1:
                cout << "\n Insertar en un Nodo \n";
                cin>>m;
                insertarNodo(m);
                break;
            case 2:
            	cout<<"\n Mostrar nodo \n";
                mostrarNodo(list);
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
	
}while(opcion!=0);
	
	getch();
	return 0;	
}


void insertarNodo(int n) {
 	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
    
    if( primero==NULL){
   		primero=nuevo_nodo;
   		primero->siguiente=primero;
   		ultimo = primero;
	   } else{
	   	ultimo->siguiente = nuevo_nodo;
	   	nuevo_nodo->siguiente = primero;
	   	ultimo = nuevo_nodo;
	   	
	   }
	   
	   cout << "Elemento " << n << " insertado en la lista" << endl;

}     
void mostrarNodo(nodo *list){
     nodo *actual = primero;
     cout << "Lista: ";
     if (primero != NULL) {
    	do{	
        cout << "[" << actual->dato << "] -> ";
        actual = actual->siguiente;
        }while(actual!=primero);
     }
     cout << "NULL" << endl;
}


/*
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
	
	void mostrarLista(nodo *list) {
    nodo *actual = list;

    cout << "Lista: ";
    while (actual != NULL) {
        cout << "[" << actual->dato << "] -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}
}
*/









