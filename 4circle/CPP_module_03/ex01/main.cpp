/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:23:25 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/08 01:30:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void){
	ClapTrap clap("clap");
	ScavTrap scav("scav");
	std::cout << std::endl;

	scav.guardGate();
	std::cout << std::endl;

	scav.attack("another ClapTrap");
	std::cout << std::endl;

	scav.takeDamage(5); //재정의안한거
	std::cout << std::endl;

	std::cout<<scav.getHp()<<std::endl;
	std::cout<<scav.getEp()<<std::endl;
	std::cout<<scav.getAd()<<std::endl;
	std::cout << std::endl;
	
	return (0);
}