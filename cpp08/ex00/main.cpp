#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::list<int> l;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
	}
	try
	{
		std::cout << "Vector: " << *easyfind(v, 5) << std::endl;
		std::cout << "List: " << *easyfind(l, 5) << std::endl;
		std::cout << "Vector (not found): " << *easyfind(v, 15) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	try
	{
		std::cout << "List (not found): " << *easyfind(l, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	return 0;
}