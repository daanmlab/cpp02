/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:34:51 by dabalm            #+#    #+#             */
/*   Updated: 2024/03/05 16:53:57 by dabalm           ###   ########.fr       */
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
    Fixed &operator=(Fixed const &value);
    Fixed(Fixed const &value);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
