#pragma once
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class Warlock
{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(const Warlock &obj);
	Warlock &operator=(Warlock const &obj);

	std::map<std::string, ASpell *> spells;

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