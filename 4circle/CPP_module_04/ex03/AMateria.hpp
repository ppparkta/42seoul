/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:09:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 20:29:19 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __A_MATERIA_HPP__
#define __A_MATERIA_HPP__

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type; 
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& amateria);
		virtual AMateria operator =(const AMateria &amateria);
		virtual ~AMateria();
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif