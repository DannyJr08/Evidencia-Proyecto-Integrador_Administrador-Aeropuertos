#ifndef AEROLINEA_H
#define AEROLINEA_H

#include "Vuelo.h"

#include <string>

class Aerolinea
{
    public:
        // Constructores
        Aerolinea();
        Aerolinea(string, bool, short, short, short);
        // Getters
        string getNombre();
        bool getEsMexicana();
        short getMaxSlots();
        short getCantVuelosDemorados();
        short getVecesRegistradoVuelo();
        // Setters
        void setNombre(string);
        void setEsMexicana(bool);
        void setMaxSlots(short);
        void setCantVuelosDemorados(short);
        void setVecesRegistradoVuelo(short);
        // Métodos propios
        void mostrarDatos();
        void aniadirVecesRegistradoVuelo();
        void aniadirVuelosDemorados();
    private:
        string nombre;
        bool esMexicana;
        short maxSlots;
        short cantVuelosDemorados;
        short vecesRegistradoVuelo;
};

// Constructores
Aerolinea::Aerolinea()
{
    nombre = "";
    esMexicana = true;
    maxSlots = 0;
    cantVuelosDemorados = 0;
    vecesRegistradoVuelo = 0;
}

Aerolinea::Aerolinea(string name, bool esMex, short maxS, short cantVD, short vRV)
{
    nombre = name;
    esMexicana = esMex;
    maxSlots = maxS;
    cantVuelosDemorados = cantVD;
    vecesRegistradoVuelo = vRV;
}

// Getters
string Aerolinea::getNombre()
{
    return nombre;
}

bool Aerolinea::getEsMexicana()
{
    return esMexicana;
}

short Aerolinea::getMaxSlots()
{
    return maxSlots;
}

short Aerolinea::getCantVuelosDemorados()
{
  return cantVuelosDemorados;
}

short Aerolinea::getVecesRegistradoVuelo()
{
  return vecesRegistradoVuelo;
}

// Setters
void Aerolinea::setNombre(string nombre)
{
    this-> nombre = nombre;
}

void Aerolinea::setEsMexicana(bool esMex)
{
    esMexicana = esMex;
}

void Aerolinea::setMaxSlots(short maxSlots)
{
    this-> maxSlots = maxSlots;
}

void Aerolinea::setCantVuelosDemorados(short cantVuelosD)
{
  cantVuelosDemorados = cantVuelosD;
}

void Aerolinea::setVecesRegistradoVuelo(short vecesRV)
{
  vecesRegistradoVuelo = vecesRV;
}

// Metodos propios
// Imprime todos los datos de la aerolínea.
void Aerolinea::mostrarDatos() 
{
  cout << "Nombre de la aerolinea: " << nombre << endl;
  if (esMexicana == true)
  {
    cout << "La aerolinea es mexicana?: " << "Si" << endl;
  }
  else
  {
    cout << "La aerolinea es mexicana?: " << "No" << endl;
  }
  cout << "Cantidad maxima de slots: " << maxSlots << endl;
  cout << "Cantidad de vuelos demorados: " << cantVuelosDemorados << endl;
}

void Aerolinea::aniadirVecesRegistradoVuelo()
{
  vecesRegistradoVuelo++; // Se aumenta el contador de las veces que se ha registrado un vuelo en la aerolinea seleccionada.
}

void Aerolinea::aniadirVuelosDemorados()
{
  cantVuelosDemorados++; // Asimismo, también aumenta el contador cuando se reportan los vuelos demorados.
}
#endif // AEROLINEA_H
