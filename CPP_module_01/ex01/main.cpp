/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:25:31 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 21:30:14 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie *horde = zombieHorde(10, "sooyang");
	if (!horde){
		std::cout<<"error: fail allocated"<<std::endl;
		return (1);
	}
	delete[] horde;
	return (0);
}