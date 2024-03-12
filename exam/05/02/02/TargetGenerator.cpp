#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const &obj)
{
	*this = obj;
}
TargetGenerator &TargetGenerator::operator=(TargetGenerator const &obj)
{
	this->targets = obj.targets;
	return *this;
}

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {}
/*
* void learnTargetType(ATarget*), teaches a target to the generator

* void forgetTargetType(string const &), that makes the generator forget a
  target type if it's known

* ATarget* createTarget(string const &), that creates a target of the
  specified type
*/
void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
	{
		this->targets[target->getType()] = target;
	}
}
void TargetGenerator::forgetTargetType(std::string const &type)
{
	if (this->targets.find(type) != this->targets.end())
	{
		this->targets.erase(this->targets.find(type));
	}
}
ATarget *TargetGenerator::createTarget(std::string const &type)
{
	ATarget *result = NULL;
	if (this->targets.find(type) != this->targets.end())
	{
		result = this->targets[type];
	}
	return result;
}