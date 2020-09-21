#ifndef LEERJSON_H
#define LEERJSON_H
#include <string>
//
using namespace std;

class LeerJson
{
    public:
        LeerJson();
        void RecibirArchivo();
        void MostrarProy();
        void RecibirLibreria();
        void MostrarObjetos();
        void EliminarObjetos(int proy, int nivel, int obj);
        void RecibirNivel(int NumNombreProy);
        bool VerificarProy(int proy);
        bool VerificarObj(int obj);
        void Niveles(int Proy);


    protected:

    private:

};

#endif // LEERJSON_H
