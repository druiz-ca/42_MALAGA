
#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "Warlock.hpp"
#include "ATarget.hpp"

using namespace std;

class Dummy: public ATarget
{
    public:
        Dummy();
        ~Dummy();
        
        ATarget *clone() const;
};


#endif