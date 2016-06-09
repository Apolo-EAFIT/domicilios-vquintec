/* 
 * File:   nodo.h
 * Author: ValentinQ
 *
 * Created on 8 de junio de 2016, 08:01 PM
 */

#pragma once

class Nodo {
public:
    Nodo();
    Nodo(int dato);
    int getDato();
    void setNAntecesor(Nodo nAntecesor);
    Nodo getNAntecesor();
    void setPesoAcum(int pesoAcum);
    int getPesoAcum();
    void setMarca(bool marca);
    bool getMarca();
    void setVisitado(bool visitado);
    bool isVisitado();
    
private:
    int dato;
    Nodo nAntecesor;
    int pesoAcum;
    bool marca;
    bool visitado = false;
};
