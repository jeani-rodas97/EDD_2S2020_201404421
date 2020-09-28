#include "ReporteNiv.h"

ReporteNiv::ReporteNiv()
{
    this->Inicio = 0;
    this->Final = 0;
    this->Cantidad = 0;
}

ReporteNiv::~ReporteNiv()
{
    //dtor
}

void ReporteNiv::Nuevo(int proy, int niv, int CP, int CV, int CO)
{
    ContObj *agregar = new ContObj(proy, niv, CP, CV, CO);
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
