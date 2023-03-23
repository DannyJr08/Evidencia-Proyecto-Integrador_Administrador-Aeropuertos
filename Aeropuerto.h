#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include "Aerolinea.h"

#include <string>

class Aeropuerto
{
    public:
        // Constructores
        Aeropuerto();
        Aeropuerto(string, string, string, bool, short, short, short, short, short, short);
        // Getters
        string getCiudad();
        string getNombre();
        string getClave();
        bool getSaturado();
        short getHoraInicioSat();
        short getMinutoInicioSat();
        short getHoraFinalSat();
        short getMinutoFinalSat();
        short getMaxAerolin();
        short getVecesRegistradoAerolinea();
        // Setters
        void setCiudad(string);
        void setNombre(string);
        void setClave(string);
        void setSaturado(bool);
        void setHoraInicioSat(short);
        void setMinutoInicioSat(short);
        void setHoraFinalSat(short);
        void setMinutoFinalSat(short);
        void setMaxAerolin(short);
        void setVecesRegistradoAerolinea(short);
        // Metodos propios
        void reportarSaturacion();
        void mostrarDatos();
        void aniadirVecesRegistradoAerolinea();
        void restarVecesRegistradoAerolinea();
    private:
        string ciudad;
        string nombre;
        string clave;
        bool saturado;
        short horaInicioSat;
        short minutoInicioSat;
        short horaFinalSat;
        short minutoFinalSat;
        short maxAerolin;
        short vecesRegistradoAerolinea;
};

// Constructores
Aeropuerto::Aeropuerto()
{
    ciudad = "";
    nombre = "";
    clave = "";
    saturado = false;
    horaInicioSat = -1;
    minutoInicioSat = -1;
    horaFinalSat = -1;
    minutoFinalSat = -1;
    maxAerolin = 0;
    vecesRegistradoAerolinea = 0;
}

Aeropuerto::Aeropuerto(string city, string name, string key, bool saturated, short hIS, short mIS, short hFS, short mFS, short mA, short vRA)
{
  ciudad = city;
  nombre = name;
  clave = key;
  saturado = saturated;
  horaInicioSat = hIS;
  minutoInicioSat = mIS;
  horaFinalSat = hFS;
  minutoFinalSat = mFS;
  maxAerolin = mA;
  vecesRegistradoAerolinea = vRA;
}

// Getters
string Aeropuerto::getCiudad()
{
  return ciudad;
}
string Aeropuerto::getNombre()
{
  return nombre;
}

string Aeropuerto::getClave()
{
  return clave;
}

bool Aeropuerto::getSaturado()
{
    return saturado;
}

short Aeropuerto::getHoraInicioSat()
{
    return horaInicioSat;
}

short Aeropuerto::getMinutoInicioSat()
{
    return minutoInicioSat;
}

short Aeropuerto::getHoraFinalSat()
{
    return horaFinalSat;
}

short Aeropuerto::getMinutoFinalSat()
{
    return minutoFinalSat;
}

short Aeropuerto::getMaxAerolin()
{
  return maxAerolin;
}

short Aeropuerto::getVecesRegistradoAerolinea()
{
  return vecesRegistradoAerolinea;
}

// Setters
void Aeropuerto::setCiudad(string ciudad)
{
  this-> ciudad = ciudad;
}

void Aeropuerto::setNombre(string nombre)
{
  this-> nombre = nombre;
}

void Aeropuerto::setClave(string clave)
{
  this-> clave = clave;
}

void Aeropuerto::setSaturado(bool saturado)
{
    this-> saturado = saturado;
}

void Aeropuerto::setHoraInicioSat(short horaInSat)
{
    horaInicioSat = horaInSat;
}

void Aeropuerto::setMinutoInicioSat(short minInSat)
{
    minutoInicioSat = minInSat;
}

void Aeropuerto::setHoraFinalSat(short horaFinSat)
{
    horaFinalSat = horaFinSat;
}

void Aeropuerto::setMinutoFinalSat(short minFinSat)
{
    minutoFinalSat = minFinSat;
}

void Aeropuerto::setMaxAerolin(short maxAerolin)
{
  this-> maxAerolin = maxAerolin;
}

void Aeropuerto::setVecesRegistradoAerolinea(short vecesAero)
{
  vecesRegistradoAerolinea = vecesAero;
}

// Metodos propios
// Establece el aeropuerto en estado de saturación y también asigna el horario en el que se encntrará en ese estado.
void Aeropuerto::reportarSaturacion()
{
  saturado = true;
  horaInicioSat = 7;
  minutoInicioSat = 0;
  horaFinalSat = 23;
  minutoFinalSat = 0;

  cout << "\nLa saturacion ha sido reportada." << endl;
  cout << "No se podran agregar mas vuelos desde las 7:00 hasta las 23:00." << endl;
}
// Imprime todos los datos del aeropuerto.
void Aeropuerto::mostrarDatos()
{
  cout << "\nCiudad del aeropuerto: " << ciudad << endl;
  cout << "Nombre del aeropuerto: " << nombre << endl;
  cout << "Clave del aeropuerto: " << clave << endl;
  cout << "Cantidad maxima de aerolineas: " << maxAerolin << endl;
  if (saturado == true)
  {
    cout << "Se encuentra saturado el aeropuerto? " << "Si" << endl;
  }
  else
  {
    cout << "Se encuentra saturado el aeropuerto? " << "No" << endl;
  }
}

void Aeropuerto::aniadirVecesRegistradoAerolinea()
{
  vecesRegistradoAerolinea++; // Aumenta el contador de las veces en que se registra una aerolinea en el aeropuerto seleccionado.
}

void Aeropuerto::restarVecesRegistradoAerolinea()
{
  vecesRegistradoAerolinea--; // Disminuye el contador de las veces en que se registra una aerolinea en el aeropuerto seleccionado.
}
#endif // AEROPUERTO_H
