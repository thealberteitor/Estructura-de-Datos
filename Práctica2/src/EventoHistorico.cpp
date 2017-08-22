#include <iostream>
#include <string>
#include <stdlib.h>
#include "EventoHistorico.h"

EventoHistorico::EventoHistorico(){
	eventos=NULL;
	anio=0;
	tamanio=0;
}

EventoHistorico::EventoHistorico(int tamanio, int anio){

	eventos=new string[tamanio];

	this->tamanio=tamanio;
	this->anio=anio;
}

EventoHistorico::~EventoHistorico(){
	delete[]eventos;
}

string EventoHistorico::GetEvento(int pos) const{   //Devuelve UN evento
	return eventos[pos];
}

int EventoHistorico::GetAnio() const{
	return anio;
}

int EventoHistorico::GetTamanio() const{
	return tamanio;
}

EventoHistorico::EventoHistorico(const EventoHistorico& nuevo){

	int tam=nuevo.GetTamanio();

	if(tam){
		eventos=new string[tam];
		for(int i=0; i<tam;i++){
			eventos[i] = nuevo.GetEvento(i);
		}
		anio = nuevo.GetAnio();
	}else{
		eventos=NULL;
		anio=0;
	}
}

EventoHistorico& EventoHistorico::operator=(const EventoHistorico& nuevo){

	if(this!=&orig){
		int tam=nuevo.GetTamanio();
		string* aux = new string[tam];
		for(int i=0; i<tam;i++){
			aux[i] = nuevo.GetEvento(i);
		}
		anio = nuevo.GetAnio();
		delete[]eventos;
		eventos = aux;
		
		return *this;
}

bool EventoHistorico::Busca(string palabra_clave) const{
	bool aparece=false;
	for(int i=0;i<tamanio && !aparece; i++){
		if(eventos[i].find(palabra_clave)!=-1)
			aparece=true;
	}
	return aparece;
}

void EventoHistorico::AniadeEvento(string evento){   //Introduce UN evento al FINAL

	string *aux = new string[tamanio+1];

	for(int i=0; i<tamanio; i++){
		aux[i]=eventos[i];
	}
	delete[]eventos;
	aux[tamanio+1] = evento;
	eventos = aux;
	tamanio++;
}

void EventoHistorico::Elimina(string evento){    //Elimina UN evento

	string *aux = new string[tamanio-1];

	for(int i=0; i<tamanio; i++){
		if(eventos[i]!=evento){
			aux[i]=eventos[i];
		}
	}
	delete[]eventos;
	eventos = aux;
	tamanio--;
}

ostream &operator<<(ostream &os, const EventoHistorico &nuevo){  //Muestra TODOS los evento y el AÑO

  os << nuevo.anio << ": " ;
  for(int i=0; i<nuevo.tamanio; i++){	//Encontramos un fallo en tamanio que se iguala a 0 y no conseguimos encontrar el error		
    os << nuevo.eventos[i] << ", ";
  }
  return os;
}

void EventoHistorico::CargarEvento(string frase){

	int pos1, pos2;
	anio = atoi(frase.substr(0,frase.find('#')).c_str());
	pos1 = frase.find('#');
	
	while(pos1 != -1){
		frase = frase.substr(pos1+1,frase.size());
		pos2 = frase.find('#');
		string *aux = new string[tamanio+1];
		for(int i=0; i<tamanio; i++) {
			aux[i] = eventos[i];
		}
		
		if(pos2 == -1){
			aux[tamanio] = frase;
		}else{
			aux[tamanio] = frase.substr(pos1,pos2);
		}
		delete[]eventos;
		tamanio++;
		eventos = aux;
		pos1 = pos2;
	}
}

void EventoHistorico::EliminaEvento(){

	delete[]eventos;
}


bool EventoHistorico::operator>(const EventoHistorico &evento) const{
	return (anio > evento.GetAnio());
}

bool EventoHistorico::operator<(const EventoHistorico &evento) const{
	return (anio < evento.GetAnio());
}

