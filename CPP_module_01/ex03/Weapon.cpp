/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:29:26 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/28 00:51:23 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
	std::cout<<this->type<<" is created"<<std::endl;
}

Weapon::~Weapon(void) {
    std::cout<<this->type<<" is deleted"<<std::endl;
}

const std::string &Weapon::getType(void) {
    return this->type;
}

void Weapon::setType(std::string type) {
	std::cout<<this->type<<" changed ";
    this->type = type;
	std::cout<<this->type<<std::endl;
}