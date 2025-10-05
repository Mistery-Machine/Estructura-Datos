#include "ListaProductos.h"
#include <iostream>

ListaProductos::~ListaProductos(){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"es_ES.UTF-8");
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        std::cout <<"La lista esta vacía"<< std::endl;
    }
    while(nodoTemp!=nullptr){
        Producto* siguiente = nodoTemp -> getSiguiente();
        delete nodoTemp;
        nodoTemp = siguiente;
    }    
    primero = nullptr;
}

Producto* ListaProductos::getPrimero(){
    return primero;
}

void ListaProductos::insertarInicio(
        int pId, 
        std::string pNombre, 
        double pPrecio, 
        int pCantidad){
    
    Producto* nuevoNodo = new Producto(
        pId,
        pNombre,
        pPrecio,
        pCantidad);

        nuevoNodo -> setSiguiente(nuevoNodo);
        primero = nuevoNodo;
            
        }


void ListaProductos::insertarFinal(
        int pId, 
        std::string pNombre, 
        double pPrecio, 
        int pCantidad){
    
    Producto* nuevoNodo = new Producto(
        pId,
        pNombre,
        pPrecio,
        pCantidad);

        if(primero==nullptr){
            primero=nuevoNodo;
        }
        //validar si el ID ya existe usando buscar. 
        else if(this -> buscar(pId) != nullptr){
            std::cout<<"El producto ya existe"<<std::endl;
            return;
        }
        else{
            Producto* ultimo = this -> getUltimo();
            ultimo -> setSiguiente(nuevoNodo);
            std::cout<<"El producto ha sido insertado al final de la lista"<<std::endl;
        }
            
        }

Producto* ListaProductos::getUltimo(){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"es_ES.UTF-8");
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        std::cout <<"La lista esta vacía"<< std::endl;
    }

    while(nodoTemp -> getSiguiente() != nullptr){
        nodoTemp= nodoTemp->getSiguiente();
    }
    return nodoTemp;
}

Producto* ListaProductos::buscar(std::string nombreBuscar){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"es_ES.UTF-8");
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        std::cout <<"La lista esta vacía"<< std::endl;
    }

    while(nodoTemp -> getNombre() != nombreBuscar &&
        nodoTemp -> getSiguiente() != nullptr){
        nodoTemp= nodoTemp->getSiguiente();
    }
    if(nodoTemp -> getNombre() == nombreBuscar){
        std::cout <<"Producto encontrado"<<std::endl;
        return nodoTemp;
    }else{
        std::cout <<"Producto no encontrado"<<std::endl;
        return nullptr;        
    }
}

//Sobrecarga de buscar para buscar por ID 

Producto* ListaProductos::buscar(int idBuscar){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"es_ES.UTF-8");
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        std::cout <<"La lista esta vacía"<< std::endl;
    }

    while(nodoTemp -> getId() != idBuscar &&
        nodoTemp -> getSiguiente() != nullptr){
        nodoTemp= nodoTemp->getSiguiente();
    }
    if(nodoTemp -> getId() == idBuscar){
        std::cout <<"Producto encontrado"<<std::endl;
        return nodoTemp;
    }else{
        std::cout <<"Producto no encontrado"<<std::endl;
        return nullptr;        
    }
}

Producto* ListaProductos::eliminar(std::string nombreEliminar){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"es_ES.UTF-8");
    Producto* nodoActual = primero;
    Producto* nodoAnterior = nullptr;
    bool encontrado = false;

    while ((nodoActual != nullptr)&& !encontrado){
        encontrado = nodoActual -> getNombre() == nombreEliminar;
        if(!encontrado){
            nodoAnterior = nodoActual;
            nodoActual = nodoActual ->getSiguiente();
        }
    }
    if(nodoActual != nullptr){
        if(nodoActual == primero){
            primero = primero -> getSiguiente();
        }else{
            nodoAnterior -> setSiguiente(nodoActual-> getSiguiente());
        }
        std::cout <<"El producto ha sido eliminado de la lista"<<std::endl;
        delete nodoActual;
        return nodoActual;
    }
    std::cout<<"El producto no ha sido encontrado en la lista, por lo tanto no se eliminó"<<std::endl;
    return nullptr;
}

void ListaProductos::imprimir(){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"es_ES.UTF-8");
    Producto* nodoTemp = primero;
    if(nodoTemp == nullptr){
        std::cout <<"La lista esta vacía"<< std::endl;
    }
    while(nodoTemp!=nullptr){
        nodoTemp -> imprimir();
        nodoTemp = nodoTemp -> getSiguiente();
    }    
}