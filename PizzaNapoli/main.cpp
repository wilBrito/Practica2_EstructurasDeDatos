#include <iostream>
#include "ABBCentros.h"
#include "Napoli.h"
#include <stdlib.h>
#include<Napoli.h>
#include <cstdlib>  //las dos ultimas para srand(time(NULL)) para que sea aleatorio
#include <ctime>
using namespace std;

int menu(){
    int result;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"|Opcion                                   |Funcion                               |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 1                                       |Insertar un centro                    |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 2                                       |Borrar un centro                      |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 3                                       |Mostrar las ventas de un centro       |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 4                                       |Buscar una venta                      |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 5                                       |Extraer una venta                     |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 6                                       |Trasladar una venta a otro centro     |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 7                                       |Mostrar estadísticas de los centros   |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 8                                       |Generar y distribuir nuevas ventas    |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 0                                       |Salir                                 |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"Selecciona: "<<endl;
    cin>>result;
    return result;
}

int main()
{
    Napoli pizzeriaNapoli;
    srand(time(NULL));
    cout<<"Pizzeria Napoli"<<endl;
    cout<<"Generando 10 centos..."<<endl;
    pizzeriaNapoli.generarNcentros();
    cout<<"Centros generandos correctamente"<<endl;
    cout<<"Arbol inicial:"<<endl;
    pizzeriaNapoli.mostrarCentros();
    cout<<"Generando 30 ventas..."<<endl;
    pizzeriaNapoli.generarNventas();
    cout<<"Ventas generandas correctamente"<<endl;
    cout<<"Centros tras la insercion de ventas:"<<endl;
    pizzeriaNapoli.mostrarCentros();
    int n;
    do{
        n = menu();

        switch(n){
            case 1:{
                int id=1000;
                int loc;
                bool locval=false;
                char valid;
                while(!(id>=0&&id<1000)){
                cout<<"inserte el ID del nuevo centro"<<endl;
                cin>>id;
                if(id<0||id>999){
                    cout<<"id no valido"<<endl;
                }}
                while(!locval){
                cout<<"inserte la ubicación del nuevo centro (0-20)"<<endl;
                cin>>loc;
                if(loc<0||loc>20){
                    cout<<"id no valido"<<endl;
                }
                else{
                    cout<<"localidad: ";
                    cout<<localidades[loc]<<endl;
                    cout<<"Deseas esa localidad Y/N?"<<endl;
                    cin>>valid;
                    if(valid=='Y'){
                        locval=true;
                    }
                }}
                Centro cent={id,localidades[loc],ListaVentas()};
                pizzeriaNapoli.InsertarCentro(cent);
                pizzeriaNapoli.mostrarCentros();//PRUEBA
                }
                break;
            case 2:{
                int id = 1000;
                cout<<"Centros en el arbol: ";
                pizzeriaNapoli.InOrdenIds();
                cout<<endl;
                cout<<"Inserte el ID del centro a borrar"<<endl;
                cin>>id;
                if(id<0||id>999) cout<<"id no valido"<<endl;
                else{
                pizzeriaNapoli.BorrarCentro(id);
                pizzeriaNapoli.mostrarCentros();//PRUEBA
                }
                }
                break;
            case 3:{
                int id = 1000;
                cout<<"Centros en el arbol: ";
                pizzeriaNapoli.InOrdenIds();
                cout<<endl;
                cout<<"Inserte el ID del centro a borrar"<<endl;
                cin>>id;
                if(id<0||id>999) cout<<"id no valido"<<endl;
                else if(!pizzeriaNapoli.VerificadorDeCentro(id)) cout<<"Centro no encontrado"<<endl;
                else{
                pizzeriaNapoli.MostrarVentasDeCentro(id);
                }
                }
                break;
            case 4:
                break;
            case 5:{
                break;}
            case 6:
                break;
            case 7:
                break;
            case 8:{
                cout<<"Generando 30 ventas..."<<endl;
                pizzeriaNapoli.generarNventas();
                cout<<"Ventas generandas correctamente"<<endl;}
                break;
            case 0:
                //salir
                break;
            default:

                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                cout<<"Opcion no valida, vuelva a seleccionar"<<endl;
                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                break;
        }
    }while(n!=0);

    return 0;
}
