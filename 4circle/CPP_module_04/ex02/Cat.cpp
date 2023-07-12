/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:15:16 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/13 02:54:15 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout<<"Cat Default constructor called"<<std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat){
	std::cout<<"Cat Copy constructor called"<<std::endl;
	this->type = cat.type;
	this->brain = new Brain();
	// this->brain = cat.brain;
}

Cat&Cat::operator=(const Cat& cat){
	std::cout<<"Cat Copy assignment operator called"<<std::endl;
	if (this != &cat){
		if (this->brain != NULL)
			delete brain;
		this->type = cat.type;
	}
	this->brain = new Brain(*cat.brain);
	return *this;
}

Cat::~Cat(){
	delete this->brain;
	std::cout<<"Cat Destructor called"<<std::endl;
}

void Cat::makeSound() const{
	std::cout<<"Ma-ah"<<std::endl; 
}

void Cat::printIdeas() const{
	this->brain->getIdeasAddress();
}