/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 02:30:08 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 02:56:50 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout<<"Brain default constructor"<<std::endl;
}

Brain::Brain(const Brain &brain){
	std::cout<<"Brain copy constructor"<<std::endl;
	*this = brain;
}

Brain& Brain::operator =(const Brain &brain){
	std::cout<<"Brain copy assignment operator"<<std::endl;
	if (this != &brain){
		for (int i=0;i<100;i++)
		this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain(){
	std::cout<<"Brain destructor"<<std::endl;
}

void Brain::getIdeasAddress() const{
	std::cout<<this->ideas<<std::endl;
}