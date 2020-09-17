#ifndef MATRIZDISP_H
#define MATRIZDISP_H
#include "ListaCab.h"
#include "ObjetoM.h"
#include "string"

using namespace std;


class MatrizDisp
{
    public:
        MatrizDisp();
        void InsertarObj(ObjetoM *objNuevo, int x, int y);
        void GraficarMatriz();

    protected:

    private:
        ListaCab *HorizontalX;
        ListaCab *VerticalY;
        void NoHayXniY(ObjetoM *objNuevo, int x, int y);
        void HayX(ObjetoM *objNuevo, int x, int y);
        void HayY(ObjetoM *objNuevo, int x, int y);
        void HayXY(ObjetoM *objNuevo, int x, int y);
};

#endif // MATRIZDISP_H
