/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:16:49 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 21:32:01 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	Zombie *horde = new Zombie[N];
	if (!horde)
		return (0);
	for (int i=0;i<N;i++){
		horde[i].setName(name);
		horde[i].announce();
	}
	return horde;
}