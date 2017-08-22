#include<iostream>
#include"pilamax.h"

using namespace std;
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
void Pila<T>::Mostrar(){
	for(int i=0; i<tamanio; i++){
    		cout  << "Valor: " << datos[i].valor << "  Máximo: " << datos[i].maximo << endl;
 	}
}
