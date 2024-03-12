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
TargetGenerator::~TargetGenerator()
{
	// for (std::map<std::string, ATarget *>::iterator it = this->targets.begin(); it != this->targets.end(); ++it)
	//{
	//	delete it->second;
	// }
	// this->targets.clear();
}
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
		// if (this->targets.find(target->getType()) == this->targets.end())
		//{
		this->targets[target->getType()] = target;
		//}
	}
}
void TargetGenerator::forgetTargetType(std::string const &targetType)
{
	if (this->targets.find(targetType) != this->targets.end())
	{
		// delete this->targets.find(targetType)->second;
		this->targets.erase(this->targets.find(targetType));
	}
}
ATarget *TargetGenerator::createTarget(std::string const &targetType)
{
	ATarget *target = NULL;
	if (this->targets.find(targetType) != this->targets.end())
	{
		target = this->targets[targetType];
	}
	return target;
}