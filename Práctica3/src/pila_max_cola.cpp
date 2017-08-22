/**
  * @file cola.cpp
  * @brief Implementación del TDA Cola
  *
  */
#include <cassert>
#include <iostream>
using namespace std;
//#include "cola.h" 

/* _________________________________________________________________________ */


template <class T>
Pila<T>::Pila(const Pila<T> & original){
  if (original.primera!=0){           //Si tiene elementos
    Celda *p = original.primera;      //Copiamos el puntero a la primera celda
    ultima = new Celda(p->elemento,0); //Inicializamos la lista de nodos
    p = p->siguiente;                     //Avanzamos el puntero
    while (p!=0){                         //Mientras queden elementos
      ultima->siguiente = new Celda(p->elemento,0); //Copiamos el elemento
      ultima = ultima->siguiente;                   //Avanzamos los punteros
      p = p->siguiente;
    }
  }
  else
    primera = ultima = 0;            //Si no tiene elementos
  num_elem = original.num_elem;
}

/* _________________________________________________________________________ */

template <class T>
Pila<T>& Pila<T>::operator=(const Pila<T> & otra){
  Celda * p;
  
  if (this != &otra){    //Comprobación de rigor. Si son diferentes objetos
    while (primera!=0){  //Borramos la lista de nodos de la cola *this
      p = primera;
      primera = primera->siguiente;
      delete p;
    }
    if (otra.primera!=0){        //Si la otra cola tiene elementos
      p = otra.primera;          //Copiamos el puntero al primer nodo
      primera=ultima= new Celda(p->elemento,0); //Reservamos el primer nodo
      p=p->siguiente;                           //Avanzamos el puntero
      while (p!=0){                             //Mientras queden elementos
        ultima->siguiente=new Celda(p->elemento,0); //Creamos un nuevo nodo
        ultima=ultima->siguiente;                   //Actualizamos ultima
        p=p->siguiente;                             //Avanzamos el puntero
      }
    }
    else primera=ultima=0;      //Si la otra cola está vacía
    num_elem=otra.num_elem;
  }
  return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}


