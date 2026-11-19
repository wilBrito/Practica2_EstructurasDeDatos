#ifndef CENTRO_H
#define CENTRO_H

#include <ListaVentas.h>
#include <string>
#include <iostream>
using namespace std;

struct Centro
{
    int id_centro;
    string localidad;
    ListaVentas listaDeVentasCentro;

};

#endif // CENTRO_H
