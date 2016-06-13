/* 
 * File:   grafo.cpp
 * Author: Valentín Q
 *
 * Created on June 7, 2016, 6:45 PM
 */

#include "grafo.h"
#include <sstream>

using namespace std;
Grafo::Grafo(string ruta)
{
    fAristas.open(ruta);
    int nNodos = getNroNodos();
    
    mAdyacencia.assign(nNodos, vector<short>(nNodos,0));
    
    llenarMatrizAdya();
    
}

vector< vector<short> > Grafo::getGrafo(){
    return mAdyacencia;
}

void Grafo::llenarMatrizAdya(){
    string linea;
    int contLinea = 0;
    vector<string> infoArista;
    
    while(getline(fAristas,linea)){
        infoArista = explode(linea,' ');
        setPeso(stoi(infoArista[0]),stoi(infoArista[1]),stoi(infoArista[2]));
        contLinea++;
    }
}

void Grafo::setPeso(int nInicio, int nFin, int peso){
    mAdyacencia[nInicio][nFin] = peso;
}

int Grafo::getPeso(int nInicio, int nFin){
    return mAdyacencia[nInicio][nFin];
}

int Grafo::getNroNodos(){
    string linea;
    getline(fAristas,linea);
    return stoi(linea);
}

vector<string> Grafo::explode(string const & s, char delim){
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}
