/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:53:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 21:22:21 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void setName(std::string name);
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif