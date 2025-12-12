/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:38:24 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/28 20:02:44 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/*
CONSTRUCTORS DESTRUCTORS
*/

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
CONSTRUCTORS
*/

Fixed::Fixed(const int i) : _value(i << this->_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << this->_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_value = src.getRawBits();
	return *this;
}

/*
CONVERSION FUNCTIONS
*/

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_bits);
}

int Fixed::toInt(void) const
{
	return this->_value >> this->_bits;
}

/*
INCREMENT DECREMENT OPERATORS
*/

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}


/*
COMPARISON OPERATORS
*/

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->_value != rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_value == rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->_value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->_value <= rhs._value;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return this->_value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_value < rhs._value;
}

/*
MATH OPERATORS
*/

Fixed Fixed::operator+(const Fixed &src)
{
	return Fixed(this->toFloat() + src.toFloat());
}


Fixed Fixed::operator-(const Fixed &rhs)
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	if (rhs.toFloat() == 0)
	{
		exit (1);
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

/*
MIN MAX FUNCTIONS
*/

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
ASSIGNATION OPERATOR
*/

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}