#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects) {}
ASpell::ASpell(ASpell const &obj)
{
	*this = obj;
}
ASpell &ASpell::operator=(ASpell const &obj)
{
	this->name = obj.name;
	this->effects = obj.effects;
	return *this;
}
ASpell::~ASpell() {}
std::string ASpell::getName() const
{
	return this->name;
}
std::string ASpell::getEffects() const
{
	return this->effects;
}
void ASpell::launch(ATarget const &obj) const
{
	obj.getHitBySpell(*this);
}