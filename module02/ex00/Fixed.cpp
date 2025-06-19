/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:01:45 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 23:01:46 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Инициализация статического константного члена класса
const int Fixed::_fractionalBits = 8;

// 1. Конструктор по умолчанию
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// 2. Конструктор копирования (теперь с выводом)
Fixed::Fixed(const Fixed& other) : _value(other._value) { // Копируем _value из other
    std::cout << "Copy constructor called" << std::endl;
}

// 3. Оператор присваивания копированием (теперь с выводом)
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) { // Проверка на самоприсваивание
        _value = other._value; // Копируем _value из other
    }
    return *this;
}

// 4. Деструктор (теперь с выводом)
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Член-функции
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
    // std::cout << "setRawBits member function called. Raw value set to " << _value << std::endl;
    // Этот вывод можно убрать, если он не нужен для конкретного main-файла
}

int Fixed::getFractionalBits() {
    return _fractionalBits;
}