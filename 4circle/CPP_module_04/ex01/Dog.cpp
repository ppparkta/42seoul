/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:15:16 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/13 02:47:24 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	std::cout<<"Dog Default constructor called"<<std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog){
	std::cout<<"Dog Copy constructor called"<<std::endl;
	this->type = dog.type;
	this->brain = new Brain();
}

Dog&Dog::operator=(const Dog& dog){
	std::cout<<"Dog Copy assignment operator called"<<std::endl;
	if (this != &dog){
		if (this->brain != NULL)
			delete brain;
		this->brain = dog.brain;
		this->type = dog.type;
	}
	this->brain = new Brain(*dog.brain);
	return *this;
}

Dog::~Dog(){
	delete this->brain;
	std::cout<<"Dog Destructor called"<<std::endl;
}

void Dog::makeSound() const{
	std::cout<<"Bowwow"<<std::endl; 
}

void Dog::printIdeas() const{
	this->brain->getIdeasAddress();
}