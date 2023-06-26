/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:29:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 22:57:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef __HUMAN_B__
#define __HUMAN_B__
#include "./Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif