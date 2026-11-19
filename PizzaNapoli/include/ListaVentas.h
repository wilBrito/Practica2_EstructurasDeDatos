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
        void InsertarNodoVenta(Venta v);

        void BorrarNodoVenta(Venta v);
        bool ListaVentasVacia();
        void EsCabeza();

        void EsFinal();
        void EsSiguiente();
        bool EsActual();
        Venta ValorActual();
        void RecorrerListaVentas();

        int LonguitudListaVentas();
        void InsertarNodoVentaIntermedio(Venta v, int p);
        void InsertarNodoVentaIzq(Venta v);
};

#endif // LISTAVENTAS_H
