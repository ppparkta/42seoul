#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class ATarget;
class ASpell;
class SpellBook;

class Warlock
{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(Warlock const &obj);
	Warlock &operator=(Warlock const &obj);
	SpellBook spellBook;

public:
	Warlock(std::string name, std::string title);
	~Warlock();
	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &title);
	void introduce() const;

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget const &target);
};