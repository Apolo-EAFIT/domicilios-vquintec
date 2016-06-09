/* 
 * File:   grafo.h
 * Author: Valentín Q
 *
 * Created on June 7, 2016, 6:56 PM
 */

#pragma once

#include <iostream>
#include <vector>
#include "nodo.h"

class Grafo {
public:
    Grafo(int nNodos);
    getNodo(int nodo);
    
private:
    int nNodos;
    //vector<Nodo> listaNodo;
};