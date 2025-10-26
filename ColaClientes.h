#ifndef COLACLIENTES_H
#define COLACLIENTES_H

#include "Cliente.h"
#include <iostream>
using namespace std;

class NodoCliente {
private:
    Cliente* cliente;
    NodoCliente* siguiente;

public:
    NodoCliente(Cliente* c) {
        cliente = c;
        siguiente = nullptr;
    }

    Cliente* getCliente() { return cliente; }
    NodoCliente* getSiguiente() { return siguiente; }
    void setSiguiente(NodoCliente* sig) { siguiente = sig; }
};

class ColaClientes {
private:
    NodoCliente* frente;

public:
    ColaClientes();
    ~ColaClientes();

    void insertar(Cliente* nuevoCliente);
    void atender();
    void mostrarCola();
    bool estaVacia();
};

#endif