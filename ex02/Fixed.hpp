/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:07:18 by mario             #+#    #+#             */
/*   Updated: 2023/09/14 10:39:43 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
    public:
    
        Fixed(void);
        Fixed(int const num);
        Fixed(float const num);
        Fixed(const Fixed &copy);
        ~Fixed();
        
        Fixed &operator=(const Fixed &copy);
        
        bool operator<(const Fixed &other);
        bool operator>(const Fixed &other);
        bool operator<=(const Fixed &other);
        bool operator>=(const Fixed &other);
        bool operator==(const Fixed &other);
        bool operator!=(const Fixed &other);

        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);
        Fixed operator++(void);
        Fixed operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        
        int		getRawBits(void) const;
		void	setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        
        
    private:
        
        int	_whole;
        static int const _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif