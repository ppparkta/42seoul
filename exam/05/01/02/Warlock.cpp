#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}
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
Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}
std::string Warlock::getName() const
{
	return this->name;
}
std::string Warlock::getTitle() const
{
	return this->title;
}
void Warlock::setTitle(std::string title)
{
	this->title = title;
}
void Warlock::introduce() const
{
	//<NAME>: I am <NAME>, <TITLE>!
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *obj)
{
	// if (obj)
	//{
	//	if (this->spells.find(obj->getName()) == this->spells.end())
	//	{
	//		this->spells[obj->getName()] = obj;
	//	}
	// }
	this->spellBook.learnSpell(obj);
}
void Warlock::forgetSpell(std::string spellName)
{
	// if (this->spells.find(spellName) != this->spells.end())
	//{
	//	delete this->spells.find(spellName)->second;
	//	this->spells.erase(this->spells.find(spellName));
	// }
	this->spellBook.forgetSpell(spellName);
}
void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	// if (this->spells.find(spellName) != this->spells.end())
	//{
	//	this->spells[spellName]->launch(target);
	// }
	if (this->spellBook.createSpell(spellName))
	{
		this->spellBook.createSpell(spellName)->launch(target);
	}
}