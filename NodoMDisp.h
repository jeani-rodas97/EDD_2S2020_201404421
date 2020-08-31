#ifndef NODOMDISP_H
#define NODOMDISP_H
#include <string>
#include "ObjetoM.h"

using namespace std;

class NodoMDisp
{
    public:
        NodoMDisp *arribaN;
        NodoMDisp *abajoN;
        NodoMDisp *sigN;
        NodoMDisp *antN;
        //Siguiente y anterior en nodo cabecera
        int cabeza;
        NodoMDisp *sigNC;
        NodoMDisp *antNC;

        NodoMDisp(int PX, int PY, ObjetoM *Pobj);
        NodoMDisp(int cabecera);
        int getPX();
        int getPY();

    protected:

    private:
        int CabX;
        int CabY;
        ObjetoM *obj;
};

#endif // NODOMDISP_H
