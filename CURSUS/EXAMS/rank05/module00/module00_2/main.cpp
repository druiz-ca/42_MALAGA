
#include "Warlock.hpp"

int main()
{
    cout << "constructor:" << endl;
    Warlock gabriel("gabriel", "primer titulo");


    cout << "introduce: " << endl;
    gabriel.introduce();

    cout << "new title " << endl;
    gabriel.setTitle("segundo titulo");
    gabriel.introduce();

    cout << "destructor: " << endl;


}