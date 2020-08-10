#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


int menuEditarProy(void)
{
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

        default: cout<< "Ingrese un numero correcto" << endl;

    }
}

int menuPrincipal(void)
{
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
            cout << "Opcion 1 " << endl;
            break;

        case 2:
            system("cls");
            menuEditarProy();
            break;

        case 3:

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

int main()
{
    int uno = 1;
    //system("color 57");
    system("color 75");
    //system("color 5e");
    cout<<"\n\n\t ===========================================\n";
    cout<<"\t|            DATOS DEL ESTUDIANTE           |\n";
    cout<<"\t|===========================================|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  USAC                                     |"<<endl;
    cout<<" \t|  Estructuras de datos                     |"<<endl;
    cout<<" \t|  Seccion C                                |"<<endl;
    cout<<" \t|  Jeanifer Alejandra Garcia Rodas          |"<<endl;
    cout<<" \t|  201404421                                |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  Presione 1 para continuar                |"<<endl;
    cout<<"\t ===========================================\n";

    cin >> uno ;
    system("cls");

    menuPrincipal();

    return 0;
}
