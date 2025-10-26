#include "menu.h"
#include "Cliente.h"
#include <iostream>
#include <limits>

static void imprimirResultado(Producto* p){
    if(!p) std::cout<<"No encontrado\n";
    else p->imprimir();
}

void menu(){
    Cliente cli("Cliente Demo","1-1111-1111");
    int op=0;
    do{
        std::cout<<"\n=== MENÚ ===\n"
                 <<"1) Agregar producto\n"
                 <<"2) Mostrar productos\n"
                 <<"3) Ordenar por Selección\n"
                 <<"4) Ordenar por Mezcla\n"
                 <<"5) Búsqueda lineal\n"
                 <<"6) Búsqueda binaria (asegurar orden)\n"
                 <<"7) Salir\n> ";
        std::cin>>op;
        if(std::cin.fail()){ std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); continue; }
        if(op==1){
            int id,cant; double precio; std::string nombre;
            std::cout<<"ID: "; std::cin>>id; std::cout<<"Nombre: "; std::cin>>nombre;
            std::cout<<"Precio: "; std::cin>>precio; std::cout<<"Cantidad: "; std::cin>>cant;
            cli.agregarProducto(id,nombre,precio,cant);
        } else if(op==2){
            cli.mostrarProductos();
        } else if(op==3 || op==4){
            int atr, dir; std::cout<<"Atributo (1=id,2=nombre,3=precio,4=cantidad): "; std::cin>>atr;
            std::cout<<"Dirección (1=asc,2=desc): "; std::cin>>dir; bool asc = (dir==1);
            long long cmp = (op==3)? cli.ordenarSeleccion(atr,asc) : cli.ordenarMezcla(atr,asc);
            std::cout<<"Comparaciones: "<<cmp<<"\n"; cli.mostrarProductos();
        } else if(op==5){
            int atr; std::cout<<"Atributo (1=id,2=nombre,3=precio,4=cantidad): "; std::cin>>atr;
            long long cmp=0; Producto* res=nullptr;
            if(atr==1 || atr==4){ int v; std::cout<<"Valor entero: "; std::cin>>v; res=cli.buscarLineal(atr,v,cmp); }
            else if(atr==3){ double v; std::cout<<"Valor real: "; std::cin>>v; res=cli.buscarLineal(atr,v,cmp); }
            else { std::string v; std::cout<<"Valor texto: "; std::cin>>v; res=cli.buscarLineal(atr,v,cmp); }
            std::cout<<"Comparaciones: "<<cmp<<"\n"; imprimirResultado(res);
        } else if(op==6){
            int atr, dir; std::cout<<"Atributo (1=id,2=nombre,3=precio,4=cantidad): "; std::cin>>atr;
            std::cout<<"Dirección (1=asc,2=desc): "; std::cin>>dir; bool asc = (dir==1);
            long long cmp=0; Producto* res=nullptr;
            if(atr==1 || atr==4){ int v; std::cout<<"Valor entero: "; std::cin>>v; res=cli.buscarBinaria(atr,v,asc,cmp,true); }
            else if(atr==3){ double v; std::cout<<"Valor real: "; std::cin>>v; res=cli.buscarBinaria(atr,v,asc,cmp,true); }
            else { std::string v; std::cout<<"Valor texto: "; std::cin>>v; res=cli.buscarBinaria(atr,v,asc,cmp,true); }
            std::cout<<"Comparaciones: "<<cmp<<"\n"; imprimirResultado(res);
        }
    }while(op!=7);
}
