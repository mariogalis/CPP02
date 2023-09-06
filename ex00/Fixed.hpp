/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:50:24 by magonzal          #+#    #+#             */
/*   Updated: 2023/07/11 19:31:35 by magonzal         ###   ########.fr       */
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
		Fixed(std::string name);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed const &operator=(const Fixed &copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:

		int	_whole;
		static int const _bits = 8;
};

#endif