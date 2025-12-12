#include "Base.hpp"

int main()
{
	Base *base = new Base;
	Base *generated = base->generate();
	base->identify(generated);
	base->identify(*generated);
	delete base;
	delete generated;
	return 0;
}