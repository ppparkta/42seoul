#pragma once
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
class ASpell;
class ATarget;
class SpellBook;

/*
Modify the Warlock, now, make it have a spell book that will be created with
him and destroyed with him. Also make his learnSpell and forgetSpell functions
call those of the spell book.
*/
class Warlock
{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(const Warlock &obj);
	Warlock &operator=(Warlock const &obj);

	SpellBook spellBook;

public:
	Warlock(std::string name, std::string title);
	~Warlock();
	std::string getName() const;
	std::string getTitle() const;
	void setTitle(std::string title);
	void introduce() const;

	void learnSpell(ASpell *obj);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget &target);
};