#include "gato.h"

using namespace std;

gato::gato(string jugador1, string jugador2)
{
    this->jugador1 = jugador1;
    this->jugador2 = jugador2;

    for (int i = 0; i < 9; i++)
    {
        mostrar[i] = to_string(i + 1);
    }
}

void gato::mostrarTablero()
{
    cout << "         |         |         " << endl;
    cout << "    " << mostrar[0] << "    |    " << mostrar[1] << "    |    " << mostrar[2] << "    " << endl;
    cout << "_________|_________|_________" << endl;
    cout << "         |         |         " << endl;
    cout << "    " << mostrar[3] << "    |    " << mostrar[4] << "    |    " << mostrar[5] << "    " << endl;
    cout << "_________|_________|_________" << endl;
    cout << "         |         |         " << endl;
    cout << "    " << mostrar[6] << "    |    " << mostrar[7] << "    |    " << mostrar[8] << "    " << endl;
    cout << "         |         |         " << endl;
}

void gato::revisaGanador()
{
    turno += 1;

    if (mostrar[0] == mostrar[1] && mostrar[1] == mostrar[2])
    {
        ganador(mostrar[0]);
    }
    else if (mostrar[3] == mostrar[4] && mostrar[4] == mostrar[5])
    {
        ganador(mostrar[3]);
    }
    else if (mostrar[6] == mostrar[7] && mostrar[7] == mostrar[8])
    {
        ganador(mostrar[6]);
    }
    else if (mostrar[0] == mostrar[4] && mostrar[4] == mostrar[8])
    {
        ganador(mostrar[0]);
    }
    else if (mostrar[6] == mostrar[4] && mostrar[4] == mostrar[2])
    {
        ganador(mostrar[6]);
    }
    if (turno == 10)
    {
        ganador("E");
    }
}

void gato::ganador(string ganador)
{
    if (ganador == "E")
    {
        cout << endl;
        cout << "-------------------------------------" << endl;
        cout << "   NO Gano nadie lo sentimos mucho" << endl;
        cout << "-------------------------------------" << endl;
        fin();
    }
    else if (ganador == "X")
    {
        cout << endl;
        cout << "-------------------------------------" << endl;
        cout << "Felicidades Gano " << jugador1 << " Con las X" <<endl;
        cout << "-------------------------------------" << endl;
        fin();
    }
    else
    {
        cout << endl;
        cout << "-------------------------------------" << endl;
        cout << "Felicidades Gano " << jugador2 << " Con las O" <<endl;
        cout << "-------------------------------------" << endl;
        fin();
    }
    
}

bool gato::fin()
{
    return true;
}


//Falta agregar validacion de que no se intente sobre escribir una jugada
void gato::jugada()
{

    string seleccion;
    if (turno % 2 != 0)
    {
        cout << endl;
        cout << jugador1;
        cout << " Ingrese el numero de la casilla donde desea hacer su moviento " << endl;
        getline(cin, seleccion);
        mostrar[stoi(seleccion)-1] = "X";

    }
    else
    {
        cout << endl;
        cout << jugador2;
        cout << " Ingrese el numero de la casilla donde desea hacer su moviento " << endl;
        getline(cin, seleccion);
        mostrar[stoi(seleccion)-1] = "O";

    }
    mostrarTablero();
    revisaGanador();
}


bool gato::validacion(string seleccion)
{
    try
    {
        
    }
    catch(exception &err)
    {
        cout << "No se ingreso un numero, Intentelo de nuevo" << endl;
    }
    







}