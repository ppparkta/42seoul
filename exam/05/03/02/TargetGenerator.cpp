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
void TargetGenerator::learnTargetType(ATarget *) {
	if ()
}
void TargetGenerator::forgetTargetType(std::string const &) {}
ATarget *TargetGenerator::createTarget(std::string const &) {}