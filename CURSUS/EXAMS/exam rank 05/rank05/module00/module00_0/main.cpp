
#include "Warlock.hpp"

int main()
{
    cout << "Constructors:" << endl;
    Warlock richard("Richard", "Master of de Universe");

    cout << "Introduce:" << endl;
    richard.introduce();

    cout << "New title:" << endl;
    richard.setTitle("Master of the Earth");
    richard.introduce();

    cout << "Destructor:" << endl;

}