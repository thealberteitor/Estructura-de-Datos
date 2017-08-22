#include<iostream>
#include<fstream>
#include"Cronologia.h"

using namespace std;

void Error(){
  cout << "Error, opción no permitida" << endl;
}

void menu(int opcion, Cronologia mi_cronologia){

    switch(opcion){
      case 1:{
        int anio;
        cout << "Introduce el anio: ";
        cin >> anio;
        mi_cronologia.ImprimeEventos(anio);
        break;
      }

      case 2:{
        string event;
        cout << "Introduce el nombre del evento: ";
        cin >> event;
        mi_cronologia.MostrarAnio(event);
        break;
      }

      case 3:{
        int anio;
        string event;
        cout << "Introduce el anio: ";
        cin >> anio;
        cout << "Introduce el nombre del Evento: ";
        cin >> event;
        mi_cronologia.AniadeEvento(anio,event);
        break;
      }

      case 4:{
        int anio;
        cout << "Introduce un anio: ";
        cin >> anio;
        EventoHistorico x(0,anio);
        mi_cronologia.AniadeNuevo(x);
        break;
      }

      case 5:{
        int anio;
        cout << "Introduce un anio: ";
        cin >> anio;
        mi_cronologia.Elimina(anio);
        break;
      }

      case 6:{
		cout << mi_cronologia << endl;
          break;
      }
      default:{
        Error();
      }
    }
}

int main(int argc,char *argv[]){

  int opcion;

  if(argc!=2){
    Error();
    return 0;
  }

  ifstream f (argv[1]);

  if(!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
   	return 0;
   }

  Cronologia mi_cronologia;
  mi_cronologia.Cargar(argv[1]); 			//Cargamos en memoria, en el traductor.

  do{
  cout << "Bienvenidos al programa Cronología" << endl;
  cout << "1)-Devolver Elementos de un año " << endl;
  cout << "2)-Devolver el año al que pertenece un evento " << endl;
  cout << "3)-Introducir un nuevo evento en un año ya creado" << endl;
  cout << "4)-Inserta en el vector EventoHistorico un NUEVO año no exitente " << endl;
  cout << "5)-Elimina un evento a partir de un año " << endl;
  cout << "6)-Mostrar todo" << endl;
  cout << "Introduzca una opción: ";
  cin >> opcion;
  menu(opcion, mi_cronologia);

  }while(opcion < 1 || opcion > 6);
}
