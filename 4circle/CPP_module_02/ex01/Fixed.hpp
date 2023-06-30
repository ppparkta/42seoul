/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/30 19:24:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int fixedPointNumber;
		static const int fractionalBits=8;

	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &fixed);
		Fixed& operator =(const Fixed &fixed);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator <<(std::ostream& os, const Fixed &fixed);

#endif