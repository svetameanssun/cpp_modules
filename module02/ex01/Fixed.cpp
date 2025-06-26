/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:11:57 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/23 15:08:08 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  _value = 0;
}

Fixed::Fixed(const int value) {
  std::cout << "Integer constructor called" << std::endl;
  _value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  _value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy construtor called" << std::endl;
  _value = fixed.getRawBits();
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (_value);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _value = raw;
}

float Fixed::toFloat(void) const {
  return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt(void) const { return (_value >> _fractionalBits); }

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy operator called" << std::endl;
  if (this != &fixed) _value = fixed.getRawBits();
  return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}