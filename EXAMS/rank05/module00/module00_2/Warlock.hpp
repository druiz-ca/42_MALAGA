
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Warlock
{
    public:
        Warlock(string const &name, string const &title);
        virtual ~Warlock();

        void setTitle(string const &title);
        void introduce();

    private:
        string name;
        string title;

};

#endif