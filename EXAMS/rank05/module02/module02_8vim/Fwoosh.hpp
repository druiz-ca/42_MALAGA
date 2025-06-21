#include "ASpell.hpp"

using namespace std;

class Fwoosh: public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const;
};
