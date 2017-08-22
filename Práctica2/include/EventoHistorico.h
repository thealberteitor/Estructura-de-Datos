#ifndef E_H_H
#define E_H_H

/**
  * @file eventohistorico.h
  * @brief Fichero Cabecera del TDA EventoHistorico
  *
  */


#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. EventoHistorico
  *
  * Una instancia @e c del tipo de dato abstracto @c EventoHistorico es un objeto
  * compuesto por un vector de cadenas de caracteres, donde cada elemento representa
  * un evento histórico, y un entero que representa el año en que acontecieron
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

class EventoHistorico{

	private:
/**
  * @page repConjunto Rep del TDA EventoHistorico
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e anio>=0
  *
  */

		string *eventos;
		int anio;
		int tamanio;

/**
  * @brief Sobrecarga del operador de salida <<.
  * @param os flujo de salida.
  * @param nuevo objeto de tipo EventoHistorico a mostrar.
  * @return Devuelve el flujo de salida donde se muestra el objeto.
  */
		friend ostream &operator<<(ostream &os, const EventoHistorico &nuevo);

	public:

/**
  * @brief Constructor por defecto de la clase. Crea un objeto vacío.
  */	
		EventoHistorico();

/** @brief Constructor por parámetros de la clase.
  * @param tamanio tamaño del vector, número de eventos históricos.
  * @param anio año en el que acontecieron los eventos históricos almacenados en el vector.
  * @return crea una "lista" con los eventos históricos de un año dado.
  */
		EventoHistorico(int tamanio, int anio);

/** @brief Constructor por copia de la clase.
  * @param nuevo objeto de tipo EventoHistorico del que copiaremos los datos para crear el nuevo objeto.
  */
		EventoHistorico(const EventoHistorico& nuevo);

/**
  * @brief Destructor de la clase.
  */
		~EventoHistorico();

/**
  * @brief Consultor de eventos.
  * @param pos posición en el vector del evento a consultar.
  * @return Devuelve el evento en una posición dada.
  */
		string GetEvento(int pos) const;

/**
  * @brief Consultor del año.
  * @return Devuelve el año del conjunto de eventos implícito.
  */		
		int GetAnio() const;

/**
  * @brief Consultor de tamaño.
  * @return Devuelve el tamaño del vector de eventos del objeto implícito.
  */
		int GetTamanio() const;

/** @brief Sobrecarga del operador de asignación =.
  * @param nuevo objeto que asignaremos a nuestro objeto implícito.
  */
		EventoHistorico& operator=(const EventoHistorico& nuevo);

/** @brief Busca en los diferentes eventos históricos si aparece una palabra clave dada.
  * @param palabra_clave palabra a buscar en la lista de eventos.
  * @return Devuelve \e true si la palabra ha sido encontrada o \a false si no.
  */
		bool Busca(string palabra_clave) const;

/**
  * @brief Añade un evento al final del vector de eventos.
  * @param evento evento a añadir en el objeto implícito.
  */
		void AniadeEvento(string evento);

/**
  * @brief Elimina un evento del vector.
  * @param evento evento a eliminar en el objeto implícito.
  */
		void Elimina(string evento);

/**
  * @brief Carga en el vector del objeto implícito un evento que consigue parseando el texto 
  * del fichero usando como delimitador de eventos el caracter '#'.
  * @param frase string que contiene todos los eventos históricos de un año separados por '#'.
  */
		void CargarEvento(string frase);

/**
  * @brief Elimina el vector de eventos del objeto EventoHistorico
  */
		void EliminaEvento();
/**
  * @brief Sobrecarga del operador > para comparar objetos según el año.
  * @param evento objeto que queremos comparar con el objeto implícito.
  * @return Devuelve \e true si el año del objeto implícito es mayor al del objeto pasado como parámetro.
  */
		bool operator>(const EventoHistorico &evento) const;

/**
  * @brief Sobrecarga del operador < para comparar objetos según el año.
  * @param evento objeto que queremos comparar con el objeto implícito.
  * @return Devuelve \e true si el año del objeto implícito es menor al del objeto pasado como parámetro.
  */
		bool operator<(const EventoHistorico &evento) const;
};

#endif
