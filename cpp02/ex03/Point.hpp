/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:18:11 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/23 13:49:47 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point
{
public:
	Point(void);
	Point(const Point &src);
	Point(const float x, const float y);
	~Point(void);
	Point &operator=(const Point &src);
	float getX(void) const;
	float getY(void) const;
	void displayCoordinates(float const x, float const y) const;

private:
	const float _x;
	const float _y;
};

#endif