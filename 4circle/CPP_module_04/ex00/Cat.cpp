/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:15:16 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 02:00:08 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout<<"Cat Default constructor called"<<std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& cat){
	std::cout<<"Cat Copy constructor called"<<std::endl;
	this->type = cat.type;
}

Cat&Cat::operator=(const Cat& cat){
	std::cout<<"Cat Copy assignment operator called"<<std::endl;
	if (this != &cat)
		this->type = cat.type;
	return *this;
}

Cat::~Cat(){
	std::cout<<"Cat Destructor called"<<std::endl;
}

void Cat::makeSound() const{
	std::cout<<"Ma-ah"<<std::endl; 
}