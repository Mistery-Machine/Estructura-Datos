#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H
#include "Producto.h"
#include <string>

class ListaProductos{
    private: 
        Producto* primero;
        
    public: 

        Producto* getPrimero();
        Producto* getUltimo();

        ListaProductos(){
            primero = nullptr;
        };

        ~ListaProductos();

        void insertarInicio(int pId, std::string pNombre, double pPrecio, int pCantidad);
        void insertarFinal(int pId, std::string pNombre, double pPrecio, int pCantidad);


        Producto* buscar(int idBuscar);
        Producto* buscar(std::string nombreBuscar);
        Producto* eliminar(std::string nombreEliminar);

        void imprimir();




};

#endif