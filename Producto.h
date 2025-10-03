#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <windows.h>

class Producto
{
    // Atributos
private:
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    Producto *siguiente;

    // Metodos
public:
    // Constructor
    Producto(int pId, std::string pNombre, double pPrecio, int pCantidad)
    {
        SetConsoleOutputCP(CP_UTF8);
        setlocale(LC_ALL, "es_ES.UTF-8");

        id = pId;
        nombre = pNombre;
        precio - pPrecio;
        cantidad = pCantidad;
        siguiente = nullptr;
    }
    // Destructor
    ~Producto();

    // Getter
    int getId();
    std::string getNombre();
    double getPrecio();
    int getCantidad();
    Producto *getSiguiente();

    // Setters
    void setId(int nuevoId);
    void setNombre(std::string nuevoNombre);
    void setPrecio(double nuevoPrecio);
    void setCantidad(int nuevaCantidad);
    void setSiguiente(Producto *nuevoSiguiente);

    // Imprimir
    void imprimir();
};

#endif