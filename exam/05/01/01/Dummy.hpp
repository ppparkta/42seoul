#include "ATarget.hpp"
class ATarget;

class Dummy : public ATarget
{
public:
	Dummy();
	~Dummy();
	Dummy *clone() const;
};