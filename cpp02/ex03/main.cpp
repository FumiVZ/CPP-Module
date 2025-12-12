/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:43:12 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/28 20:00:14 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
Point a(0.0f, 0.0f);
Point b(5.0f, 0.0f);
Point c(2.5f, 5.0f);

a.displayCoordinates(a.getX(), a.getY());
b.displayCoordinates(b.getX(), b.getY());
c.displayCoordinates(c.getX(), c.getY());
// Test 1 : Point à l'intérieur
Point p1(2.5f, 2.0f);
std::cout << "Test 1 (inside): " << (bsp(a, b, c, p1) ? " Pass" : " Fail") << std::endl;

// Test 2 : Point sur un bord
Point p2(2.5f, 0.0f);
std::cout << "Test 2 (on border AB): " << (bsp(a, b, c, p2) ? "Pass" : " Fail") << std::endl;

// Test 3 : Point sur un sommet
Point p3(0.0f, 0.0f);
std::cout << "Test 3 (on point A)" << (bsp(a, b, c, p3) ? " Pass" : " Fail") << std::endl;

// Test 4 : Point juste a cote
Point p4(0.0f, 0.1f);
std::cout << "Test 3 (near point A)" << (bsp(a, b, c, p4) ? " Pass" : " Fail") << std::endl;

// Test 5 : Point tres loin
Point p5(123.456f, 500.20f);
std::cout << "Test 3 (Far from triangle)" << (bsp(a, b, c, p5) ? " Pass" : " Fail") << std::endl;

return 0;
}