#ifndef REPORTENIV_H
#define REPORTENIV_H
#include "ContObj.h"


class ReporteNiv
{
    public:
        ReporteNiv();
        virtual ~ReporteNiv();
        void Nuevo(int proy, int niv, int CP, int CV, int CO);

    protected:

    private:
        ContObj *Inicio;
        ContObj *Final;
        int Cantidad;

};

#endif // REPORTENIV_H
