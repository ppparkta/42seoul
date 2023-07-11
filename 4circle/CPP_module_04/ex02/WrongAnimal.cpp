/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:25:20 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 02:00:30 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal"){
	std::cout<<"WrongAnimal Default constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrong_animal){
	std::cout<<"WrongAnimal Copy constructor called"<<std::endl;
	this->type = wrong_animal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrong_animal){
	std::cout<<"WrongAnimal Copy assignment operator called"<<std::endl;
	if (this != &wrong_animal)
		this->type = wrong_animal.type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout<<"WrongAnimal Destructor called"<<std::endl;
}

const std::string WrongAnimal::getType() const{
	return this->type;
}

void WrongAnimal::makeSound() const{
	std::cout<<"Common wrong animal sounds"<<std::endl; 
}