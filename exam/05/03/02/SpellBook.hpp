#pragma once
#include <iostream>
#include <map>

#include "ASpell.hpp"

class ASpell;

class SpellBook
{
private:
	SpellBook(SpellBook const &obj);
	SpellBook &operator=(SpellBook const &obj);
	std::map<std::string, ASpell *> spells;

public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell *);
	void forgetSpell(std::string const &);
	ASpell *createSpell(std::string const &);
};