/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:07:03 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 21:22:51 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout<<"hi "<<this->name<<" zombie :)"<<std::endl;
}

Zombie::~Zombie(){
	std::cout<<"bye zombie: "<<this->name<<"!"<<std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}

void Zombie::announce(void){
	std::cout<<this->name<<": BraiiiiinnnzzZ..."<<std::endl;
}
