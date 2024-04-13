#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct nodo{
	int dato;
	nodo *der;
	nodo *izq;
};

nodo *arbol = NULL;
void insertar(nodo *&,int);
void mostrarArbol(nodo *, int);
nodo *crearNodo(int);

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

void menu (){
	system("color f5");
	int opcion;
	cout<<"\n|-------------------------- |";
	cout<<"\n|           *COLA*          |";
	cout<<"\n|---------------------------|";
	cout<<"\n|         1.Insertar        |";
	cout<<"\n|         2.Mostrar         |";
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
					cout<<"Ingrese caracter"<<endl;
					cin>>dato;
					insertar(arbol,dato);
					break;
				case 2:
					cout<<"Mostrando Arbol"<<endl;
					mostrarArbol(arbol,contador);
					cout<<"\n Mostrando el Post Orden \n";
					postOrden(arbol);
					cout<<"\n\n";
					cout<<"\n Mostrando el Pre Orden \n";
					preOrden(arbol);
					cout<<"\n\n";
					cout<<"\n Mostrando el In Orden \n";
					inOrden(arbol);
					cout<<"\n\n";
					break;	
				case 3:
					cout<<"Eliminando Arbol"<<endl;
					break;
				case 0:
					cout<<"Saliendo..."<<endl;
					break;		
			}
			system("pause");
			system("cls");
		}while(opcion!=0);
}
