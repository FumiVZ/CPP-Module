#include "Array.hpp"

int main(void)
{
	Array<int> intArray(5);
	for (unsigned int i = 0; i < 5; i++)
	{
		intArray[i] = i;
	}
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << intArray[i] << std::endl;
	}
	try
	{
		intArray[6] = 5;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	} 
	return 0;
}
