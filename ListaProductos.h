#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H
#include "Producto.h"

class ListaProductos{
private:
    Producto* primero;
public:
    ListaProductos();
    ~ListaProductos();

    bool estaVacia() const;
    Producto* getPrimero() const;
    void setPrimero(Producto* p);

    void insertarFinal(int id, const std::string& nombre, double precio, int cantidad);
    int size() const;
    void imprimir() const;
};

#endif
