#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
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

Equipo simularPartido(Equipo& equipoLocal, Equipo& equipoVisitante) {
	int golesLocal = rand() % 3;
    int golesVisitante = rand() % 3;
    int contar = 0;

    cout
    << "\n|----------------------------|"
    << "\n|         RESULTADO          |" 
    << "\n|----------------------------|"
    << "\n    " 
	<< equipoLocal.pais 
	<< " [" 
	<< golesLocal 
	<< "] - [" 
	<< golesVisitante
	<< "] " 
	<< equipoVisitante.pais
	<< "\n|----------------------------|"
    <<endl;
	
	equipoLocal.goles +=golesLocal;
	equipoVisitante.goles += golesVisitante;    

    if (equipoLocal.goles > equipoVisitante.goles) {
        equipoLocal.puntos += 3;
        return equipoLocal;
    } else if (equipoLocal.goles < equipoVisitante.goles) {
        equipoVisitante.puntos += 3;
        return equipoVisitante; 
    }else{
    	equipoLocal.puntos +=1;
    	equipoVisitante.puntos +=1;
	}
    
    equipoLocal.tarjetasAmarillas += rand() % 3;
    equipoVisitante.tarjetasAmarillas += rand() % 3;

    equipoLocal.tarjetasRojas += rand() % 2;
    equipoVisitante.tarjetasRojas += rand() % 2;
    
        if (equipoLocal.puntos > equipoVisitante.puntos) {
        return equipoLocal;
    } else {
        return equipoVisitante;
    }
}

void Mostrar(const vector<Equipo>& equipos) {
    cout << "\nResultados finales de la fase de grupos:" << endl;
    int numEquipos = equipos.size();
    int maxEquipos = min(4, numEquipos);
    for (int i = 0; i < maxEquipos; ++i) {
        cout 
            << "\n |---------------------------|"
            << "\n        (" 
			<< equipos[i].pais 
			<< "):"
            << "\n |    Puntos-"  
			<< equipos[i].puntos 
			<< "               |" 
            << "\n |     Goles-"
			<< equipos[i].goles 
			<< "               |" 
            << "\n |        TA-" 
			<< equipos[i].tarjetasAmarillas 
			<< "               |" 
            << "\n |        TR-" 
			<< equipos[i].tarjetasRojas 
			<< "               |"
            << "\n |---------------------------|" 
            << endl;
    }
    if(numEquipos >= 4){
    	cout<<" "<<endl;
	}
}

void simularPartidos(vector<Equipo>& equipos, vector<Equipo>& ganadoresFase) {
    int numEquipos = equipos.size();
    int partidosJugados = 0;
    for (int i = 0; i < numEquipos; i+=2) {
            if (partidosJugados >= 4) {
                break;
            }
			     
            cout << "\n|----------------------------|"
                 << "\n|  Simulando partido entre   |" 
                 << "\n|----------------------------|"
                 << "\n      " 
                 << equipos[i].pais 
                 << " y " 
                 << equipos[i+1].pais
                 << "\n|----------------------------|"
                 << endl;
                    
            Equipo ganador = simularPartido(equipos[i], equipos[i+1]);
            ganadoresFase.push_back(ganador);
            
            cout<< "\n|-------------------------|"
                << "\n| Equipo ganador: " 
				<< ganador.pais
                << "\n|-------------------------|"
                << endl;
                
    		cout << "\n|-------------------------|"
         		 << "\n|   Ganador de la fase    |" 
         		 << "\n|-------------------------|"
         		 << "\n|   " 
				 << ganadoresFase[0].pais 
				 << "   |"
         		 << "\n|-------------------------|"
         		 << endl;
            
            partidosJugados++;
    }
}

Nodo* crearArbol(vector<Equipo>& ganadoresFase, int inicio, int fin){
	if (inicio>fin) return nullptr;
	
	int medio = (inicio + fin)/2;
	Nodo* raiz = new Nodo(ganadoresFase[medio]);
	raiz->izquierda = crearArbol(ganadoresFase, inicio, medio -1);
	raiz->derecha = crearArbol(ganadoresFase, medio +1, fin);
	
	return raiz;	
}

Nodo* crearArbolEliminacion(vector<Equipo>& ganadoresEliminacion, int inicio, int fin){
	if (inicio>fin) return nullptr;
	
	int medio = (inicio + fin)/2;
	Nodo* raiz = new Nodo(ganadoresEliminacion[medio]);
	raiz->izquierda = crearArbolEliminacion(ganadoresEliminacion, inicio, medio -1);
	raiz->derecha = crearArbolEliminacion(ganadoresEliminacion, medio +1, fin);
	
	return raiz;	
}

Equipo simularFinal(Nodo* raiz) {
    if (!raiz) return {"", "", 0, 0, 0, 0};

    Equipo equipoLocal = simularFinal(raiz->izquierda);
    Equipo equipoVisitante = simularFinal(raiz->derecha);

    return simularPartido(equipoLocal, equipoVisitante);
}

void procesarBloque(const vector<string>& bloque, vector<Equipo>& equipos) {
    if (bloque.size() != 4) {
        cerr << "Error: El bloque no tiene 4 lineas." << endl;
        return;
    }

    string pais, entrenador;
    for (int i = 0; i < 4; ++i) {
        stringstream ss(bloque[i]);
        getline(ss, pais, ',');
        ss.ignore();
        getline(ss, entrenador, '-');
        equipos.push_back({pais, entrenador, 0, 0, 0, 0});
    }
}

void simularEliminacionDirecta(vector<Equipo>& ganadoresFase, vector<Equipo>& ganadoresEliminacion) {
    // Simular octavos de final   
    for (int i = 0; i < ganadoresFase.size(); i += 2) {
        cout << "\n|-------------------------|"
             << "\n|Simulando octavos de final|" 
             << "\n|-------------------------|"
             << "\n      " 
			 << ganadoresFase[i].pais 
			 << " vs " 
			 << ganadoresFase[i+1].pais
             << "\n|-------------------------|"
             << endl;

        Equipo ganador = simularPartido(ganadoresFase[i], ganadoresFase[i+1]);
        ganadoresEliminacion.push_back(ganador);
        cout << "\n|--------------------------|"
             << "\n|         RESULTADO        |" 
             << "\n|--------------------------|"
             << "\n    " 
			 << ganadoresFase[i].pais 
			 << " [" 
			 << ganadoresFase[i].goles 
			 << "] - [" 
			 << ganadoresFase[i+1].goles 
			 << "] " 
			 << ganadoresFase[i+1].pais  
             << "\n|--------------------------|"
             << "\n| Equipo ganador: " 
			 << ganadoresFase[0].pais
             << "\n|--------------------------|"
             << endl;
    }  
    
    vector<Equipo> ganadoresCuartos;
    for (int i = 0; i < ganadoresEliminacion.size(); i += 2) {
        cout << "\n|-------------------------|"
             << "\n|Simulando cuartos de final|" 
             << "\n|-------------------------|"
             << "\n      " 
			 << ganadoresEliminacion[i].pais 
			 << " vs " 
			 << ganadoresEliminacion[i+1].pais
             << "\n|-------------------------|"
             << endl;

        Equipo ganador = simularPartido(ganadoresEliminacion[i], ganadoresEliminacion[i+1]);
        ganadoresCuartos.push_back(ganador);
        cout << "\n|------------------------|"
             << "\n|       RESULTADO        |" 
             << "\n|------------------------|"
             << "\n    " 
			 << ganadoresEliminacion[i].pais 
			 << " [" 
			 << ganadoresEliminacion[i].goles 
			 << "] - [" 
			 << ganadoresEliminacion[i+1].goles 
			 << "] " 
			 << ganadoresEliminacion[i+1].pais  
             << "\n|------------------------|"
             << "\n| Equipo ganador: " 
			 << ganador.pais
             << "\n|------------------------|"
             << endl;
    }
	    
    vector<Equipo> ganadoresSemifinales;
    for (int i = 0; i < ganadoresCuartos.size(); i += 2) {
        cout << "\n|-------------------------|"
             << "\n|Simulando semifinales    |" 
             << "\n|-------------------------|"
             << "\n      " 
			 << ganadoresCuartos[i].pais 
			 << " vs " 
			 << ganadoresCuartos[i+1].pais
             << "\n|-------------------------|"
             << endl;

        Equipo ganador = simularPartido(ganadoresCuartos[i], ganadoresCuartos[i+1]);
        ganadoresSemifinales.push_back(ganador);
        cout << "\n|------------------------|"
             << "\n|       RESULTADO        |" 
             << "\n|------------------------|"
             << "\n    " 
			 << ganadoresCuartos[i].pais 
			 << " [" 
			 << ganadoresCuartos[i].goles 
			 << "] - [" 
			 << ganadoresCuartos[i+1].goles 
			 << "] " 
			 << ganadoresCuartos[i+1].pais  
             << "\n|------------------------|"
             << "\n| Equipo ganador: " 
			 << ganador.pais
             << "\n|------------------------|"
             << endl;
    }

    // Simular final
    cout << "\n|-------------------------|"
         << "\n|   Simulando la final    |" 
         << "\n|-------------------------|"
         << "\n      " 
		 << ganadoresSemifinales[0].pais 
		 << " vs " 
		 << ganadoresSemifinales[1].pais
         << "\n|-------------------------|"
         << endl;

    Equipo ganadorFinal = simularPartido(ganadoresSemifinales[0], ganadoresSemifinales[1]);
    cout << "\n|------------------------|"
         << "\n|       RESULTADO        |" 
         << "\n|------------------------|"
         << "\n    " 
		 << ganadoresSemifinales[0].pais 
		 << " [" 
		 << ganadoresSemifinales[0].goles 
		 << "] - [" 
		 << ganadoresSemifinales[1].goles 
		 << "] " 
		 << ganadoresSemifinales[1].pais  
         << "\n|------------------------|"
         << "\n| Equipo ganador: " 
		 << ganadorFinal.pais
         << "\n|------------------------|"
         << endl;

    cout << "\n|-------------------------|"
         << "\n|   Ganador de la final   |" 
         << "\n|-------------------------|"
         << "\n|   " 
		 << ganadorFinal.pais 
		 << "   |"
         << "\n|-------------------------|"
         << endl;

}

void faseEliminacionDirecta() {
	vector<Equipo> equipos;
    vector<Equipo> ganadoresEliminacion;
    vector<Equipo> ganadoresFase;
    
    cout<<"Simular fase de grupos: "<<endl;
    simularPartidos(equipos, ganadoresFase);
    Mostrar(equipos);
    
    cout<<"Simular fase de eliminacion: "<<endl;
    simularEliminacionDirecta(ganadoresFase, ganadoresEliminacion);
}

void partido(){     
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
    
    vector<string> bloque;
    int contadorLineas = 0;
    bool faseFinal = false;
	int lineaFinal = -1;
	 // Variable para controlar si se ha llegado al final del archivo
    
    while (getline(archivoEquipos, linea)) {
        ++contadorLineas;
        if (contadorLineas <= lineaFinal) {
            continue;
        }
        
        // Si encuentra el carácter "-", verifica si hay al menos 4 equipos en el bloque actual
        if (linea.find("-") != string::npos) {
            if (equipos.size() >= 4) {
                procesarBloque(bloque, equipos);
                simularPartidos(equipos, ganadoresFase);
                Mostrar(equipos);
                faseFinal = true; // Indica que se ha completado la fase de grupos
            }
            // Reinicia el contador y los vectores para el siguiente bloque
            contadorLineas = 0;
            equipos.clear();
            bloque.clear();
        }
        // Si no ha llegado al final de la fase de grupos, continúa leyendo y procesando equipos
        else if (!faseFinal) {
            bloque.push_back(linea);
            // Cuando se alcanzan 4 líneas, procesa el bloque y reinicia para el siguiente
            if (contadorLineas == 4) {
                procesarBloque(bloque, equipos);
                contadorLineas=0;
                bloque.clear();
            }
        }
        
        // Si se ha llegado al final de la fase final, sale del bucle
       if (faseFinal) {
            lineaFinal = contadorLineas;
            break;
        }
    }
    
    archivoEquipos.close();
    
    // Si no se ha completado la fase de grupos, muestra un mensaje
    if (!faseFinal) {
        cout << "No se encontraron suficientes equipos para simular la fase de grupos." << endl;
    }
    
    Nodo* raiz = crearArbol(ganadoresFase, 0, ganadoresFase.size() - 1);
    Equipo campeon = simularFinal(raiz);
    
   ofstream archivoGanadores;
    archivoGanadores.open("ganadores_fase.txt",ios::out);
    if (archivoGanadores.is_open()) {
        for (int i=0; i<ganadoresFase.size(); i++) {
            archivoGanadores << ganadoresFase[i].pais << "," 
			<< ganadoresFase[i].entrenador 
                << "," << ganadoresFase[i].puntos << endl; 
        }
        archivoGanadores.close();
    } else {
        cerr << "No se pudo abrir el archivo 'ganadores_fase.txt'" << endl;
    }
}

void menu (){
    system("color f5");
    cout<<"\n|-------------------------- |";
    cout<<"\n|         *MUNDIAL*         |";
    cout<<"\n|---------------------------|";
    cout<<"\n|     1.Fase de grupos      |";
    cout<<"\n|     2.Eliminacion directa |";
    cout<<"\n|     3.Final               |";
    cout<<"\n|     0.Salir               |";
    cout<<"\n|---------------------------|";
    cout<<"\n Escoja una Opcion: ";
}

int main() {
    int opcion;
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
                    cout << "\n Simulando Partido Eliminacion directa: \n"<<endl;
                    faseEliminacionDirecta();
                    break;
                    
                    case 0:
                    cout<<"Saliendo..."<<endl;
                    break;
                    
                    default:
                    cout<<"\n  Opcion Invalida"<<endl;
                }
 }while(opcion!=0);
return 0;
}

