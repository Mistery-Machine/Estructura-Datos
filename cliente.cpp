#include "Cliente.h"
#include <iostream>

// ---------- Constructor básico ----------
Cliente::Cliente(const std::string& n, const std::string& c)
: nombre(n), cedula(c) {}

// ---------- Operaciones de alto nivel ----------
void Cliente::agregarProducto(int id, const std::string& nombre, double precio, int cantidad){
    lista.insertarFinal(id,nombre,precio,cantidad);
}

void Cliente::mostrarProductos() const{
    lista.imprimir();
}

// ---------- Utilidades internas ----------
static int sgn(long long x){ return (x>0)-(x<0); }

Producto** Cliente::aArreglo(int &n) const{
    n = lista.size();
    Producto** arr = new Producto*[n];
    Producto* cur = lista.getPrimero();
    int i=0; 
    while(cur){ arr[i++]=cur; cur = cur->getSiguiente(); }
    return arr;
}

int Cliente::comparar(const Producto* a, const Producto* b, int atributo) const{
    if(atributo==1) return sgn(static_cast<long long>(a->getId()) - b->getId());
    if(atributo==2) return a->getNombre().compare(b->getNombre());
    if(atributo==3) return (a->getPrecio()<b->getPrecio()? -1: (a->getPrecio()>b->getPrecio()? 1: 0));
    if(atributo==4) return sgn(static_cast<long long>(a->getCantidad()) - b->getCantidad());
    return 0;
}

int Cliente::compararConValor(const Producto* a, int atributo, int v) const{
    if(atributo==1) return sgn(static_cast<long long>(a->getId()) - v);
    if(atributo==4) return sgn(static_cast<long long>(a->getCantidad()) - v);
    return 0;
}

int Cliente::compararConValor(const Producto* a, int atributo, double v) const{
    if(atributo==3){
        if(a->getPrecio()<v) return -1;
        if(a->getPrecio()>v) return 1;
        return 0;
    }
    return 0;
}

int Cliente::compararConValor(const Producto* a, int atributo, const std::string& v) const{
    if(atributo==2) return a->getNombre().compare(v);
    return 0;
}

// ---------- Ordenamientos ----------
void Cliente::seleccion(Producto** arr, int n, int atributo, bool asc, long long &cmp) const{
    for(int i=0;i<n-1;i++){
        int best=i;
        for(int j=i+1;j<n;j++){
            int c = comparar(arr[j], arr[best], atributo); cmp++;
            if(asc ? (c<0) : (c>0)) best=j;
        }
        if(best!=i){ Producto* t=arr[i]; arr[i]=arr[best]; arr[best]=t; }
    }
}

void Cliente::mergeDo(Producto** arr, int l, int m, int r, int atributo, bool asc, long long &cmp) const{
    int n1=m-l+1, n2=r-m;
    Producto** L = new Producto*[n1];
    Producto** R = new Producto*[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        int c = comparar(L[i], R[j], atributo); cmp++;
        bool takeLeft = asc ? (c<=0) : (c>=0);
        arr[k++] = takeLeft ? L[i++] : R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
    delete[] L; delete[] R;
}

void Cliente::mergeRec(Producto** arr, int l, int r, int atributo, bool asc, long long &cmp) const{
    if(l>=r) return;
    int m = l+(r-l)/2;
    mergeRec(arr,l,m,atributo,asc,cmp);
    mergeRec(arr,m+1,r,atributo,asc,cmp);
    mergeDo(arr,l,m,r,atributo,asc,cmp);
}

void Cliente::mergeSort(Producto** arr, int n, int atributo, bool asc, long long &cmp) const{
    if(n<=1) return;
    mergeRec(arr,0,n-1,atributo,asc,cmp);
}

bool Cliente::estaOrdenado(Producto** arr, int n, int atributo, bool asc) const{
    for(int i=1;i<n;i++){
        int c = comparar(arr[i-1], arr[i], atributo);
        if(asc ? (c>0) : (c<0)) return false;
    }
    return true;
}

void Cliente::reencadenarDesdeArreglo(Producto** arr, int n){
    if(n==0) return;
    for(int i=0;i<n-1;i++) arr[i]->setSiguiente(arr[i+1]);
    arr[n-1]->setSiguiente(nullptr);
    lista.setPrimero(arr[0]);
}

// ---------- API pública de ordenamiento ----------
long long Cliente::ordenarSeleccion(int atributo, bool asc){
    int n=0; Producto** arr = aArreglo(n);
    long long cmp=0; seleccion(arr,n,atributo,asc,cmp);
    reencadenarDesdeArreglo(arr,n);
    delete[] arr;
    return cmp;
}

long long Cliente::ordenarMezcla(int atributo, bool asc){
    int n=0; Producto** arr = aArreglo(n);
    long long cmp=0; mergeSort(arr,n,atributo,asc,cmp);
    reencadenarDesdeArreglo(arr,n);
    delete[] arr;
    return cmp;
}

// ---------- Búsquedas ----------
Producto* Cliente::buscarLineal(int atributo, int v, long long &cmp){
    Producto* cur = lista.getPrimero();
    while(cur){
        cmp++;
        if(compararConValor(cur,atributo,v)==0) return cur;
        cur = cur->getSiguiente();
    }
    return nullptr;
}

Producto* Cliente::buscarLineal(int atributo, double v, long long &cmp){
    Producto* cur = lista.getPrimero();
    while(cur){
        cmp++;
        if(compararConValor(cur,atributo,v)==0) return cur;
        cur = cur->getSiguiente();
    }
    return nullptr;
}

Producto* Cliente::buscarLineal(int atributo, const std::string& v, long long &cmp){
    Producto* cur = lista.getPrimero();
    while(cur){
        cmp++;
        if(compararConValor(cur,atributo,v)==0) return cur;
        cur = cur->getSiguiente();
    }
    return nullptr;
}

Producto* Cliente::buscarBinaria(int atributo, int v, bool asc, long long &cmp, bool asegurarOrden){
    int n=0; Producto** arr = aArreglo(n);
    if(asegurarOrden && !estaOrdenado(arr,n,atributo,asc)){
        long long tmp=0; mergeSort(arr,n,atributo,asc,tmp);
    }
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        int c = compararConValor(arr[m],atributo,v); cmp++;
        if(c==0){ Producto* res=arr[m]; delete[] arr; return res; }
        if(asc){ if(c<0) l=m+1; else r=m-1; }
        else   { if(c>0) l=m+1; else r=m-1; }
    }
    delete[] arr; return nullptr;
}

Producto* Cliente::buscarBinaria(int atributo, double v, bool asc, long long &cmp, bool asegurarOrden){
    int n=0; Producto** arr = aArreglo(n);
    if(asegurarOrden && !estaOrdenado(arr,n,atributo,asc)){
        long long tmp=0; mergeSort(arr,n,atributo,asc,tmp);
    }
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        int c = compararConValor(arr[m],atributo,v); cmp++;
        if(c==0){ Producto* res=arr[m]; delete[] arr; return res; }
        if(asc){ if(c<0) l=m+1; else r=m-1; }
        else   { if(c>0) l=m+1; else r=m-1; }
    }
    delete[] arr; return nullptr;
}

Producto* Cliente::buscarBinaria(int atributo, const std::string& v, bool asc, long long &cmp, bool asegurarOrden){
    int n=0; Producto** arr = aArreglo(n);
    if(asegurarOrden && !estaOrdenado(arr,n,atributo,asc)){
        long long tmp=0; mergeSort(arr,n,atributo,asc,tmp);
    }
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        int c = compararConValor(arr[m],atributo,v); cmp++;
        if(c==0){ Producto* res=arr[m]; delete[] arr; return res; }
        if(asc){ if(c<0) l=m+1; else r=m-1; }
        else   { if(c>0) l=m+1; else r=m-1; }
    }
    delete[] arr; return nullptr;
}
