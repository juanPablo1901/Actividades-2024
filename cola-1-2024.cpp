#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo {
	int elemento;
	int prioridad;
	Nodo *siguiente; 
};

void insertarCola(Nodo *&,Nodo *&, int);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&, int &);
void mostrarCola(Nodo *&, Nodo *&, int &);
void OrdenarPrioridad(Nodo *&);


int main (){
	
	system("color f1");
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato, opcion, pr;
	
			do{
	cout<<"\n|-------------------------- |";
	cout<<"\n|           *COLA*          |";
	cout<<"\n|---------------------------|";
	cout<<"\n|         1.Insertar        |";
	cout<<"\n|         2.Sacar           |";
	cout<<"\n|         3.Mostrar         |";
	cout<<"\n|         0.Salir           |";
	cout<<"\n|---------------------------|";
	cout<<"\n Escoja una Opcion: ";
	cin>>opcion;
	switch (opcion) {
            case 1:
                cout << "\n Insertar una Pila: ";
                cin>>dato;
				insertarCola(frente,fin,dato);
                break;
            case 2:
            	cout<<"\n Quitar: ";
            	if(frente==NULL){
					cout<<"\n Error en saca("<<dato<<"). La pila esta vacia \n"<<endl;
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
            case 3:
                cout << "\n Mostrando: ";
				mostrarCola(frente,fin,dato);
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

void mostrarCola(Nodo *&frente, Nodo *&fin, int &n){
	
	struct Nodo *nuevo_nodo;
	nuevo_nodo = frente->siguiente;
	cout<<"Caracter   Prioridad"<<endl;
	cout<<"---------------------"<<endl;
	
	while(nuevo_nodo!=NULL){
		cout<<" "<<nuevo_nodo->elemento<<" | "<<nuevo_nodo->prioridad<<endl;
		nuevo_nodo=nuevo_nodo->siguiente;
	}
}

void OrdenarPrioridad(Nodo *&frente){
	
	struct Nodo *aux1, *aux2;
	int pAux;
	char cAux;
	
	aux1 = frente; 
	while(aux1->siguiente !=NULL){
		
		aux2 = aux1->siguiente;
			
		while(aux2 !=NULL){
			if (aux1->prioridad > aux2->prioridad){
				pAux = aux1->prioridad;
				cAux = aux1->elemento;
				
				aux1->prioridad = aux2->prioridad;
				aux1->elemento = aux2->elemento;
				
				aux2->prioridad = pAux;
				aux1->elemento = cAux;
			}	
			aux2 = aux2->siguiente;
		}	
		aux1 = aux1->siguiente;
	}
}


