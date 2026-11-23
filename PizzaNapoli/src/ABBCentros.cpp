#include "ABBCentros.h"
#include "Venta.h"
#include <Centro.h>
#include <ListaVentas.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
using namespace std;
NodoABBCentro* ABBCentros::getRaiz(){
return raiz;}
//Árbol vacío
bool ABBCentros::Vacio(NodoABBCentro *r)
{
    return r==NULL;
}

//Nodo es de tipo hoja
bool ABBCentros::EsHoja(NodoABBCentro *r)
{
    return !r->derecho && !r->izquierdo;
}

//Coloca el nodo actual en raíz
void ABBCentros::Raiz()
{
    actual = raiz;
}

// Poda: borrar todos los nodos a partir de uno incluido
void ABBCentros::Podar(NodoABBCentro* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el árbol ABB
void ABBCentros::Insertar(const Centro dat)
{
   NodoABBCentro *padre = NULL;

   actual = raiz;
   // Buscar el int en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat.id_centro != actual->dato.id_centro) {
      padre = actual;
      if(dat.id_centro > actual->dato.id_centro) actual = actual->derecho;
      else if(dat.id_centro < actual->dato.id_centro) actual = actual->izquierdo;
    }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoABBCentro(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat.id_centro < padre->dato.id_centro) padre->izquierdo = new NodoABBCentro(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat.id_centro > padre->dato.id_centro) padre->derecho = new NodoABBCentro(dat);
}

// Eliminar un elemento de un árbol ABB
void ABBCentros::Borrar(const Centro dat)
{
   NodoABBCentro *padre = NULL;
   NodoABBCentro *nodo;
   Centro aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat.id_centro == actual->dato.id_centro) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre){ // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            }
            else raiz=NULL;

            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat.id_centro > actual->dato.id_centro) actual = actual->derecho;
         else if(dat.id_centro < actual->dato.id_centro) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ABBCentros::InOrden(NodoABBCentro *nodo, bool r)
{
  if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
    if(Vacio(nodo)) return;
   if(nodo->izquierdo) InOrden(nodo->izquierdo, false);
   imprimirNodo(nodo);
   if(nodo->derecho) InOrden(nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ABBCentros::PreOrden(NodoABBCentro *nodo, bool r)
{
    if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
    if(Vacio(nodo)) return;
   imprimirNodo(nodo);
   if(nodo->izquierdo) PreOrden(nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ABBCentros::PostOrden(NodoABBCentro *nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(Vacio(nodo)) return;
   if(nodo->izquierdo) PostOrden(nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(nodo->derecho, false);
   imprimirNodo(nodo);
}

// Buscar un valor en el árbol
bool ABBCentros::Buscar(const Centro dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.id_centro == actual->dato.id_centro) return true;
      else if(dat.id_centro > actual->dato.id_centro) actual = actual->derecho; // Seguir
      else if(dat.id_centro < actual->dato.id_centro) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}
// Buscar un id en el árbol
bool ABBCentros::BuscarId(int id)
{
   actual = raiz;
   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(id== actual->dato.id_centro) return true;
      else if(id > actual->dato.id_centro) actual = actual->derecho; // Seguir
      else if(id < actual->dato.id_centro) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}
// Calcular la altura del nodo que contiene el int dat
int  ABBCentros::Altura(const Centro dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.id_centro == actual->dato.id_centro) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat.id_centro > actual->dato.id_centro) actual = actual->derecho;
         else if(dat.id_centro < actual->dato.id_centro) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int  ABBCentros::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void  ABBCentros::auxContador(NodoABBCentro *nodo)
{   if(nodo==NULL) return;
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int  ABBCentros::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void  ABBCentros::auxAltura(NodoABBCentro *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}
int ABBCentros::centro_aleatorio(){
    actual=raiz;
    while(!Vacio(actual)){
        int mover=rand()%3;
        if(mover==0){
            return actual->dato.id_centro;
        }
        //1 ir a los nodos a la izquierda
        else if(mover==1){
            //si esta vacio devolvemos el actual
            if(Vacio(actual->izquierdo)){
                return actual->dato.id_centro;}
            else{
                actual=actual->izquierdo;
            }
        }
        //2 ir a los nodos a la derecha
        else{
            //si esta vacio devolvemos el actual
            if(Vacio(actual->derecho)){
                return actual->dato.id_centro;}
            else{
                actual=actual->derecho;
            }
        }
    }
}
void ABBCentros::insertar_venta(Venta v){
    actual=raiz;
    bool encontrado=false;
    while(!Vacio(actual)&& !encontrado){
        //si es el centro, se inserta en la lista
        if(v.id_centro==actual->dato.id_centro){
            actual->dato.listaDeVentasCentro.InsertarNodoVenta(v);
            encontrado=true;
        }
        //si el id del centro es menor que el actual, se mira en el nodo izquierdo.
        else if(v.id_centro<actual->dato.id_centro){
            actual=actual->izquierdo;
        }
        //si el id del centro es mayor que el actual, se mira en el nodo derecho.
        else if(v.id_centro>actual->dato.id_centro){
            actual=actual->derecho;
        }
    }
    if(!encontrado){
        cout<<"Centro no encontrado"<<endl;
    }}

void ABBCentros::imprimirNodo(NodoABBCentro *nodo){
cout<<"ID: "<<left<<setw(10)<<nodo->dato.id_centro<<setw(10)<<"Localidad: "<<setw(20)<<nodo->dato.localidad<<setw(10)<<"num ventas: "<<setw(5)<<nodo->dato.listaDeVentasCentro.LonguitudListaVentas()<<endl;}

// Función de prueba para recorridos del árbol
void Mostrar(int &d)
{
   cout << d << ",";
}














void ABBCentros::InsertarVentaEnCentro(Venta v)
{

    //Creamos Nodo auxiliar apuntando a la raiz
    NodoABBCentro *aux = raiz;


    //Vamos a recorrer el arbol binario, sabiendo que lo hemos creado con id_centro distinto con valor numerico, ordenado
    while(aux != nullptr){
        //Distinguimos caso que hemos encontrado el id
        if(aux->dato.id_centro == v.id_centro){
            //Insertamos valor en la lista del centro correspondiente
            aux->dato.listaDeVentasCentro.InsertarNodoVenta(v);
        }

        //Como esta ordenado vemos es mayor el nodo del arbol, es decir el id_centro del arbol que de la venta
        else if(aux->dato.id_centro > v.id_centro){
            //Vamos por la izq
            aux = aux->izquierdo;
        }

        //Es mayor
        else{
           //Vamos por la derecha
           aux = aux->derecho;
        }
    }
}
