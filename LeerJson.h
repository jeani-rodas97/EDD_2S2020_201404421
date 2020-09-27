#ifndef LEERJSON_H
#define LEERJSON_H
#include <string>
//
using namespace std;

class LeerJson
{
    public:
        LeerJson();
        void InsertarDatos(int NumProy, int NumNivel, int id, string nombre, string letra, string color, int posX, int posY);
        void RecibirArchivo();
        void RecibirNivel(int NumNombreProy);
        void RecibirLibreria();
        void MostrarProy();
        void MostrarObjetos();
        void MostrarNiveles(int proyecto);
        void MostrarDescendente();
        void EliminarObjetos(int proy, int nivel, int obj);
        void EliminarProyecto(int proy);
        bool VerificarProy(int proy);
        bool VerificarObj(int obj);
        void Niveles(int Proy);
        int CantProy();
        void CopiarNiv(int proy, int copiar, int pegar);


    protected:

    private:

};

#endif // LEERJSON_H
