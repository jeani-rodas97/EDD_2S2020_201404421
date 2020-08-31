#ifndef MATRIZDISP_H
#define MATRIZDISP_H
#include "ListaCab.h"
#include "ObjetoM.h"


class MatrizDisp
{
    public:
        MatrizDisp();

    protected:

    private:
        ListaCab *HorizontalX;
        ListaCab *VerticalY;
        void Vacia(ObjetoM *objNuevo, int x, int y);

};

#endif // MATRIZDISP_H
