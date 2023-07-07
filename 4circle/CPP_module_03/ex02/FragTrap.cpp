/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:00:01 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/08 01:30:35 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout<<"FragTrap Default constructor called"<<std::endl;
	this->name="frag_default";
	this->hp=100;
	this->ep=100;
	this->ad=30;
}

FragTrap::FragTrap(std::string name){
	std::cout<<"FragTrap Name constructor called"<<std::endl;
	this->name=name;
	this->hp=100;
	this->ep=100;
	this->ad=30;
}

FragTrap::FragTrap(FragTrap &frag){
	std::cout<<"FragTrap Copy constructor called"<<std::endl;
	*this = frag;
}

FragTrap& FragTrap::operator =(const FragTrap &frag){
	std::cout<<"FragTrap Copy assignment operator called"<<std::endl;
	if (this != &frag)
		*this = frag;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout<<"FragTrap Destructor called"<<std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout<<"positive high fives request!"<<std::endl;
}

void FragTrap::attack(const std::string &target){
	if (this->hp <= 0){
		std::cout<<this->name<<" is dead." << std::endl;
		return;
	}
	if (this->ep <= 0){
		std::cout<<"FragTrap "<<this->name<<" has no energy points left."<<std::endl;
		return;
	}
	this->ep--;
	std::cout<<"FragTrap "<<this->name<<" consumed 1 energy point."<<std::endl;
	std::cout<<"FragTrap "<<this->name<<" attacks "<<target<<", causing "<<this->ad<<" points of damage!"<< std::endl;
}