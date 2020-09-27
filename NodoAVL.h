#ifndef NODOAVL_H
#define NODOAVL_H
#include <string>
using namespace std;

class NodoAVL
{
    public:
        NodoAVL(int Info, string Nombre);
        int getInfo();
        string getNombre();
        NodoAVL *getRamaIzq();
        NodoAVL *getRamaDer();
        int getFactorEquilibrio();
        //void setNombre(string Nombre);
        void setInfo(int Info);
        void setRamaIzq(NodoAVL *n);
        void setRamaDer(NodoAVL *n);
        void setFactorEquilibrio(int Valor);

    protected:


    private:
        int Info;
        string Nombre;
        NodoAVL *HijoIzquierdo;
        NodoAVL *HijoDerecho;
        int FactorEquilibrio;


};

#endif // NODOAVL_H
