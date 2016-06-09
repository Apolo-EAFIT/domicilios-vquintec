/* 
 * File:   nodo.cpp
 * Author: Valentín Q
 *
 * Created on 8 de junio de 2016, 08:01 PM
 */

#include "nodo.h"

Nodo::Nodo():
        nAntecesor(false),
        dato(-1),
        pesoAcum(-1),
        marca(false)
{}

Nodo::Nodo(int dato):
        nAntecesor(false),
        dato(dato),
        pesoAcum(-1),
        marca(false)
{
    
}

int Nodo::getDato(){
    return this->dato;
}

void Nodo::setNAntecesor(Nodo nAntecesor){
    this->nAntecesor = nAntecesor;
}

Nodo Nodo::getNAntecesor(){
    return this->nAntecesor;
}

void Nodo::setPesoAcum(int pesoAcum){
    this->pesoAcum = pesoAcum;
}

int Nodo::getPesoAcum(){
    return this->pesoAcum;
}

void Nodo::setMarca(bool marca){
    this->marca = marca;
}

bool Nodo::getMarca(){
    return this->marca;
}

void Nodo::setVisitado(bool visitado){
    this->visitado = visitado;
}

bool Nodo::isVisitado(){
    return this->visitado;
}

