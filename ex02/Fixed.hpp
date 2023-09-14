/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:07:18 by mario             #+#    #+#             */
/*   Updated: 2023/09/14 17:33:52 by magonzal         ###   ########.fr       */
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
        
        bool operator<(const Fixed &other)const;
        bool operator>(const Fixed &other)const;
        bool operator<=(const Fixed &other)const;
        bool operator>=(const Fixed &other)const;
        bool operator==(const Fixed &other)const;
        bool operator!=(const Fixed &other)const;

        Fixed operator+(const Fixed &other)const;
        Fixed operator-(const Fixed &other)const;
        Fixed operator*(const Fixed &other)const;
        Fixed operator/(const Fixed &other)const;
        
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
        
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        
    private:
        
        int	_whole;
        static int const _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
