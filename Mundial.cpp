#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct Equipo {
    string pais;
    string entrenador;
    int puntos;
    int goles;
    int tarjetasAmarillas;
    int tarjetasRojas;
};

struct Nodo {
	Equipo equipo;
	Nodo* izquierda;
	Nodo* derecha;
	
	Nodo(Equipo equipo) : equipo(equipo), izquierda(nullptr), derecha(nullptr){}
};

Equipo simularPartido(Equipo &equipoLocal, Equipo &equipoVisitante) {
    
	int golesLocal = rand() % 3; 
    int golesVisitante = rand() % 3; 

    equipoLocal.goles += golesLocal;
    equipoVisitante.goles += golesVisitante;

    if (golesLocal > golesVisitante) {
        equipoLocal.puntos += 3;
		return equipoLocal;
    } else if (golesLocal < golesVisitante) {
        equipoVisitante.puntos += 3;
		return equipoVisitante; 
    } else {
        equipoLocal.puntos += 1; 
        equipoVisitante.puntos += 1;
        return equipoLocal;
    }

    equipoLocal.tarjetasAmarillas += rand() % 3;
    equipoVisitante.tarjetasAmarillas += rand() % 3;

    equipoLocal.tarjetasRojas += rand() % 2;
    equipoVisitante.tarjetasRojas += rand() % 2;
}


Nodo* crearArbol(vector<Equipo>& ganadoresFase, int inicio, int fin){
	if (inicio>fin) return nullptr;
	
	int medio = (inicio + fin)/2;
	Nodo* raiz = new Nodo(ganadoresFase[medio]);
	raiz->izquierda = crearArbol(ganadoresFase, inicio, medio -1);
	raiz->derecha = crearArbol(ganadoresFase, medio +1, fin);
	
	return raiz;
	
}

Equipo simularFinal(Nodo* raiz) {
    if (!raiz) return {"", "", 0, 0, 0, 0};

    Equipo equipoLocal = simularFinal(raiz->izquierda);
    Equipo equipoVisitante = simularFinal(raiz->derecha);

    return simularPartido(equipoLocal, equipoVisitante);
}

void partido (){
	srand(time(NULL));
	
    vector<Equipo> equipos;
    vector<Equipo> ganadoresFase;
    
    string linea;
    ifstream archivoEquipos;
	archivoEquipos.open("Equipos.txt",ios::in); 
	   
    if(archivoEquipos.fail()) {
        cerr << "No se pudo abrir el archivo 'Equipos.txt'" << endl;
        return;
    } 
    
    for(int i=0; i<3 && std::getline(archivoEquipos, linea); i++){      
        stringstream ss(linea);
        string pais, entrenador;
        getline(ss, pais, ',');
        getline(ss, entrenador);
        equipos.push_back({pais, entrenador, 0, 0, 0, 0}); 		 
    }
    archivoEquipos.close();

    for (int i = 0; i < equipos.size(); ++i) {
        for (int j = i + 1; j < equipos.size(); ++j) {
            cout << "\n |-------------------------|"
			<< 		"\n |*Simulando partido entre*|" 
            <<      "\n |-------------------------|"
			<<"\n      "<<equipos[i].pais<<" y "<<equipos[j].pais
			<<      "\n |-------------------------|"
			<< endl;
            
            cout 
            << "\n |------------------------|"
            << "\n |      *RESULTADOS*      |" 
            << "\n |------------------------|"
			<< "\n    " 
			<< equipos[i].pais 
			<< " [" 
			<< equipos[i].goles 
			<< "] - [" << 
			equipos[j].goles 
			<< "]" 
			<< equipos[j].pais  
			<<"\n |------------------------|"
			<< endl;
			
			Equipo ganador = simularPartido(equipos[i], equipos[j]);
            ganadoresFase.push_back(ganador);
    }
}

cout << "\nResultados finales de la fase de grupos:" << endl;
    	for (int i = 0; i < equipos.size(); ++i){
        cout 
        <<"\n |---------------------------|"
		<<"\n        ("
		<< equipos[i].pais 
		<<"):"
		<<"\n |     Puntos-"  
		<< equipos[i].puntos
		<<"              |" 
		<<"\n |      Goles-" 
		<< equipos[i].goles
		<<"              |" 
		<<"\n |         TA-" 
		<< equipos[i].tarjetasAmarillas
		<<"              |" 
		<<"\n |         TR-" 
		<< equipos[i].tarjetasRojas
		<<"              |"
		<<"\n |---------------------------|" 
		<< endl;
    }
    
    Nodo* raiz = crearArbol(ganadoresFase, 0, ganadoresFase.size() - 1);
    
    Equipo campeon = simularFinal(raiz);
    
    cout<<"El campeon del torneo es: "<<campeon.pais <<endl;
    
    ofstream archivoGanadores;
	archivoGanadores.open("ganadores_fase.txt",ios::out);
    if (archivoGanadores.is_open()) {
        for (int i=0; i<ganadoresFase.size(); i++) {
            archivoGanadores << ganadoresFase[i].pais << "," << ganadoresFase[i].entrenador 
			<< "," << ganadoresFase[i].puntos << endl; 
        }
        archivoGanadores.close();
    } else {
        cerr << "No se pudo abrir el archivo 'ganadores_fase.txt'" << endl;
    }
    
    cout<<"Ganadores: "<<ganadoresFase.size()<<endl;
}

void menu (){
	system("color f5");
	cout<<"\n|-------------------------- |";
	cout<<"\n|         *MUNDIAL*         |";
	cout<<"\n|---------------------------|";
	cout<<"\n|     1.Fase de grupos      |";
	cout<<"\n|     2.Partido a Partido   |";
	cout<<"\n|     3.Final               |";
	cout<<"\n|     0.Salir               |";
	cout<<"\n|---------------------------|";
	cout<<"\n Escoja una Opcion: ";
}

int main() {
	int opcion, texto;
    do{	
		system("color f5");
		menu();
		cin>>opcion;
        switch(opcion){
            		case 1:
            		cout<<"\n Simulando Fase de grupo: \n\n";
					partido();
            	    break;
					
					case 2:
					cout << "\n Simulando Partido: \n"<<endl;
            		break;
            	
            		case 3:
            		cout<<" "<<endl;
            		break;
            	
            		case 4:
            		cout<<" "<<endl;            	
            		break;
       				
					case 0:
					cout<<"Saliendo..."<<endl;
					break;
					
					default:
					cout<<"\n  Opcion Invalida"<<endl;
			    }
		system("pause");
		system("cls");
 }while(opcion!=0);
return 0;
}
