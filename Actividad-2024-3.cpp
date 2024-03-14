#include <iostream>
#include <conio.h>
using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
};

void insertarLista(nodo *&, int);
void mostrarLista(nodo *);
void eliminarNodo(nodo *&, int);
void calcularMayorMenor(nodo *);
void sumar(nodo *);

int main() {
    nodo *list = NULL;
    int opcion;
    int m;
    int verificar;
    int valorAEliminar;

    do {
    cout<<"\n|-------------------------------------------------------|";
	cout<<"\n|               *LISTA CIRCULAR SIMPLE*                 |";
	cout<<"\n|-------------------------------------------------------|";
	cout<<"\n|   1. Insertar un numero  |   4. Ver mayor y menor     |";
	cout<<"\n|   2. Mostrar la lista    |   5. Sumar todo            |";
	cout<<"\n|   3. Eliminar un numero  |   0. Salir del sistema     |";
	cout<<"\n|-------------------------------------------------------|";
	cout<<"\n Escoja una Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> m;
                insertarLista(list, m);
                break;
            case 2:
                mostrarLista(list);
                break;
            case 3:
                cout << "Ingrese el valor que desea eliminar: ";
                cin >> valorAEliminar;
                eliminarNodo(list, valorAEliminar);
                break;
            case 4:
            	cout <<"\n Mostrar mayor y menor \n" << endl;
                calcularMayorMenor(list);
                break;
            case 5:
            	cout <<"\n SUMA \n" << endl;
                sumar(list);
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
    } while (opcion != 0);

    getch();
    return 0;
}

void insertarLista(nodo *&list, int n) {
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato = n;

    nodo *aux1 = list;
    nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (list == aux1) {
        list = nuevo_nodo;
    } else {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    cout << "Elemento " << n << " insertado en la lista" << endl;
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

void eliminarNodo(nodo *&list, int valor) {
    if (list != NULL) {
        nodo *aux_borrar;
        nodo *anterior = NULL;
        aux_borrar = list;

        while (aux_borrar != NULL) {
            if (aux_borrar->dato == valor) {
                // Si el nodo a eliminar es el primero
                if (anterior == NULL) {
                    list = list->siguiente;
                    delete aux_borrar;
                    aux_borrar = list;
                } else {
                    anterior->siguiente = aux_borrar->siguiente;
                    delete aux_borrar;
                    aux_borrar = anterior->siguiente;
                }
            } else {
                anterior = aux_borrar;
                aux_borrar = aux_borrar->siguiente;
            }
        }

        cout << "\n Se han eliminado todos los nodos con el valor " << valor << endl;
    } else {
        cout << "\n La lista está vacía." << endl;
    }
}


void calcularMayorMenor(nodo *lista){
	int mayor = 0, menor=9999;
	
	while(lista!=NULL){
		if((lista->dato) > mayor){
			mayor = lista->dato;
		}
		if((lista->dato)<menor){
			menor = lista->dato;
		}
		lista = lista->siguiente;
	}
	
	cout<<"\n El mayor es: "<<mayor<<endl;
	cout<<"\n El menor es: "<<menor<<endl;
}

void sumar(nodo *lista){
	int suma;
	int prom=0;
	
	while(lista!=NULL){
		suma=lista->dato+lista->dato;
		prom++;
		lista = lista->siguiente;
	}
	cout<<"\n La suma es: "<<suma<<endl;
	cout<<"\n Su promedio es: "<<(suma+0.0)/prom<<endl;
	
}

