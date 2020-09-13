#include "Metodos.h"
#include <string>

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
