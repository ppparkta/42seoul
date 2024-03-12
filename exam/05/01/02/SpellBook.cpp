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
	for (std::map<std::string, ASpell *>::iterator it = this->spells.begin(); it != this->spells.end(); ++it)
	{
		delete it->second;
	}
	this->spells.clear();
}

/*
* void learnSpell(ASpell*), that COPIES a spell in the book (clone)
* void forgetSpell(string const &), that deletes a spell from the book, except
  if it isn't there
* ASpell* createSpell(string const &), that receives a string corresponding to
  the name of a spell, creates it, and returns it.
*/
void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		this->spells[spell->getName()] = spell;
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

// 스킬북 안에 스킬이 있으면 복사하고 없으면 NULL을 반환
ASpell *SpellBook::createSpell(std::string const &spellName)
{
	ASpell *result = NULL;
	if (this->spells.find(spellName) != this->spells.end())
	{
		result = spells[spellName];
	}
	return result;
}