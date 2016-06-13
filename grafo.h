/* 
 * File:   grafo.h
 * Author: Valentín Q
 *
 * Created on June 7, 2016, 6:56 PM
 */
#pragma once

#include "nodo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Grafo {
public:
    Grafo(string ruta);
    int getNroNodos();
    vector<string> explode(string const & s, char delim);
    vector< vector<short> > getGrafo();
    void llenarMatrizAdya();
    void setPeso(int nInicio, int nFin, int peso);
    int getPeso(int nInicio, int nFin);
    
private:
    ifstream fAristas, domicilios;
    vector< vector<short> > mAdyacencia;
    vector<Nodo> nodo;
};