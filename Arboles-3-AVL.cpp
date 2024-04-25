#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct nodo{
	int dato;
	int altura;
	nodo *der;
	nodo *izq;
	nodo *padre;
};

nodo *arbol = NULL;
void insertar(nodo *&,int);

int alturaNodo(nodo *);

void mostrarArbol(nodo *, int);
void MostrarNivel(nodo *, int);
int  cantNivel(nodo *);

nodo *crearNodo(int);

void RotacionIzquierda(nodo *);

void Eliminar(nodo *, int);
void eliminarNodo(nodo*);

nodo* minimo(nodo*);

void reemplazar(nodo*, nodo*);
void destruirNodo(nodo*);


nodo *crearNodo(int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;

	return nuevo_nodo;
}


void insertar(nodo *&arbol, int n){
	if (arbol == NULL){
		nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}else{
		int valorRaiz = arbol->dato;
		 if(n<valorRaiz){
			insertar(arbol->izq,n);
			alturaNodo(arbol->izq);
			
		}if (n>valorRaiz){
			insertar(arbol->der,n);
			alturaNodo(arbol->der);
		}
	}
}


void mostrarArbol(nodo *arbol, int cont){
	if(arbol == NULL){
		return;
		}else{
		mostrarArbol(arbol->der,cont+1);
			for(int i=0;i<cont;i++){
				cout<<"   ";
			}
			cout<<"("<<arbol->dato<<")"<<endl;
			mostrarArbol(arbol->izq, cont+1);	
		}
}

void postOrden(nodo*arbol){
	if(arbol==NULL){
		return;
	}else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<" ["<<arbol->dato<<"]->";
	}
}

void preOrden(nodo*arbol){
	if(arbol==NULL){
		return;
	}else{
		
		cout<<" ["<<arbol->dato<<"]->";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(nodo*arbol){
	if(arbol==NULL){
		return;
	}else{
		
		inOrden(arbol->izq);
		cout<<" ["<<arbol->dato<<"]->";
		inOrden(arbol->der);
	}
}


int cantNivel(nodo *arbol){
	if (arbol!=NULL){
		int izq = cantNivel(arbol->izq)+1;
		int der = cantNivel(arbol->der)+1;
		if(izq>der){
			return izq;
		}else{
			return der;
		}
		
	}
}

void MostrarNivel(nodo *arbol, int n){
	if(arbol != NULL){
		if(n==0){
			cout<<" ["<<arbol->dato<<"]->";
		}
		
		MostrarNivel(arbol->izq, n-1);
		MostrarNivel(arbol->der, n-1);
	}
}

int alturaNodo(nodo *arbol){
	if(arbol!=NULL){
		int hi = alturaNodo(arbol->izq);
		int hd = alturaNodo(arbol->der);
		if(hi>hd){
			return hi+1;
		}else{
			return hd+1;
		}
	}
}

void MostrarAltura(nodo *arbol, int n){
	if(arbol!=NULL){
		if(n==0){
			cout<<""<<arbol->altura+1<<"";
		}
		MostrarAltura(arbol->izq, n+1);
		MostrarAltura(arbol->der, n+1);
	}
}

void Eliminar(nodo* arbol, int n){
	if (arbol==NULL){
		return;
	}else if(n<arbol->dato){
		Eliminar(arbol->izq, n);
	}else if(n>arbol->dato){
		Eliminar(arbol->der, n);
	}else{
		eliminarNodo(arbol);
	}
}

void eliminarNodo(nodo* nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		nodo* menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}else if(nodoEliminar->izq){
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}else if(nodoEliminar->der){
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}else{
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}

nodo* minimo(nodo* arbol){
	if(arbol==NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}else{
		return arbol;
	}
}

void reemplazar(nodo* arbol, nodo* nuevoNodo){
	if(arbol->padre){
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->der=nuevoNodo;
		}else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der=nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre=arbol->padre;
	}
}

void destruirNodo(nodo* Nodo){
	Nodo->izq=NULL;
	Nodo->der=NULL;
	delete Nodo;
}

void menu (){
	system("color f5");
	int opcion;
	cout<<"\n|-------------------------- |";
	cout<<"\n|           *COLA*          |";
	cout<<"\n|---------------------------|";
	cout<<"\n|         1.Insertar        |";
	cout<<"\n|         2.Mostrar         |";
	cout<<"\n|         3.Post-Orden      |";
	cout<<"\n|         4.Pre-Orden       |";
	cout<<"\n|         5.In-Orden        |";
	cout<<"\n|         6.Nivel           |";
	cout<<"\n|         7.Eliminar Dato   |";
	cout<<"\n|         0.Salir           |";
	cout<<"\n|---------------------------|";
	cout<<"\n Escoja una Opcion: ";
}

int main (){
system("color f1");
		struct nodo;
		int opcion, dato, contador=0;
		do{
			menu();
			cin>>opcion;
			switch(opcion){
				case 1:
					cout<<"Ingrese un numero"<<endl;
					cin>>dato;
					insertar(arbol,dato);
					break;
				case 2:
					cout<<"Mostrando Arbol"<<endl;
					mostrarArbol(arbol,contador);
					break;
				case 3:
					cout<<"\n Mostrando el Post Orden \n";
					postOrden(arbol);
					break;
				case 4:
					cout<<"\n Mostrando el Pre Orden \n";
					preOrden(arbol);
					break;
				case 5: 
					cout<<"\n Mostrando el In Orden \n";
					inOrden(arbol);
					break;
				case 6:
					cout<<"Mostrar los niveles "<<endl;
						for(int i=0; i<cantNivel(arbol); i++){
						cout<<"\n Nivel "<<i<<"\n";
						MostrarNivel(arbol, i);
						cout<<"\n\n";
					}
					break;
				case 7:
					cout<<"Eliminando Dato"<<endl;
					cin>>dato;
					Eliminar(arbol, dato);
					cout<<"\n"; 
					break;
				case 8: 
					cout<<"mostrar"<<endl;
					for(int i=0; i<alturaNodo(arbol); i++){
						cout<<i<<"\n";
						MostrarAltura(arbol, i);
					}
					break;
				case 0:
					cout<<"Saliendo..."<<endl;
					break;		
			}
			system("pause");
			system("cls");
		}while(opcion!=0);
}
