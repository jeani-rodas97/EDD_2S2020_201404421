#ifndef LISTAGLOBAL_H
#define LISTAGLOBAL_H
#include "NodoNivel.h"
#include <string>

class ListaGlobal
{
    public:
        ListaGlobal();
        void NuevoNivel(int proy, int nivel, Lista *obj);
        void MostrarNivel(int proy);
        bool ExisteNiv(int nivel);
        NodoNivel *BuscarNivel(int nivel);
        int RetornarNivel(int proy);
        int CantNivel;



    protected:

    private:
        NodoNivel *Inicio, *Final;
        //int CantNivel;
        bool Vacia();

};

#endif // LISTAGLOBAL_H
