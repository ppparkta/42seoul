/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:23:20 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/08 01:32:21 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout<<"ScavTrap Default constructor called"<<std::endl;
	this->name = "scav_default";
	this->hp=100;
	this->ep=50;
	this->ad=20;
}

ScavTrap::ScavTrap(std::string name){
	std::cout<<"ScavTrap Name constructor called"<<std::endl;
	this->name = name;
	this->hp=100;
	this->ep=50;
	this->ad=20;
}

ScavTrap::ScavTrap(const ScavTrap& scav){
	std::cout<<"ScavTrap Copy constructor called"<<std::endl;
	*this = scav;
}

ScavTrap& ScavTrap::operator =(const ScavTrap& scav){
	std::cout<<"ScavTrap Copy assignment operator called"<<std::endl;
	if (this != &scav)
		*this = scav;
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout<<"ScavTrap Destructor called"<<std::endl;
}

void ScavTrap::guardGate(){
	std::cout<<"ScavTrap is now in Gate keeper mode."<<std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->hp <= 0){
		std::cout<<this->name<<" is dead." << std::endl;
		return;
	}
	if (this->ep <= 0){
		std::cout<<"ScavTrap "<<this->name<<" has no energy points left."<<std::endl;
		return;
	}
	this->ep--;
	std::cout<<"ScavTrap "<<this->name<<" consumed 1 energy point."<<std::endl;
	std::cout<<"ScavTrap "<<this->name<<" attacks "<<target<<", causing "<<this->ad<<" points of damage!"<< std::endl;
}