#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct nodo {
	int dato;
	int altura;
	nodo *der;
	nodo *izq;
	nodo *padre;
};

nodo* arbol = NULL;


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

int alturaNodo(nodo * nodo){
	if (nodo == NULL)
	return 0;
	return nodo->altura;
}

int maximo(int a, int b){
	return (a>b) ? a: b;
}

nodo *crearNodo(int dato){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato=dato;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->altura = 1;
	return nuevo_nodo;
}

nodo* rotacionDerecha(nodo* y){
	nodo* x = y->izq;
	nodo* z = x->der;
	
	x->der = y;
	y->izq = z;
	
	y->altura = maximo(alturaNodo(y->izq), alturaNodo(y->der)) + 1;
	x->altura = maximo(alturaNodo(x->izq), alturaNodo(x->der)) + 1;
	
	return x;
	
}

nodo* rotacionIzquierda(nodo* x){
	nodo* y = x->der;
	nodo* z = y->izq;
	
	y->izq = x;
	x->der = z;
	
	x->altura = maximo(alturaNodo(x->izq), alturaNodo(x->der)) + 1;
	y->altura = maximo(alturaNodo(y->izq), alturaNodo(y->der)) + 1;
	
	return y;	
}

nodo* insertar(nodo* raiz, int dato) {
    if (raiz == NULL) {
        return crearNodo(dato);
    }

    if (dato < raiz->dato) {
        raiz->izq = insertar(raiz->izq, dato);
    } else if (dato > raiz->dato) {
        raiz->der = insertar(raiz->der, dato);
    } else {
        return raiz;
    }

    raiz->altura = 1 + maximo(alturaNodo(raiz->izq), alturaNodo(raiz->der));

    int balance = alturaNodo(raiz->izq) - alturaNodo(raiz->der);

    if (balance > 1 && dato < raiz->izq->dato) {
        return rotacionDerecha(raiz);
    }
    if (balance < -1 && dato > raiz->der->dato) {
        return rotacionIzquierda(raiz);
    }
    if (balance > 1 && dato > raiz->izq->dato) {
        raiz->izq = rotacionIzquierda(raiz->izq);
        return rotacionDerecha(raiz);
    }
    if (balance < -1 && dato < raiz->der->dato) {
        raiz->der = rotacionDerecha(raiz->der);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}
	
void mostrarArbol(nodo *arbol, int cont){
	 if(arbol != NULL){
		mostrarArbol(arbol->der,cont+1);
			for(int i=0;i<cont;i++){
				cout<<"   ";
			}
			cout<<"("<<arbol->dato<<")"<<endl;
			mostrarArbol(arbol->izq, cont+1);	
		}
}

void postOrden(nodo* raiz){
	if(raiz==NULL){
		return;
	}else{
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout<<" ["<<raiz->dato<<"]->";
	}
}

void preOrden(nodo* raiz){
	if(raiz==NULL){
		return;
	}else{
		
		cout<<" ["<<raiz->dato<<"]->";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void inOrden(nodo* raiz){
	if(raiz==NULL){
		return;
	}else{
		
		inOrden(raiz->izq);
		cout<<" ["<<raiz->dato<<"]->";
		inOrden(raiz->der);
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

void Eliminar(nodo* raiz, int n){
	if (raiz==NULL){
		return;
	}else if(n<raiz->dato){
		Eliminar(raiz->izq, n);
	}else if(n>raiz->dato){
		Eliminar(raiz->der, n);
	}else{
		eliminarNodo(raiz);
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

nodo* minimo(nodo* raiz){
	if(raiz==NULL){
		return NULL;
	}
	if(raiz->izq){
		return minimo(raiz->izq);
	}else{
		return raiz;
	}
}

void reemplazar(nodo* raiz, nodo* nuevoNodo){
	if(raiz->padre){
		if(raiz->dato == raiz->padre->izq->dato){
			raiz->padre->der=nuevoNodo;
		}else if(raiz->dato == raiz->padre->der->dato){
			raiz->padre->der=nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre=raiz->padre;
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

int main() {
system("color f1");
		struct nodo;
		int opcion, dato, contador=0;
		do{
			menu();
			cin>>opcion;
			switch(opcion){
				case 1:
					cout<<"\n  Ingrese un numero \n"<<endl;
					cin>>dato;
					arbol = insertar(arbol,dato);
					break;
				case 2:
					cout<<"\n Mostrando Arbol \n"<<endl;
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
		
		return 0;
}
