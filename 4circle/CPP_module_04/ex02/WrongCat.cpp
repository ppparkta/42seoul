/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:25:24 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 02:00:59 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat(){
	std::cout<<"WrongCat Default constructor called"<<std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wrong_cat){
	std::cout<<"WrongCat Copy constructor called"<<std::endl;
	this->type = wrong_cat.type;
}

WrongCat& WrongCat::operator=(const WrongCat& wrong_cat){
	std::cout<<"WrongCat Copy assignment operator called"<<std::endl;
	if (this != &wrong_cat)
		this->type = wrong_cat.type;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout<<"WrongCat Destructor called"<<std::endl;
}

void WrongCat::makeSound() const{
	std::cout<<"Ma-ah............"<<std::endl; 
}