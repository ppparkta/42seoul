/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/29 20:27:02 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {
	private:
		int fixedPointNumber;
		static const int fractionalBits=8;

	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed& operator =(const Fixed&);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif