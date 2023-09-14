/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:09:27 by mario             #+#    #+#             */
/*   Updated: 2023/09/14 11:07:04 by mario            ###   ########.fr       */
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
	std::cout << "getRawBits member function called" << std::endl;
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

int	Fixed::toInt(void) const
{
	return (_whole >> Fixed::_bits);
}

float	Fixed::toFloat(void) const
{
	return ((double)_whole / (double)(1 << _bits));
}


Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &copy)
		_whole = copy.getRawBits();
	return(*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}