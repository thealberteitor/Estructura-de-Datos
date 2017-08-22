#include <iostream>
#include <fstream>
#include "Cronologia.h"
#include "EventoHistorico.h"

using namespace std;

Cronologia::Cronologia(){

	mi_cronologia = NULL;
	tam = 0;
}

Cronologia::Cronologia(int tamanio){

	mi_cronologia = new EventoHistorico[tamanio];
	tam = tamanio;
}

Cronologia::~Cronologia(){
	delete[]mi_cronologia;
}

void Cronologia::ImprimeEventos(int anio) const{		//Imprime TODOS los eventos de UN año

	for(int i=0; i<tam; i++){
		if(mi_cronologia[i].GetAnio() == anio){
			cout << mi_cronologia[i];
		}
	}
}

EventoHistorico Cronologia::GetEventoHistorico(int i) const{
	return mi_cronologia[i];	
}

int Cronologia::GetTam() const{
	return tam;
}


Cronologia::Cronologia(const Cronologia& nuevo){
	
	int tam = nuevo.GetTam();
	if(tam){
		mi_cronologia = new EventoHistorico[tam];
		for(int i=0; i<tam;i++){
			mi_cronologia[i] = nuevo.GetEventoHistorico(i);
		}
	}else
		mi_cronologia = NULL;
}

Cronologia& Cronologia::operator=(const Cronologia& nuevo){

	if(this!=&nuevo){
		for(int i=0; i<tam; i++){
			mi_cronologia[i].EliminaEvento();
		}
		delete[]mi_cronologia;

		int tam=nuevo.GetTam();

		if(tam){
			mi_cronologia = new EventoHistorico[tam];
			for(int i=0; i<tam;i++){
				mi_cronologia[i] = nuevo.GetEventoHistorico(i);
			}
		}else
			mi_cronologia=NULL;
	}
	return *this;
}

void Cronologia::Ordenar(){

	int anio;	
	for(int i=0; i<tam; i++){
		anio = mi_cronologia[i].GetAnio();
		for(int j=0; i<tam; j++){
			if(anio>mi_cronologia[j].GetAnio()){
				EventoHistorico aux = mi_cronologia[i];
				mi_cronologia[i] = mi_cronologia[j];
				mi_cronologia[j] = aux;
				anio = mi_cronologia[i].GetAnio();
			}
		}
	}

}

void Cronologia::BuscarEventos(string palabra_clave) const{		

	for(int i=0; i<tam; i++){
		if(mi_cronologia[i].Busca(palabra_clave)){
			cout << mi_cronologia[i];
		}
	}
}

ostream &operator<<(ostream &os, const Cronologia &nuevo){ 		//Muestra TODOS los eventos históricos
													//de la cronología dada
  for(int i=0; i<nuevo.tam; i++){
    os << nuevo.mi_cronologia[i] << endl;
  }
  return os;
}


int Cronologia::MostrarAnio(string evento) const{				//Devuelve el AÑO en el que se encuentra el evento

	int encontrado = -1;

	for(int i=0; i < tam; i++){
		for(int j=0; j < mi_cronologia[i].GetTamanio(); j++){
			if(mi_cronologia[i].GetEvento(j) == evento){
				encontrado =  mi_cronologia[i].GetAnio();
			}
		}
	}

	return encontrado;

}

void Cronologia::AniadeEvento(int anio, string evento){		//Establece un NUEVO evento a partir de un año YA creado

	for(int i=0; i<tam; i++){
		if(mi_cronologia[i].GetAnio() == anio){
			mi_cronologia[i].AniadeEvento(evento);
		}
	}
}

void Cronologia::AniadeNuevo(EventoHistorico x){				//Inserta en el vector EventoHistorico un NUEVO año no exitente

	EventoHistorico* aux = new EventoHistorico[tam+1];

	for(int i=0; i<tam; i++){
		aux[i] = mi_cronologia[i];
	}

	aux[tam+1] = x;

	delete[]mi_cronologia;

	mi_cronologia = aux;
	tam++;

}


void Cronologia::Elimina(int anio){		//Elimina un evento a partir de un año

	EventoHistorico* aux = new EventoHistorico[tam-1];

	for(int i=0; i<tam-1; i++){
		if(mi_cronologia[i].GetAnio() != anio){
			aux[i] = mi_cronologia[i];
		}else{
			mi_cronologia[i].EliminaEvento();
		}
	}

	delete[]mi_cronologia;

	mi_cronologia = aux;
	tam--;
}


void Cronologia::Cargar(const char fichero[]){

	ifstream fs (fichero);
	string frase;
	while(getline(fs,frase)){
		EventoHistorico* aux = new EventoHistorico[tam+1];
		for(int i=0; i<tam; i++){
			aux[i] = mi_cronologia[i];			
		}	

		aux[tam].CargarEvento(frase);
		
		delete[]mi_cronologia;
		mi_cronologia = aux;
		tam++;
	}
}
