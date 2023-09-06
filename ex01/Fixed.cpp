/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:24:39 by magonzal          #+#    #+#             */
/*   Updated: 2023/09/06 19:51:16 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

  Fixed::Fixed(void) :_whole(0)
  {
        std::cout << "Default constructor called" << std::endl;
  }

  Fixed::Fixed(int const num)