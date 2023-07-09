/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:04:43 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 02:03:41 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal"){
	std::cout<<"Animal Default constructor called"<<std::endl;
}

Animal::Animal(const Animal &animal){
	std::cout<<"Animal Copy constructor called"<<std::endl;
	this->type = animal.type;
}

Animal& Animal::operator =(const Animal &animal){
	std::cout<<"Animal Copy assignment operator called"<<std::endl;
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

Animal::~Animal(){
	std::cout<<"Animal Destructor called"<<std::endl;
}

const std::string Animal::getType() const{
	return this->type;
}

void Animal::makeSound() const{
	std::cout<<"Common animal sounds"<<std::endl; 
}