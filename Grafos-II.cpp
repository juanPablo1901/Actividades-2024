#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <queue>
#include <climits>
using namespace std;

class Nodo{
	public:
		Nodo(char info){
			this->info = info;
		};
		// mapeo de conexiones
		map<char, Nodo*> conexiones;
		map<char, int> cargas;
		// clave o valor identificador del nodo
		char info;
		// metodos
		bool buscarConexion(char clave);
		void agregarConexion(char clave, Nodo* nodo);
		void eliminarConexion(char clave);
};

// crear conexion entre nodos
void Nodo::agregarConexion(char clave, Nodo* nodo){
	conexiones[clave] = nodo;
}


// eliminar conexion entre nodos
void Nodo::eliminarConexion(char clave){
	conexiones.erase(clave);
}


// buscar una conexion entre nodos
bool Nodo::buscarConexion(char clave){
	for(auto& X: conexiones){
		if(X.first == clave){
			return true;
		}
	}
	return false;
}

class Grafo{
	public:
		Grafo(){
			// nomenclatura de Nodos
			this->nomenclatura = 65;
			// tamaño maximo
			this->maximo = 15;
		};
		// mapeo de nodos en el grafo
		
		map<char, Nodo*> nodosTotales;
		map<pair<char, char>, int> conexionesConValor;
		vector<Nodo*> listaNodos();
		
		// propiedades del grafo
		char nomenclatura;
		int maximo;
		int valorPorDefecto = 0;
		// metodos
		
		void agregarNodo();
		void generarConexion(char nodo1, char nodo2);
		void generarConexion(char nodo1, char nodo2, int valor);
		void eliminarNodo(char clave);
		void borrarConexion(char nodo1, char nodo2);
		void mostrarNodos();
		void mapaAdyacencia();
		void mapaAdyacencia2(int valor);
		void mostrarCorta();
		void rutaMasCorta(char origen, char destino);
		void menu();
};

// agregar nodos al grafo como una lista
void Grafo::agregarNodo(){
	if(nodosTotales.size()<maximo){
		Nodo* nuevoNodo = new Nodo(nomenclatura);
		nodosTotales[nomenclatura] = nuevoNodo;
		printf("Usted ha generado el Nodo %c\n\n",nuevoNodo->info);
		nomenclatura++;
	} else{
		printf("Cantidad Maxima de nodos\n\n");	
	}
}

void Grafo::generarConexion(char nodo1, char nodo2) {
    generarConexion(nodo1, nodo2, valorPorDefecto);
}

void Grafo::generarConexion(char nodo1, char nodo2, int valor) {
    auto it1 = nodosTotales.find(nodo1);
    auto it2 = nodosTotales.find(nodo2);
    if (it1 != nodosTotales.end() && it2 != nodosTotales.end()) {
        if (nodo1 != nodo2) {
            Nodo* conn1 = nodosTotales[nodo1];
            Nodo* conn2 = nodosTotales[nodo2];
            conn1->agregarConexion(nodo2, conn2);
            conn2->agregarConexion(nodo1, conn1);
            conexionesConValor[{nodo1, nodo2}] = valor;
            conexionesConValor[{nodo2, nodo1}] = valor;
        }
        else {
            Nodo* conn = nodosTotales[nodo1];
            conn->agregarConexion(nodo1, conn);
            conexionesConValor[{nodo1, nodo1}] = valor;
        }
    }
    else {
        cout << "Nodos no existentes" << endl;
    }
}

// eliminar nodos y sus conexiones del grafo
void Grafo::eliminarNodo(char clave){
	auto it1 = nodosTotales.find(clave);
	if(it1 != nodosTotales.end()){
		Nodo *eliminar = nodosTotales[clave];
		for(auto& X: eliminar->conexiones){
			Nodo *conn = X.second;
			conn->conexiones.erase(clave);
		}
		delete(eliminar);
		nodosTotales.erase(clave);
		printf("Nodo eliminado\n");
	} else {
		printf("Nodo no existente");
	}
}

// borrar las conexiones entre los nodos
void Grafo::borrarConexion(char nodo1, char nodo2){
	auto it1 = nodosTotales.find(nodo1);
	auto it2 = nodosTotales.find(nodo2);
	if(it1 != nodosTotales.end() && it2 != nodosTotales.end()){
		Nodo* conn1 = nodosTotales[nodo1];
		Nodo* conn2 = nodosTotales[nodo2];
		if(conn1->buscarConexion(nodo2) && conn2->buscarConexion(nodo1)){
			if(nodo1 != nodo2){
				conn1->eliminarConexion(nodo2);
				conn2->eliminarConexion(nodo1);
			} else {
				conn1->eliminarConexion(nodo1);
			}
			printf("Conexion Eliminada\n");
		} else {
			printf("No hay conexión entre los nodos %c y %c\n", nodo1, nodo2);
		}
	} else {
		printf("Al menos uno de los nodos no existe en el grafo\n");
	}
}

// genera una lista para mostrar los nodos
void Grafo::mostrarNodos(){
	for(auto& datos: nodosTotales){
		printf("Nodo: %c\n",datos.first);
	}
	printf("\n");
}

// genera una lista de nodos de tipo vector
vector<Nodo*> Grafo::listaNodos(){
	vector<Nodo*> nodos;
	for(auto& datos: nodosTotales){
		nodos.push_back(datos.second);
	}
	return nodos;
}

// muestra el mapa de conexiones del grafo
void Grafo::mapaAdyacencia(){
	int alcance = nodosTotales.size();
	int ady[alcance][alcance];
	vector<Nodo*> nodos = listaNodos();
	for(int i=0; i<alcance; i++){
		Nodo *nodoIt = nodos[i];
		for(int j=0; j<alcance; j++){
			if(nodoIt->buscarConexion(nodos[j]->info)){
				ady[i][j] = 1;
			} else {
				ady[i][j] = 0;
			}
		}
	}
	for(int i=0; i<alcance; i++){
		Nodo *nodoIt = nodos[i];
		for(int j=0; j<alcance; j++){
			if(j==0){
				printf(" %c ",nodoIt->info);
			}
			printf(" %d ",ady[i][j]);
		}
		printf("\n");
	}
}

void Grafo::mapaAdyacencia2(int valor){
	int alcance = nodosTotales.size();
	vector<Nodo*> nodos = listaNodos();
	cout<<"   ";
	for(int i=0; i<alcance; i++){
		cout<<"  "<<nodos[i]->info;
	}
	cout<<endl;
	for(int i=0; i<alcance; ++i){
		Nodo *nodoIt = nodos[i];
		cout<<nodoIt->info<<"  ";
		for(int j=0; j<alcance; ++j){
			if(nodoIt->buscarConexion(nodos[j]->info)){
				cout<<"  "<<conexionesConValor[{alcance}] = valor;
			}else{
			cout<<"  0";
			}
		
		}
		cout<<endl;
	}
	cout<<endl;
}

void Grafo::rutaMasCorta(char origen, char destino){
	map<char, int> distancia;
	map<char, char> anterior;
	priority_queue<pair<int, char>> pq;
	
	for (auto& nodo : nodosTotales){
		distancia[nodo.first]=INT_MAX;
		anterior[nodo.first] = 0;
	}
	
	distancia[origen] = 0;
	pq.push({0, origen});
	
	while (!pq.empty()){
		char nodoActual = pq.top().second;
		pq.pop();
		
		for (auto& conexion : nodosTotales[nodoActual]->conexiones){
			char nodoVecino = conexion.first;
			int peso = nodosTotales[nodoActual]->cargas[nodoVecino];
			if(distancia[nodoActual] + peso < distancia[nodoVecino]){
				distancia[nodoVecino] = distancia[nodoActual] + peso;
				anterior[nodoVecino] = nodoActual;
				pq.push({-distancia[nodoVecino], nodoVecino});
			}
		}
	}

	vector<char> camino;
	for(char nodo = destino; nodo!=0; nodo=anterior[nodo]){
		camino.push_back(nodo);
	}
	if(camino.back()==destino){
		cout<<"La distancia mas corta desde "<<origen << " hasta "
		<<destino<<" es: "<< distancia[destino]<<endl;
		cout<<"\n El camino es: "<<endl;
		for(auto it = camino.rbegin(); it!=camino.rend(); ++it){
			cout << *it;
			if(it+1!=camino.rend()){
				cout<<" -> ";
			}
		}
		cout<<endl;
	 } else {
		cout<<"No hay camino desde "<<origen<<" hasta "<<destino<<endl;
	}
}

void Grafo::menu(){
	system("color f5");
	int opcion;
	cout<<"\n|-----------------------------------|";
	cout<<"\n|               *GRAFO*             |";
	cout<<"\n|-----------------------------------|";
	cout<<"\n|     1.Agregar Nodo                |";
	cout<<"\n|     2.Agregar Conexion            |";
	cout<<"\n|     3.Mostrar Nodos               |";
	cout<<"\n|     4.Mostrar mapa de adyacencia  |";
	cout<<"\n|     5.Mostrar mapa de adyacencia 2|";
	cout<<"\n|     6.Mostrar Camino mas corto    |";
	
	cout<<"\n|     7.Eliminar Nodo               |";
	cout<<"\n|     8.Eliminar Conexion           |";
	cout<<"\n|     0.Salir                       |";
	cout<<"\n|-----------------------------------|";
	cout<<"\n Escoja una Opcion: ";
}

// identifica la entrada de datos
bool isCharacter(char caracter){
	if(isdigit(caracter)){
		return false;
	} else if(isalpha(caracter)){
		return true;
	} else{
		return false;
	}
}


// metodo main
int main(){
	int valor;
	char  origen, destino;
	int op = 0;
	char nodo1, nodo2;
	Grafo grafoX;
	do{
		grafoX.menu();
		cin>>op;
		switch(op){
			case 1:
				grafoX.agregarNodo();
				break;
			case 2:
				printf("Ingrese primero un nodo y luego el siguiente (ejm: A, B, C) deben ser existentes\n");
				printf("Nodo 1: "); cin>>nodo1;
				printf("Nodo 2: "); cin>>nodo2;
				
				if(isCharacter(nodo1) && isCharacter(nodo2)){
					printf("Valor: "); cin>>valor;
					grafoX.generarConexion(nodo1, nodo2, valor);
				}else {
					printf("Caracteres no validos\n");
				}
				break;
			case 3:
				grafoX.mostrarNodos();
				break;
			case 4:
				grafoX.mapaAdyacencia();
				break;
			case 5:
				grafoX.mapaAdyacencia2(valor);	
				break;
			case 6:
				cout<<"Ingrese la ruta que quieres trasar: \n";
				cout<<"Origen: "; cin>>origen;
				cout<<"Destino: "; cin>>destino;
				grafoX.rutaMasCorta(origen, destino);
				break;
			case 7:
				printf("Ingrese el nodo a eliminar debe ser existente: \n"); 
				cin>>nodo1;
				grafoX.eliminarNodo(nodo1);
				break;
			case 8:
				printf("Ingrese la conexion que desea eliminar, debe ser existente\n");
				printf("Nodo 1: "); cin>>nodo1;
				printf("Nodo 2: "); cin>>nodo2;
				grafoX.borrarConexion(nodo1, nodo2);
				break;
			case 0:
				printf("\n Saliendo...");
				exit(0);
				break;
			default:
				printf("\n  Opcion Invalida");
		}
	}while(op!=0);
	return 0;
}
