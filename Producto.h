#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class Producto{
private:
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    Producto* siguiente;
public:
    Producto(int pid, const std::string& pnom, double pprecio, int pcant);

    int getId() const;
    const std::string& getNombre() const;
    double getPrecio() const;
    int getCantidad() const;

    Producto* getSiguiente() const;
    void setSiguiente(Producto* p);

    void imprimir() const;
};

#endif
