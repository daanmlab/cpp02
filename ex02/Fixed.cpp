/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:34:49 by dabalm            #+#    #+#             */
/*   Updated: 2024/03/06 12:39:53 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_bits;
}

Fixed::Fixed(Fixed const &value)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = value;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

Fixed &Fixed::operator=(Fixed const &value)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_value = value.getRawBits();
    return *this;
}

bool operator>(const Fixed &valueLeft, const Fixed &valueRight)
{
    return valueLeft.getRawBits() > valueRight.getRawBits();
}

bool operator<(const Fixed &valueLeft, const Fixed &valueRight)
{
    return valueLeft.getRawBits() < valueRight.getRawBits();
}

bool operator>=(const Fixed &valueLeft, const Fixed &valueRight)
{
    return valueLeft.getRawBits() >= valueRight.getRawBits();
}

bool operator<=(const Fixed &valueLeft, const Fixed &valueRight)
{
    return valueLeft.getRawBits() <= valueRight.getRawBits();
}

bool operator==(const Fixed &valueLeft, const Fixed &valueRight)
{
    return valueLeft.getRawBits() == valueRight.getRawBits();
}

bool operator!=(const Fixed &valueLeft, const Fixed &valueRight)
{
    return valueLeft.getRawBits() != valueRight.getRawBits();
}

Fixed operator+(const Fixed &valueLeft, const Fixed &valueRight)
{
    return Fixed(valueLeft.toFloat() + valueRight.toFloat());
}

Fixed operator-(const Fixed &valueLeft, const Fixed &valueRight)
{
    return Fixed(valueLeft.toFloat() - valueRight.toFloat());
}

Fixed operator*(const Fixed &valueLeft, const Fixed &valueRight)
{
    return Fixed(valueLeft.toFloat() * valueRight.toFloat());
}

Fixed operator/(const Fixed &valueLeft, const Fixed &valueRight)
{
    return Fixed(valueLeft.toFloat() / valueRight.toFloat());
}

Fixed &Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << this->_bits);
}

int Fixed::toInt(void) const
{
    return this->_value >> this->_bits;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << (float)value.toFloat();
    return out;
}

Fixed &Fixed::min(Fixed &valueLeft, Fixed &valueRight)
{
    return valueLeft < valueRight ? valueLeft : valueRight;
}

Fixed &Fixed::max(Fixed &valueLeft, Fixed &valueRight)
{
    return valueLeft > valueRight ? valueLeft : valueRight;
}

Fixed const &Fixed::min(Fixed const &valueLeft, Fixed const &valueRight)
{
    return valueLeft < valueRight ? valueLeft : valueRight;
}

Fixed const &Fixed::max(Fixed const &valueLeft, Fixed const &valueRight)
{
    return valueLeft > valueRight ? valueLeft : valueRight;
}