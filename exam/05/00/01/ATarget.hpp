#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
protected:
	std::string _type;

public:
	ATarget(std::string type);
	ATarget(ATarget const &obj);
	ATarget &operator=(ATarget const &obj);
	virtual ~ATarget();
	virtual ATarget *clone() const = 0;
	std::string getType() const;
	void getHitBySpell(ASpell const &obj) const;
};