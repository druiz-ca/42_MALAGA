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
int eleccion;
/*
- mostrar todo con colores simbolos etc 
- controlar si el nombre de archivo a crear ya existe, en ese caso, preguntar un nuevo nombre o sobreescribir
*/

void opciones(int opcion, vector<struct_Tarea> &vector_Tareas);
void ft_consulta_eleccion();

void MostrarMenu()
{
    cout << "=========================" << endl;
    cout << "       MENU OPCIONES     " << endl;
    cout << "=========================" << endl;
    cout << "[1] Añadir tarea         " << endl;
    cout << "[2] Completar tarea      " << endl;
    cout << "[3] Mostrar tareas       " << endl;
    cout << "[4] Eliminar tarea       " << endl;
    cout << "[5] Modificar tarea      " << endl;
    cout << "[6] Marcar todas completadas" << endl;
    cout << "[7] Mostrar pendientes   " << endl;
    cout << "[8] Tareas pendientes    " << endl;
    cout << "[9] Guardar tareas       " << endl;
    cout << "[10] Cargar tareas       " << endl;
    cout << "[11] Salir               " << endl;
    cout << "=========================" << endl;
}

void ft_crearnuevatarea(vector<struct_Tarea> &vector_Tareas)
{
    string crearla;
    eleccion = -1;
    cout << "Quieres crearla ahora? si o no" << endl;
    cin >> crearla;
    if (crearla == "si")
        opciones(1, vector_Tareas);
    else
        ft_consulta_eleccion();
}

void ft_consulta_eleccion()
{   
    cout << "Entonces, ¿Qué quieres hacer?: 1 - Mostrar menú , 2 - Salir" << endl;
    cin >> eleccion;
    if (eleccion == 1)
        return;
    else
        exit(0);
}

void opciones(int opcion, vector<struct_Tarea> &vector_Tareas)
{
    struct_Tarea Nueva_tarea;
    switch(opcion)
    {
        case(1):
        {
            cout << "Escribe la descripción de la tarea: ";
            cin >> Nueva_tarea.descripcion;
            cin.ignore();
            Nueva_tarea.completada = false;
            Nueva_tarea.num = vector_Tareas.size()+1;
            vector_Tareas.push_back(Nueva_tarea);
            cout << "Tareas añadida" << endl;
            cout << endl;
            ft_consulta_eleccion();
            break;
        }
        case(2):
        {
            // Comprobar primero si ya hay tareas
            if (vector_Tareas.empty())
            {
                cout << "no hay tareas aún" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }
            // Ejecucín de la solicitud de complegar tarea
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
            ft_consulta_eleccion();
            break;
        }
        case(3):
        {
            // Comprobar primero si ya hay tareas
            if (vector_Tareas.empty())
            {
                cout << "no hay tareas aún" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }

            for(int i=0; i < vector_Tareas.size(); i++)
            cout << vector_Tareas[i].num << " - " << vector_Tareas[i].descripcion << " - " << boolalpha << (bool)vector_Tareas[i].completada << endl;
            cout << endl;
            ft_consulta_eleccion();
            break;
        }
        case(4):
        {     
            // Consultar primero si ya hay tareas
            if (vector_Tareas.size() == 0)
            {
                cout << "Aún no hay ninguna tarea" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }   
            int num1 = 0;
            cout <<  "que tarea quieres eliminar" << endl;
            cin >> num1;
            if (num1 <= 0 || num1 >= vector_Tareas.size())
            {
                cout << "num erroneo" << endl;
                ft_consulta_eleccion();
            }
            vector_Tareas.erase(vector_Tareas.begin() + num1);
            ft_consulta_eleccion();   
            break; 
        }
        case(5):
        {
            int num2 = 0;
            string cadena;
            // Consultar primero si ya hay tareas
            if (vector_Tareas.size() == 0)
            {
                cout << "Aún no hay ninguna tarea" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }
            cout << "que tarea quiere modificar:" << endl;
            cin >> num2;
            cout << "como quiere que se llame ahora: " << endl;
            cin >> cadena;
            vector_Tareas[num2].descripcion = cadena;
            ft_consulta_eleccion();  
            break;   
        }
        case(6):
        {
            // Consultar primero si ya hay tareas
            if (vector_Tareas.size() == 0)
            {
                cout << "Aún no hay ninguna tarea" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }
            for (int i = 0; i < vector_Tareas.size(); i++)
                if (vector_Tareas[i].completada == false)
                    vector_Tareas[i].completada = true;
            ft_consulta_eleccion();
        break;
        }
        case(7):
        {
            // Consultar primero si ya hay tareas
            if (vector_Tareas.size() == 0)
            {
                cout << "Aún no hay ninguna tarea" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }
            // Ejecutar la solicitud de mostrar pendientes
            for (int i = 0; i < vector_Tareas.size();i++)
            {
                if (vector_Tareas[i].completada == false)
                    cout << vector_Tareas[i].num << " - " << vector_Tareas[i].descripcion << " - " << boolalpha << vector_Tareas[i].completada << endl;
            }
            ft_consulta_eleccion();
            break;
        }
        case(8):
        {
            // Consultar primero si ya hay tareas
            if (vector_Tareas.size() == 0)
            {
                cout << "Aún no hay ninguna tarea" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }
            int num = 0;
            for (int i = 0; i < vector_Tareas.size(); i++)
                if (vector_Tareas[i].completada == false)
                    num++;
            cout << "Quedan " << num << " tareas pendientes." << endl;
            ft_consulta_eleccion();
            break;
        }
        case(9):
        {
            string nombre_archivo;
            // Consultar primero si ya hay tareas
            if (vector_Tareas.size() == 0)
            {
                cout << "Aún no hay ninguna tarea" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }
            cout << "¿Cómo quieres que se llame tu archivo?" << endl;
            cin >> nombre_archivo;
            nombre_archivo += ".txt";
            ofstream archivo(nombre_archivo);
            cout << "Archivo creado!" << endl;


            for (int i = 0; i < vector_Tareas.size(); i++)
            archivo << vector_Tareas[i].num << " - "\
            << vector_Tareas[i].descripcion << " - "\
            << vector_Tareas[i].completada << endl;

            /* archivo << "[" << endl;
            for (int i = 0; i < vector_Tareas.size(); i++) {
                archivo << "  {" << endl;
                archivo << "    \"num\": " << vector_Tareas[i].num << "," << endl;
                archivo << "    \"descripcion\": \"" << vector_Tareas[i].descripcion << "\"," << endl;
                archivo << "    \"completada\": " << (vector_Tareas[i].completada ? "true" : "false") << endl;
                archivo << "  }" << (i < vector_Tareas.size() - 1 ? "," : "") << endl;
            }
            archivo << "]" << endl;   */  
            
            
            archivo.close();
            cout << "Tareas guardadas correctamente." << endl;
            ft_consulta_eleccion(); 
            break;  
        }
        case(10):
        {
            string nombre;
            cout << "Introduce el nombre del archivo que deseas cargar: " << endl;
            cin >> nombre;
            nombre += ".txt";
            ifstream archivo(nombre);
            if (!archivo)
            {
                cout << "El archivo no existe!" << endl;
                ft_crearnuevatarea(vector_Tareas);
                break;
            }
            string linea;
            struct_Tarea vector_tarea_aux;
            vector_Tareas.clear();
            while (getline(archivo, linea))
            {
                int pos1 = linea.find(" - ");
                int pos2 = linea.rfind(" - ");
                
                vector_tarea_aux.num = stoi(linea.substr(0, pos1));
                vector_tarea_aux.descripcion = linea.substr(pos1 + 3, pos2 - pos1 - 3);
                //vector_tarea_aux.completada = stoi(linea.substr(pos2, linea.end()))
                vector_Tareas.push_back(vector_tarea_aux);
            }
            cout << endl;
            archivo.close();
            ft_consulta_eleccion();
            break;
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
        else if(opcion == 11)
            break;
        else
            cout << "Opción errónea" << endl;
    }
    
}