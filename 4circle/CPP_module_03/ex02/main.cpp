/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:15:12 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/08 01:32:11 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frag("frag");
	std::cout << std::endl;
	
	frag.attack("another FragTrap");
	std::cout << std::endl;

	frag.takeDamage(5);

	frag.getHp();
	frag.getEp();
	frag.getAd();
	std::cout << std::endl;

	frag.highFivesGuys();
	std::cout << std::endl;

	std::cout<<frag.getHp()<<std::endl;
	std::cout<<frag.getEp()<<std::endl;
	std::cout<<frag.getAd()<<std::endl;
	std::cout << std::endl;

	return (0);
}