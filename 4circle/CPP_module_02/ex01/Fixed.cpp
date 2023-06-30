/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:45:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/30 19:41:36 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static int fractionalBits = 8;

Fixed::Fixed() : fixedPointNumber(0){
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int raw){
	std::cout<<"Int constructor called"<<std::endl;
	this->fixedPointNumber = raw << this->fractionalBits;
}

Fixed::Fixed(const float raw){
	std::cout<<"Float constructor called"<<std::endl;
	this->fixedPointNumber = roundf(raw * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &fixed){
	std::cout<<"Copy constructor called"<<std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed){
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this == &fixed)
		return *this;
	this->fixedPointNumber = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const{
	return this->fixedPointNumber;
}

void Fixed::setRawBits(int const raw){
	this->fixedPointNumber = raw;
}

float Fixed::toFloat(void) const{
	return static_cast<float>(this->fixedPointNumber) / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const{
	return this->fixedPointNumber >> this->fractionalBits;
}

std::ostream &operator <<(std::ostream& os, const Fixed &fixed){
	return os << fixed.toFloat();
}