#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
class ASpell;
/*
Now, make a SpellBook class, in canonical form, that can't be copied or instantiated
by copy. It will have the following functions:

* void learnSpell(ASpell*), that COPIES a spell in the book
* void forgetSpell(string const &), that deletes a spell from the book, except
  if it isn't there
* ASpell* createSpell(string const &), that receives a string corresponding to
  the name of a spell, creates it, and returns it.
*/
class SpellBook
{
private:
	SpellBook(SpellBook const &obj);
	SpellBook &operator=(SpellBook const &obj);
	std::map<std::string, ASpell *> spells;

public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string const &spellName);
	ASpell *createSpell(std::string const &spellName);
};