#include <iostream>
#include <string>
#include <vector>
#include <fstream> // para manejar archivos

using namespace std;

struct struct_Tarea
{
    int num;
    string descripcion;
    bool completada;
};

/*
- Ahora que cuando escoja un opcion y la muestre pregunte que quiere hacer en vez
de mostrar directamente el menu*/

void MostrarMenu()
{
    cout << "Menu opciones:" << endl;
    cout << "1: Añadir tarea" << endl;
    cout << "2: completar tareas" << endl;
    cout << "3: mostrar todas las tareas" << endl;
    cout << "4: eliminar tarea de la lista" << endl;
    cout << "5: modificar una tarea" << endl;
    cout << "6: marcar todas como completadas" << endl;
    cout << "7: mostrar solo tareas pendientes" << endl;
    cout << "8: cuantas tareas pendientes hay" << endl;
    cout << "9: Guardar tareas en un archivo" << endl;
    cout << "10: Cargar tareas de un archivo" << endl;
    cout << "11: salir" << endl;
}

void opciones(int opcion, vector<struct_Tarea> &vector_Tareas)
{
    struct_Tarea Nueva_tarea;
    int eleccion = 0;
    switch(opcion)
    {
        case(1):
            cout << "Escribe la descripción de la tareaa: ";
            cin >> Nueva_tarea.descripcion;
            cin.ignore();
            Nueva_tarea.completada = false;
            Nueva_tarea.num = vector_Tareas.size()+1;
            vector_Tareas.push_back(Nueva_tarea);
            cout << "Tareas añadida" << endl;
            cout << endl;
            cout << "Ahora, ¿Qué quieres hacer?: 1 - Mostrar menú , 2 - Salir" << endl;
            cin >> eleccion;
            if (eleccion == 1)
                break;
            else
                exit(0);
            
        case(2):
            if (vector_Tareas.empty())
            {
                cout << "no hay tareas aún" << endl;
                return ;
            }
            cout << "que tarea ha completado: " << endl;

            int num_tarea;
            cin >> num_tarea;
            cin.ignore();
            if (num_tarea > 0 && num_tarea <= vector_Tareas.size())
            {
                vector_Tareas[num_tarea - 1].completada = true;
                cout << "Tarea marcada como terminada" << endl;
            }
            else
                cout << "num erroneo" << endl;
            cout << endl;
            if (eleccion == 1)
                break;
            else
                exit(0);
        case(3):
            if (vector_Tareas.empty())
            {
                cout << "no hay tareas aún" << endl;
                return ;
            }
            for(int i=0; i < vector_Tareas.size(); i++)
                cout << vector_Tareas[i].num << " - " << vector_Tareas[i].descripcion << " - " << boolalpha << (bool)vector_Tareas[i].completada << endl;
            cout << endl;
            if (eleccion == 1)
                break;
            else
                exit(0);
        case(4):
        {

            int num1 = 0;
            cout <<  "que tarea quieres eliminar" << endl;
            cin >> num1;
            if (num1 <= 0 || num1 >= vector_Tareas.size())
            {
                cout << "num erroneo" << endl;
                break;
            }
            vector_Tareas.erase(vector_Tareas.begin() + num1);
            if (eleccion == 1)
                break;
            else
                exit(0);        
        }
        case(5):
        {

            int num2 = 0;
            string cadena;
            cout << "que tarea quiere modificar:" << endl;
            cin >> num2;
            cout << "como quiere que se llame ahora: " << endl;
            cin >> cadena;
            vector_Tareas[num2].descripcion = cadena;
            if (eleccion == 1)
                break;
            else
                exit(0);        
        }
        case (6):
        {
            for (int i = 0; i < vector_Tareas.size(); i++)
                if (vector_Tareas[i].completada == false)
                    vector_Tareas[i].completada = true;
            if (eleccion == 1)
                break;
            else
                exit(0);
        }
        case(7):
        {
            for (int i = 0; i < vector_Tareas.size();i++)
            {
                if (vector_Tareas[i].completada == false)
                    cout << vector_Tareas[i].num << " - " << vector_Tareas[i].descripcion << " - " << boolalpha << vector_Tareas[i].completada << endl;
            }
            if (eleccion == 1)
                break;
            else
                exit(0);
        }
        case(8):
        {
            int num = 0;

            for (int i = 0; i < vector_Tareas.size(); i++)
                if (vector_Tareas[i].completada == false)
                    num++;
            cout << "Quedan " << num << " tareas pendientes." << endl;
            if (eleccion == 1)
                break;
            else
                exit(0);
        }
        case(9):
        {
            ofstream archivo("archivo_de_tareas.txt");
            cout << "Archivo creado!" << endl;
            for (int i = 0; i < vector_Tareas.size(); i++)
            archivo << vector_Tareas[i].num << " - "\
            << vector_Tareas[i].descripcion << " - "\
            << vector_Tareas[i].completada << endl;
            archivo.close();
            cout << "Tareas guardadas correctamente." << endl;
            if (eleccion == 1)
                break;
            else
                exit(0);        
        }
        case(10):
        {

        }
    }
}


int main()
{
    int opcion;
    vector <struct_Tarea> vector_Tareas;

    while (true)
    {
        MostrarMenu();
        cin >> opcion;
        if (opcion == 1)
            opciones(1, vector_Tareas);
        else if (opcion == 2)
            opciones(2, vector_Tareas);
        else if (opcion == 3)
            opciones(3, vector_Tareas);
        else if (opcion == 4)
            opciones(4, vector_Tareas);
        else if (opcion == 5)
            opciones(5, vector_Tareas);
        else if (opcion == 6)
            opciones(6, vector_Tareas);
        else if(opcion == 7)
            opciones(7, vector_Tareas);
        else if(opcion == 8)
            opciones(8, vector_Tareas);
        else if(opcion == 9)
            opciones(9, vector_Tareas);
        else if(opcion == 10)
            opciones(10, vector_Tareas);
        else if (opcion == 11)
            break;
        else
            cout << "Opción errónea" << endl;
    }
    
}