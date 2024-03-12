#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

void leaks()
{
	system("leaks a.out");
}

int main()
{
	atexit(leaks);
	Warlock richard("Richard", "the Titled");

	Dummy bob;
	Fwoosh *fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);

	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);
}