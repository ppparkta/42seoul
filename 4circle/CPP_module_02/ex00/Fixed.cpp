/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:45:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/05 15:08:18 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static int fractionalBits = 8;

Fixed::Fixed() : fixedPointNumber(0){
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& fixed){
	std::cout<<"Copy constructor called"<<std::endl;
	fixedPointNumber = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixed){
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &fixed) {
            this->fixedPointNumber = fixed.getRawBits();
    }
	return *this;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->fixedPointNumber;
}

void Fixed::setRawBits(int const raw){
	this->fixedPointNumber = raw;
}