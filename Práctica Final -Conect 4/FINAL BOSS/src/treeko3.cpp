#ifndef TREEKO
#define TREEKO

#include<iostream>
#include"ArbolGeneral.h"
#include"tablero.cpp"
#include<cmath>
using namespace std;

ArbolGeneral<Tablero>& Construir(Tablero& tablero, ArbolGeneral<Tablero>& arbol, int nivel){
	nivel--;
	tablero.cambiarTurno();	
	for(int i=0; i<tablero.GetColumnas() && nivel != 0; i++){
		if(tablero.hayHueco(i) != -1){
			Tablero partida(tablero);
			partida.colocarFicha(i);
			ArbolGeneral<Tablero> subarbol(partida);
			arbol.insertar_hijomasizquierda(arbol.raiz(), Construir(partida,subarbol,nivel));
		}
		
	}


	return arbol;
}

void ConstruirArbol(Tablero tablero, ArbolGeneral<Tablero>& arbol, int nivel){
	tablero.cambiarTurno();
	Construir(tablero, arbol, nivel);

}


int Columna(Tablero tablero){

	int n2 = 0, n3 = 0, n4 = 0;
	
	for(int j=0; j<tablero.GetColumnas(); j++){
		int contador = 0;
		for(int i=tablero.GetFilas()-1; i>=0; i--){
			if(tablero.GetCasilla(i,j) == tablero.GetTurno()){
				contador++;
			}else{
				switch(contador){

					case 2:{
						n2++;
						break;
					}
		
					case 3:{
						n3++;
						break;
					}
		
					case 4:{
						n4++;
						break;
					}
				}

				contador=0;
			}						
			
		}	
	} 

	return (n2*3 + n3*9 + n4*1000);
}

int Fila(Tablero tablero){

	int n2 = 0, n3 = 0, n4 = 0;

	for(int i=0; i<tablero.GetFilas(); i++){
		int contador = 0;
		for(int j=0; j<tablero.GetColumnas(); j++){
			if(tablero.GetCasilla(i,j) == tablero.GetTurno()){
				contador++;
			}
	
			if(tablero.GetCasilla(i,j) != tablero.GetTurno() || j == tablero.GetColumnas()-1){
				
				switch(contador){

					case 2:{
						n2++;
						break;
					}
		
					case 3:{

						n3++;
						break;
					}
		
					case 4:{
						n4++;
						break;
					}
				}
	
				contador=0;
			}						

		}	
	} 

	return (n2*3 + n3*9 + n4*1000);
}

int Diagonal1(Tablero tablero){

	int n2 = 0, n3 = 0, n4 = 0;
	
	
	for(int j=0; j<tablero.GetColumnas(); j++){
		int contador = 0;
		for(int k=0; k<tablero.GetFilas() && k+j<tablero.GetColumnas(); k++){
			
			if(tablero.GetCasilla(k,j+k) == tablero.GetTurno()){
				contador++;
			}

			if(tablero.GetCasilla(k,j+k) != tablero.GetTurno() || k+j == tablero.GetColumnas()-1){

				switch(contador){

					case 2:{
						n2++;
						break;
					}
			
					case 3:{

						n3++;
						break;
					}
		
					case 4:{
						n4++;
						break;
					}
				}
		
				contador=0;
			}			

		}
	}
	

	
	for(int i=0; i<tablero.GetFilas(); i++){
		int contador = 0;
		for(int k=0; k+i<tablero.GetFilas() && k<tablero.GetColumnas(); k++){
				
			if(tablero.GetCasilla(i+k,1+k) == tablero.GetTurno()){
				contador++;
			}

			if(tablero.GetCasilla(i+k,1+k) != tablero.GetTurno() || k+i == tablero.GetFilas()-1){

				switch(contador){

					case 2:{
						n2++;
						break;
					}
			
					case 3:{
						n3++;
						break;
					}
		
					case 4:{
						n4++;
						break;
					}
				}
		
				contador=0;
			}			

		}
	}	

	return (n2*3 + n3*9 + n4*1000);
}

int Diagonal2(Tablero tablero){

	int n2 = 0, n3 = 0, n4 = 0;

	
	for(int j=tablero.GetColumnas()-1; j>=0; j--){	
		int contador = 0;
		for(int k=0; k<tablero.GetFilas() && j-k>=0; k++){
			
			if(tablero.GetCasilla(k,j-k) == tablero.GetTurno()){
				contador++;
			}

			if(tablero.GetCasilla(k,j-k) != tablero.GetTurno() || k == tablero.GetFilas()-1){

				switch(contador){

					case 2:{
						n2++;
						break;
					}
			
					case 3:{
						n3++;
						break;
					}
			
					case 4:{
						n4++;
						break;
					}
				}
	
				contador=0;
			}			
		}
	}
	

	for(int i=0; i<tablero.GetFilas(); i++){
		int contador = 0;
		for(int k=0; k+i<tablero.GetFilas(); k++){
			
			if(tablero.GetCasilla(i+k,(tablero.GetColumnas()-2)-k) == tablero.GetTurno()){
				contador++;
			}

			if(tablero.GetCasilla(i+k,(tablero.GetColumnas()-2)-k) != tablero.GetTurno() || k == tablero.GetFilas()-1){

				switch(contador){

					case 2:{
						n2++;
						break;
					}
			
					case 3:{
						n3++;
						break;
					}
			
					case 4:{
						n4++;
						break;
					}
				}
		
				contador=0;
			}			
		}
	}
		
	return (n2*3 + n3*9 + n4*1000);

}

int AnalisisTablero(Tablero tablero){

	int valor = 0;

	valor += Columna(tablero);
	valor += Fila(tablero);
	valor += Diagonal1(tablero);
	valor += Diagonal2(tablero);
	
	
	valor *= -1;
		
	return valor;
}

int AnalisisHijos(ArbolGeneral<Tablero>& arbol, ArbolGeneral<Tablero>::Nodo nodo){

	int calidad = 0;

	for(int i=0; nodo != 0; i++){
		if(nodo->etiqueta.GetTurno() != 2){
			calidad -= AnalisisTablero(nodo->etiqueta);
			calidad -= AnalisisHijos(arbol,arbol.hijomasizquierda(nodo));
		}else{
			calidad += AnalisisTablero(nodo->etiqueta);
			calidad += AnalisisHijos(arbol,arbol.hijomasizquierda(nodo));
		}
		nodo = nodo->drcha;		
	}

	return calidad;


}

void AnalisisArbol(ArbolGeneral<Tablero>& arbol, Tablero& tablero){

	ArbolGeneral<Tablero>::Nodo aux = arbol.hijomasizquierda(arbol.raiz());
	ArbolGeneral<Tablero>::Nodo aux2;

	int maximo = -1;
	int candidato, mejor_i = 1;
	
	for(int i=0; aux!=0; i++){

		candidato = AnalisisHijos(arbol,aux);
		if(maximo <= abs(candidato)){
			aux2 = aux;
			maximo = abs(candidato);
		}
		aux = aux->drcha;
	}
	

	tablero = aux2->etiqueta;
	

}


#endif
