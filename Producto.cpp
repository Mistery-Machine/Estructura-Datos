#include "Producto.h"
#include <iostream>

Producto::Producto(int pid, const std::string& pnom, double pprecio, int pcant)
: id(pid), nombre(pnom), precio(pprecio), cantidad(pcant), siguiente(nullptr) {}

int Producto::getId() const { return id; }
const std::string& Producto::getNombre() const { return nombre; }
double Producto::getPrecio() const { return precio; }
int Producto::getCantidad() const { return cantidad; }

Producto* Producto::getSiguiente() const { return siguiente; }
void Producto::setSiguiente(Producto* p){ siguiente = p; }

void Producto::imprimir() const{
    std::cout << "ID:" << id
              << " | Nombre:" << nombre
              << " | Precio:" << precio
              << " | Cantidad:" << cantidad << "\n";
}
