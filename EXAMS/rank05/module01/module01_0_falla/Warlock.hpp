
#ifndef WARLOCK_HPP // si no esta definida la macro entonces la define (para que no procese el hpp cada vez que se llama)
# define WARLOCK_HPP // es como si la macro va a contender todo el contenido del .hpp!!

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

using namespace std;

class Warlock
{
    public:
        Warlock(string const &name, string const &title);
        // virtual pq se crearán objetos que hereden de este (la base)
        // asi se destruye primero la clase derivada y después la base
        // si no lo tuviera solo se llamaría al de la derivada y habría pérdidas de memoria
        virtual ~Warlock();

        //string const &getName(void) const;
        //string const &getTitle(void) const;

        void setTitle(string const &title);
        void introduce(void) const;
        
        void learnSpell(ASpell *spell); // spell: hechizo
        void forgetSpell(string spellName);
        void launchSpell(string spellName, ATarget const &target);

    private:
        // el constructor sin parámetro se pone en private para
        // evitar que se creen objetos sin parámetros!!!
        // Warlock();

        string _name;
        string _title;

        // contenedor(lista) de tipo vector
            // almacena punteros a objetos ASpell
        map<string, ASpell*> _spellBook;
};

#endif