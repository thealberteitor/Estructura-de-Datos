/**
  * @file pilamax.h
  * @brief Fichero cabecera del TDA Pila.
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo.
  */

#include <iostream>

using namespace std;

template <class T>
class Pila{
	private:

		struct Elemento{
			T valor;
			T maximo;

/**
 * @brief Constructor por defecto.
 */

			Elemento():valor(0),maximo(0){}

/**
 * @brief Constructor por parámetros.
 * @param numero Valor nuevo para el campo @e valor de la estructura.
 * @param max Valor nuevo para el campo @e maximo de la estructura.
 */

			Elemento(const T &numero, const T &max): valor(numero), maximo(max){}

/**
 * @brief Constructor por parámetros.
 * @param numero Valor nuevo para el campo @e valor y @e maximo de la estructura.
 */

			Elemento(const T &numero): valor(numero), maximo(numero){};
		};

		Elemento *datos;
		int tamanio;

		friend ostream &operator<<(ostream &os, const Elemento &nuevo){
	
  			os << nuevo.valor << "-" << nuevo.maximo << endl;
		}


	public:

/**
 * @brief Constructor por defecto.
 */

		Pila():datos(0), tamanio(0){}

/**
 * @brief Constructor por copia.
 * @param nuevo Objeto a copiar.
 */

		Pila(const Pila<T> &nuevo);

/**
 * @brief Destructor de la clase.
 */

		inline ~Pila(){ delete[]datos; }

/**
 * @brief Sobrecarga del operador de asignación =.
 * @param nuevo Objeto a asignar al objeto original.
 */

		Pila &operator=(const Pila<T> &nuevo);

/**
 * @brief Consulta el tamaño del objeto.
 */

		inline T GetTamanio() const{ return tamanio; }

/**
 * @brief Consulta el campo @e valor de la estructura @e Elemento del objeto.
 */

		inline T GetValor(T i) const{ return datos[i].valor; }

/**
 * @brief Consulta el campo @e maximo de la estructura @e Elemento del objeto.
 */

		inline T GetMax(T i) const{ return datos[i].maximo; }

/**
 * @brief Modifica el campo @e valor de la estructura @e Elemento del objeto.
 */

		inline void SetValor(T i){ datos[tamanio].valor=i; }

/**
 * @brief Modifica el campo @e maximo de la estructura @e Elemento del objeto.
 */

		inline void SetMaximo(T i){ datos[tamanio].maximo=i; }

/**
 * @brief Consulta el primer elemento del vector.
 */

		inline T &Frente(){	return datos[0].valor; }

/**
 * @brief Consulta el primer elemento del vector.
 */

		inline const T &Frente () const{ return datos[0].valor; }

/**
 * @brief Consulta si el vector está vacío.
 */

		inline bool Vacia(){ return tamanio==0; }

/**
 * @brief Consulta el tope de la pila.
 */

		inline Elemento Tope(){ return datos[0]; }

/**
 * @brief Añade un elemento a la pila.
 */

		void Poner(const T &elem){
	
			Elemento *aux = new Elemento[tamanio+1];

			for(int i=0; i<tamanio; i++){
				aux[i] = datos[i];
			}

			aux[tamanio].valor = elem;

			if(elem > aux[tamanio-1].maximo){
				aux[tamanio].maximo = elem;
			}else{
				aux[tamanio].maximo = aux[tamanio-1].maximo;
			}

			delete[]datos;
			datos = aux;
			tamanio++;
		}

/**
 * @brief Elimina un elemento de la pila.
 */

		void Quitar(){

			Elemento *aux = new Elemento[tamanio-1];

			for(int i=0; i<tamanio-1; i++){		
				aux[i] = datos[i+1];
			}

			delete[]datos;
			datos = aux;
			tamanio--;
		}
/**
 * @brief Muestra el objeto de la clase.
 */

		void Mostrar();

};
