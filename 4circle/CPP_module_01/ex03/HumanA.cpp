/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:29:33 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/28 00:49:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon){
	this->name = name;
	this->weapon = &weapon;
	std::cout<<this->name<<"(HumanA) is here"<<std::endl;
}

HumanA::~HumanA(void){
	std::cout<<this->name<<"(HumanA) is gone"<<std::endl;
}

void HumanA::attack(void){
	std::cout<<this->name<<" attacks with their "<<this->weapon->getType()<<std::endl;
}