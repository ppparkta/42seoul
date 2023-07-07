/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:59:59 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/08 01:27:31 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAG_TRAP_HPP__
#define __FRAG_TRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &frag);
		FragTrap& operator =(const FragTrap &frag);
		~FragTrap();
		
		void highFivesGuys(void);
		void attack(const std::string &target);
};

#endif