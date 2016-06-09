/* 
 * File:   grafo.cpp
 * Author: Valentín Q
 *
 * Created on June 7, 2016, 6:45 PM
 */

#include "grafo.h"
#include <vector>
#include <iostream>

using namespace std;

Grafo::Grafo(int nNodos){
    vector<vector<short>> mAdyacencia(nNodos, vector<short>(nNodos,0));
}


