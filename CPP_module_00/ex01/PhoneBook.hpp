/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:16:30 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/19 23:27:26 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__
#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact[8];
		int index;
		void input(const std::string msg, std::string *input);
		int isValid(const std::string msg);
		void print(int idx);
		void printDtl(int idx);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void ADD(void);
		void SEARCH(void);
		void EXIT(void);
};

#endif