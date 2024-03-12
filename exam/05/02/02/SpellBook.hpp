#pragma once
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

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