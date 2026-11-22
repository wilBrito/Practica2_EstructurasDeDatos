#ifndef NAPOLI_H
#define NAPOLI_H
#include <ABBCentros.h>
#include <string>
#include <iostream>
const string localidades[]={"Mostoles","Alcala","Daganzo","Leganes","Fuenlabrada","Getafe","Alcorcon","Torrejon","Parla","Alcobendas","Coslada","Pozuelo","Rivas","Valdemoro","Majadahonda"
,"Aranjuez","Arganda","Boadilla","Pinto","Colmenar","Tres Cantos"};
const string pizzas[][2]={{"NP01","Tradicional"},{"NP02","Tradicional"},{"NP03","Carne"},{"NP04","Carne"},{"NP05","Verduras"},{"NP06","Verduras"},{"NP07","Quesos"},{"NP08","Quesos"}};
using namespace std;

class Napoli
{

    ABBCentros arbolCentrosDeNapoli;
    int cont_ventas;
    public:
        Napoli();
        void generarNcentros();
        void generarNventas();
        void mostrarCentros();
        void InsertarCentro(Centro);
};

#endif // NAPOLI_H
