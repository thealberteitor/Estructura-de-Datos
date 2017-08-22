/**
  * @file pila_max_list.h
  * @brief Fichero cabecera del TDA Lista
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo.
  */

#include <iostream>

using namespace std;

template <class T>
class Lista{

	private:

		struct Elemento{
			
			int valor;
			int maximo;
			Elemento *siguiente;

/**
 * @brief Constructor por defecto.
 *
 */
			Elemento():siguiente(0),valor(0), maximo(0){}

/**
 * @brief Constructor por parámetros.
 * @param numero Valor nuevo para el campo @e valor de la estructura.
 * @param max Valor nuevo para el campo @e maximo de la estructura.
 * @param sig Valor nuevo para el campo @e siguiente de la estructura.
 */

			Elemento(const T &numero, const T &max, Elemento *sig): valor(numero), maximo(max), siguiente(sig){}	
			
		};

		int tamanio;
		Elemento *first;		
		friend ostream &operator<<(ostream &os, const Elemento &nuevo){
			os << nuevo.valor << "-" << nuevo.maximo << endl;
		}

	public:

/**
 * @brief Constructor por defecto.
 */

		Lista():first(0), tamanio(0){}

/**
 * @brief Constructor por copia.
 * @param original Objeto a copiar.
 */

		Lista(const Lista<T> &original);

/**
 * @brief Destructor de la clase.
 */

		~Lista();

/**
 * @brief Sobrecarga del operador de asignación =.
 * @param otra Objeto a asignar al objeto original.
 */

		Lista &operator=(const Lista<T> &otra);

/**
 * @brief Consulta si la lista está vacía.
 */

		inline bool Vacia() const{
			return (tamanio==0);
		}

/**
 * @brief Consulta el elemento al frente de la lista.
 */

		inline T &Frente(){
			assert(first!=0);
			return first->valor;
		}

/**
 * @brief Consulta el elemento al frente de la lista.
 */
 
		inline const T &Frente () const{
			assert(first!=0);
			return first->valor;
		}

/**
 * @brief Consulta el elemento @e tope de la pila.
 * @return Devuelve el tope de pila.
 */

		Elemento Tope(){
			return *first;		
		}

/**
 * @brief Añade un elemento a la pila.
 * @param elem Elemento a añadir.
 */

		void Poner(const T &elem);

/**
 * @brief Elimina el primer elemento de la pila.
 */

		void Quitar();

/**
 * @brief Muestra el objeto de la clase.
 */
		void Mostrar();	
		
		inline int GetTamanio() const{
			return tamanio;
		}

};
