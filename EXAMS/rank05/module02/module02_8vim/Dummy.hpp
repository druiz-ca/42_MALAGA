#include "ATarget.hpp"

using namespace std;

class Dummy: public ATarget
{
	public:
		Dummy();
		~Dummy();
		ATarget* clone() const;
};
