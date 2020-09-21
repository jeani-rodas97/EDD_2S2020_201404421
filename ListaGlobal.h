#ifndef LISTAGLOBAL_H
#define LISTAGLOBAL_H
#include "NodoNivel.h"
#include <string>

class ListaGlobal
{
    public:
        ListaGlobal();
        void NuevoNivel(int proy, int nivel);
        void MostrarNivel(int proy);


    protected:

    private:
        NodoNivel *Inicio, *Final;
        int Cant;

};

#endif // LISTAGLOBAL_H
