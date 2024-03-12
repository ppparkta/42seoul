#include "ASpell.hpp"

class ASpell;

class Fwoosh : public ASpell
{
public:
	Fwoosh();
	~Fwoosh();
	Fwoosh *clone() const;
};