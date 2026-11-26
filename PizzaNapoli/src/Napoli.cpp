#include "Napoli.h"
#include "ABBCentros.h"
#include "Venta.h"
#include "ListaVentas.h"
#include<ABBCentros.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <string>
#include<Venta.h>
using namespace std;

Napoli::Napoli()
{
    cont_ventas=0;
}
void Napoli::generarNcentros(){
while(arbolCentrosDeNapoli.NumeroNodos()<10){
    int id=rand()%1000;
    string localidad=localidades[arbolCentrosDeNapoli.NumeroNodos()];
        Centro centroNapoli={id,localidad,ListaVentas()};
        arbolCentrosDeNapoli.Insertar(centroNapoli);
}}
void Napoli::generarNventas(){
    int i=0;
    ListaVentas creadas;
    bool insertar=false;
    char entrada;
    while(i<30){
        string cont_string=to_string(cont_ventas);
        while(cont_string.size()<5){
            cont_string="0"+cont_string;
        }
        string id_ventaa="V"+cont_string;
        int elem_pizzas=rand()%8;
        string cod_pizzaa=pizzas[elem_pizzas][0];
        string categoriaa=pizzas[elem_pizzas][1];
        int unidadesa=rand()%20+1;
        int mesano=rand()%12+1;
        int dia;
        if(mesano==2){
            dia=rand()%29+1;
        }
        else if(mesano == 4 || mesano == 6 || mesano == 9 || mesano == 11){
            dia=rand()%30+1;
        }
        else{
            dia=rand()%31+1;
        }
        string mes_string= to_string(mesano);
        string dia_string= to_string(dia);
        while(mes_string.size()<2){
            mes_string="0"+mes_string;
        }
        while(dia_string.size()<2){
            dia_string="0"+dia_string;
        }
        string fecha=dia_string+"-"+mes_string+"-2026";
        int id_centroa=arbolCentrosDeNapoli.centro_aleatorio();
        cont_ventas++;
        cont_ventas=cont_ventas%100000;
        Venta ventaa={id_centroa,id_ventaa,cod_pizzaa,categoriaa,unidadesa,fecha};
        creadas.InsertarNodoVenta(ventaa);
        i++;}
        creadas.MostrarVentas();
        while(!insertar){
        cout<<"PRESIONE ENTER PARA INSERTARLAS"<<endl;
        entrada=cin.get();
        if(entrada=='\n'){
            insertar=true;
        }
        else{
        cout<<"ENTER NO PULSADO"<<endl;
        }}
        while(!creadas.ListaVentasVacia()){
            Venta act=creadas.Cabeza();
            arbolCentrosDeNapoli.insertar_venta(act);
            creadas.BorrarNodoVenta(act);
        }
}
void Napoli::mostrarCentros(){
arbolCentrosDeNapoli.InOrden(arbolCentrosDeNapoli.getRaiz(),true);}
void Napoli::InsertarCentro(Centro cent){
arbolCentrosDeNapoli.Insertar(cent);}


//Para BORRAR CENTRO
bool Napoli::VerificadorDeCentro(int id){
    bool a=arbolCentrosDeNapoli.BuscarId(id);
    return a;
}

void Napoli::BorrarCentro(int id){
    arbolCentrosDeNapoli.Borrar(id);

}



//PARA MOSTRAR VENTAS POR CENTRO
void Napoli::MostrarVentasDeCentro(int id){

    Centro centroBuscado = arbolCentrosDeNapoli.CentroDeId(id);

    if(centroBuscado.listaDeVentasCentro.LonguitudListaVentas() == 0){
        cout<<"Es una lista vacia"<<endl;
    }
    else{
        cout<<"CENTRO "<<centroBuscado.id_centro<<" - "<<centroBuscado.localidad<<endl;
        centroBuscado.listaDeVentasCentro.MostrarVentas();
    }
}
void Napoli::InOrdenIds(){
        arbolCentrosDeNapoli.InOrdenIds();
}
void Napoli::EstadisticasArbol(){
arbolCentrosDeNapoli.VentasYPizzasCentro();}
