/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:24:41 by magonzal          #+#    #+#             */
/*   Updated: 2023/09/11 13:47:21 by mario            ###   ########.fr       */
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
        Fixed &operator=(const Fixed &copy);
        ~Fixed();
        int		getRawBits(void) const;
		void	setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        
        int	_whole;
        static int const _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif