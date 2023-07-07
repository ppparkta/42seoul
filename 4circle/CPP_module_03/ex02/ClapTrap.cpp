/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:51:00 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/08 00:43:33 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():hp(10), ep(10), ad(0){
	std::cout<<"ClapTrap Default constructor called"<<std::endl;
	this->name = "clap_default";
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), ep(10), ad(0){
	std::cout<<"ClapTrap Name constructor called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap){
	std::cout<<"ClapTrap Copy constructor called"<<std::endl;
	*this=clap;
}

ClapTrap& ClapTrap::operator =(const ClapTrap &clap){
	std::cout<<"ClapTrap Copy assignment operator called"<<std::endl;
	if (this != &clap){
		this->name = clap.name;
		this->hp = clap.hp;
		this->ep = clap.ep;
		this->ad = clap.ad;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout<<"ClapTrap Destructor called"<<std::endl;
}

std::string ClapTrap::getName() const{
	return this->name;
}

int ClapTrap::getHp() const{
	return this->hp;
}

int ClapTrap::getEp() const{
	return this->ep;
}

int ClapTrap::getAd() const{
	return this->ad;
}

void ClapTrap::attack(const std::string& target){
	if (this->hp <= 0){
		std::cout<<this->name<<" is dead." << std::endl;
		return;
	}
	if (this->ep <= 0){
		std::cout<<"ClapTrap "<<this->name<<" has no energy points left."<<std::endl;
		return;
	}
	this->ep--;
	std::cout<<"ClapTrap "<<this->name<<" consumed 1 energy point."<<std::endl;
	std::cout<<"ClapTrap "<<this->name<<" attacks "<<target<<", causing "<<this->ad<<" points of damage!"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hp <= amount)
		amount = this->hp;
	this->hp -= amount;
	std::cout<<"ClapTrap "<<this->name<<" take "<<amount<<" damage"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->hp <= 0){
		std::cout<<this->name<<" is dead"<< std::endl;
		return;
	}
	if (this->ep <= 0){
		std::cout<<"ClapTrap "<<this->name<<" has no energy points left."<<std::endl;
		return;
	}
	this->ep--;
	this->hp += amount;
	std::cout<<"ClapTrap "<<this->name<<" repairs it self by "<< amount<<" hit points!"<<std::endl;
}