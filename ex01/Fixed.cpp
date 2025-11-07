/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:37:35 by hparveen          #+#    #+#             */
/*   Updated: 2025/11/07 10:55:54 by hparveen         ###   ########.fr       */
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
    std::cout << MAGENTA << "getRawBits member function called" << RESET << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_rawBits >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
