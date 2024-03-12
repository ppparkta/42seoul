#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

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
	/*
	* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
	* forgetSpell, takes a string corresponding a to a spell's name, and makes the
	  Warlock forget it. If it's not a known spell, does nothing.
	* launchSpell, takes a string (a spell name) and a reference to ATarget, that
	  launches the spell on the selected target. If it's not a known spell, does
	  nothing.
	*/
	Warlock(std::string const &name, std::string const &title);
	~Warlock();
	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &title);
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget const &target);
};