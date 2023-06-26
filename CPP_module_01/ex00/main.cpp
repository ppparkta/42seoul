/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:49:26 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 21:25:46 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie *zombie1 = newZombie("sooyang1");
	if (!zombie1) {
		std::cout<<"error: fail allocated"<<std::endl;
		return (1);
	}
	randomChump("sooyang2");
	delete zombie1;
	return (0);
}