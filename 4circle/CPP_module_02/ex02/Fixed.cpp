/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:45:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/05 19:11:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static int fractionalBits = 8;

Fixed::Fixed() : fixedPointNumber(0){
	//std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int raw){
	//std::cout<<"Int constructor called"<<std::endl;
	this->fixedPointNumber = raw << this->fractionalBits;
}

Fixed::Fixed(const float raw){
	//std::cout<<"Float constructor called"<<std::endl;
	this->fixedPointNumber = roundf(raw * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &fixed){
	//std::cout<<"Copy constructor called"<<std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed){
	//std::cout<<"Copy assignment operator called"<<std::endl;
	if (this == &fixed)
		return *this;
	this->fixedPointNumber = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	//std::cout<<"Destructor called"<<std::endl;
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

bool Fixed::operator <(const Fixed &fixed) const{
	return this->fixedPointNumber < fixed.getRawBits();
}

bool Fixed::operator >(const Fixed &fixed) const{
	return this->fixedPointNumber > fixed.getRawBits();
}

bool Fixed::operator <=(const Fixed &fixed) const{
	return this->fixedPointNumber <= fixed.getRawBits();
}

bool Fixed::operator >=(const Fixed &fixed) const{
	return this->fixedPointNumber >= fixed.getRawBits();
}

bool Fixed::operator ==(const Fixed &fixed) const{
	return this->fixedPointNumber == fixed.getRawBits();
}

bool Fixed::operator !=(const Fixed &fixed) const{
	return this->fixedPointNumber != fixed.getRawBits();
}

Fixed Fixed::operator +(const Fixed &fixed) const{
	Fixed return_fixed(this->toFloat()+fixed.toFloat());
	return return_fixed;
}

Fixed Fixed::operator -(const Fixed &fixed) const{
	Fixed return_fixed(this->toFloat()-fixed.toFloat());
	return return_fixed;
}

Fixed Fixed::operator *(const Fixed &fixed) const{
	Fixed return_fixed(this->toFloat()*fixed.toFloat());
	return return_fixed;
}

Fixed Fixed::operator /(const Fixed &fixed) const{
	Fixed return_fixed(this->toFloat()/fixed.toFloat());
	return return_fixed;
}

Fixed& Fixed::operator ++(){
	this->fixedPointNumber += 1;
	return *this;
}

Fixed& Fixed::operator --(){
	this->fixedPointNumber -= 1;
	return *this;
}

Fixed Fixed::operator ++(int){
	Fixed fixed(*this);
	++(*this);
	return fixed;
}

Fixed Fixed::operator --(int){
	Fixed fixed(*this);
	--(*this);
	return fixed;
}

static Fixed &min(Fixed &fixed1, Fixed &fixed2){
	if (fixed1 >= fixed2)
		return fixed2;
	else
		return fixed1;
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 <= fixed2)
		return fixed1;
	else
		return fixed2;
}

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2){
	if (fixed1 >= fixed2)
		return fixed1;
	else
		return fixed2;
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2){
	if (fixed1 <= fixed2)
		return fixed2;
	else
		return fixed1;
}

std::ostream &operator <<(std::ostream& os, const Fixed &fixed){
	return os << fixed.toFloat();
}