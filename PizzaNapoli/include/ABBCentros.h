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
        // Busca un id
        bool BuscarId(int id);
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
        void InOrden(NodoABBCentro *nodo=NULL, bool r=true);
        void PreOrden(NodoABBCentro *nodo=NULL, bool r=true);
        void PostOrden(NodoABBCentro *nodo=NULL, bool r=true);
        //devuelve el id de un centro aleatorio
        int centro_aleatorio();
        //inserta la venta en el centro correspondiente
        void insertar_venta(Venta v);


        //Insertamos ventas en los centros del arbol
        void InsertarVentaEnCentro(Venta v);
        Centro CentroDeId(int id_centro);

        NodoABBCentro* getRaiz();
    private:
        // Funciones auxiliares
        void Podar(NodoABBCentro* &);
        void auxContador(NodoABBCentro*);
        void auxAltura(NodoABBCentro*, int);
        void imprimirNodo(NodoABBCentro*);
};
#endif // ABBCENTROS_H
