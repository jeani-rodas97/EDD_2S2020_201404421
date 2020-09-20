#include "LeerJson.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Metodos.h"
#include "ArbolAVL.h"
#include "ArbolABB.h"
#include "MatrizDisp.h"
//
#include "json\json.h"
#include "jsoncpp.cpp"


//#include <json/json.h>
//#include <jsoncpp/json/json.h>
//#include <jsoncpp/json/json.h>
//#include "json.h"//Tira error

using namespace std;
ArbolAVL *AVL = new ArbolAVL();
ArbolABB *ABB = new ArbolABB();

LeerJson::LeerJson()
{

}
void LeerJson::RecibirArchivo()
{
    ///C:\\Users\\Jeany\\Downloads\\Proy.json   Para que funcione, colocar sin comilas y doble slash inverso
    Metodos metodo;

    char rutJson[100];
    int NumNombreProy, Xinicial, Yinicial, Xfinal, Yfinal, NumNivel;
    string ColorNodo;
    Json::Value dato;
    Json::Reader ReadJson;
    cout << "Ingrese la ruta de ubicacion ";
    cin >> rutJson;
    ifstream ArchJson(rutJson, ifstream::binary);
    //cout << "Abre el archivo" << endl;
    ReadJson.parse(ArchJson, dato);
    //cout << dato["proyectos"] << endl; /// En dato esta todo el archivo+;
                ///Estoy en proyectos
    const Json::Value& proy = dato["proyectos"]; // array of characters
    for (int i = 0; i < proy.size(); i++)
    {
        cout << "Nombre: " << proy[i]["nombre"].asString() << endl;
        NumNombreProy = metodo.ConvertirAscci(proy[i]["nombre"].asString());
        cout << NumNombreProy << endl;
        ///Aqui voy a insertar el nombre al arbol
        AVL->NuevoNodo(NumNombreProy, proy[i]["nombre"].asString());
                ///Estoy en niveles
        const Json::Value& nivel = proy[i]["niveles"];
        for (int j = 0; j < nivel.size(); j++)
        {
            NumNivel = nivel[j]["nivel"].asInt();
            cout << "Nivel: " << nivel[j]["nivel"].asString() << endl;
            cout << "Nuevo nivel, nueva matriz:     " << NumNombreProy << NumNivel << endl;
            MatrizDisp *MatrizNivel = new MatrizDisp(NumNombreProy, NumNivel);
                ///Estoy en paredes
            const Json::Value& paredes = nivel[j]["paredes"];
            for (int k = 0; k < paredes.size(); k++)
            {
                ColorNodo = paredes[k]["color"].asString();
                cout << "color: " << paredes[k]["color"].asString() << endl;
                const Json::Value& paredInicio = paredes[k]["inicio"];
                Xinicial = paredInicio[0].asInt();
                Yinicial = paredInicio[1].asInt();
                cout << "inicioX: " << paredInicio[0].asString() << endl;
                cout << "inicioY: " << paredInicio[1].asString() << endl;
                const Json::Value& paredFinal = paredes[k]["final"];
                cout << "finalX: " << paredFinal[0].asString() << endl;
                cout << "finalY: " << paredFinal[1].asString() << endl;
                Xfinal = paredFinal[0].asInt();
                Yfinal = paredFinal[1].asInt();
                if (Xinicial == Xfinal)
                {
                    ///Avanzamox en y
                    for(int y = Yinicial; y <= Yfinal; y++)
                    {
                        cout << "creando " << Xinicial << " , " << y << endl;
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "P", ColorNodo, Xinicial, y ), Xinicial, y);
                    }
                }
                if (Yinicial == Yfinal)
                {
                    for (int x = Xinicial; x <= Xfinal; x++)
                    {
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "P", ColorNodo, x, Yinicial), x, Yinicial);
                    }
                }

            }
            MatrizNivel->GraficarMatriz(NumNombreProy, NumNivel);
        }
    }
    AVL->GraficarArbol(AVL->getRaiz());
}

void LeerJson::MostrarProy()
{
    AVL->inorden(AVL->getRaiz());
}

void LeerJson::MostrarObjetos()
{
    ABB->InOrden(ABB->getRaiz());
}

void LeerJson::RecibirLibreria()
{
    char rutJson[100];
    Json::Value dato;
    Json::Reader ReadJson;
    int id;
    string nombre;
    cout << "Ingrese la ruta de ubicacion ";
    cin >> rutJson;
    ifstream ArchJson(rutJson, ifstream::binary);
    ReadJson.parse(ArchJson, dato);

    const Json::Value& lib = dato["Libreria"];
    for (int i = 0; i < lib.size(); i++)
    {
        cout << "Identificador: " << lib[i]["identificador"].asInt() << endl;
        id = lib[i]["identificador"].asInt();
        cout << "Nombre: " << lib[i]["nombre"].asString() << endl;
        nombre = lib[i]["nombre"].asString();
        cout << "Letra: " << lib[i]["letra"].asString() << endl;
        cout << "Color: " << lib[i]["color"].asString() << "\n" << endl;

        ABB->NuevoNodo(id, nombre);
    }
    ABB->GraficarArbol(ABB->getRaiz());
    cout<< "pasar a in orden" << endl;
    ABB->InOrden(ABB->getRaiz());
}

void LeerJson::EliminarObjetos()
{

}
