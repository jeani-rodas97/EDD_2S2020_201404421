#include "Menu.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "MatrizDisp.h"
#include "ObjetoM.h"
#include "Metodos.h"
#include "LeerJson.h"

using namespace std;

int Menu::Principal(void)
{
    MatrizDisp *matriz = new MatrizDisp();
    Metodos metodo;
    Menu menu;
    LeerJson leerfile;
    int OpPrincipal;
    system("color 57");
    cout<<"\n\n\t ===========================================\n";
    cout<<"\t|              ELIJA UNA OPCION             |\n";
    cout<<"\t|===========================================|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  1. Ver proyectos                         |"<<endl;
    cout<<" \t|  2. Editar proyectos                      |"<<endl;
    cout<<" \t|  3. Cargar proyecto                       |"<<endl;
    cout<<" \t|  4. Graficar proyectos                    |"<<endl;
    cout<<" \t|  5. Guardar proyectos                     |"<<endl;
    cout<<" \t|  6. Cargar librerias                      |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<"\t ===========================================\n";

    cin >> OpPrincipal;
    switch (OpPrincipal)
    {
        case 1:
            ///No hay X no hay Y CASO 1
            cout << "intentando ingresar 1,5" << endl;
            matriz->InsertarObj(new ObjetoM(1, 'A', "rosa", 1,1), 1,5);
            ///Hay X no hay Y CASO 3
            cout << "intentando ingresar 1,2" << endl;
            matriz->InsertarObj(new ObjetoM(1, 'A', "rosa", 1,2), 1,2);
            ///Hay X hay Y CASO 4
            cout << "intentando ingresar 2,2" << endl;
            matriz->InsertarObj(new ObjetoM(1, 'A', "rosa", 2,2), 2,2);
            ///No hay X no hay Y CASO 1
            cout << "intentando ingresar 2,1" << endl;
            matriz->InsertarObj(new ObjetoM(1, 'A', "rosa", 2,1), 2,1);
            ///No hay X no hay Y
            cout << "intentando ingresar 4,4" << endl;
            matriz->InsertarObj(new ObjetoM(1, 'A', "rosa", 4,4), 4,4);
            cout << "Opcion 1 " << endl;
            break;

        case 2:
            system("cls");
            menu.EditarProy();
            break;

        case 3:
            //cout << metodo.ConvertirAscci("casa ")<< endl;
            leerfile.RecibirArchivo();
            //leerjson.LeerJson("hola");
            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        default: cout<< "Ingrese un numero correcto" << endl;

    }
}

int Menu::EditarProy(void)
{
    Menu menu;
    int OpPrincipal;
    system("color 75");
    cout<<"\n\n\t ===========================================\n";
    cout<<"\t|              ELIJA UNA OPCION             |\n";
    cout<<"\t|===========================================|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  1. Agregar nivel                         |"<<endl;
    cout<<" \t|  2. Editar nivel                          |"<<endl;
    cout<<" \t|  3. Copiar nivel                          |"<<endl;
    cout<<" \t|  4. Crear cant. pisos                     |"<<endl;
    cout<<" \t|  5. Agregar objeto                        |"<<endl;
    cout<<" \t|  6. Mover objeto                          |"<<endl;
    cout<<" \t|  7. Eliminar objeto                       |"<<endl;
    cout<<" \t|  8. Eliminar pared                        |"<<endl;
    cout<<" \t|  9. Eliminar nivel                        |"<<endl;
    cout<<" \t|  10. Eliminar proyecto                    |"<<endl;
    cout<<" \t|  11. Salir                                |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<"\t ===========================================\n";

    cin >> OpPrincipal;
    switch (OpPrincipal)
    {
        case 1:
            cout << "Opcion 1 " << endl;
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;

        case 9:

            break;

        case 10:

            break;

        case 11:
            system("cls");
            menu.Principal();
            break;

        default: cout<< "Ingrese un numero correcto" << endl;

    }
}
