#include <iostream>
#include "pila_max_list.h"

using namespace std;

int main(){

  Lista <int> p;
  int i;

  for ( i=10; i>=0; i--){ 
    p.Poner(i);
  }

  while (!p.Vacia() ){
	cout << p.Tope();
	p.Quitar();
  }     
  
  return 0;
}
