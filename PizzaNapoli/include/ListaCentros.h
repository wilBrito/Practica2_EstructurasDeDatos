#ifndef LISTACENTROS_H
#define LISTACENTROS_H

#include <iostream>

using namespace std;

class NodoCentro
{
    private:
        Centro valor;
        NodoCentro *siguiente;

        friend class ListaCentros;

    public:
        NodoCentro(Centro c, NodoCentro *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};

class ListaCentros
{
    private:
        pnodo cabeza, actual, final;
    public:
        ListaCentros();
        virtual ~ListaCentros();




};

#endif // LISTACENTROS_H
