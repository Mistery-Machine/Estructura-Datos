#include "ColaClientes.h"

ColaClientes::ColaClientes() {
    frente = nullptr;
}

ColaClientes::~ColaClientes() {
    while (!estaVacia()) {
        atender();
    }
}

bool ColaClientes::estaVacia() {
    return frente == nullptr;
}

void ColaClientes::insertar(Cliente* nuevoCliente) {
    NodoCliente* nuevoNodo = new NodoCliente(nuevoCliente);

    // Si la cola está vacía
    if (frente == nullptr) {
        frente = nuevoNodo;
        cout << "Cliente agregado al inicio de la cola.\n";
        return;
    }

    // Si el cliente tiene mayor prioridad que el primero
    if (nuevoCliente->getPrioridad() > frente->getCliente()->getPrioridad()) {
        nuevoNodo->setSiguiente(frente);
        frente = nuevoNodo;
        cout << "Cliente agregado con prioridad más alta.\n";
        return;
    }

    // Buscar posición adecuada
    NodoCliente* actual = frente;
    while (actual->getSiguiente() != nullptr &&
           actual->getSiguiente()->getCliente()->getPrioridad() >= nuevoCliente->getPrioridad()) {
        actual = actual->getSiguiente();
    }

    nuevoNodo->setSiguiente(actual->getSiguiente());
    actual->setSiguiente(nuevoNodo);
    cout << "Cliente agregado al final de la cola.\n";
}

void ColaClientes::atender() {
    if (estaVacia()) {
        cout << "No hay clientes en la cola.\n";
        return;
    }

    NodoCliente* temp = frente;
    frente = frente->getSiguiente();

    cout << "\nAtendiendo cliente:\n";
    temp->getCliente()->mostrarDatos();

    delete temp;
}

void ColaClientes::mostrarCola() {
    if (estaVacia()) {
        cout << "\nNo hay clientes en la cola.\n";
        return;
    }

    cout << "\n--- CLIENTES EN COLA ---\n";
    NodoCliente* actual = frente;
    while (actual != nullptr) {
        actual->getCliente()->mostrarDatos();
        actual = actual->getSiguiente();
    }
}