#include "ListaVentas.h"
#include "Venta.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

//LISTA VACIA
ListaVentas::ListaVentas()
{
    cabeza = actual = final= NULL;
}

//lONGITUD LISTA
int ListaVentas::LonguitudListaVentas()
{
    int cont=0;
    pnodo aux = cabeza;
    while(aux != NULL){
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

void ListaVentas::InsertarNodoVenta(Venta v) {
    pnodo aux;

    if (ListaVentasVacia())
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
void ListaVentas::BorrarNodoVenta(Venta v) {
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


bool ListaVentas::ListaVentasVacia(){
    return cabeza == NULL;
}


//PONE EL PUNTERO DONDE ESTE O SI ESTA ELIMINADO, LO INICIALIZA CON VALOR CABEZA
void ListaVentas::EsCabeza()
{
    actual = cabeza;
}

//PONE EL PUNTERO ACTUAL EN EL FINAL
void ListaVentas::EsFinal()
{
    EsCabeza();
    if(!ListaVentasVacia())
        while(actual->siguiente)
            EsSiguiente();
}

void ListaVentas::EsSiguiente()
{
    if(actual){
        actual = actual->siguiente;
    }
}

//?????????
bool ListaVentas::EsActual()
{
    return actual != NULL;
}


Venta ListaVentas::ValorActual()
{
    return actual->valor;
}


void ListaVentas::RecorrerListaVentas()
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


void ListaVentas::InsertarNodoVentaIntermedio(Venta v, int p)
{
    //Me aseguro que exista el nodo
    if(LonguitudListaVentas() < p || p < 1 ){
        cout<<"Error, No existe posi del nodo";
    }
    else{

        if(p==1){
            InsertarNodoVentaIzq(v);
        }
        else{
            pnodo aux = new NodoVenta(v, NULL);
            EsCabeza();//Actualizo actual a cabeza


            //p-1 para que se me quede en un nodo antes
            while (p-1 > 1){
                EsSiguiente();//Va avanzado el actual
                p--;
            }
            //Cuando llega al nodo indicado sale del bucle
            aux->siguiente = actual->siguiente;
            actual->siguiente = aux;

            EsCabeza();
        }
    }
}

void ListaVentas::InsertarNodoVentaIzq(Venta v)
{
    pnodo aux = new NodoVenta(v, NULL);
    aux->siguiente = cabeza;
    cabeza = aux;

}
void ListaVentas::MostrarVentas(){
    pnodo aux;
    aux = cabeza;
    cout <<left<<setw(10)<<"ID CENTRO"<<setw(10)<<"ID VENTA"<<setw(10)<<"COD PIZZA"<<setw(20)<<"CATEGORIA"<<setw(10)<<"UNIDADES"<<setw(10)<<"FECHA"<<endl;
    while(aux)
    {
        cout <<left<<setw(10)<<aux->valor.id_centro<<setw(10)<<aux->valor.id_venta<<setw(10)<<aux->valor.cod_pizza<<setw(20)<<aux->valor.categoria<<setw(10)<<aux->valor.unidades<<setw(10)<<aux->valor.fecha_venta<<endl;
        aux = aux->siguiente;
    }
}
Venta ListaVentas::Cabeza(){
return cabeza->valor;}





