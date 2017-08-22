#include <iostream>
#include "pila_max.h"

using namespace std;

int main(){

  Pila<int> p;

  for ( int i=10; i>=0 ; i--) 
    p.Poner(i);
  
  while (!p.Vacia() ){
    cout << p.Tope();
    p.Quitar();
  }     
  
  return 0;
}
