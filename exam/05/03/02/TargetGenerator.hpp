#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
private:
	TargetGenerator(TargetGenerator const &obj);
	TargetGenerator &operator=(TargetGenerator const &obj);
	std::map<std::string, ATarget *> targets;

public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget *);
	void forgetTargetType(std::string const &);
	ATarget *createTarget(std::string const &);
};