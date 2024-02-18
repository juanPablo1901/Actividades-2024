#include <iostream>
#include <conio.h>
using namespace std;


struct nodo
{
    int dato;
    nodo* siguiente;
};

void insertarLista(nodo *&,int);
void mostrarLista(nodo *);



int main(){
	nodo *list = NULL;
	int m;
	int verificar;
	
	cout<<"Ingrese un numero: "<<"["<<"] \n"<<endl;
	do{
		
		cin>>m;
		insertarLista(list, m);
		cout<<"Desea continuar?"<<"["<<"1 = si"<<"]"<<"["<<"0 = no"<<"] \n"<<endl;
		cin>>verificar;
		
		if(verificar>=2){
			verificar = 0;
		}
		cout<<"Ingresa un numero"<<"["<<"] \n"<<endl;
		
		
	} while(verificar!=0);
	
	mostrarLista(list);
	
	
	getch();
	return 0;
}


void insertarLista(nodo *&list,int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	
	nodo *aux1 = list;
	nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato<n)){
		aux2= aux1;
		aux1 = aux1->siguiente;
	}
	if(list == aux1){
		list = nuevo_nodo;
	}
	else {
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	
	cout<<"Elemento \n"<<n<<"\ninsertado en la lista \n"<<endl;
	
}

void mostrarLista(nodo *list){
	nodo *actual = new nodo();
	actual = list;
	
	while(actual !=NULL){
		cout<<"["<<actual->dato<<"] -> ";
		actual = actual->siguiente;
	}
	
}




