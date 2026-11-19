#include "ListaVentas.h"
#include "Venta.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

//LISTA VACIA
ListaVentas::ListaVentas()
{
    cabeza = actual = final= NULL;
}

//lONGITUD LISTA
int ListaVentas::longuitudListaVentas()
{
    int cont=1;
    pnodo aux = cabeza;
    while(aux->siguiente != NULL){
        cont++;
        aux = aux->siguiente;
    }
    delete aux;
    return cont;
}

void ListaVentas::insertarNodoVenta(Venta v) {
    pnodo aux;

    if (listaVentasVacia())
    {
        cabeza = new NodoVenta(v, NULL);
        final=cabeza;
    }
    else
    {
        aux= new NodoVenta(v,NULL);
        final->siguiente=aux;
        final=aux;
    }
}


//BORRAR NODOVENTA BUSCADO POR MEDIO DEL ID_VENTA
void ListaVentas::borrarNodoVenta(Venta v) {
    pnodo anterior;

    actual = cabeza;

    while (actual->valor.id_venta != v.id_venta && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }

    if (actual->valor.id_venta == v.id_venta){ //comprobación de que está v en la lista
        if(actual==cabeza)
            cabeza = actual->siguiente;
        else
        {
            anterior->siguiente = actual->siguiente;
            if (actual==final)
            {
                final=anterior;
            }
        }
        actual->siguiente=NULL;
        delete actual;
    }
}


bool ListaVentas::listaVentasVacia(){
    return cabeza == NULL;
}


//PONE EL PUNTERO DONDE ESTE O SI ESTA ELIMINADO, LO INICIALIZA CON VALOR CABEZA
void ListaVentas::esCabeza()
{
    actual = cabeza;
}

//PONE EL PUNTERO ACTUAL EN EL FINAL
void ListaVentas::esFinal()
{
    esCabeza();
    if(!listaVentasVacia())
        while(actual->siguiente)
            esSiguiente();
}

void ListaVentas::esSiguiente()
{
    if(actual){
        actual = actual->siguiente;
    }
}

//?????????
bool ListaVentas::esActual()
{
    return actual != NULL;
}


Venta ListaVentas::valorActual()
{
    return actual->valor;
}


void ListaVentas::recorrerListaVentas()
{
    pnodo aux;
    aux = cabeza;

    while(aux)
    {
        cout << aux->valor.id_venta << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}


void ListaVentas::insertarNodoVentaIntermedio(Venta v, int p)
{
    //Me aseguro que exista el nodo
    if(longuitudListaVentas() < p || p < 1 ){
        cout<<"Error, No existe posi del nodo";
    }
    else{

        if(p==1){
            insertarNodoVentaIzq(v);
        }
        else{
            pnodo aux = new NodoVenta(v, NULL);
            esCabeza();//Actualizo actual a cabeza


            //p-1 para que se me quede en un nodo antes
            while (p-1 > 1){
                esSiguiente();//Va avanzado el actual
                p--;
            }
            //Cuando llega al nodo indicado sale del bucle
            aux->siguiente = actual->siguiente;
            actual->siguiente = aux;

            esCabeza();
        }
    }
}

void ListaVentas::insertarNodoVentaIzq(Venta v)
{
    pnodo aux = new NodoVenta(v, NULL);
    aux->siguiente = cabeza;
    cabeza = aux;

}






