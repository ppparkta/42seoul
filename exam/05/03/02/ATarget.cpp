#include "ATarget.hpp"

ATarget::ATarget(std::string const &type) : type(type) {}
ATarget::ATarget(ATarget const &obj)
{
	*this = obj;
}
ATarget &ATarget::operator=(ATarget const &obj)
{
	this->type = obj.type;
	return *this;
}
ATarget::~ATarget() {}
std::string const &ATarget::getType() const
{
	return this->type;
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
	//<TYPE> has been <EFFECTS>!
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}