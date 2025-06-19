/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:27:44 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 23:27:45 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
 
Point::Point()
{
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
    // std::cout << "Fixed constructor called" << std::endl;
}

Point::Point(const Point &point): _x(point._x), _y(point._y)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
    return (_x);
}

Fixed Point::getY() const
{
    return (_y);
}

Point & Point::operator = (const Point &point)
{
    // std::cout << "Copy operator called" << std::endl;
    if(this != &point)
    {
        (Fixed) _x = point.getX();
        (Fixed) _y = point.getY();
    }
    return (*this);
}
 
std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << "[" << point.getX() << "-" << point.getY() << "]";
    return (out);
}