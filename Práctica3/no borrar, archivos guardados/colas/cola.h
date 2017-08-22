/**
  * @file cola.h
  * @brief Fichero cabecera del TDA Cola
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  */

#ifndef __Cola_H__
#define __Cola_H__

#include <cassert>
#include<iostream>
using namespace std;
/**
 *  @brief T.D.A. Cola
 *
 *
 * Una instancia @e c del tipo de dato abstracto Cola sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e FIFO
 * (First In, First Out}). En una cola, las operaciones de inserción tienen
 * lugar en uno de los extremos, denominado @e final de la cola, mientras que
 * el borrado y consulta se lleva a cabo en el otro extremo, denominado 
 * @e frente de la cola. Una cola de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<

 * En esta cola, tendremos acceso únicamente al elemento del @e Frente,
 * es decir, a @e a1. El borrado o consulta de un elemento será sobre @e a1,
 * mientras que la inserción de un nuevo elemento se hará después de
 * @e an (final de la cola).
 *
 * Si n=0 diremos que la cola está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número 
 * de elementos de la cola.
 *
 * @author 
 * @date 
*/
template <class T>
class Cola{
	
  private:
    struct Celda {       
      T elemento;        ///< Elemento de información.
	 T maximo;
      Celda * siguiente; ///< Puntero al siguiente nodo.

      /**
       * @brief Constructor por defecto
       */
      Celda() : siguiente(0), maximo(0){
      }
      /**
       * @brief Constructor con parámetros
       * @param elem Elemento de información.
       * @param sig Puntero al siguiente nodo.
       */
      Celda(const T & elem, const T & max, Celda * sig): elemento(elem), maximo(max), siguiente(sig){
      }
    };

	friend ostream &operator<<(ostream &os, const Celda &nuevo){
			os << nuevo.elemento << "-" << nuevo.maximo << endl;
	}

    Celda * primera; ///< Puntero al primer nodo de la lista.
    Celda * ultima;  ///< Puntero al último nodo de la lista.
    int num_elem;    ///< Número de elementos de la cola.
    
	

  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Cola(): primera(0), ultima(0), num_elem(0){
    }
    /**
     * @brief Constructor de copias
     * @param original La cola de la que se hará la copia.
     */
    Cola(const Cola<T> & original);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Cola(){
		 Celda * aux;
		 while (primera!=0){             //Mientras queden elementos
		    aux = primera;                //Copiamos el puntero
		    primera = primera->siguiente; //Avanzamos primera
		    delete aux;                   //Borramos el nodo
  		}
	}
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La cola que se va a asignar.
     */
    Cola& operator= (const Cola<T> & otra);
    /**
     * @brief Comprueba si la cola está vacía
     */
    bool Vacia() const{
      return num_elem==0;
    }
    /**
     * @brief Devuelve el elemento del frente de la cola
     */
    T& frente (){
      assert(primera!=0);        //Si la cola está vacía, abortar
      return primera->elemento;  //Devuelve el elemento del frente de la cola
    }
    /**
     * @brief Devuelve el elemento del frente de una cola constante
     */
    const T & frente () const{
      assert(primera!=0);        //Si la cola está vacía, abortar
      return primera->elemento;  //Devuelve el elemento del frente de la cola
    }
    /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void Poner(const T & elem){

	if(primera!=0){
		Celda *aux;		
		if(elem < ultima->maximo){
			aux = new Celda(elem,ultima->maximo,0);    //Creamos un nuevo nodo dependiendo del elemento introducido
		}else{
			aux = new Celda(elem,elem,0);
		}

	  	if (primera==0)                    	//Si la lista está vacía,
	  		primera = ultima = aux;          //primera y ultima apuntan a ese nodo
	  	else{                    		  //Si la lista ya tenia nodos,
	  		ultima->siguiente = aux;		 //Actualizamos el puntero siguiente del ultimo nodo
	  		ultima = aux;            	//Actualizamos ultima
	  }
	  
	}else{
		primera = ultima = new Celda(elem,elem,0);
	}
		num_elem++;                //Incrementamos el numero de elementos
		
	}
    /**
     * @brief Quita el elemento del frente de la cola
     */
    void Quitar(){
 		 assert(primera!=0);             //Si la cola está vacía, abortar
  		Celda *aux = primera;           //Copiamos el puntero al primer nodo
 		 primera = primera->siguiente;   //Actualizamos primera
 		 delete aux;                     //Borramos el primer nodo
  		if (primera == 0){               //Si no quedan nodos,
  		 	ultima=0;                     //actualizamos ultima
		} 		
		num_elem--;                     //Actualizamos el número de elementos
	}
    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const{ 
      return num_elem; 
    }
	
	inline Celda Tope(){ return *primera; }

};

#endif // __Cola_H__
