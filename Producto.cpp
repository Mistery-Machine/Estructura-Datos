#include "Producto.h"
#include <iostream>
#include <windows.h>

// Destructor
Producto::~Producto()
{
    siguiente = nullptr;
}

int Producto::getId()
{
    return id;
}

std::string Producto::getNombre()
{
    return nombre;
}

double Producto::getPrecio()
{
    return precio;
}

int Producto::getCantidad()
{
    return cantidad;
}

Producto *Producto::getSiguiente()
{
    return siguiente;
}

// Setters
void Producto::setId(int nuevoId)
{
    id = nuevoId;
}
void Producto::setNombre(std::string nuevoNombre)
{
    nombre = nuevoNombre;
}
void Producto::setPrecio(double nuevoPrecio)
{
    precio = nuevoPrecio;
}
void Producto::setCantidad(int nuevaCantidad)
{
    cantidad = nuevaCantidad;
}
void Producto::setSiguiente(Producto *nuevoSiguiente)
{
    siguiente = nuevoSiguiente;
}

// imprimir

void Producto::imprimir()
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Precio: " << precio << std::endl;
    std::cout << "Cantidad: " << cantidad << "\n"
              << std::endl;
}