/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:34:51 by dabalm            #+#    #+#             */
/*   Updated: 2024/03/06 12:39:23 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
# include <string>

class Fixed
{
private:
    int _value;
    static const int _bits = 8;
public:
    Fixed();
    Fixed(float const value);
    Fixed(int const value);
    friend std::ostream &operator<<(std::ostream &out, Fixed const &value);
    Fixed &operator=(Fixed const &value);
    friend bool operator>(const Fixed &valueLeft, const Fixed &valueRight);
    friend bool operator<(const Fixed &valueLeft, const Fixed &valueRight);
    friend bool operator>=(const Fixed &valueLeft, const Fixed &valueRight);
    friend bool operator<=(const Fixed &valueLeft, const Fixed &valueRight);
    friend bool operator==(const Fixed &valueLeft, const Fixed &valueRight);
    friend bool operator!=(const Fixed &valueLeft, const Fixed &valueRight);
    friend Fixed operator+(const Fixed &valueLeft, const Fixed &valueRight);
    friend Fixed operator-(const Fixed &valueLeft, const Fixed &valueRight);
    friend Fixed operator*(const Fixed &valueLeft, const Fixed &valueRight);
    friend Fixed operator/(const Fixed &valueLeft, const Fixed &valueRight);
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    Fixed &operator!=(Fixed const &value);
    Fixed(Fixed const &value);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static Fixed &min(Fixed &valueLeft, Fixed &valueRight);
    static Fixed &max(Fixed &valueLeft, Fixed &valueRight);
    static Fixed const &min(Fixed const &valueLeft, Fixed const &valueRight);
    static Fixed const &max(Fixed const &valueLeft, Fixed const &valueRight);
};

#endif
