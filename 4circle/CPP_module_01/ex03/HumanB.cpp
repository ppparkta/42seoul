/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:29:31 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/28 19:53:49 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
	std::cout<<this->name<<"(HumanB) is here"<<std::endl;
}

HumanB::~HumanB(void){
	std::cout<<this->name<<"(HumanB) is gone"<<std::endl;
}

void HumanB::attack(void){
	std::cout<<this->name<<" attacks with their "<<this->weapon->getType()<<std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	std::cout<<this->name<<"'s weapon is setted ";
	this->weapon = &weapon;
	std::cout<<this->weapon->getType()<<std::endl;
}