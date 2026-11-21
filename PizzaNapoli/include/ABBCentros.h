#ifndef ABBCENTROS_H
#define ABBCENTROS_H

#include<Centro.h>
#include <iostream>

using namespace std;


class NodoABBCentro
{
    private:
        // Miembros:
        Centro dato;
        NodoABBCentro *izquierdo;
        NodoABBCentro *derecho;
        friend class ABBCentros;

    public:
        // Constructor:
        NodoABBCentro(const Centro dat, NodoABBCentro *izq=NULL, NodoABBCentro *der=NULL) :
            dato(dat), izquierdo(izq), derecho(der) {}

};

class ABBCentros
{
    private:
        // Punteros de la lista, para cabeza y nodo actual:
        NodoABBCentro *raiz;
        NodoABBCentro *actual;
        int contador;
        int altura;

    public:
        ABBCentros(): raiz(NULL), actual(NULL), contador(0), altura(0) {};

        // Insertar en árbol ordenado:
        void Insertar(const Centro c);
        // Borrar un elemento del árbol:
        void Borrar(const Centro c);
        // Función de búsqueda:
        bool Buscar(const Centro c);
        // Comprobar si el árbol está vacío:
        bool Vacio(NodoABBCentro *r);
        // Comprobar si es un nodo hoja:
        bool EsHoja(NodoABBCentro *r);
        // Contar número de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un int:
        int Altura(const Centro c);
        // Moverse al nodo raiz:
        void Raiz();
        // Aplicar una función a cada elemento del árbol:
        void InOrden(void (*func)(Centro&), NodoABBCentro *nodo=NULL, bool r=true);
        void PreOrden(void (*func)(Centro&), NodoABBCentro *nodo=NULL, bool r=true);
        void PostOrden(void (*func)(Centro&), NodoABBCentro *nodo=NULL, bool r=true);


        //Insertamos ventas en los centros del arbol
        void InsertarVentaEnCentro(Venta v);

    private:
        // Funciones auxiliares
        void Podar(NodoABBCentro* &);
        void auxContador(NodoABBCentro*);
        void auxAltura(NodoABBCentro*, int);
};



#endif // ABBCENTROS_H
