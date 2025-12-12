/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_sed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:54:12 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/15 15:13:27 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_SED_HPP
#define L_SED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

void l_sed(char *filename, char *s1, char *s2);
char *replace_name(const char *filename);
#endif