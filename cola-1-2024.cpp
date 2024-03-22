#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo {
	int elemento;
	Nodo *siguiente; 
};

void insertarCola(Nodo *&,Nodo *&, int);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&, int &);

int main (){
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato, opcion;
	
			do{
	cout<<"\n|-------------------------- |";
	cout<<"\n|           *COLA*          |";
	cout<<"\n|---------------------------|";
	cout<<"\n|         1.Insertar        |";
	cout<<"\n|         2.Sacar           |";
	cout<<"\n|         0.Salir           |";
	cout<<"\n|---------------------------|";
	cout<<"\n Escoja una Opcion: ";
	cin>>opcion;
	switch (opcion) {
            case 1:
                cout << "\n Insertar una Cola: ";
                cin>>dato;
				insertarCola(frente,fin,dato);
                break;
            case 2:
            	cout<<"\n Quitar: ";
            	if(frente==NULL){
					cout<<"\n Error en sacar("<<dato<<"). La }Cola esta vacia \n"<<endl;
					}	
                while(frente!=NULL){
                	suprimirCola(frente, fin, dato);
                	if(frente!=NULL){
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


void insertarCola(Nodo *&frente, Nodo*&fin, int n){
	
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->elemento=n;
	nuevo_nodo->siguiente=NULL;
	
	if (cola_vacia(frente)){
		frente = nuevo_nodo;
	}else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin=nuevo_nodo;
	
	cout<<"\n Elemento ["<<n<<"] insertado en la cola correctamente"<<endl;
	
}

bool cola_vacia(Nodo *frente){
	
	
	if(frente == NULL){
		return true;
	}else{
		return false;
	}
	
	/*return(frente==NULL)? true : false;*/
}


void suprimirCola(Nodo *&frente, Nodo *&fin, int &n){
	
	n = frente->elemento;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente->siguiente;
	}
	
	delete aux;
}



