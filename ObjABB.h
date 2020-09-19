#ifndef OBJABB_H
#define OBJABB_H
#include <string>

using namespace std;

class ObjABB
{
    public:
        ObjABB(int id, string nombre, string letra, string color);
        int getId();
        string getNombre();
        string getLetra();
        string getColor();

        void setId(int id);
        void setNombre(string nombre);
        void setLetra(string letra);
        void setColor(string color);

    protected:

    private:
        int id;
        string nombre;
        string letra;
        string color;
        int puntos[];
};

#endif // OBJABB_H
