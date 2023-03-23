// Juan Daniel Rodríguez Oropeza A01411625
// José Angel Tobón Salazar A01411655
// 02 de Febrero de 2021
#include <iostream>
#include <string>

#include "Pasajero.h"
#include "Vuelo.h"
#include "Aerolinea.h"
#include "Aeropuerto.h"

using namespace std;

int main()
{
    // Datos Aeropuerto
    short cantArps, aerolinArp, opcionArp, opcionArpDos, opcionOrArp, opcionDestArp;
    string nombreArp, claveArp, ciudadArp;
    short posArp = 0;

    // Datos Aerolinea
    string nombreAero;
    bool esMexicana;
    short maxSlots, cantAeros, cantVuelosDemoradosAero;
    short totalMaxSlots = 0;
    short cantVuelosDemorados = 0;
    short posAero = 0;

    // Datos Vuelo
    string id, origenCiudad, destinoCiudad, origenAeropuerto, destinoAeropuerto, fechaSalida, fechaLlegada;
    short horaDespegue, horaAterrizaje, minutoDespegue, minutoAterrizaje, capacidadPasajeros, numEscala;
    short asientosOcupados = 0;
    bool esVueloNacional, tieneEscala, estaATiempo;
    short asientosOEstaAero, opcionVuelo;
    short posVuelo = 0;

    //Datos pasajero
    short asientosLibres, totalAsientosLibres, cantPasajeros;
    short posPas = 0;

    // Datos adiconales   
    short opcion, opcionDos, opcionAero;
    short vecesNuevoUno = 0;
    short vecesUno = 0;
    short vecesDos = 0;
    short vecesNueve = 0;
    bool quiereSalir = false;

    // Tamaño del arreglo de los aeropuertos.
    cantArps = 3;
    Aeropuerto arps[cantArps];
    
    // Tamaño del arreglo de las aerolineas.
    cantAeros = 3;
    Aerolinea aeros[cantAeros];

    // Tamaño del arreglo de los vuelos.
    totalMaxSlots = 3;
    Vuelo listaVuelos[totalMaxSlots];

    // Tamaño del arreglo de los pasajeros.
    cantPasajeros = 3;
    Pasajero pasajs[cantPasajeros];

    do
    {
      // Menu principal
      cout << "\nBienvenido a la interfaz de la red de aeropuertos de los Estados Unidos Mexicanos." << endl;
      cout << "Escoja una de las siguientes opciones" << endl;
      cout << "\n1.- Dar de alta un aeropuerto." << endl;
      cout << "2.- Dar de alta una aerolinea." << endl;
      cout << "3.- Agregar un vuelo." << endl;
      cout << "4.- Reportar un retraso en un vuelo." << endl;
      cout << "5.- Reportar una saturacion en un aeropuerto." << endl;
      cout << "6.- Revisar slots (vuelos) disponibles en general por todos los aeropuertos." << endl;
      cout << "7.- Desplegar los vuelos disponibles por aerolinea." << endl;
      cout << "8.- Comprar boleto para pasajero." << endl;
      cout << "9.- Salir. \n" << endl;
      cin >> opcion;
      cin.ignore();
      
      // Contador de veces que se elige una función
      if (opcion == 1)
      {
        vecesNuevoUno++;
      }
      
      if (opcion == 2)
      {
        vecesUno++;
      }
      
      if (opcion == 3)
      {
        vecesDos++;
      }

      if (opcion == 9)
      {
        vecesNueve++;
      }
      switch (opcion)
      {
        case 1:
          // Verifica que no se haya alcanzado el limite de aeropuertos.
          if (vecesNuevoUno > 1 && ((posArp + 1) > cantArps))
          {
            cout << "Ya se alcanzo la cantidad maxima de aeropuertos" << endl;
            break;
          }

          // El usuario introduce la ciudad en donde se ubica el aeropuerto.
          cout << "\nIntrouzca la ciudad en donde se ubica el aeropuerto: " << endl;
          getline(cin, ciudadArp);

          // El usuario introduce el nombre del aeropuerto.
          cout << "Introduzca el nombre del aeropuerto:" << endl;
          getline(cin, nombreArp);

          // El usuario introduce la clave identificadora del aeropuerto.
          cout << "Introduzca la clave del aeropuerto:" << endl;
          getline(cin, claveArp);

          // El usuario introduce la capacidad maxima de aerolineas que pueda gestionar el aeropuerto.
          cout << "Introduce la capacidad maxima de aerolineas de este aeropuerto:" << endl;
          cin >> aerolinArp;

          // Valida la función anterior.
          while (aerolinArp <= 0)
          {
            cout << "Dato invalido. Intente de nuevo." << endl;
            cout << "Introduce la capacidad maxima de aerolineas de este aeropuerto:" << endl;
            cin >> aerolinArp;
          }

          // Se asignan los valores introducidos por el usuario.
          arps[posArp].setCiudad(ciudadArp);
          arps[posArp].setNombre(nombreArp);
          arps[posArp].setClave(claveArp);
          arps[posArp].setMaxAerolin(aerolinArp);

          // Aumenta la posicion del arreglo del aeropuerto.
          posArp++;

          break; // Fin de la funcion

        case 2:
          // Verifica que por lo menos se haya dado de alta un aeropuerto.
          if (vecesNuevoUno == 0)
          {
            cout << "Aun no se ha registrado ningun aeropuerto." << endl;
            cout << "Regresando al menu principal..." << endl;
            vecesUno--;
            break;
          }
          
          // Verifica que no se haya alcanzado el limite de aerolineas.
          if (vecesUno > 1 && ((posAero +1) > cantAeros))
          {
            cout << "\nCon este intento la capacidad maxima de aerolineas se superaria." << endl;
            break;
          }
          
          // Selecciona el aeropuerto a la cual quiere añadir la aerolinea al usuario.
          cout << "\nSeleccione el aeropuerto a la cual pertenecera la aerolinea:" << endl;
          cout << "AVISO: Si el aeropuerto tiene los datos vacios significa que esa aerolinea aun no ha sido registrada, por lo que no aun no se puede escoger." << endl;
          for (int i = 0; i<cantArps; i++)
          {
            cout << "\nAeropuerto " << i + 1 << endl;
            arps[i].mostrarDatos();
            cout << endl;
          }
          cin >> opcionArp;

          // Valida la funcion anterior
          while (opcionArp <= 0 || (opcionArp > (cantArps + 1)) || arps[opcionArp-1].getNombre() == "")
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "\nSeleccione el aeropuerto a la cual pertenecera la aerolinea:" << endl;
            cout << "AVISO: Si la aerolinea tiene los datos vacios significa que esa aerolinea aun no ha sido registrada, por lo que no aun no se puede escoger." << endl;
            for (int i = 0; i<cantArps; i++)
            {
              cout << "\nAeropuerto " << i + 1 << endl;
              arps[i].mostrarDatos();
            }
            cin >> opcionArp;
          }

          // Suma las veces que se ha registrado una aerolinea en el aeropuerto.
          arps[opcionArp-1].aniadirVecesRegistradoAerolinea();

          // Verifica si la capacidad maxima de aerolineas ha sido superada para el aeropuerto escogido.
          if (arps[opcionArp-1].getVecesRegistradoAerolinea() > arps[opcionArp-1].getMaxAerolin())
          {
            // En caso de que sí se cumpla esta condicion, se pide le pide al usuario que ingrese una aerolinea a otro aeropuerto o que vuelva al menú principal.
            cout << "\nSe ha superado la capacidad maxima de aerolineas para este aeropuerto." << endl;
            cout << "Por favor seleccione otro aeropuerto o vuelva al menu principal." << endl;
            cout << "Que decide?" << endl;
            cout << "1.- Aniadir aerolinea a otro aeropuerto." << endl;
            cout << "2.- Volver al menu principal." << endl;
            cin >> opcion;

            // Valida la funcion anterior
            while (opcion != 1 && opcion != 2)
            {
              cout << "\nOpcion invalida. Intente de nuevo." << endl;
              cout << "\nPor favor seleccione otro aeropuerto o vuelva al menu principal." << endl;
              cout << "Que decide?" << endl;
              cout << "1.- Aniadir aerolinea a otro aeropuerto." << endl;
              cout << "2.- Volver al menu principal." << endl;
              cin >> opcion;
            }

            // Se vuelve a preguntar por el aeropuerto a la cual quiere agregar una aerolinea.
            if (opcion == 1)
            {
              cout << "Seleccione el aeropuerto a la cual pertenecera la aerolinea:" << endl;
              cout << "AVISO: Si la aerolinea tiene los datos vacios significa que esa aerolinea aun no ha sido registrada, por lo que no aun no se puede escoger." << endl;
              for (int i = 0; i<cantAeros; i++)
              {
                cout << "\nAeropuerto " << i + 1 << endl;
                arps[i].mostrarDatos();
              }
              cin >> opcionArp;

              // Valida la funcion anterior
              while (opcionArp <= 0 || (opcionArp > (cantArps + 1)))
              {
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                cout << "Seleccione el aeropuerto a la cual pertenecera la aerolinea:" << endl;
                for (int i = 0; i<cantArps; i++)
                {
                  cout << "\nAeropuerto " << i + 1 << endl;
                  aeros[i].mostrarDatos();
                }
                cin >> opcionArp;
              }

              // Suma las veces que se ha registrado una aerolinea en el aeropuerto.
              arps[opcionArp-1].aniadirVecesRegistradoAerolinea();

              // Manda al usuario al menu principal si el usuario escoge un aeropuerto que no haya sido registrado pero que su plaza aparezca ahí, la cual, por ende no está disponible.
              if (arps[opcionArp-1].getNombre() == "")
              {
                cout << "\nOtra vez ha seleccionado una aerolinea que no ha sido registrada." << endl;
                cout << "Regresara al menu principal." << endl;
                arps[opcionArp-1].restarVecesRegistradoAerolinea();
                break;
              }
            }
            else
            {
              // En caso de que no quiera agregar mas vuelos se regresa al menu principal.
              cout << "Volviendo al menu principal..." << endl;
              quiereSalir = true; 
            }
          }
          // Aqui es donde se sale de la funcion.
          if (quiereSalir == true)
          {
            break; // Vuelve al menú principal.
          }

          // Despliega las aerolineas disponibles así como las plazas que no han sido registradas pero que aún están libres.
          cout << "\nEstas son las aerolineas que ya han sido registradas en la red de aeropuertos. Si los datos aparecen vacios, significa que esta en blanco ese espacio y se puede utilizar para registrar una nueva aerolinea." << endl;

          for (int i=0; i<cantAeros; i++)
          {
            cout << "\nAerolinea " << i + 1 << endl;
            aeros[i].mostrarDatos();
            cout << endl;
          }

          cout << "La aerolinea que desea registrar a este aeropuerto aparece aqui?" << endl;
          cout << "1.- Si" << endl;
          cout << "2.- No, en este momento deseo registrar una aerolinea." << endl;
          cout << endl;
          cin >> opcion;

          // Valida la función anterior.
          while (opcion != 1 && opcion != 2)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            for (int i=0; i<cantAeros; i++)
            {
              cout << "\nAerolinea " << i + 1 << endl;
              aeros[i].mostrarDatos();
            }

            cout << "La aerolinea que desea registrar a este aeropuerto aparece aqui?" << endl;
            cout << "1.- Si" << endl;
            cout << "2.- No, en este momento deseo registrar una aerolinea." << endl;
            cin >> opcion;
          }

          // Si la aerolinea ya está registrada, el usuario procede a seleccionarla.
          if (opcion == 1)
          {
            cout << "Seleccione la aerolinea que desea registrar en este aeropuerto" << endl;
            for (int i=0; i<cantAeros; i++)
            {
              cout << "\nAerolinea " << i + 1 << endl;
              aeros[i].mostrarDatos();
              cout << endl;
            }
            cin >> opcionDos;

            // Verifica que haya ingresado un dato valido y una aerolinea ya registrada.
            while (opcionDos <= 0 || opcionDos > cantAeros || (aeros[opcionDos-1].getNombre() == ""))
            {
              cout << "Opcion invalida. Intente de nuevo." << endl;
              cout << "Seleccione la aerolinea que desea registrar en este aeropuerto" << endl;
              for (int i=0; i<cantAeros; i++)
              {
                cout << "\nAerolinea " << i + 1 << endl;
                aeros[i].mostrarDatos();
              }
              cin >> opcionDos;
            }
          }
          else // Si no es así, el usuario procede a registrar la aerolinea.
          {
            // Introduce nombre de la aerolinea.
          cout << "\nIntroduzca el nombre de la aerolinea: ";
          cin.ignore();
          getline(cin, nombreAero);
          // Introduce si la aerolinea es mexicana o extranjera.
          cout << "La aerolinea es mexicana?" << endl;
          cout << "1.- Si" << endl;
          cout << "2.- No" << endl;
          cin >> opcion;
          
          // Valida la funcion anterior.
          while (opcion != 1 && opcion != 2)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "La aerolinea es mexicana?" << endl;
            cout << "1.- Si" << endl;
            cout << "2.- No" << endl;
            cin >> opcion;
          }

          // Establece el valor del atributo de acuerdo a la respuesta del usuario.
          if (opcion == 1)
          {
            esMexicana = true;
          }
          else if (opcion == 2)
          {
            esMexicana = false;
          }

          // Introduce la cantidad maxima de vuelos que podra tener dicha aerolinea que acaba de registrar.
          cout << "Introduce la cantidad maxima de slots (vuelos) que tendra la aerolinea: ";
          cin >> maxSlots;
          
          // Valida la funcion anterior
          while (maxSlots <= 0)
          {
            cout << "\nDato invalido. Intente de nuevo." << endl;
            cout << "Introduce la cantidad maxima de slots (vuelos) que tendra la aerolinea: ";
            cin >> maxSlots;
          }

          // Establece los valores de los atributos de acuerdo a la respuesta del usuario.
          aeros[posAero].setNombre(nombreAero);
          aeros[posAero].setMaxSlots(maxSlots);
          aeros[posAero].setEsMexicana(esMexicana);
          aeros[posAero].setCantVuelosDemorados(cantVuelosDemorados);

          // Imprime los datos de la aerolinea.
          cout << "\nAerolinea " << posAero + 1 << endl;
          aeros[posAero].mostrarDatos(); // Aquí se llama a la función de la clase para que imprima los datos.
          posAero++; // Se aumenta la posición del arreglo para que la siguiente aerolinea que introduzca el usuario no reemplace a la anterior.
          }
          
          break; // Fin de la funcion.

        case 3: 
          // Verifica que por lo menos se haya dado de alta un aeropuerto.
          if (vecesNuevoUno == 0)
          {
            cout << "Aun no se ha registrado ningun aeropuerto." << endl;
            cout << "Regresando al menu principal..." << endl;
            vecesDos--;
            break;
          }
          else if (vecesUno == 0) // Verifica que por lo menos se haya dado de alta una aerolinea.
          {
            cout << "Aun no se ha registrado ninguna aerolinea." << endl;
            cout << "Regresando al menu principal..." << endl;
            vecesDos--;
            break;
          }

          // Verifica que no se haya alcanzado el limite total de vuelos para el aeropuerto.
          if (vecesDos > 1 && ((posVuelo + 1) > totalMaxSlots))
          {
            cout << "\nCon este intento la capacidad maxima de vuelos se superaria." << endl;
            break;
          }
          
          // Selecciona la aerolinea a la cual le quiere añadir el vuelo el usuario.
          cout << "\nSeleccione la aerolinea a la cual pertenecera el vuelo:" << endl;
          cout << "AVISO: Si la aerolinea tiene los datos vacios significa que esa aerolinea aun no ha sido registrada, por lo que no aun no se puede escoger." << endl;
          for (int i = 0; i<cantAeros; i++)
          {
            cout << "\nAerolinea " << i + 1 << endl;
            aeros[i].mostrarDatos();
            cout << endl;
          }
          cin >> opcionAero;

          // Valida la funcion anterior
          while (opcionAero <= 0 || (opcionAero > (cantAeros + 1)) || aeros[opcionAero-1].getNombre() == "")
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "Seleccione la aerolinea a la cual pertenecera el vuelo:" << endl;
            for (int i = 0; i<cantAeros; i++)
            {
              cout << "\nAerolinea " << i + 1 << endl;
              aeros[i].mostrarDatos();
            }
            cin >> opcionAero;
          }

          // Cuenta las veces que se han registrado vuelos para la aerolinea que escogió el usuario.
          aeros[opcionAero-1].aniadirVecesRegistradoVuelo();

          // Verifica si el contador de las veces que se ha registrado vuelos para dicha aerolinea ha superado el limite de slots (vuelos) permitidos que tiene.
          if (aeros[opcionAero-1].getVecesRegistradoVuelo() > aeros[opcionAero-1].getMaxSlots())
          {
            // En caso de que sí se cumpla esta condicion, se pide le pide al usuario que ingrese un vuelo a otra aerolinea o que vuelva al menú principal.
            cout << "\nSe ha superado la capacidad maxima de slots (vuelos) para esta aerolinea." << endl;
            cout << "Por favor seleccione otra aerolinea o vuelva al menu principal." << endl;
            cout << "Que decide?" << endl;
            cout << "1.- Aniadir vuelo a otra aerolinea." << endl;
            cout << "2.- Volver al menu principal." << endl;
            cin >> opcion;

            // Valida la funcion anterior
            while (opcion != 1 && opcion != 2)
            {
              cout << "\nOpcion invalida. Intente de nuevo." << endl;
              cout << "\nPor favor seleccione otra aerolinea o vuelva al menu principal." << endl;
              cout << "Que decide?" << endl;
              cout << "1.- Aniadir vuelo a otra aerolinea." << endl;
              cout << "2.- Volver al menu principal." << endl;
              cin >> opcion;
            }

            // Se vuelve a preguntar por la aerolinea a la cual quiere agregar un vuelo.
            if (opcion == 1)
            {
              cout << "Seleccione la aerolinea a la cual pertenecera el vuelo:" << endl;
              for (int i = 0; i<cantAeros; i++)
              {
                cout << "\nAerolinea " << i + 1 << endl;
                aeros[i].mostrarDatos();
              }
              cin >> opcionAero;

              // Valida la funcion anterior
              while (opcionAero <= 0 || opcionAero > (cantAeros + 1))
              {
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                cout << "Seleccione la aerolinea a la cual pertenecera el vuelo:" << endl;
                for (int i = 0; i<cantAeros; i++)
                {
                  cout << "\nAerolinea " << i + 1 << endl;
                  aeros[i].mostrarDatos();
                }
                cin >> opcionAero;
              }
              aeros[opcionAero-1].aniadirVecesRegistradoVuelo(); // Aumenta el contador de las veces que se ha registrado un vuelo en la aerolinea escogida.
            }
            else
            {
              // En caso de que no quiera agregar mas vuelos se regresa al menu principal.
              cout << "Volviendo al menu principal..." << endl;
              quiereSalir = true; 
            }
          }
          // Aqui es donde se sale de la funcion.
          if (quiereSalir == true)
          {
            break; // Vuelve al menú principal.
          }

          // Aqui le pregunta al usuario si el vuelo sale de un aeropuerto ya previamente registrado o uno en el que planea registrar en el futuro en la misma red de aeropuertos.
          for (int i=0; i<cantArps; i++)
          {
              cout << "\nAeropuerto " << i + 1 << endl;
              arps[i].mostrarDatos();
          }
          cout << "\nEl vuelo sale de un aeropuerto previamente registrado o que tenga planeado registrar en un futuro?" << endl;
          cout << "1.- Si" << endl;
          cout << "2.- No" << endl;
          cout << endl;
          cin >> opcionOrArp;

          // Valida la funcion anterior.
          while (opcionOrArp != 1 && opcionOrArp != 2)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            for (int i=0; i<cantArps; i++)
            {
              cout << "\nAeropuerto " << i + 1 << endl;
              arps[i].mostrarDatos();
            }
            cout << "\nEl vuelo sale de un aeropuerto previamente registrado o que tenga planeado registrar en un futuro?" << endl;
            cout << "1.- Si" << endl;
            cout << "2.- No" << endl;
            cin >> opcionOrArp;
          }

          // En caso de que haya escogido que sí, el usuario procede a seleccionar el aeropuerto de origen.
          if (opcionOrArp == 1)
          {
            cout << "\nSeleccione un aeropuerto de origen:" << endl;
            for (int i=0; i<cantArps; i++)
            {
              cout << "\nAeropuerto " << i + 1 << endl;
              arps[i].mostrarDatos();
              cout << endl;
            }
            cin >> opcionArp;

            // Valida la funcion anterior
            while (opcionArp <= 0 || (opcionArp > (cantArps + 1)) || arps[opcionArp-1].getNombre() == "")
            {
              cout << "\nOpcion invalida. Intente de nuevo." << endl;
              cout << "Seleccione el aeropuerto de origen:" << endl;
              cout << "AVISO: Si el aeropuerto tiene los datos vacios significa que ese aeropuerto aun no ha sido registrado, por lo que no aun no se puede escoger." << endl;
              for (int i = 0; i<cantArps; i++)
              {
                cout << "\nAeropuerto " << i + 1 << endl;
                arps[i].mostrarDatos();
              }
              cin >> opcionArp;
            }
          }
          // Si el aeropuerto se encuentra saturado se despliega el siguiente mensaje y se pide primero la fecha y hora del vuelo.
          if (opcionOrArp == 1 && arps[opcionArp-1].getSaturado() == true)
          {
            cout << "\nATENCION" << endl;
            cout << "\nEn este momento el Aeropuerto " << arps[opcionArp-1].getNombre() << " se encuentra saturado." << endl;
            cout << "Recuerde que ahora solo podra agregar vuelos en horarios fuera del rango de entre las 7:00 y 23:00" << endl;
            cout << "En esta ocasion le pediremos que primero ingrese los datos de la fecha y hora del vuelo que desea aniadir" << endl;
            cout << "\nIntroduzca la fecha de salida (DD/MM/AA): ";
            //cin.ignore();
            cin >> fechaSalida;
            cout << "Introduzca la fecha de llegada (DD/MM/AA): ";
            //cin.ignore();
            cin >> fechaLlegada;
            cout << "Introduzca solamente la hora de salida, (formato 24hrs) LOS MINUTOS NO: ";
            cin >> horaDespegue;

            // Valida la funcion anterior
            while (horaDespegue < 0 || horaDespegue > 23)
            {
              cout << "\nDato invalido. Intente de nuevo." << endl;
              cout << "Introduzca solamente la hora de salida, (formato 24hrs) LOS MINUTOS NO: ";
              cin >> horaDespegue;
            }

            // Verifica que la hora de despegue no esté entre las horas en las que estara saturado el aeropuerto.
            while (horaDespegue >= arps[opcionArp-1].getHoraInicioSat() && horaDespegue <= arps[opcionArp-1].getHoraFinalSat())
            {
              cout << "La hora introducida interfiere con el horario de saturacion del Aeropuerto " << arps[opcionArp-1].getNombre() << "." << endl;
              cout << "Intente de nuevo." << endl;
              cout << "Introduzca solamente la hora de salida, (formato 24hrs) LOS MINUTOS NO: ";
              cin >> horaDespegue;

              // Valida la funcion anterior
              while (horaDespegue < 0 || horaDespegue > 23)
              {
                cout << "\nDato invalido. Intente de nuevo." << endl;
                cout << "Introduzca solamente la hora de salida, (formato 24hrs) LOS MINUTOS NO: ";
                cin >> horaDespegue;
              }
            }
            
            // Introduce el minuto de salida.
            cout << "Introduzca el minuto de salida: ";
            cin >> minutoDespegue;

            // Valida la funcion anterior
            while (minutoDespegue < 0 || minutoDespegue > 59)
            {
              cout << "\nDato invalido. Intente de nuevo." << endl;
              cout << "Introduzca el minuto de salida: ";
              cin >> minutoDespegue;
            }

            // Verifica que el minuto de despegue no interfiera con el horario de saturación el aeropuerto, basándose en la hora de despegue introducida por el usuario.
            while (horaDespegue == arps[opcionArp-1].getHoraFinalSat() && minutoDespegue == 0)
            {
              cout << "\nRecuerda que a las 23:00 esta saturado el aeropuerto, puede poner el vuelo un poco mas tarde." << endl;
              cout << "Intente de nuevo." << endl;
              cout << "\nIntroduzca el minuto de salida: ";
              cin >> minutoDespegue;

              // Valida la funcion anterior
              while (minutoDespegue < 0 || minutoDespegue > 59)
              {
                cout << "\nDato invalido. Intente de nuevo." << endl;
                cout << "Introduzca el minuto de salida: ";
                cin >> minutoDespegue;
              }
            }
          }
          
          // Aquí se registra a qué aerolínea pertenece este vuelo.
          listaVuelos[posVuelo].setPertAero(aeros[opcionAero-1]); // Aquí se hace uso de la composición.

          // Aquí el usuario introduce el id del vuelo.
          cout << "\nIntroduzca el id del vuelo: ";
          cin >> id;

          // Si el usuario ya escogido un aeropuerto de origen, automaticamente se registran sus datos en la ficha del vuelo.
          if (opcionOrArp == 1)
          {
            origenCiudad = arps[opcionArp-1].getCiudad();
            origenAeropuerto =arps[opcionArp-1].getClave();
          }
          else // En caso contrario, el usuario introduce los datos por su cuenta.
          {
            cout << "Introduzca la ciudad de origen: ";
            cin.ignore();
            getline(cin, origenCiudad);
            cout << "Introduzca la clave del aeropuerto de origen: ";
            //cin.ignore();
            //getline(cin, origenAeropuerto);
            cin >> origenAeropuerto;
          }
          
          // Aquí le preguntan al usuario si el destino es hacia otro aeropuerto ya registrado o que vaya a formar parte de la red de aeropuertos, o si es el destino es ajeno a este.
          cout << "\nEl destino de este vuelo es hacia otro aeropuerto ya dado de alta o uno que en el que planea hacerlo en un futuro?" << endl;
          cout << "1.- Si" << endl;
          cout << "2.- No" << endl;
          cout << endl;
          cin >> opcionDestArp;

          // Valida la función anterior.
          while (opcionDestArp != 1 && opcionDestArp != 2)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "\nEl destino de este vuelo es hacia otro aeropuerto ya dado de alta o uno que en el que planea hacerlo en un futuro?" << endl;
            cout << "1.- Si" << endl;
            cout << "2.- No" << endl;
            cin >> opcionDestArp;
          }

          
          // Si el destino es un aeropuerto ya registrado, el usaurio procede a seleccionarlo, aun no puede escoger aeropuertos que no hayan sido dados de alta dentro de la red de aeropuertos.
          if (opcionDestArp == 1)
          {
            cout << "Seleccione un aeropuerto como su destino." << endl;
            for (int i=0; i<cantArps; i++)
            {
              cout << "\nAeropuerto " << i + 1 << endl;
              arps[i].mostrarDatos();
              cout << endl;
            }
            cin >> opcionArpDos;

            // Valida la funcion anterior.
            while (opcionArpDos <= 0 || (opcionArpDos > (cantArps + 1)) || arps[opcionArpDos-1].getNombre() == "" || arps[opcionArp-1].getClave() == arps[opcionArpDos-1].getClave()) // El suario tampoco puede escoger el mismo aeropuerto que el de origen, porque en ese caso no habría vuelo.
            {
              cout << "\nOpcion invalida. Intente de nuevo." << endl;
              cout << "Puede ser que haya escogido una opcion que no exista o el mismo aeropuerto que el de origen." << endl;
              cout << "\nSeleccione el aeropuerto de destino al cual pertenecera el vuelo:" << endl;
              cout << "AVISO: Si el aeropuerto tiene los datos vacios significa que ese aeropuerto aun no ha sido registrado, por lo que no aun no se puede escoger." << endl;
              for (int i = 0; i<cantArps; i++)
              {
                cout << "\nAeropuerto " << i + 1 << endl;
                arps[i].mostrarDatos();
              }
              cin >> opcionArpDos;
            }

            // Si el aeropuerto de destino se encuentra saturado, solamente la hora de llegada podra ser fuera del horario de saturación.
            if (opcion == 1 && arps[opcionArpDos-1].getSaturado() == true)
            {
              cout << "\nATENCION" << endl;
              cout << "\nEn este momento el Aeropuerto " << arps[opcionArp-1].getNombre() << " se encuentra saturado." << endl;
              cout << "Recuerde que ahora solo podra agregar vuelos en horarios fuera del rango de entre las 7:00 y 23:00" << endl;
              
              // Introduce la hora de llegada.
              cout << "Introduzca solamente la hora de llegada, (formato 24hrs) LOS MINUTOS NO: ";
              cin >> horaAterrizaje;

              // Valida la funcion anterior
              while (horaAterrizaje < 0 || horaAterrizaje > 23)
              {
                cout << "\nDato invalido. Intente de nuevo." << endl;
                cout << "Introduzca solamente la hora de llegada, (formato 24hrs) LOS MINUTOS NO: ";
                cin >> horaAterrizaje;
              }
              // Verifica que la hora de aterrizaje no esté entre las horas en las que estara saturado el aeropuerto.
              while (horaAterrizaje >= arps[opcionArpDos-1].getHoraInicioSat() && horaAterrizaje < arps[opcionArpDos-1].getHoraFinalSat())
              {
                cout << "La hora introducida interfiere con el horario de saturacion del Aeropuerto " << arps[opcionDos-1].getNombre() << "." << endl;
                cout << "Intente de nuevo." << endl;
                // Introduce la hora de llegada.
                cout << "Introduzca solamente la hora de llegada, (formato 24hrs) LOS MINUTOS NO: ";
                cin >> horaAterrizaje;

                // Valida la funcion anterior
                while (horaAterrizaje < 0 || horaAterrizaje > 23)
                {
                  cout << "\nDato invalido. Intente de nuevo." << endl;
                  cout << "Introduzca solamente la hora de llegada, (formato 24hrs) LOS MINUTOS NO: ";
                  cin >> horaAterrizaje;
                }
              }
            
              // Introduce el minuto de llegada-
              cout << "Introduzca el minuto de llegada: ";
              cin >> minutoAterrizaje;

              // Valida la funcion anterior
              while (minutoAterrizaje < 0 || minutoAterrizaje > 59)
              {
                cout << "\nDato invalido. Intente de nuevo." << endl;
                cout << "Introduzca el minuto de llegada: ";
                cin >> minutoAterrizaje;

              }

              // Verifica que el minuto de aterrizaje no interfiera con el horario de saturación el aeropuerto, basándose en la hora de aterrizaje introducida por el usuario.
              while (horaAterrizaje == arps[opcionArp-1].getHoraFinalSat() && minutoAterrizaje == 0)
              {
                // Introduce el minuto de llegada-
                cout << "Introduzca el minuto de llegada: ";
                cin >> minutoAterrizaje;

                // Valida la funcion anterior
                while (minutoAterrizaje < 0 || minutoAterrizaje > 59)
                {
                  cout << "\nDato invalido. Intente de nuevo." << endl;
                  cout << "Introduzca el minuto de llegada: ";
                  cin >> minutoAterrizaje;
                }
              }
            }
          }

          // Si el destino es un aeropuerto previamente registrado, automáticamente se registran sus datos en la ficha del vuelo.
          if (opcionDestArp == 1)
          {
            destinoCiudad = arps[opcionArpDos-1].getCiudad();
            destinoAeropuerto = arps[opcionArpDos-1].getClave();
          }
          else // Si no, el usuario los introduce por su cuenta.
          {
            cout << "Introduzca la ciudad destino: ";
            cin.ignore();
            getline(cin, destinoCiudad);
            cout << "Introduzca la clave del aeropuerto de salida: ";
            //cin.ignore();
            //getline(cin, destinoAeropuerto);
            cin >> destinoAeropuerto;
          }

          // Si no está saturado el aeropuerto, se preguntan la fecha y horarios del vuelo hasta después porque no son prioridad cuando todo va de manera normal.
          if ((opcionOrArp == 1 && arps[opcionArp-1].getSaturado() == false) || opcionOrArp == 2)
          {
            // Introduce la fecha de salida.
            cout << "Introduzca la fecha de salida (DD/MM/AA): ";
            //cin.ignore();
            cin >> fechaSalida;

            // Introduce la fecha de llegada.
            cout << "Introduzca la fecha de llegada (DD/MM/AA): ";
            //cin.ignore();
            cin >> fechaLlegada;

            // Introduce la hora de salida.
            cout << "Introduzca solamente la hora de salida, (formato 24hrs) LOS MINUTOS NO: ";
            cin >> horaDespegue;

            // Valida la funcion anterior
            while (horaDespegue < 0 || horaDespegue > 23)
            {
              cout << "\nDato invalido. Intente de nuevo." << endl;
              cout << "Introduzca solamente la hora de salida, (formato 24hrs) LOS MINUTOS NO: ";
              cin >> horaDespegue;
            }

            // Introduce el minuto de salida.
            cout << "Introduzca el minuto de salida: ";
            cin >> minutoDespegue;

            // Valida la funcion anterior
            while (minutoDespegue < 0 || minutoDespegue > 59)
            {
              cout << "\nDato invalido. Intente de nuevo." << endl;
              cout << "Introduzca el minuto de salida: ";
              cin >> minutoDespegue;
            }
          }

          // Si el aeropuerto de destino no está saturado, se piden estos datos de manera cotidiana.
          if ((opcionDestArp == 1 && arps[opcionArpDos-1].getSaturado() == false) || opcionDestArp == 2)
          {
            // Introduce la hora de llegada.
            cout << "Introduzca solamente la hora de llegada, (formato 24hrs) LOS MINUTOS NO: ";
            cin >> horaAterrizaje;

            // Valida la funcion anterior
            while (horaAterrizaje < 0 || horaAterrizaje > 23)
            {
              cout << "\nDato invalido. Intente de nuevo." << endl;
              cout << "Introduzca solamente la hora de llegada, (formato 24hrs) LOS MINUTOS NO: ";
              cin >> horaAterrizaje;
            }

            // Introduce el minuto de llegada.
            cout << "Introduzca el minuto de llegada: ";
            cin >> minutoAterrizaje;

            // Valida la funcion anterior
            while (minutoAterrizaje < 0 || minutoAterrizaje > 59)
            {
              cout << "\nDato invalido. Intente de nuevo." << endl;
              cout << "Introduzca el minuto de llegada: ";
              cin >> minutoAterrizaje;
            }
          }

          // El usuario introduce la capacidad de asientos del vuelo.
          cout << "Introduzca la capacidad de asientos del vuelo: ";
          cin >> capacidadPasajeros;

          // El usuario introduce la capacidad de asientos que estan ocupados en el vuelo.
          cout << "Introduzca la cantidad de asientos que estan ocupados actualmente: ";
          cin >> asientosOcupados;

          // Aquí se le pregunta al usuario si el vuelo será dentro del país.
          cout << "El vuelo es en el interior de la Republica Mexicana?" << endl;
          cout << "1.- Si" << endl;
          cout << "2.- No" << endl;
          cin >> opcion;

          // Valida la función anterior.
          while (opcion != 1 && opcion != 2)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "El vuelo es en el interior de la Republica Mexicana?" << endl;
            cout << "1.- Si" << endl;
            cout << "2.- No" << endl;
            cin >> opcion;
          }
          
          // Dependiendo de la respuesta se asigna si el vuelo es internacional o no.
          if (opcion == 1)
          {
            esVueloNacional = true;
          }
          else if (opcion == 2)
          {
            esVueloNacional = false;
          }
          
          // Aquí se le pregunta al usuario si el vuelo tiene escalas o no.
          cout << "El vuelo tiene alguna escala?" << endl;
          cout << "1.- Si" << endl;
          cout << "2.- No" << endl;
          cin >> opcion;

          // Valida la función anterior.
          while (opcion != 1 && opcion != 2)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "El vuelo tiene alguna escala?" << endl;
            cout << "1.- Si" << endl;
            cout << "2.- No" << endl;
            cin >> opcion;
          }
          
          // Si la respuesta a la pregunta anterior es afirmativa, se le pregunta al usuario el número de escalas.
          if (opcion == 1)
          {
            tieneEscala = true;
            cout << "Introduzca la cantidad de escalas: ";
            cin >> numEscala;
            
            // Valida la función anterior.
            while (numEscala <= 0)
            {
              cout << "\nDato invalido. Intente de nuevo." << endl;
              cout << "Introduzca la cantidad de escalas: ";
              cin >> numEscala;
            }
          }
          else if (opcion == 2) // En caso contrario, se establece automáticamente que el vuelo tiene 0 escalas.
          {
            tieneEscala = false;
            numEscala = 0;
          }
          
          // Automaticamente al registrar un vuelo se establece que está a tiempo, si el usuario desea cambiar esto, lo puede hacer mediante la función correspondiente en el menú principal.
          estaATiempo = true;
          

          // Verifica que la cantidad de asientos ocupados introducida sea valida.
          while (asientosOcupados < 0 || asientosOcupados > capacidadPasajeros)
          {
            cout << "\nDato invalido. Intente de nuevo." << endl;
            cout << "\nIntroduzca la cantidad de asientos que estan ocupados actualmente: ";
            cin >> asientosOcupados;
          }

          // Se calcula la cantidad de asientos libres.
          asientosLibres = capacidadPasajeros - asientosOcupados;

          // Se calcula cuantos asientos quedan libres por toda la cantidad de vuelos registrados en el sistema.
          totalAsientosLibres += asientosLibres;

          // Se asignan los datos del vuelo.
          listaVuelos[posVuelo].setId(id);
          listaVuelos[posVuelo].setOrigenCiudad(origenCiudad);
          listaVuelos[posVuelo].setDestinoCiudad(destinoCiudad);
          listaVuelos[posVuelo].setOrigenAeropuerto(origenAeropuerto);
          listaVuelos[posVuelo].setDestinoAeropuerto(destinoAeropuerto);
          listaVuelos[posVuelo].setFechaSalida(fechaSalida);
          listaVuelos[posVuelo].setFechaLlegada(fechaLlegada);
          listaVuelos[posVuelo].setHoraDespegue(horaDespegue);
          listaVuelos[posVuelo].setHoraAterrizaje(horaAterrizaje);
          listaVuelos[posVuelo].setMinutoDespegue(minutoDespegue);
          listaVuelos[posVuelo].setMinutoAterrizaje(minutoAterrizaje);
          listaVuelos[posVuelo].setCapacidadPasajeros(capacidadPasajeros);
          listaVuelos[posVuelo].setAsientosOcupados(asientosOcupados);
          listaVuelos[posVuelo].setEsVueloNacional(esVueloNacional);
          listaVuelos[posVuelo].setTieneEscala(tieneEscala);
          listaVuelos[posVuelo].setNumEscalas(numEscala);
          listaVuelos[posVuelo].setEstaATiempo(estaATiempo);
          
          // Le imprime al usuario la ficha del vuelo.
          cout << "\nVuelo " << posVuelo+1 << endl;
          listaVuelos[posVuelo].mostrarDatos();
          
          // Se suma por una unidad la posicion del arreglo de vuelos para que se pueda registrar el siguiente.
          posVuelo++;
          
          break; // Fin de la función.

        case 4:
          // Verifica que por lo menos se haya dado de alta un aeropuerto.
          if (vecesNuevoUno == 0)
          {
            cout << "Aun no se ha registrado ningun aeropuerto." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }
          else if (vecesUno == 0) // Verifica que por lo menos se haya dado de alta una aerolínea.
          {
            cout << "Aun no se ha registrado ninguna aerolinea." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }
          else if (vecesDos == 0) // Verifica que por lo menos se haya dado de alta un vuelo.
          {
            cout << "Aun no se ha registrado ningun vuelo." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }

          // El usuario debe seleccionar de que aerolinea es el vuelo que quiere reportar el retraso.
          cout << "Seleccione la aerolinea a la cual quiere reportar un vuelo con retraso: ";
          for (int i=0; i<cantAeros; i++)
          {
            cout << "\nAerolinea " << i + 1 << endl;
            cout << i + 1 << ".- " << aeros[i].getNombre() << endl;
          }
          
          cin >> opcionAero;

          // Valida la función anterior.
          while (opcionAero <= 0)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "\nSeleccione la aerolinea a la cual quiere reportar un vuelo con retraso: ";
            for (int i=0; i<cantAeros; i++)
            {
              cout << "\nAerolinea " << i + 1 << endl;
              cout << i + 1 << ".- " << aeros[i].getNombre() << endl;
            }
            cin >> opcionAero;
          }

          // Aquí el usuario selecciona el vuelo con el cual quiere reportar el retraso.
          cout << "Seleccione el vuelo con el cual quiere reportar el retraso: " << endl;
          for (int i=0; i<totalMaxSlots; i++)
          {
            // Despliega solo los vuelos de la aerolinea seleccionada.
            if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre())
            {
              cout << "\nVuelo " << i + 1 << " de la Aerolinea " << aeros[opcionAero-1].getNombre() << endl;
              listaVuelos[i].mostrarDatos();
            }
          }

          cin >> opcion;

          // Valida la función anterior.
          while (opcion <= 0 || opcion > totalMaxSlots)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "\nSeleccione el vuelo con el cual quiere reportar el retraso: " << endl;
          
            for (int i=0; i<totalMaxSlots; i++)
            {
              // Despliega solo los vuelos de la aerolinea seleccionada.
              if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre())
              {
                cout << "\nVuelo " << i + 1 << "de la Aerolinea " << aeros[opcionAero-1].getNombre() << endl;
                listaVuelos[i].mostrarDatos();
              }
            }
            cin >> opcion;
          }

          bool siEstaATiempo;
          
          // Aqui confirma que el vuelo escogido haya sido establecido como a tiempo previamente, así como confirmar que el vuelo esocgido pertenece a la aerolinea elegida.
          for (int i=0; i<totalMaxSlots; i++)
          {
            if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre() && listaVuelos[opcion-1].getEstaATiempo() == true) // Aquí es otra de las ocasiones donde se puede ver la composición.
            {
              siEstaATiempo = false;
              listaVuelos[i].setEstaATiempo(siEstaATiempo);
            }
          }

          // Aquí se le suma a la aerolinea una unidad a la cantidad de vuelos demorados que tiene.
          aeros[opcionAero-1].aniadirVuelosDemorados();
          cout << "Ahora la aerolinea " << aeros[opcionAero-1].getNombre() << " tiene " << aeros[opcionAero-1].getCantVuelosDemorados() << " vuelo demorado(s)." << endl;
          
          break; // Fin de la función.

        case 5:
          // Aquí se le pregunta al usuario si está seguro de reportar una saturación en uno de los aeropuertos.
          cout << "\nEsta seguro de que quiere reportar una saturacion en uno de los aeropuertos ya dados de alta?" << endl;
          cout << "Recuerde que ya no se podran agregar vuelos entre las 7:00 y las 23:00." << endl;
          cout << "Confirme su decision." << endl;
          cout << "1.- Si, reportar una saturacion." << endl;
          cout << "2.- No, no hay nada que reportar." << endl;
          cin >> opcion;

          // Valida la funcion anterior.
          while (opcion != 1 && opcion != 2)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "\nEsta seguro de que quiere reportar una saturacion en uno de los aeropuertos ya dados de alta?" << endl;
            cout << "Recuerde que ya no se podran agregar vuelos entre las 7:00 y las 23:00." << endl;
            cout << "Confirme su decision." << endl;
            cout << "1.- Si, reportar una saturacion." << endl;
            cout << "2.- No, no hay nada que reportar." << endl;
            cin >> opcion;
          }

          // Si el usuario se arrepiente de su decisión vuelve al menú principal.
          if (opcion == 2)
          {
            break;
          }

          // El usuario elige el aeropuerto donde quiere reportar la saturación.
          for (int i=0; i<cantArps; i++)
          {
            cout << "\nAeropuerto " << i + 1 << endl;
            arps[i].mostrarDatos();
          }
          cout << "\nSeleccione al aeropuerto donde quiere reportar la saturacion: " << endl;
          cin >> opcionArp;

          // Valida la función anterior.
          while (opcionArp <= 0 || opcionArp > cantArps || arps[opcionArp-1].getNombre() == "")
          {
            cout << "Opcion invalida. Intente de nuevo." << endl;
            for (int i=0; i<cantArps; i++)
            {
              cout << "\nAeropuerto " << i + 1 << endl;
              arps[i].mostrarDatos();
            }
            cout << "\nSeleccione al aeropuerto donde quiere reportar la saturacion: " << endl;
            cin >> opcionArp;
          }
          // Se registra qué aeropuerto queda saturado para saber en cual hay que restringir el horario de los vuelos.
          arps[opcionArp-1].reportarSaturacion();
          break;

        case 6:
          // Verifica que por lo menos se haya dado de alta un aeropuerto.
          if (vecesNuevoUno == 0)
          {
            cout << "Aun no se ha registrado ningun aeropuerto." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }
          else if (vecesUno == 0) // Verifica que por lo menos se haya registrado una aerolinea.
          {
            cout << "Aun no se ha registrado ninguna aerolinea." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }
          else if (vecesDos == 0) // Verifica que por lo menos se haya registrado un vuelo.
          {
            cout << "Aun no se ha registrado ningun vuelo." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }

          // Aquí se despliegan todos los vuelos disponibles.
          cout << "Estos son todos los vuelos disponibles actualmente" << endl;

          for (int i=0; i<totalMaxSlots; i++)
          {
            listaVuelos[i].mostrarDatos();
          }
          
          break; // Fin de la función.

        case 7:
          // Verifica que por lo menos se haya dado de alta un aeropuerto.
          if (vecesNuevoUno == 0)
          {
            cout << "Aun no se ha registrado ningun aeropuerto." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }
          else if (vecesUno == 0) // Verifica que por lo menos se haya registrado una aerolinea.
          {
            cout << "Aun no se ha registrado ninguna aerolinea." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }
          else if (vecesDos == 0) // Verifica que por lo menos se haya registrado un vuelo.
          {
            cout << "Aun no se ha registrado ningun vuelo." << endl;
            cout << "Regresando al menu principal..." << endl;
            break;
          }

          // EL usuario selleciona la aerolinea de la cual quiere ver sus vuelos.
          cout << "Seleccione la aerolinea de la cual quiere revisar sus vuelos: ";
          for (int i=0; i<cantAeros; i++)
          {
            cout << "\nAerolinea " << i + 1 << endl;
            cout << i + 1 << ".- " << aeros[i].getNombre() << endl;
          }
          
          cin >> opcionAero;

          // Valida la funcion anterior.
          while (opcionAero <= 0 || opcionAero > (cantAeros + 1))
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "\nSeleccione la aerolinea de la cual quiere reservar un vuelo: ";
            for (int i=0; i<cantAeros; i++)
            {
              cout << "\nAerolinea " << i + 1 << endl;
              cout << i + 1 << ".- " << aeros[i].getNombre() << endl;
            }
            cin >> opcionAero;
          }

          // Aquí despliegan los vuelos disponibles de la aerolinea que seleccionó el usuario.
          cout << "Estos son los vuelos de la aerolinea que selecciono: " << endl;

          for (int i=0; i<totalMaxSlots; i++)
          {
            // Imprime solamente vuelos pertenecientes a la aerolinea.
            if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre()) // También aquí se puede ver la composición.
            {
              cout << "\nVuelo " << i + 1 << " de la Aerolinea " << aeros[opcionAero-1].getNombre() << endl;
              listaVuelos[i].mostrarDatos();
            }
          }

          break; // Fin de la función.

        case 8:
          // Verifica que por lo menos se haya dado de alta un aeropuerto.
          if (vecesNuevoUno == 0)
          {
            cout << "Aun no se ha registrado ningun aeropuerto." << endl;
            cout << "Regresando al menu principal..." << endl;
            vecesNueve--;
            break;
          }
          else if (vecesUno == 0) // Verifica que por lo menos se haya dado de alta una aerolinea.
          {
            cout << "Aun no se ha registrado ninguna aerolinea." << endl;
            cout << "Regresando al menu principal..." << endl;
            vecesNueve--;
            break;
          }
          else if (vecesDos == 0) // Verifica que por lo menos se haya dado de alta un vuelo.
          {
            cout << "Aun no se ha registrado ningun vuelo." << endl;
            cout << "Regresando al menu principal..." << endl;
            vecesNueve--;
            break;
          }

          // Verifica si con este intento superaria la cantidad de pasajeros que se especcificó en el arreglo.
          if (vecesNueve > 1 && ((posPas + 1) > cantPasajeros))
          {
            cout << "\nCon este intento la capacidad maxima de pasajeros se superaria." << endl;
            break;
          }

          // El usuario selecciona de que aerolinea quiere reservar el vuelo.
          cout << "Seleccione la aerolinea de la cual quiere reservar un vuelo: ";
          for (int i=0; i<cantAeros; i++)
          {
            cout << "\nAerolinea " << i + 1 << endl;
            cout << i + 1 << ".- " << aeros[i].getNombre() << endl;
          }
          
          cin >> opcionAero;

          // Valida la función anterior.
          while (opcionAero <= 0 || opcionAero > (cantAeros + 1))
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "\nSeleccione la aerolinea de la cual quiere reservar un vuelo: ";
            for (int i=0; i<cantAeros; i++)
            {
              cout << "\nAerolinea " << i + 1 << endl;
              cout << i + 1 << ".- " << aeros[i].getNombre() << endl;
            }
            cin >> opcionAero;
          }

          // El usuario selecciona el vuelo que quiere reservar.
          cout << "Seleccione el vuelo que quiere reservar: " << endl;

          for (int i=0; i<totalMaxSlots; i++)
          {
            // Imprime solamente vuelos pertenecientes a la aerolinea.
            if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre()) // También aquí se puede ver la composición.
            {
              cout << "\nVuelo " << i + 1 << " de la Aerolinea " << aeros[opcionAero-1].getNombre() << endl;
              listaVuelos[i].mostrarDatos();
            }
          }

          cin >> opcionVuelo;

          // Valida la función anterior.
          while (opcionVuelo <= 0 || opcionVuelo > totalMaxSlots)
          {
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            cout << "\nSeleccione el vuelo que quiere reservar: " << endl;
          
            for (int i=0; i<totalMaxSlots; i++)
            {
              // Imprime solamente vuelos pertenecientes a la aerolinea.
              if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre()) // También aquí se puede ver la composición.
              {
                cout << "\nVuelo " << i + 1 << " de la Aerolinea " << aeros[opcionAero-1].getNombre() << endl;
                listaVuelos[i].mostrarDatos();
              }
            }
            cin >> opcionVuelo;
          }
          
          bool senialBreak;
          
          // Si el vuelo que eligio esta lleno, se le regresa al usuario al menú principal.
          for (int i=0; i<totalMaxSlots; i++)
          {
            if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre() && listaVuelos[opcionVuelo-1].getCapacidadPasajeros() == listaVuelos[opcionVuelo-1].getAsientosOcupados()) // Aquí también se puede ver ejecutada la composición.
            {
              cout << "\nEl cupo de este esta lleno." << endl;
              cout << "Volviendo al menu principal..." << endl;
              senialBreak = true;
            }
            else
            {
              senialBreak = false;
            }
          }

          // Manda al usuario al menú principal si se cumple la función anterior.
          if (senialBreak == true)
          {
            break;
          }

          // Registra cuantos asientos quedan libres.
          for (int i=0; i<totalMaxSlots; i++)
          {
            if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre())
            {
              asientosOEstaAero = listaVuelos[opcionVuelo-1].getAsientosOcupados() + 1;
              listaVuelos[opcionVuelo-1].setAsientosOcupados(asientosOEstaAero);
            }
          }
          
          cin.ignore();
          pasajs[posPas].reservarVuelo(); // Llama a la función para reservar el vuelo.

          // Le muestra los datos que el usuario introdujo de el pasajero.
          cout << "\nA continuacion le mostramos sus datos para que los cheque" << endl;
          pasajs[posPas].mostrarDatos();

          cout << "\nGracias por su reservacion!" << endl;
          // También imprime la ficha del vuelo actualizada.
          cout << "\nSe han actualizado los datos del vuelo escogido." << endl;
          cout << "A continuacion se los desplegaremos." << endl;
          for (int i=0; i<totalMaxSlots; i++)
          {
            if (aeros[opcionAero-1].getNombre() == listaVuelos[i].getPertAero().getNombre())
            {
              cout << endl;
              listaVuelos[opcionVuelo-1].mostrarDatos();
            }
          }

          posPas++; // Aumenta una unidad la posición del arreglo de los pasajeros para que se pueda registrar correctamente el siguiente.
          
          break; // Fin de la función.
          
        case 9:
          // Mensaje de despedida para el usuario.
          cout<<"\nGracias por acceder a la red de aropuertos de los Estados Unidos Mexicanos. \n"<<endl;
          
          break;  // Fin de la función.

        default:
          // Mensaje que manda al usuario si se equivoca de numero en el menú principal.
          cout << "\nOpcion invalida. Intente de nuevo." << endl;
          
          break; // Fin de la función.
      }
    } while (opcion != 9); // Termina el programa si se escoge la opción nueve.
    return 0;
} 
