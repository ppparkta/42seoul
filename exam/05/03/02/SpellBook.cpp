#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const &obj)
{
	*this = obj;
}
SpellBook &SpellBook::operator=(SpellBook const &obj)
{
	this->spells = obj.spells;
	return *this;
}

SpellBook::SpellBook() {}
SpellBook::~SpellBook()
{
	if (this->spells.size() != 0)
	{
		for (std::map<std::string, ASpell *>::iterator it = this->spells.begin(); it != this->spells.end(); ++it)
		{
			delete it->second;
		}
		this->spells.clear();
	}
}
void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (this->spells.find(spell->getName()) == this->spells.end())
		{
			this->spells[spell->getName()] = spell->clone();
		}
	}
}
void SpellBook::forgetSpell(std::string const &spellName)
{
	if (this->spells.find(spellName) != this->spells.end())
	{
		delete this->spells.find(spellName)->second;
		this->spells.erase(this->spells.find(spellName));
	}
}
ASpell *SpellBook::createSpell(std::string const &spellName)
{
	ASpell *result = NULL;
	if (this->spells.find(spellName) != this->spells.end())
	{
		result = this->spells[spellName];
	}
	return result;
}