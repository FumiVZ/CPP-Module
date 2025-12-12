#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " <level>" << std::endl;
		return 1;
	}
	Harl harl;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelIndex = -1;
	std::string level = av[1];
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break;
		}
	}
	if (levelIndex == -1)
	{
		std::cout << "Invalid level" << std::endl;
		return 1;
	}
	switch (levelIndex)
	{
	case 0:
		harl.complain("debug");
	case 1:
		harl.complain("info");
	case 2:
		harl.complain("warning");
	case 3:
		harl.complain("error");
		break;
	default:
		std::cout << "Invalid level" << std::endl;
		break;
	}
}
