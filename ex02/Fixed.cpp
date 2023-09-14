/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:09:27 by mario             #+#    #+#             */
/*   Updated: 2023/09/14 17:43:45 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
 
Fixed::Fixed(void) :_whole(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) : _whole(num << _bits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const num) : _whole(roundf(num * (1 << _bits)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return(_whole);
}
Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
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
	//std::cout << "Copy assignment operator called" << std::endl;
	if(this != &copy)
		_whole = copy.getRawBits();
	return(*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}

/*************************************************************************************/

bool	Fixed::operator<(const Fixed &copy) const
{
	return (_whole < copy._whole);
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (_whole > copy._whole);
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (_whole <= copy._whole);
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (_whole >= copy._whole);
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (_whole == copy._whole);
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (_whole != copy._whole);
}

/*************************************************************************************/

Fixed	Fixed::operator+(const Fixed &copy) const
{
	Fixed resul;
	
	resul._whole = _whole + copy._whole;
	return(resul);
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	Fixed resul;
	
	resul._whole = _whole - copy._whole;
	return(resul);
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	Fixed	result;

	result._whole = ((long)this->_whole * (long)copy._whole) >> Fixed::_bits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	Fixed	result;

	result._whole = ((long)this->_whole / (long)copy._whole) << Fixed::_bits;
	return (result);
}

/*************************************************************************************/


Fixed	Fixed::operator++(void)
{
	_whole++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	
	_whole++;
	return (temp);
}

Fixed	Fixed::operator--(void)
{
	_whole--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	
	_whole++;
	return (temp);
}

/*************************************************************************************/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return(a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return(a > b ? a : b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	return(a < b ? a : b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	return(a > b ? a : b);
}
