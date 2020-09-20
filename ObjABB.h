#ifndef OBJABB_H
#define OBJABB_H
#include <string>

using namespace std;

class ObjABB
{
    public:
        ObjABB(int proy, int nivel, int id, string nombre, string letra, string color, int posX, int posY);
        int getProy();
        int getNivel();
        int getId();
        string getNombre();
        string getLetra();
        string getColor();
        int getPosX();
        int getPosY();

        void setProy(int proy);
        void setNivel(int nivel);
        void setId(int id);
        void setNombre(string nombre);
        void setLetra(string letra);
        void setColor(string color);
        void setPosX(int posX);
        void setPosY(int posY);

    protected:

    private:
        int proy, nivel, posX, posY;
        int id;
        string nombre;
        string letra;
        string color;
        int puntos[];
};

#endif // OBJABB_H
