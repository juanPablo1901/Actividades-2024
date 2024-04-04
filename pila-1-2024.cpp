#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo {
	int elemento;
	Nodo *siguiente; 
};

void agregarpila(Nodo *&, int);
void sacarPila(Nodo *&, int &);
void eliminarPila(Nodo *&, int &);
void mostrarPila(Nodo *&, int &);

int main (){
	system("color f1");
	Nodo *pila = NULL;
	int dato, opcion;
	
		do{
	cout<<"\n|-------------------------- |";
	cout<<"\n|           *PILA*          |";
	cout<<"\n|---------------------------|";
	cout<<"\n|         1.Insertar        |";
	cout<<"\n|         2.Mostrar         |";
	cout<<"\n|         3.Sacar           |";
	cout<<"\n|         0.Salir           |";
	cout<<"\n|---------------------------|";
	cout<<"\n Escoja una Opcion: ";
	cin>>opcion;
	switch (opcion) {
            case 1:
                cout << "\n Insertar una Pila: ";
                cin>>dato;
				agregarpila(pila,dato);
                break;
            case 2:
            	cout << "\n Mostrando: \n";
				mostrarPila(pila,dato);
            	break;
            case 3:
            	cout<<"\n Sacar Pila: ";
            	if(pila==NULL){
					cout<<"\n Error en saca("<<dato<<"). La pila esta vacia \n"<<endl;
					}	
                while(pila!=NULL){
                	sacarPila(pila,dato);
                	if(pila!=NULL){
                		cout<<" ["<<dato<<"] -";
					}else{
						cout<<" ["<<dato<<"] .";
					}
				}
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
            }
	}while(opcion!=0);
	
	getch();
	return 0;	
}


void agregarpila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->elemento = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\n Elemento "<<n<<" agregado a Pila correctamente "<<endl;
}

void mostrarPila(Nodo *&pila, int &n){
	
	Nodo *aux = pila;
	while(aux!=NULL){
		cout<<aux->elemento<<"\n";
		aux=aux->siguiente;
	}
}

void sacarPila(Nodo *&pila, int &n){	
	Nodo *aux = pila;
	n = aux->elemento;
	pila = aux->siguiente;
	delete aux;
}
