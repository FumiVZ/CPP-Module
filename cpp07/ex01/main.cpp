#include "iter.hpp"


void constIsEven(int const &n)
{
	if (n % 2 == 0)
	{
		std::cout << "even" << std::endl;
	}
	else
	{
		std::cout << "odd" << std::endl;
	}
}

void isEven(int &n)
{
	if (n % 2 == 0)
	{
		std::cout << "even" << std::endl;
	}
	else
	{
		std::cout << "odd" << std::endl;
	}
}


int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	::iter(intArray, 5, constIsEven);
	::iter(intArray, 5, isEven);
	return 0;
}