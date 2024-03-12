#include "Warlock.hpp"
Warlock::Warlock() {}
Warlock::Warlock(Warlock const &obj)
{
	*this = obj;
}
Warlock &Warlock::operator=(Warlock const &obj)
{
	this->name = obj.name;
	this->title = obj.title;
	return *this;
}

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}
std::string const &Warlock::getName() const
{
	return this->name;
}
std::string const &Warlock::getTitle() const
{
	return this->title;
}
void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}
void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
void Warlock::learnSpell(ASpell *spell)
{
	// if (spell)
	//{
	//	if (this->spells.find(spell->getName()) == this->spells.end())
	//	{
	//		this->spells[spell->getName()] = spell;
	//	}
	// }
	spellBook.learnSpell(spell);
}
void Warlock::forgetSpell(std::string spellName)
{
	// if (this->spells.find(spellName) != this->spells.end())
	//{
	//	delete this->spells.find(spellName)->second;
	//	this->spells.erase(this->spells.find(spellName));
	// }
	spellBook.forgetSpell(spellName);
}
void Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	// if (this->spells.find(spellName) != this->spells.end())
	//{
	//	this->spells[spellName]->launch(target);
	// }
	if (spellBook.createSpell(spellName))
	{
		spellBook.createSpell(spellName)->launch(target);
	}
}