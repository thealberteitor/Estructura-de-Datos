#include <iostream>
#include "cola.h"

using namespace std;

int main(){

  Cola<int> p;

  for ( int i=10; i>=0 ; i--){ 
    p.Poner(i);
  }

  while (!p.Vacia() ){
    cout << p.Tope();
    p.Quitar();
  }     
  
  return 0;
}
