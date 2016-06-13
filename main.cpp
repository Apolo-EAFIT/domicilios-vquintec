/* 
 * File:   main.cpp
 * Author: Valentín Q
 *
 * Created on June 3, 2016, 3:02 PM
 */
#include "grafo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h> /* stoi */
#include <limits.h>
#include <algorithm>

using namespace std;


void imprimirM(vector<vector<short>> mAdyacencia){
    for(int i = 0;i < mAdyacencia.size();i++){
        for(int j = 0;j < mAdyacencia.size();j++){
            cout << mAdyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int mindistance(int dist[],int sptset[],int V){
    // Initialize min value
    int min=INT_MAX,min_index,v;

    for(v=0;v<V;v++)
        if(sptset[v]==0 && dist[v]<=min)
            min=dist[v],min_index=v;

    return min_index;
}

// A utility function to print the constructed distance array
vector<string> print(int dist[],int path[],int dest, int src, int V){
    vector<string> result(4);
    string ruta = to_string(dest) + " <- ";
    char buffer[33];
    result[0] = to_string(src); //Punto inicial
    result[1] = to_string(dest); //Punto final o destino
    result[2] = to_string(dist[dest]); //Distancia del recorrido
    while(path[dest]){
        ruta = ruta + to_string(path[dest]) + " <- ";
        dest=path[dest];
    }
    if(src == 0){
        ruta = ruta + to_string(src);
    }
    
    result[3] = ruta;
    return result;
}

/*
 * Tomado de: http://codepad.org/Jx9hMd3Z
 */
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
vector<string> dijkstra(vector< vector<short> > graph,int src,int dest){
    int V = graph.size();
    int dist[V],i,count,v; // The output array.  dist[i] will hold the shortest
                           // distance from src to i
    
    int sptset[V],path[V]; // sptSet[i] will true if vertex i is included in shortest
                           // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for(i=0;i<V;i++)
        dist[i]=INT_MAX, sptset[i]=0;

    // Distance of source vertex from itself is always 0
    dist[src]=0;
    path[src]=0;

    // Find shortest path for all vertices
    for(count=0;count<V-1;count++){
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = mindistance(dist,sptset,V);
        
        if(u==dest)
            break;
        
        // Mark the picked vertex as processed
        sptset[u]=1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for(v = 0;v < V;v++){
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v]
            if(!sptset[v]&& graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
                path[v]=u;
            }
        }
    }
    // Retorna un vector con los datos
    return print(dist,path,dest,src, V);
}

bool contains(vector<short> posExcluidas,int element){
    for(int i = 0;i < posExcluidas.size();i++){
        if(posExcluidas[i] == element){
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    string rutaM = "medellin_arcos.txt";
    Grafo *grafo = new Grafo(rutaM);
    
    vector<string> datosDijkstra(4);
    datosDijkstra = dijkstra(grafo->getGrafo(),0,4);
    
    ifstream domicilios("domicilios2.txt");
    
    string linea;
    getline(domicilios,linea);
    vector<string> infoArista;
    vector<short> posExcluidas;
    int contLinea = 1, puntoInicial, puntoFinal = 1;
    string ruta_final, aux;
    
    while(getline(domicilios,linea)){
        cout << "REPARTIDOR # " << contLinea << endl;
        infoArista = grafo->explode(linea,' ');
        posExcluidas.assign(infoArista.size()-1,-1);
        puntoInicial = stoi(infoArista[0]);
        int menor, posEvaluar, posActual = 0, acumDis;
        ruta_final = "";
        acumDis = 0;
        for(int i = 0;i < infoArista.size()-2;i++){
            
            menor = INT_MAX;
            for(int j = 1;j < infoArista.size()-1;j++){
                if(posActual != j){
                    datosDijkstra = dijkstra(grafo->getGrafo(),stoi(infoArista[posActual]),stoi(infoArista[j]));
                    if(stoi(datosDijkstra[2]) < menor && !contains(posExcluidas,j)){
                        menor = stoi(datosDijkstra[2]);
                        posEvaluar = j;
                        posExcluidas[i] = j;
                    }
                }
            }
            datosDijkstra = dijkstra(grafo->getGrafo(),stoi(infoArista[posActual]),stoi(infoArista[posEvaluar]));
            //cout << "Desde: " << datosDijkstra[0] << " Hasta: " << datosDijkstra[1] << " Se recorrieron: " << datosDijkstra[2] << " metros." << endl;
            //aux.assign(datosDijkstra[3].begin(),datosDijkstra[3].end());
            //reverse(aux.begin(), aux.end());
            //cout << "El camino recorrido fue: " << aux << endl;
            ruta_final = ruta_final + " <- " + datosDijkstra[3] + "\n";
            acumDis = acumDis + stoi(datosDijkstra[2]);
            posActual = posEvaluar;
            
            if(i == infoArista.size()-3){
                puntoFinal = stoi(infoArista[posActual]);
                //cout << "POSICION PARA VOLVER: " << puntoFinal << endl;
            }
            
        }
        cout << "RUTA FINAL: " << ruta_final << endl;
        cout << "Distancia total: " << acumDis << endl;
        datosDijkstra = dijkstra(grafo->getGrafo(),puntoFinal,puntoInicial);
        cout << "CAMINO DE VUELTA: " << endl;
        cout << "Desde: " << datosDijkstra[0] << " Hasta: " << datosDijkstra[1] << " Se recorrieron: " << datosDijkstra[2] << " metros." << endl;
        //aux.assign(datosDijkstra[3].begin(),datosDijkstra[3].end());
        //reverse(aux.begin(), aux.end());
        cout << "El camino recorrido fue: " << datosDijkstra[3] << endl;
        
        contLinea++;
    }
    
    
    return 0;
}

