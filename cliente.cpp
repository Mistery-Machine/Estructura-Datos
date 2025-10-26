#include "Cliente.h"
#include <iostream>
#include <windows.h>
using namespace std;

Cliente::Cliente(string n, string c, int p) {
    nombre = n;
    cedula = c;
    prioridad = p; 
}

Cliente::~Cliente() {
}

string Cliente::getNombre() {
    return nombre;
}

string Cliente::getCedula() {
    return cedula;
}

int Cliente::getPrioridad() {
    return prioridad;
}

void Cliente::setNombre(string n) {
    nombre = n;
}

void Cliente::setCedula(string c) {
    cedula = c;
}

void Cliente::setPrioridad(int p) {
    prioridad = p;
}

void Cliente::mostrarDatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Cédula: " << cedula << endl;
    cout << "Prioridad: ";

    switch (prioridad) {
        case 1:
            cout << "Cliente Ordinario";
            break;
        case 2:
            cout << "Cliente Regular";
            break;
        case 3:
            cout << "Cliente Preferencial (adulto mayor, discapacitado, embarazada)";
            break;
        default:
            cout << "Desconocida";
            break;
    }

    cout << endl << "---" << endl;
}


void Cliente::agregarProducto(int id, string nombre, double precio, int cantidad) {
    carritoCompras.insertarFinal(id, nombre, precio, cantidad);
    cout << "Producto agregado al carrito de " << this->nombre << "." << endl;
}

void Cliente::eliminarProducto(string nombre) {
    carritoCompras.eliminar(nombre);
}

void Cliente::mostrarCarrito() {
    cout << "\nCarrito de " << nombre << ":" << endl;
    carritoCompras.imprimir();
}

void Cliente::generarReporte() {
    Producto* actual = carritoCompras.getPrimero();
    double total = 0;

    cout << "\n--- Reporte de compra de " << nombre << " ---" << endl;

    if (actual == nullptr) {
        cout << "El carrito está vacío." << endl;
        return;
    }

    while (actual != nullptr) {
        double subtotal = actual->getPrecio() * actual->getCantidad();
        cout << actual->getNombre() << " x" << actual->getCantidad()
             << " = ₡" << subtotal << endl;
        total += subtotal;
        actual = actual->getSiguiente();
    }

    cout << "---" << endl;
    cout << "Total a pagar: ₡" << total << endl;
    cout << "---" << endl;
}