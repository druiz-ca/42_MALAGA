#include <iostream>
#include <map>

using namespace std;


class pruebas
{
private:
    /* data */
public:
    pruebas(/* args */);
    ~pruebas();
};

pruebas::pruebas(/* args */)
{
    cout << "he creado un objeto prueba" << endl;
}

pruebas::~pruebas()
{
    cout << "destructor del objeto prueba" << endl;
}

int main()
{

    pruebas objeto_prueba;
    map<string, pruebas *> mapa_prueba;
    pruebas *mapa_prueba = new pruebas();
    mapa_prueba.insert(make_pair("clave2", nuevo prueba));

}

