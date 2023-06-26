/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:29:32 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 22:47:55 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMAN_A__
#define __HUMAN_A__

#include "./Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack(void);
};

#endif