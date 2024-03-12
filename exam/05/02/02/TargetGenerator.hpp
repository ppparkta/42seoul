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
	void learnTargetType(ATarget *target);
	void forgetTargetType(std::string const &type);
	ATarget *createTarget(std::string const &type);
};