/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:15:16 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 01:59:23 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	std::cout<<"Dog Default constructor called"<<std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& dog){
	std::cout<<"Dog Copy constructor called"<<std::endl;
	this->type = dog.type;
}

Dog&Dog::operator=(const Dog& dog){
	std::cout<<"Dog Copy assignment operator called"<<std::endl;
	if (this != &dog)
		this->type = dog.type;
	return *this;
}

Dog::~Dog(){
	std::cout<<"Dog Destructor called"<<std::endl;
}

void Dog::makeSound() const{
	std::cout<<"Bowwow"<<std::endl; 
}