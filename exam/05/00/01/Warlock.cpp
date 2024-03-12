#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(Warlock const &obj)
{
	*this = obj;
}
Warlock &Warlock::operator=(Warlock const &obj)
{
	this->_name = obj._name;
	this->_title = obj._title;
	return *this;
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
	{
		delete it->second;
	}
	_spells.clear();
}

std::string const &Warlock::getName() const
{
	return this->_name;
}

std::string const &Warlock::getTitle() const
{
	return this->_title;
}

void Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (this->_spells.find(spell->getName()) == this->_spells.end())
		{
			// spell->clone이 아니라 spell을 넣가
			_spells[spell->getName()] = spell;
		}
	}
}
void Warlock::forgetSpell(std::string SpellName)
{
	if (this->_spells.find(SpellName) != this->_spells.end())
	{
		delete this->_spells.find(SpellName)->second;
		this->_spells.erase(this->_spells.find(SpellName));
	}
}
void Warlock::launchSpell(std::string SepllName, ATarget const &target)
{
	if (this->_spells.find(SepllName) != this->_spells.end())
	{
		this->_spells[SepllName]->launch(target);
	}
}