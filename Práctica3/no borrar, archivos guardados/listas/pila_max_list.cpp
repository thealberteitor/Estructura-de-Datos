#include<iostream>
#include"pila_max_list.h"

using namespace std;
template <class T>
Lista<T>::Lista(const Lista<T> &original){

	Elemento *p = original.first;
	first = new Elemento(p->valor,p->maximo,0);
	Elemento *q = first;

	while(p!=0){
		p = p->siguiente;					
		if(p!=0){				
			q->siguiente = new Elemento(p->valor,p->maximo,0);
			q = q->siguiente;
		}
	}

	tamanio = original.tamanio;
}

template <class T>
Lista<T>::~Lista(){

	Elemento* aux;
	while(first!=0){
		aux = first;
		first = first->siguiente;
		delete aux;	
	}
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista<T> & otra){

	if(this != &otra){
		
		Elemento *h;

		while(first!=0){
		h = first;
		first = first->siguiente;
		delete h;	
		}
		if(otra.first!=0){
			Elemento *p = otra.first;
			first = new Elemento(p->valor,p->maximo,0);
			Elemento *q = first;
			while(p!=0){
				p = p->siguiente;					
				if(p!=0){				
					q->siguiente = new Elemento(p->valor,p->maximo,0);
					q = q->siguiente;
				}
			}

		}else{
			first = 0;
		}

		tamanio = otra.tamanio;
	}
	return *this;			
}

template <class T>
void Lista<T>::Poner(const T &elem){
	
	if(first != 0){

		Elemento *aux = first;
		int max_aux = aux->maximo;

		while(aux->siguiente != 0){
			if(aux->maximo > max_aux){
				max_aux = aux->maximo;
			}
			aux = aux->siguiente;
		}
		
		if(aux->maximo > max_aux){
			max_aux = aux->maximo;
		}
		
 		if(elem > max_aux){
			max_aux = elem;
		}
		aux->siguiente = new Elemento(elem,max_aux,0);
		tamanio++;
	}else{
		first = new Elemento(elem,elem,0);
	}   
}

template <class T>
void Lista<T>::Quitar(){

	Elemento *aux = first;
	first = first->siguiente;
	delete aux;
	tamanio--;
	               
}

template <class T>
void Lista<T>::Mostrar(){

	Elemento *aux = first;

	while(aux!=0){
		cout << aux->valor << "-" << aux->maximo << endl;
		aux = aux->siguiente;
	}	
}
