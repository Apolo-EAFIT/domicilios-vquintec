/* 
 * File:   main.cpp
 * Author: Valentín Q
 *
 * Created on June 3, 2016, 3:02 PM
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>     /* atoi */

using namespace std;


/*
 * Tomado de http://stackoverflow.com/questions/12966957/is-there-an-equivalent-in-c-of-phps-explode-function
 * Esta función se encarga de recibir un string y divirlo en un vector de string teniendo en cuenta un delimitador pasado por parametro
 */
vector<string> explode(string const & s, char delim){
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}

void imprimirM(vector<vector<int>> mAdyacencia, int nNodos){
    for(int i = 0;i < nNodos;i++){
        for(int j = 0;j < nNodos;j++){
            cout << mAdyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {
    
    ifstream fAristas("medellin_arcos.txt");
    
    int contLinea = 0, nDestino, nLlegada;
    string linea;
    
    vector<string> infoArista;
    
    //int mAdya[nroNodos][nroNodos]; Se explota el stack
    
    getline(fAristas,linea);
    const int nNodos = stoi(linea);
    vector<vector<short>> mAdyacencia(nNodos, vector<short>(nNodos,0));
    
    
    while(getline(fAristas,linea)){
        infoArista = explode(linea,' ');
        mAdyacencia[stoi(infoArista[0])][stoi(infoArista[1])] = stoi(infoArista[2]);
        contLinea++;
    }
    cout << contLinea << endl;
    //imprimirM(mAdyacencia, nNodos);
    return 0;
}


