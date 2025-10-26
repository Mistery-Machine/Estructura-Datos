#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "ListaProductos.h"

class Cliente{
private:
    std::string nombre;
    std::string cedula;
    ListaProductos lista;

    Producto** aArreglo(int &n) const;
    int comparar(const Producto* a, const Producto* b, int atributo) const;
    int compararConValor(const Producto* a, int atributo, int v) const;
    int compararConValor(const Producto* a, int atributo, double v) const;
    int compararConValor(const Producto* a, int atributo, const std::string& v) const;

    void seleccion(Producto** arr, int n, int atributo, bool asc, long long &cmp) const;
    void mergeSort(Producto** arr, int n, int atributo, bool asc, long long &cmp) const;
    void mergeRec(Producto** arr, int l, int r, int atributo, bool asc, long long &cmp) const;
    void mergeDo(Producto** arr, int l, int m, int r, int atributo, bool asc, long long &cmp) const;

    bool estaOrdenado(Producto** arr, int n, int atributo, bool asc) const;
    void reencadenarDesdeArreglo(Producto** arr, int n);

public:
    Cliente(const std::string& n, const std::string& c);

    void agregarProducto(int id, const std::string& nombre, double precio, int cantidad);
    void mostrarProductos() const;

    long long ordenarSeleccion(int atributo, bool asc);
    long long ordenarMezcla(int atributo, bool asc);

    Producto* buscarLineal(int atributo, int v, long long &cmp);
    Producto* buscarLineal(int atributo, double v, long long &cmp);
    Producto* buscarLineal(int atributo, const std::string& v, long long &cmp);

    Producto* buscarBinaria(int atributo, int v, bool asc, long long &cmp, bool asegurarOrden=true);
    Producto* buscarBinaria(int atributo, double v, bool asc, long long &cmp, bool asegurarOrden=true);
    Producto* buscarBinaria(int atributo, const std::string& v, bool asc, long long &cmp, bool asegurarOrden=true);
};

#endif
