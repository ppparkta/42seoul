/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 02:25:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 02:53:18 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class Brain {
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		Brain& operator =(const Brain &brain);
		~Brain();

		void getIdeasAddress() const;
};

#endif