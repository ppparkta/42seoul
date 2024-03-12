#include "Dummy.hpp"

Dummy::Dummy() : ATarget("arget Practice Dummy")
{
}
Dummy::~Dummy()
{
}
ATarget *Dummy::clone() const
{
	return new Dummy();
}