#ifndef PASAJERO_H
#define PASAJERO_H

#include <string>

using namespace std;

class Pasajero
{
    public:
        // Constructores
        Pasajero();
        Pasajero(string, short, string, bool, float, bool, string);
        // Getters
        string getNombre();
        short getEdad();
        string getTelefono();
        bool getTraeEquipaje();
        float getPesoEquipaje();
        bool getNacionalidadMexicana();
        string getTipoPago();
        // Setters
        void setNombre(string);
        void setEdad(short);
        void setTelefono(string);
        void setTraeEquipaje(bool);
        void setPesoEquipaje(float);
        void setNacionalidadMexicana(bool);
        void setTipoPago(string);
        // Metodos propios
        void mostrarDatos();
        void reservarVuelo();
    private:
        string nombre;
        short edad;
        string telefono;
        bool traeEquipaje;
        float pesoEquipaje;
        bool nacionalidadMexicana;
        string tipoPago;
};

// Constructores
Pasajero::Pasajero()
{
    nombre = "";
    edad = 0;
    telefono = "";
    traeEquipaje = true;
    pesoEquipaje = 0;
    nacionalidadMexicana = true;
    tipoPago = "";
}

Pasajero::Pasajero(string name, short age, string telephone, bool luggage, float weight, bool Mexican, string pay)
{
  nombre = name;
  edad = age;
  telefono = telephone;
  traeEquipaje = luggage;
  pesoEquipaje = weight;
  nacionalidadMexicana = Mexican;
  tipoPago = pay;
}

// Getters
string Pasajero::getNombre()
{
    return nombre;
}

short Pasajero::getEdad()
{
  return edad;
}

string Pasajero::getTelefono()
{
  return telefono;
}

bool Pasajero::getTraeEquipaje()
{
  return traeEquipaje;
}

float Pasajero::getPesoEquipaje()
{
  return pesoEquipaje;
}

bool Pasajero::getNacionalidadMexicana()
{
    return nacionalidadMexicana;
}

string Pasajero::getTipoPago()
{
  return tipoPago;
}

// Setters
void Pasajero::setNombre(string nombre)
{
  this-> nombre = nombre;
}

void Pasajero::setEdad(short edad)
{
  this-> edad = edad;
}

void Pasajero::setTelefono(string tel)
{
  telefono = tel;
}

void Pasajero::setTraeEquipaje(bool equip)
{
  traeEquipaje = equip;
}

void Pasajero::setPesoEquipaje(float peso)
{
  pesoEquipaje = peso;
}

void Pasajero::setNacionalidadMexicana(bool nacMex)
{
    nacionalidadMexicana = nacMex;
}

void Pasajero::setTipoPago(string tipoPago)
{
  this->tipoPago = tipoPago;
}
// Métodos propios.
// Imprime todos los datos del pasajero.
void Pasajero::mostrarDatos()
{
  cout << "\nDatos del pasajero: " << endl;
  cout << "\nNombre: " << nombre << endl;
  cout << "Edad: " << edad << endl;
  cout << "Telefono: " << telefono << endl;
  if (traeEquipaje == true)
  {
    cout << "Usted cuenta con equipaje?: " << "Si" << endl;
    cout << "Peso de su equipaje: " << pesoEquipaje << " kg" << endl;
  }
  else
  {
    cout << "Usted cuenta con equipaje?: " << "No" << endl;
    cout << "Usted no cuenta con equipaje, por lo tanto, su peso sería de: " << pesoEquipaje << " kg" << endl;
  }
  if (nacionalidadMexicana == true)
  {
    cout << "El/La pasajero(a) es mexicano(a)." << endl;
  }
  else
  {

    cout << "El/La pasajero(a) es extranjero(a)." << endl;
  }
  cout << "Tipo de pago: " << tipoPago << endl;
}
// El pasajero reserva el vuelo cuando se llame esta función en el main.
void Pasajero::reservarVuelo()
{
  short opcionPas;
  cout << "Introduzca los datos del pasajero" << endl;
  // El usuario introduce su nombre.
  cout << "Nombre completo: ";
  getline(cin, nombre);
  // El suario introduce su edad.
  cout << "Edad: ";
  cin >> edad;
  // El usuario introduce su telefono.
  cout << "Teléfono (sin guiones ni espacios): ";
  cin >> telefono;
  // Al usuario se le pregunta si cuenta con equipaje.
  cout << "Cuenta con equipaje? " << endl;
  cout << "1.- Si" << endl;
  cout << "2.- No" << endl;
  cin >> opcionPas;

  // Valida la función anterior.
  while (opcionPas != 1 && opcionPas != 2)
  {
    cout << "Opcion invalida. Intente de nuevo." << endl;
    cout << "Cuenta con equipaje? " << endl;
    cout << "1.- Si" << endl;
    cout << "2.- No" << endl;
    cin >> opcionPas;
  }
  
  // Si el usuario tiene equipaje, se le pregunta su peso total.
  if (opcionPas == 1)
  {
    traeEquipaje = true;
    cout << "Cual es el peso de su equipaje?: ";
    cin >> pesoEquipaje;
    
    // Valida la función anterior.
    while (pesoEquipaje <= 0)
    {
      cout << "Peso invalido. Intente de nuevo." << endl;
      cout << "Cual es el peso de su equipaje?: ";
      cin >> pesoEquipaje;
    }
  }
  else // De lo contrario, automáticamente se asigna el peso del equipaje con 0 kg.
  {
    traeEquipaje = false;
    pesoEquipaje = 0;
  }
  
  // Se le pregunta al usuario si es mexicano.
  cout << "Usted es mexicano(a)? " << endl;
  cout << "1.- Si" << endl;
  cout << "2.- No" << endl;
  cin >> opcionPas;
  
  // Valida la función anterior.
  while (opcionPas != 1 && opcionPas != 2)
  {
    cout << "Opcion invalida. Intente de nuevo." << endl;
    cout << "1.- Si" << endl;
    cout << "2.- No" << endl;
    cin >> opcionPas;
  }

  cin.ignore();

  // El usuario introduce como va a pagar el boleto del vuelo.
  cout << "Introduzca su tipo de pago: ";
  getline(cin, tipoPago);
}
#endif // PASAJERO_H
