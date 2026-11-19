#ifndef LISTAVENTAS_H
#define LISTAVENTAS_H

#include <Venta.h>
#include <iostream>

using namespace std;

class NodoVenta
{
    private:
        Venta valor;
        NodoVenta *siguiente;

        friend class ListaVentas;

    public:
        NodoVenta(Venta v, NodoVenta *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};

typedef NodoVenta *pnodo;

class ListaVentas
{
    private:
        pnodo cabeza, actual, final;

    public:
        ListaVentas();
        void insertarNodoVenta(Venta v);

        void borrarNodoVenta(Venta v);
        bool listaVentasVacia();
        void esCabeza();

        void esFinal();
        void esSiguiente();
        bool esActual();
        Venta valorActual();
        void recorrerListaVentas();

        int longuitudListaVentas();
        void insertarNodoVentaIntermedio(Venta v, int p);
        void insertarNodoVentaIzq(Venta v);
};

#endif // LISTAVENTAS_H
