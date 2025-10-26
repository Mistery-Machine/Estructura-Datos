#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>
#include "ListaProductos.h"
using namespace std; 

class Cliente {
private: 
    string nombre; 
    string cedula;
    int prioridad; // 1 = ordinario, 2 = regular, 3 = alta prioridad
    ListaProductos carritoCompras;

public: 
    Cliente(string n, string c, int p);
    ~Cliente(); 

    // Getters y Setters
    string getNombre();
    string getCedula();
    int getPrioridad();

    void setNombre(string n);
    void setCedula(string c);
    void setPrioridad(int p);

    // Métodos
    void mostrarDatos();

    // Carrito
    void agregarProducto(int id, string nombre, double precio, int cantidad);
    void eliminarProducto(string nombre);
    void mostrarCarrito();
    void generarReporte();
};

#endif