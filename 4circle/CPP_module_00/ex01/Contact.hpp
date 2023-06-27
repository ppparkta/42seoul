/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:00:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/19 21:57:09 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <iostream>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact(); //생성자
		~Contact(); //소멸자
		void setFirstName(std::string n_first_name);
		void setLastName(std::string n_last_name);
		void setNickname(std::string n_nickname);
		void setPhoneNumber(std::string n_phone_number);
		void setDarkestSecret(std::string n_darkest_secret);
		const std::string getFirstName(void);
		const std::string getLastName(void);
		const std::string getNickname(void);
		const std::string getPhoneNumber(void);
		const std::string getDarkestSecret(void);
};

#endif