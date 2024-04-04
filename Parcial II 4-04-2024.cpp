#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo {
	int elemento;
	Nodo *siguiente; 
};

struct nodo{
	int dato;
	nodo *der;
	nodo *izq;
};

void insertarCola(Nodo *&,Nodo *&, int);
void agregarpila(Nodo *&, int);
void insertarLista(Nodo *&, int);

bool cola_vacia(Nodo *);

void mostrarPila(Nodo *&, int &);
void mostrarCola(Nodo *&, Nodo *&, int &);


nodo *arbol = NULL;
void insertar(nodo *&,int);
void mostrarArbol(nodo *, int);

nodo *crearNodo(int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	
	return nuevo_nodo;
}

void insertar (nodo *&arbol, int n){
	if (arbol == NULL){
	
		nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}else{
		int valorRaiz = arbol->dato;
		if(n<valorRaiz){
			insertar(arbol->izq,n);
			
		}else{
			insertar(arbol->der,n);
		}
	}
}

void mostrarArbol(nodo *arbol, int cont){
	if(arbol == NULL){
		return;
		}else{
		mostrarArbol(arbol->der,cont+1);
			for(int i=0;i<cont;i++){
				cout<<"    ";
			}
			cout<<"("<<arbol->dato<<")"<<endl;
			mostrarArbol(arbol->izq, cont+1);	
		}
}

int main (){
    Nodo *list = NULL;
    Nodo *frente = NULL;
	Nodo *fin = NULL;
	Nodo *pila = NULL;
	int dato,opcion,pr,contador=0,m;
	do{
    cout<<"\n|-------------------------- |";
	cout<<"\n|           *PARCIAL*       |";
	cout<<"\n|---------------------------|";
	cout<<"\n|         1.Cola            |";
	cout<<"\n|         2.Pila            |";
	cout<<"\n|         3.Mostrar         |";
	cout<<"\n|         4.Arbol           |";
	cout<<"\n|         0.Salir           |";
	cout<<"\n|---------------------------|";
	cout<<"\n Escoja una Opcion: ";
    cin>>opcion;
        switch(opcion){
            case 1:
				cout << "Cola: "<<endl;
                cout<<"Ingrese Cola"<<endl;
				cin>>dato;
				insertarCola(frente,fin,dato);
				insertar(arbol,dato);
				insertarLista(list, m);
                break;
					
				case 2:
				cout << "Pila: "<<endl;
				cout << "Insertar Pila: ";
                cin>>dato;
				agregarpila(pila,dato);
				insertar(arbol,dato);
				insertarLista(list, m);
            	break;
            	
            	case 3:
            	cout<<"Cola"<<endl;
            	mostrarCola(frente,fin,dato);
            	cout<<"\nPila"<<endl;
            	mostrarPila(pila,dato);
            	break;
            
                case 4:
                    cout<<"Mostrando Arbol"<<endl;
					mostrarArbol(arbol,contador);
					break;
						
				case 0:
					cout<<"Saliendo..."<<endl;
					break;
					
			    }
    }while(opcion=!0);
 
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

void agregarpila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->elemento = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\n Elemento "<<n<<" agregado a Pila correctamente "<<endl;
}

void insertarLista(Nodo *&list, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->elemento = n;

    Nodo *aux1 = list;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->elemento < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (list == aux1) {
        list = nuevo_nodo;
    } else {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;
}


void mostrarCola(Nodo *&frente, Nodo *&fin, int &n){
	
	while(frente!=NULL){
		cout<<frente->elemento<<"\n";
		frente=frente->siguiente;
	}
}

void mostrarPila(Nodo *&pila, int &n){
	
	Nodo *aux = pila;
	while(aux!=NULL){
		cout<<aux->elemento<<"\n";
		aux=aux->siguiente;
	}
}

bool cola_vacia(Nodo *frente){
	
	if(frente == NULL){
		return true;
	}else{
		return false;
	}

}
