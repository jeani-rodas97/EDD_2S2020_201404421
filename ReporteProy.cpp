#include "ReporteProy.h"
#include <iostream>

using namespace std;

ReporteProy::ReporteProy()
{
    this->Inicio = 0;
    this->Final = 0;
    this->Cantidad = 0;
}

void ReporteProy::Nuevo(int proy, int CN, int CO)
{
    ContNiv *agregar = new ContNiv(proy, CN, CO);
    if (this->Inicio == 0)
    {
        this->Inicio = agregar;
        this->Final = agregar;
        this->Cantidad++;
        return;
    }
    else
    {
        this->Final->Sig = agregar;
        agregar->Ant = this->Final;
        Final = agregar;
        this->Cantidad++;
        return;
    }
}

void ReporteProy::Ascendente(ContNiv *raiz, int num)
{
    if(num <= this->Cantidad)
    {
        ContNiv *aux = this->Inicio;
        while(aux != 0)
        {
            if(aux->Sig != 0)
            {
                if(aux->CantNiv < raiz->CantNiv)
                {
                    cout << "Proyecto " << aux->Proy << " con " << aux->CantNiv << " niveles " << endl;
                    //cout << "Proyecto " << raiz->Proy << " con " << raiz->CantNiv << " niveles " << endl;

                }
            }
            aux = aux->Sig;
            num++;
            Ascendente(raiz->Sig, num);
        }
    }
}

void ReporteProy::Recorrer()
{
    ContNiv *aux = this->Inicio;
    while(aux != 0)
    {
        if(aux->Sig != 0)
        {
            cout << "Proyecto " << aux->Proy << " con " << aux->CantNiv << " niveles " << endl;
        }
        else
            return;
        aux = aux->Sig;
    }
    return;
}

void ReporteProy::Reporte4()
{
    Ascendente(this->Inicio, 1);
}
