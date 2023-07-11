/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:25:26 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/11 19:03:22 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_CAT_HPP__
#define __WRONG_CAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &wrong_cat);
		WrongCat& operator =(const WrongCat &wrong_cat);
		~WrongCat();

		void makeSound(void) const;
};

#endif