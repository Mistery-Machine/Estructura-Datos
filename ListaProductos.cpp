#include "ListaProductos.h"
#include <iostream>

ListaProductos::ListaProductos(): primero(nullptr){}

ListaProductos::~ListaProductos(){
    Producto* cur = primero;
    while(cur){ Producto* nxt = cur->getSiguiente(); delete cur; cur = nxt; }
}

bool ListaProductos::estaVacia() const{ return primero==nullptr; }
Producto* ListaProductos::getPrimero() const{ return primero; }
void ListaProductos::setPrimero(Producto* p){ primero = p; }

void ListaProductos::insertarFinal(int id, const std::string& nombre, double precio, int cantidad){
    Producto* nuevo = new Producto(id,nombre,precio,cantidad);
    if(!primero){ primero = nuevo; return; }
    Producto* cur = primero; while(cur->getSiguiente()) cur = cur->getSiguiente();
    cur->setSiguiente(nuevo);
}

int ListaProductos::size() const{
    int n=0; Producto* cur = primero; while(cur){ n++; cur = cur->getSiguiente(); }
    return n;
}

void ListaProductos::imprimir() const{
    if(!primero){ std::cout<<"(lista vacía)\n"; return; }
    Producto* cur = primero; while(cur){ cur->imprimir(); cur = cur->getSiguiente(); }
}
