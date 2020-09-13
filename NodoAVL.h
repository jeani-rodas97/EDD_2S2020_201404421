#ifndef NODOAVL_H
#define NODOAVL_H


class NodoAVL
{
    public:
        NodoAVL(int Info);
        int getInfo();

        NodoAVL *getRamaIzq();
        NodoAVL *getRamaDer();
        int getFactorEquilibrio();
        void setRamaIzq(NodoAVL *n);
        void setRamaDer(NodoAVL *n);
        void setFactorEquilibrio(int Valor);

    protected:


    private:
        int Info;
        NodoAVL *HijoIzquierdo;
        NodoAVL *HijoDerecho;
        int FactorEquilibrio;


};

#endif // NODOAVL_H
