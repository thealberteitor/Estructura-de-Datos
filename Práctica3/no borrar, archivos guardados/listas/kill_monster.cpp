#include<iostream>
#include"pila_max_list.cpp"
using namespace std;

int main(){
	
	Lista <int> primero;

	int numero;
	do{

		cout << "Introduce numero: ";
		cin >> numero;
		if(numero != -1){		
			primero.Poner(numero);
		}

	}while(numero != -1);

	Lista <int> segundo(primero);
	segundo.Mostrar();

}
