/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:24:39 by magonzal          #+#    #+#             */
/*   Updated: 2023/09/14 17:55:58 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
 
Fixed::Fixed(void) :_whole(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) : _whole(num << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const num) : _whole(roundf(num * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return(_whole);
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

void	Fixed::setRawBits(int const raw)
{
	_whole = raw;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &copy)
		_whole = copy.getRawBits();
	return(*this);
}

/*************************************************************************************/

int	Fixed::toInt(void) const
{
	return (_whole >> Fixed::_bits);
}

float	Fixed::toFloat(void) const
{
	return ((double)_whole / (double)(1 << _bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}
