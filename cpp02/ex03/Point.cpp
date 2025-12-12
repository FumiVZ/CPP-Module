/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:18:01 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/23 13:51:04 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0.0f), _y(0.0f) {}
Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::~Point(void) {}
Point &Point::operator=(const Point &src) {
	src.getX();
	src.getY();	
	return *this;
}
float Point::getX(void) const { return this->_x; }
float Point::getY(void) const { return this->_y; }

void Point::displayCoordinates(float const x, float const y) const
{
	std::cout << "Point coordinates: (" << x << ", " << y << ")" << std::endl;
}