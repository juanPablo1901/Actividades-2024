#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodo{
	
	char dato;
	int prioridad;
	struct nodo *siguiente;
	
};

struct cola{
	
	nodo *delante;
	nodo *atras;
	
};

struct nodo *crearNodo(char x, int pr){
	
	struct nodo *nuevoNodo = new(struct nodo);
	
	nuevoNodo->dato = x;
	nuevoNodo->prioridad = pr;
	
	return nuevoNodo;
};

void encolar(struct cola &q, char valor, int prioridad){
	
	struct nodo *aux = crearNodo(valor, prioridad);
	
	aux->siguiente = NULL;
	
	if(q.delante == NULL)
		q.delante = aux;
		
	else 
		(q.atras)->siguiente=aux;
		
		q.atras=aux;
}

void muestraCola (struct cola q){
	
	struct nodo *aux;
	aux=q.delante;
	
	cout<<"Caracter  Prioridad"<<endl;
	cout<<"-------------------"<<endl;
	
	while(aux != NULL){
		
		cout<<" "<<aux->dato<<" | "<<aux->prioridad<<endl;
		
		aux=aux->siguiente;
	}
	
}

void ordenarPrioridad(struct cola &q){
	
	struct nodo *aux1, *aux2;
	int pAux;
	char cAux;
	
	aux1=q.delante;
	
	while(aux1->siguiente !=NULL){
		
		aux2 = aux1->siguiente;
		
		while(aux2 != NULL){
			
			if(aux1->prioridad > aux2->prioridad){
				
				pAux = aux1->prioridad;
				cAux = aux1->dato;
				
				aux1->prioridad = aux2->prioridad;
				aux1->dato = aux2->dato;
				
				aux2->prioridad = pAux;
				aux2->dato = cAux;			
			}
			aux2 = aux2->siguiente;
		}
		aux1 = aux1->siguiente;
	}
}

void insertar(struct cola &q, char c, int pr){
	
	encolar(q,c,pr);
	
	ordenarPrioridad(q);
}

void suprimirCola(struct cola &q, int pr){
	pr = q.delante->dato;
	nodo *aux = q.delante;
	if(q.delante == q.atras){
		q.delante = NULL;
		q.atras = NULL;
	}else{
		q.delante = aux->siguiente;
	}
	if((q.delante==NULL) and (q.atras==NULL)){
		cout<<"No se puede eliminar mas tablas"<<endl;
	}	
	delete aux;
}

void menu(){
	system("color f5");
	int opcion;
	cout<<"\n|-------------------------- |";
	cout<<"\n|           *COLA*          |";
	cout<<"\n|---------------------------|";
	cout<<"\n|         1.Insertar        |";
	cout<<"\n|         2.Mostrar         |";
	cout<<"\n|         3.Eliminar        |";
	cout<<"\n|         0.Salir           |";
	cout<<"\n|---------------------------|";
	cout<<"\n Escoja una Opcion: ";
	
}
	
	
	int main(){
		
		system("color f1");
		
		struct cola q;
		q.delante = NULL;
		q.atras = NULL;
		
		char c;
		int pr, opcion, x;
		
		do{
			menu();
			cin>>opcion;
			
			switch(opcion){
				case 1:
					cout<<"Ingrese caracter"<<endl;
					cin>>c;
					cout<<"Ingrese prioridad"<<endl;
					cin>>pr;
					
					insertar(q,c,pr);
					break;
					
				case 2:
					cout<<"Mostrando cola"<<endl;
					
					if(q.delante==NULL)
						cout<<"Cola vacia"<<endl;
						else
						muestraCola(q);
						break;
						
				case 3:
					cout<<"Eliminando cola"<<endl;
					suprimirCola(q,pr);
					break;
					
						
				case 0:
					cout<<"Saliendo..."<<endl;
					break;
					
			}
			
			system("pause");
			system("cls");
			
		}while(opcion!=0);	
	} 
