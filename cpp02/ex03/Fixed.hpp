/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:38:59 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/23 18:39:41 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	// constructors destructors
	Fixed(void);
	~Fixed(void);

	// constructors
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// conversion functions
	float toFloat(void) const;
	int toInt(void) const;
	
	// assignation operators
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	// comparison operators
	bool operator!=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;

	// math operators
	Fixed operator+(const Fixed &src);
	Fixed operator-(const Fixed &src);
	Fixed operator*(const Fixed &src);
	Fixed operator/(const Fixed& src);

	// min max functions
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	
private:
	int _value;
	static const int _bits = 8;
};

// assignation operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);	

#endif