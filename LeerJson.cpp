#include "LeerJson.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Metodos.h"
//
#include "json\json.h"
#include "jsoncpp.cpp"


//#include <json/json.h>
//#include <jsoncpp/json/json.h>
//#include <jsoncpp/json/json.h>
//#include "json.h"//Tira error

using namespace std;

LeerJson::LeerJson()
{

}
void LeerJson::RecibirArchivo()
{
    ///C:\\Users\\Jeany\\Downloads\\Proy.json   Para que funcione, colocar sin comilas y doble slash inverso
    Metodos metodo;
    char rutJson[100];
    Json::Value dato;
    Json::Reader ReadJson;
    cout << "Ingrese la ruta de ubicacion ";
    cin >> rutJson;
    ifstream ArchJson(rutJson, ifstream::binary);
    //cout << "Abre el archivo" << endl;
    ReadJson.parse(ArchJson, dato);
    //cout << dato["proyectos"] << endl; /// En dato esta todo el archivo+;
    const Json::Value& proy = dato["proyectos"]; // array of characters
    for (int i = 0; i < proy.size(); i++)
    {
        cout << "Nombre: " << proy[i]["nombre"].asString() << endl;
        const Json::Value& nivel = proy[i]["niveles"];
        for (int j = 0; j < nivel.size(); j++)
        {
            cout << "Nivel: " << nivel[j]["nivel"].asString() << endl;
            cout << metodo.ConvertirAscci(nivel[j]["nivel"].asString()) << endl;
            ///Aqui voy a insertar el nombre al arbol
            const Json::Value& paredes = nivel[j]["paredes"];
            for (int k = 0; k < paredes.size(); k++)
            {
                cout << "color: " << paredes[k]["color"].asString() << endl;
                //const Json::Value& paredes = paredes[k]["paredes"];
            }
        }
    }
}
