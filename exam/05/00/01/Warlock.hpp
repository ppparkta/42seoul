#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;

class Warlock
{
private:
	std::string _name;
	std::string _title;
	Warlock();
	Warlock(Warlock const &obj);
	Warlock &operator=(Warlock const &obj);
	std::map<std::string, ASpell *> _spells;

public:
	Warlock(std::string name, std::string title);
	~Warlock();
	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &title);
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string SpellName);
	void launchSpell(std::string SepllName, ATarget const &target);
};