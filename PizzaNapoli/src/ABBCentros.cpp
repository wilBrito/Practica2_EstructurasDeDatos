#include "ABBCentros.h"
#include <Centro.h>
#include <ListaVentas.h>

using namespace std;


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
void ABBCentros::InOrden(void (*func)(Centro&) , NodoABBCentro *nodo, bool r)
{
  if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ABBCentros::PreOrden(void (*func)(Centro&), NodoABBCentro *nodo, bool r)
{
    if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   func(nodo->dato);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ABBCentros::PostOrden(void (*func)(Centro&), NodoABBCentro *nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato);
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
{
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

// Función de prueba para recorridos del árbol
void Mostrar(int &d)
{
   cout << d << ",";
}
