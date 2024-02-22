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

int main() {
    nodo *list = NULL;
    int opcion;
    int m;
    int verificar;
    int valorAEliminar;

    do {
        cout << "MENU:" << endl;
        cout << "1. Insertar un numero" << endl;
        cout << "2. Mostrar la lista" << endl;
        cout << "3. Eliminar un numero" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
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

        cout << "Se han eliminado todos los nodos con el valor " << valor << endl;
    } else {
        cout << "La lista está vacía." << endl;
    }
}
