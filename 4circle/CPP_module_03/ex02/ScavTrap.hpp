/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:23:18 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/08 01:27:29 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAV_TRAP_HPP__
#define __SCAV_TRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scav);
		ScavTrap& operator =(const ScavTrap& scav);
		~ScavTrap();

		void guardGate();
		void attack(const std::string& target);
};

#endif