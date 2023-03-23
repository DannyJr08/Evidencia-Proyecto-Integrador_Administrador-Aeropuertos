#ifndef VUELO_H
#define VUELO_H

#include <string>

#include "Aerolinea.h"

using namespace std;

class Vuelo
{
    public:
        // Constructores
        Vuelo();
        Vuelo(string, string, string, string, string, string, string, short, short, short, short, short, short, bool, bool, short, bool, Aerolinea);
        // Getters
        string getId();
        string getOrigenCiudad();
        string getDestinoCiudad();
        string getOrigenAeropuerto();
        string getDestinoAeropuerto();
        string getFechaSalida();
        string getFechaLlegada();
        short getHoraDespegue();
        short getHoraAterrizaje();
        short getMinutoDespegue();
        short getMinutoAterrizaje();
        short getCapacidadPasajeros();
        short getAsientosOcupados();
        bool getEsVueloNacional();
        bool getTieneEscala();
        short getNumEscalas();
        bool getEstaATiempo();
        Aerolinea getPertAero();
        // Setters
        void setId(string);
        void setOrigenCiudad(string);
        void setDestinoCiudad(string);
        void setOrigenAeropuerto(string);
        void setDestinoAeropuerto(string);
        void setFechaSalida(string);
        void setFechaLlegada(string);
        void setHoraDespegue(short);
        void setHoraAterrizaje(short);
        void setMinutoDespegue(short);
        void setMinutoAterrizaje(short);
        void setCapacidadPasajeros(short);
        void setAsientosOcupados(short);
        void setEsVueloNacional(bool);
        void setTieneEscala(bool);
        void setNumEscalas(short);
        void setEstaATiempo(bool);
        void setPertAero(Aerolinea);
        // Metodos propios
        void mostrarDatos();
    private:
        string id;
        string origenCiudad;
        string destinoCiudad;
        string origenAeropuerto;
        string destinoAeropuerto;
        string fechaSalida;
        string fechaLlegada;
        short horaDespegue;
        short horaAterrizaje;
        short minutoDespegue;
        short minutoAterrizaje;
        short capacidadPasajeros;
        short asientosOcupados;
        bool esVueloNacional;
        bool tieneEscala;
        short numEscalas;
        bool estaATiempo;
        Aerolinea pertAero; // Composición
};

// Constructores
Vuelo::Vuelo()
{
    id = "";
    origenCiudad = "";
    destinoCiudad = "";
    origenAeropuerto = "";
    destinoAeropuerto = "";
    fechaSalida = "";
    fechaLlegada = "";
    horaDespegue = 0;
    horaAterrizaje = 0;
    minutoDespegue = 0;
    minutoAterrizaje = 0;
    capacidadPasajeros = 0;
    asientosOcupados = 0;
    esVueloNacional = true;
    tieneEscala = true;
    numEscalas = 0;
    estaATiempo = true;
    pertAero = Aerolinea();
}

Vuelo::Vuelo(string ide, string oC, string dC, string oA, string dA, string fS, string fL, short hD, short hA, short mD, short mA, short cP, short aO, bool eVN, bool tE, short nE, bool eAT, Aerolinea pA)
{
  id = ide;
  origenCiudad = oC;
  destinoCiudad = dC;
  origenAeropuerto = oA;
  destinoAeropuerto = dA;
  fechaSalida = fS;
  fechaLlegada = fL;
  horaDespegue = hD;
  horaAterrizaje = hA;
  minutoDespegue = mD;
  minutoAterrizaje = mA;
  capacidadPasajeros = cP;
  asientosOcupados = aO;
  esVueloNacional = eVN;
  tieneEscala = tE;
  numEscalas = nE;
  estaATiempo = eAT;
  pertAero = pA;
}

// Getters
string Vuelo::getId()
{
    return id;
}

string Vuelo::getOrigenCiudad()
{
    return origenCiudad;
}

string Vuelo::getDestinoCiudad()
{
    return destinoCiudad;
}

string Vuelo::getOrigenAeropuerto()
{
    return origenAeropuerto;
}

string Vuelo::getDestinoAeropuerto()
{
    return destinoAeropuerto;
}

string Vuelo::getFechaSalida()
{
    return fechaSalida;
}

string Vuelo::getFechaLlegada()
{
    return fechaLlegada;
}

short Vuelo::getHoraDespegue()
{
    return horaDespegue;
}
short Vuelo::getHoraAterrizaje()
{
    return horaAterrizaje;
}
short Vuelo::getMinutoDespegue()
{
    return minutoDespegue;
}

short Vuelo::getMinutoAterrizaje()
{
    return minutoAterrizaje;
}

short Vuelo::getCapacidadPasajeros()
{
    return capacidadPasajeros;
}

short Vuelo::getAsientosOcupados()
{
  return asientosOcupados;
}

bool Vuelo::getEsVueloNacional()
{
    return esVueloNacional;
}

bool Vuelo::getTieneEscala()
{
    return tieneEscala;
}

short Vuelo::getNumEscalas()
{
    return numEscalas;
}

bool Vuelo::getEstaATiempo()
{
    return estaATiempo;
}

Aerolinea Vuelo::getPertAero()
{
  return pertAero;
}

// Setters
void Vuelo::setId(string id)
{
    this-> id = id;
}

void Vuelo::setOrigenCiudad(string origenCiudad)
{
    this-> origenCiudad = origenCiudad;
}

void Vuelo::setDestinoCiudad(string destinoCiudad)
{
    this-> destinoCiudad =destinoCiudad;
}

void Vuelo::setOrigenAeropuerto(string origenAero)
{
    origenAeropuerto = origenAero;
}

void Vuelo::setDestinoAeropuerto(string destinoAero)
{
    destinoAeropuerto = destinoAero;
}

void Vuelo::setFechaSalida(string fechaS)
{
    fechaSalida = fechaS;
}

void Vuelo::setFechaLlegada(string fechaL)
{
    fechaLlegada = fechaL;
}

void Vuelo::setHoraDespegue(short horaDesp)
{
    horaDespegue = horaDesp;
}

void Vuelo::setHoraAterrizaje(short horaAterr)
{
    horaAterrizaje = horaAterr;
}

void Vuelo::setMinutoDespegue(short minDesp)
{
    minutoDespegue = minDesp;
}

void Vuelo::setMinutoAterrizaje(short minAterr)
{
    minutoAterrizaje = minAterr;
}

void Vuelo::setCapacidadPasajeros(short capPas)
{
    capacidadPasajeros = capPas;
}

void Vuelo::setAsientosOcupados(short asientosO)
{
  asientosOcupados = asientosO;
}

void Vuelo::setEsVueloNacional(bool VueloN)
{
    esVueloNacional = VueloN;
}

void Vuelo::setTieneEscala(bool tieneEs)
{
    tieneEscala = tieneEs;
}

void Vuelo::setNumEscalas(short nEsc)
{
    numEscalas = nEsc;
}

void Vuelo::setEstaATiempo(bool estaAT)
{
    estaATiempo = estaAT;
}

void Vuelo::setPertAero(Aerolinea pertAero)
{
  this-> pertAero = pertAero;
}

// Metodos propios
// Imprime todos los datos del vuelo.
void Vuelo::mostrarDatos()
{
    cout << "\nAerolinea: " << pertAero.getNombre() << endl; // Poner el metodo de la funcion
    cout<<"Clave de identificación: "<<id<<endl;
    cout<<"Ciudad de origen: "<<origenCiudad << " ";
    cout<<"Aeropuerto de origen: "<<origenAeropuerto<<endl;
    cout<<"Ciudad de destino: "<<destinoCiudad<< " ";
    cout<<"Aeropuerto de destino: "<<destinoAeropuerto<<endl;
    cout<<"Fecha de salida: "<<fechaSalida<<endl;
    cout<<"Fecha de llegada: "<<fechaLlegada<<endl;
    if (horaDespegue < 10 && minutoDespegue >= 10)
    {
      cout<<"Hora de despegue: 0"<<horaDespegue<<":"<<minutoDespegue<<endl;
    }
    else if (horaDespegue < 10 && minutoDespegue < 10)
    {
      cout<<"Hora de despegue: 0"<<horaDespegue<<":0"<<minutoDespegue<<endl;
    }
    else if (horaDespegue >= 10 && minutoDespegue < 10)
    {
      cout<<"Hora de despegue: "<<horaDespegue<<":0"<<minutoDespegue<<endl;
    }
    else if (horaDespegue >= 10 && minutoDespegue >= 10)
    {
      cout<<"Hora de despegue: "<<horaDespegue<<":"<<minutoDespegue<<endl;
    }

    if (horaAterrizaje < 10 && minutoAterrizaje >= 10)
    {
      cout<<"Hora de aterrizaje: 0"<<horaAterrizaje<<":"<<minutoAterrizaje<<endl;
    }
    else if (horaAterrizaje < 10 && minutoAterrizaje < 10)
    {
      cout<<"Hora de aterrizaje: 0"<<horaAterrizaje<<":0"<<minutoAterrizaje<<endl;
    }
    else if (horaAterrizaje >= 10 && minutoAterrizaje < 10)
    {
      cout<<"Hora de aterrizaje: "<<horaAterrizaje<<":0"<<minutoAterrizaje<<endl;
    }
    else if (horaAterrizaje >= 10 && minutoAterrizaje >= 10)
    {
      cout<<"Hora de aterrizaje: "<<horaAterrizaje<<":"<<minutoAterrizaje<<endl;
    }
    cout<<"Capacidad del avión: "<<capacidadPasajeros<< " pasajeros" <<endl;
    cout << "Asientos Libres: " << capacidadPasajeros - asientosOcupados << endl;
    if (esVueloNacional == true)
    {
      cout<<"El vuelo es nacional?: "<< "Si" <<endl;
    }
    else
    {
      cout<<"El vuelo es nacional?: "<< "No" <<endl;
    }
    if (tieneEscala == true)
    {
      cout<<"Tiene escalas: "<< "Si" <<endl;
    }
    else
    {
      cout<<"Tiene escalas: "<< "No" <<endl;
    }
    cout<<"Numero de escalas: "<<numEscalas<<endl;
    if (estaATiempo == true)
    {
      cout<<"Esta a tiempo: "<< "Si" <<endl;
    }
    else
    {
      cout<<"Esta a tiempo: "<< "No" <<endl;
    }
}
#endif // VUELO_H
