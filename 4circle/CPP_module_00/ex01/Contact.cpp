/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:39:39 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/19 22:31:39 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

Contact::Contact(){
	first_name="(empty)";
	last_name="(empty)";
	nickname="(empty)";
	phone_number="(empty)";
	darkest_secret="(empty)";
}

Contact::~Contact(){};

const std::string Contact::getFirstName(void){
	return first_name;
}

const std::string Contact::getLastName(void){
	return last_name;
}

const std::string Contact::getNickname(void){
	return nickname;
}

const std::string Contact::getPhoneNumber(void){
	return phone_number;
}

const std::string Contact::getDarkestSecret(void){
	return darkest_secret;
}

void Contact::setFirstName(std::string n_first_name){
	first_name = n_first_name;
}

void Contact::setLastName(std::string n_last_name){
	last_name = n_last_name;
}

void Contact::setNickname(std::string n_nickname){
	nickname = n_nickname;
}

void Contact::setPhoneNumber(std::string n_phone_number){
	phone_number = n_phone_number;
}

void Contact::setDarkestSecret(std::string n_darkest_name){
	darkest_secret = n_darkest_name;
}