/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:53:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 21:32:11 by sooyang          ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif 