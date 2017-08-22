#include<iostream>
#include"pilamax.cpp"
using namespace std;


int main(){

	Pila <int> primero;
	int numero;
	do{

		cout << "Introduce número: ";
		cin >> numero;
		if(numero != -1){
			primero.Poner(numero);
		}

	}while(numero != -1);

	primero.Mostrar();


}
