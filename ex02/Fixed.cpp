/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:14:57 by hparveen          #+#    #+#             */
/*   Updated: 2025/11/17 10:56:44 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << BLUE << "Int constructor called" << RESET << std::endl;
    this->_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    std::cout << ORANGE << "Float constructor called" << RESET << std::endl;
    this->_rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << CYAN << "Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_rawBits >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other)const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other)const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other)const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    this->_rawBits++;
    return *this;
}

Fixed &Fixed::operator--()
{
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_rawBits++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_rawBits--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
