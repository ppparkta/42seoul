/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:50:57 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/07 19:04:09 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAP_TRAP_H__
#define __CLAP_TRAP_H__

#include <iostream>

class ClapTrap {
	private:
		std::string name;
		int hp;
		int ep;
		int ad;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clap);
		ClapTrap& operator =(const ClapTrap &clap);
		~ClapTrap();

		std::string getName() const;
		int getHp() const;
		int getEp() const;
		int getAd() const;
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif