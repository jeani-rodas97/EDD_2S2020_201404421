#ifndef REPORTEPROY_H
#define REPORTEPROY_H
#include "ContNiv.h"


class ReporteProy
{
    public:
        ReporteProy();
        void Nuevo(int proy, int CN, int CO);
        void Ascendente(ContNiv *raiz);
        void Reporte4();
        void Recorrer();

    protected:

    private:
        ContNiv *Inicio;
        ContNiv *Final;
};

#endif // REPORTEPROY_H
