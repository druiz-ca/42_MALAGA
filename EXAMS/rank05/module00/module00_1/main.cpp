
#include "Warlock.hpp"

int main()
{
    cout << "Constructor:" << endl;
    Warlock gabriel("gabriel", "primer titulo");
    
    cout << "introduce" << endl;
    gabriel.introduce();

    cout << "instroduce:" << endl;
    gabriel.setTitle("segundo tiotulo");
    gabriel.introduce();

    cout << "destructor" << endl;
}