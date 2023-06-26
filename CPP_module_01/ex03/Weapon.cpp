/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:29:26 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 23:11:21 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
	return ;
}

Weapon::~Weapon(void) {
    std::cout<<this->type<<" is deleted"<<std::endl;
	return ;
}

const std::string &Weapon::getType(void) {
    return this->type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}