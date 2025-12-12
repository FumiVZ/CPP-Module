/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:51:58 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/22 19:32:22 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "l_sed.hpp"

char *replace_name(const char *filename)
{
	std::string new_filename = filename;
	new_filename += ".replace";
	char *cstr = new char[new_filename.length() + 1];
	std::strcpy(cstr, new_filename.c_str());
	return cstr;
}

void l_sed(char *filename, char *s1, char *s2)
{
	std::ifstream file(filename);
	std::string line;
	std::string newline;
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}
	char *new_filename = replace_name(filename);
	std::ofstream file2(new_filename);
	while (std::getline(file, line))
	{
		size_t pos = line.find(s1);
		while (pos != std::string::npos)
		{
			newline = line.substr(0, pos) + s2 + line.substr(pos + std::strlen(s1));
			line = newline;
			pos = line.find(s1, pos + std::strlen(s2));
		}
		if (file.eof())
			file2 << line;
		else
			file2 << line << std::endl;
	}
	delete[] new_filename;
}

int main(int argc, char **av)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./l_sed filename s1 s2" << std::endl;
		return 1;
	}
	l_sed(av[1], av[2], av[3]);
	return 0;
}
