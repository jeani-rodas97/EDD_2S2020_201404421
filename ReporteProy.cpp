#include "ReporteProy.h"
#include <iostream>

using namespace std;

ReporteProy::ReporteProy()
{
    this->Inicio = 0;
    this->Final = 0;
}

void ReporteProy::Nuevo(int proy, int CN, int CO)
{
    ContNiv *agregar = new ContNiv(proy, CN, CO);
    if (this->Inicio == 0)
    {
        this->Inicio = agregar;
        this->Final = agregar;
        return;
    }
    else
    {
        this->Final->Sig = agregar;
        agregar->Ant = this->Final;
        Final = agregar;
        return;
    }
}

void ReporteProy::Ascendente(ContNiv *raiz)
{
    ContNiv *aux = this->Inicio;
    do{
        if(aux->CantNiv < raiz->CantNiv)
        {
            cout << "Proyecto " << aux->Proy << " con " << aux->CantNiv << " niveles " << endl;
            int AuxNiv = aux->CantNiv;
            aux->CantNiv = raiz->CantNiv;
            raiz->CantNiv = AuxNiv;

        }
        aux = aux->Sig;
    }while (aux != this->Inicio);
    Ascendente(raiz->Sig);
}

void ReporteProy::Recorrer()
{
    ContNiv *aux = this->Inicio;
    if (aux != 0)
    {
        do{
            cout << "Proyecto " << aux->Proy << " con " << aux->CantNiv << " niveles " << endl;
            aux = aux->Sig;
        } while(aux != this->Inicio);
    }
}

void ReporteProy::Reporte4()
{
    Ascendente(this->Inicio);
}
