#include "Span.hpp"
#include <vector>

int main(int ac, char **av)
{
	if (ac != 1)
	{
		//shuf -i 0-999 -n 5 | tr '\n' ' ' | xargs valgrind ./Span
		Span sp = Span(ac - 1);
		for (int i = 1; i < ac; i++)
			sp.addNumber(atoi(av[i]));
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		return 0;
	}
	else
	{
		Span sp = Span(5);
		int arr[] = {89, 123, 69, 95, 12};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
		try
		{
			sp.addNumbers(numbers.begin(), numbers.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	Span largeSpan(10000);
	for (int i = 0; i < 10000; ++i)
		largeSpan.addNumber(i);
	std::cout << "Shortest span in largeSpan: " << largeSpan.shortestSpan() << std::endl;
	std::cout << "Longest span in largeSpan: " << largeSpan.longestSpan() << std::endl;
	return 0;
}