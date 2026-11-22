#include <iostream>

#include <stdlib.h>
#include<Napoli.h>

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

    cout<<"Pizzeria Napoli"<<endl;
    cout<<"Generando 10 centos..."<<endl;
    pizzeriaNapoli.generarNcentros();
    cout<<"Centros generandos correctamente"<<endl;
    cout<<"Generando 30 ventas..."<<endl;
    pizzeriaNapoli.generarNventas();
    cout<<"Ventas generandas correctamente"<<endl;
    int n;
    do{
        n = menu();

        switch(n){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:{
                break;}
            case 6:
                break;
            case 7:
                break;
            case 8:
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
