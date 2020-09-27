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
        void BorrarNodo(NodoAVL *padre, int num);
        void GraficarArbol(NodoAVL *padre);
        void PreOrden(NodoAVL *padre);
        void InOrden(NodoAVL *padre);
        int Buscar(NodoAVL *padre, int num);
        bool BuscarPost(int num);

    protected:

    private:
        NodoAVL *Raiz;
        NodoAVL *InsertarEnABB(NodoAVL *raiz, int Valor, string Nombre );
        NodoAVL *BorrarEnABB(NodoAVL *raiz, int Valor);
        NodoAVL *Eliminar(NodoAVL *encontrado);
        string Recorrer(NodoAVL *padre);
        int Revisar(NodoAVL *padre, int num);
        int Post(NodoAVL *padre);

};

#endif // ARBOLABB_H
