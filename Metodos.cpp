#include "Metodos.h"
#include <string>
#include <sstream>

using namespace std;

Metodos::Metodos()
{
    //ctor
}

int Metodos::ConvertirAscci(string cadena)
{
    char letra;
    int acumulado = 0;
    for (int i = 0; i <= cadena.size(); i++)
    {
        letra = cadena[i];
        acumulado += letra;
    }
    return acumulado;
}

string Metodos::ConvtirIntString(int valor)
{
    stringstream cadena;
    cadena << valor;
    return(cadena.str());
}
