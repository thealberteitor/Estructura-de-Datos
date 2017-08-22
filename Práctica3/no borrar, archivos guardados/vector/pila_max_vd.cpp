#include<iostream>
#include"pilamax.h"

using namespace std;

template <class T>
Pila<T>::Pila(int n, int valor){
	datos = new Elemento(valor);
	tamanio = n;
}

template <class T>
Pila<T>::Pila(){
	datos=NULL;
	tamanio=0;
}

template <class T>
Pila<T>::Pila(const Pila<T> &nuevo){
	int tam = nuevo.GetTamanio();

	if(tam){
		datos = new Elemento[tamanio];
		for(int i=0; i<tam; i++){
			datos[i].valor = nuevo.GetValor(i);
			datos[i].maximo = nuevo.GetMax(i);
		}
	}
	else{
		datos = NULL;
	}
}



template <class T>
Pila<T>& Pila<T>::operator=(const Pila<T> & nuevo){

	if(this != &nuevo){
		delete[]datos;
		tamanio = nuevo.GetTamanio();
		if(tamanio){
			datos = new Elemento[tamanio];
			for(int i=0; i<tamanio; i++){
				datos[i].valor = nuevo.GetValor(i);
				datos[i].maximo = nuevo.GetMax(i);
			}
		}
		else{
			datos = NULL;
		}
	}
	return *this;
}

template <class T>
void Pila<T>::Poner(const T &elem){
	if(tamanio==0){
		Pila nuevo(1,elem);

	}
	else{
		Pila aux;
    int max = GetMax(tamanio-1);
    if(elem>max)
			max=elem;

		aux.datos=new Elemento(elem, max);
		for(int i=0; i<aux.GetTamanio(); i++){
			aux.SetValor(GetValor(i));
			aux.SetMaximo(GetMax(i));
		}
		aux.SetValor(elem);

    if(elem>max)
      aux.SetMaximo(elem);
    else
      aux.SetMaximo(max);
  }

	tamanio++;
	delete[]datos;
}


template <class T>
void Pila<T>::Poner(const T &elem){
	Pila aux;
	int max = elem;
	aux.datos=new Elemento[tamanio+1];

	for(int i=0; i<aux.GetTamanio(); i++){
		aux.SetValor(datos.GetValor(i));
		aux.SetMaximo(datos.GetMaximo(i));
	}

	if(elem>max)
		aux.SetMaximo(elem);
	else
		aux.SetMaximo(max);

	tamanio++;
	delete[]datos;
}

template <class T>
void Pila<T>::Quitar(){

	Pila aux;
	aux.datos=new Elemento[tamanio-1];

	for(int i=0; i<aux.GetTamanio()-1; i++){
		aux.SetValor(datos.GetValor(i));
		aux.SetMaximo(datos.GetMaximo(i));
	}
	tamanio--;
	delete[]datos;
	datos=aux;
}

template <class T>
void Pila<T>::Mostrar(){
	for(int i=0; i<tamanio; i++){
    cout  << "Valor: " << datos[i].valor << "  Máximo: " << datos[i].maximo << endl;
  }
}
