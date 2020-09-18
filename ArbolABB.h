#ifndef ARBOLABB_H
#define ARBOLABB_H
#include <string>
#include "NodoAVL.h"
///NodoAVL se debería llamar NodoArbol

using namespace std;

class ArbolABB
{
    public:
        ArbolABB();
        NodoAVL *getRaiz();
        void setRaiz(NodoAVL *root);
        void NuevoNodo(int numero, string cadena);
        void GraficarArbol(NodoAVL *padre);
        void inorden(NodoAVL *padre);

    protected:

    private:
        NodoAVL *Raiz;
        NodoAVL *InsertarEnABB(NodoAVL *raiz, int Valor, string Nombre );

};

#endif // ARBOLABB_H
