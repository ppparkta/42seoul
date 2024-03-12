#include "ATarget.hpp"

ATarget::ATarget(std::string type) : type(type) {}
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
std::string ATarget::getType() const
{
	return this->type;
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}