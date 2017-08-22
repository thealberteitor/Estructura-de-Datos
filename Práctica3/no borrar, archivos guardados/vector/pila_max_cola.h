#include<iostream>
using namespace std;

template <class T>
class Pila{
	private:

		struct Elemento{
			T valor;
			T maximo;

			Elemento():valor(0),maximo(0){}
			Elemento(const T &numero, const T &max): valor(numero), maximo(max){}
			Elemento(const T &numero): valor(numero), maximo(numero){};
		};

		Elemento *datos;
		int tamanio;

		friend ostream &operator<<(ostream &os, const Elemento &nuevo){
  			for(int i=0; i<nuevo.tamanio; i++){
  				os << "Valor: " << nuevo.valor << "  Máximo: " << nuevo.maximo << endl;
  			}
		}


	public:



		Pila(const Pila<T> &nuevo);

		Pila();

		inline bool Vacia(){ return tamanio==0; };

		inline T Tope(){ return datos[tamanio-1].valor;}

		Pila(int n, int valor);


		inline T GetTamanio() const{ return tamanio;}

		inline T GetValor(T i) const{ return datos[i].valor;}

		inline T GetMax(T i) const{ return datos[i].maximo;}

		inline void SetValor(T i){ datos[tamanio].valor=i;}

		inline ~Pila(){ delete[]datos;}

		inline void SetMaximo(T i){ datos[tamanio].maximo=i;}

		Pila &operator=(const Pila<T> &nuevo);

		void Poner(const T &elem);

		void Quitar();

		void Mostrar();

};
