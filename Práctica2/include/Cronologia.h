#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

/**
  * @file cronologia.h
  * @brief Fichero Cabecera del TDA Cronologia
  *
  */

#include <iostream>
#include<EventoHistorico.h>
using namespace std;

class Cronologia{

	private:

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de dato abstracto @c Cronologia se puede considerar
  * un contenedor de objetos de tipo @c EventoHistorico, ya que está
  * compuesto por un vector de objetos de este tipo, donde cada elemento representa
  * un evento histórico y un entero que representa el año en que acontecieron
  * los hechos, además de un entero que controla el tamaño del vector de eventos.
  * 
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Alberto Durán López
  * @author Jesús González Mairena
  * @author Ana Peña Arnedo
  * @date Octubre 2016
  */

		EventoHistorico* mi_cronologia;

		int tam;

/**
  * @brief Sobrecarga del operador de salida <<.
  * @param os flujo de salida.
  * @param nuevo objeto de tipo Cronologia a mostrar.
  * @return Devuelve el flujo de salida donde se muestra el objeto.
  */

		friend ostream &operator<<(ostream &os, const Cronologia &nuevo);

	public:

/**
  * @brief Constructor por defecto de la clase. Crea un objeto vacío.
  */
		Cronologia();

/** 
  * @brief Constructor por parámetros de la clase.
  * @param tamanio tamaño del vector de objetos de tipo EventoHistorico.
  */
		Cronologia(int tamanio);


/** --->FALTA<---
  * @brief Constructor por copia de la clase.
  * @param nuevo objeto 
  */
		Cronologia(const Cronologia& nuevo);

/**
  * @brief Destructor de la clase.
  */		
		~Cronologia();

/**
  * @brief Sobrecarga del operador de asignación =.
  * @param nuevo objeto que asignaremos a nuestro objeto implícito.
  */
		Cronologia& operator=(const Cronologia& nuevo);

/**
  * @brief Consultor de los elementos del vector de tipo EventoHistorico.
  * @param i posicion del evento a consultar.
  * @return Elemento de tipo EventoHistorico que se encuentra en la posición i.
  */
		EventoHistorico GetEventoHistorico(int i) const;

/**
  * @brief Busca los eventos históricos relacionados con una palabra clave dada.
  * @param palabra_clave palabra a buscar en la cronología.
  */
		void BuscarEventos(string palabra_clave) const;

/**
  * @brief Imprime \e todos los eventos históricos de un año dado.
  * @param anio año en el que ocurrieron los eventos históricos a mostrar.
  */
		void ImprimeEventos(int anio) const;

/**
  * @brief Consultor del tamaño.
  * @return Devuelve el tamaño del objeto implícito.
  */
		int GetTam() const;
		
/**
  * @brief Ordena los objetos de tipo EventoHistorico de la cronología según su año.
  */		
		void Ordenar();

/**
  * @brief Muestra el año en el que aconteció un evento dado.
  * @param evento evento del que queremos saber su año.
  * @return Devuelve el año en el que ocurrió el evento.
  */
		int MostrarAnio(string evento) const;

/**
  * @brief Añade un evento en un año ya existente en la cronología.
  * @param anio año donde queremos añadir el evento.
  * @param evento evento que queremos añadir a dicho año.
  */
		void AniadeEvento(int anio, string evento);

/**
  * @brief Añade un nuevo objeto de tipo EventoHistorico, con un año no existente.
  * @param x objeto EventoHistorico a añadir, compuesto por un año y los eventos acontecidos en él.
  */
		void AniadeNuevo(EventoHistorico x);

/**
  * @brief Elimina un objeto del vector de EventoHistorico asociado a un año dado.
  * @param anio año en el que acontecieron los eventos históricos a borrar de la cronología.
  */
		void Elimina(int anio);

/**
  * @brief Carga los eventos en el vector de EventoHistorico desde un fichero dado.
  * @param fichero fichero desde donde se cargan los eventos en la cronología.
  */
		void Cargar(const char fichero[]);

};

#endif
