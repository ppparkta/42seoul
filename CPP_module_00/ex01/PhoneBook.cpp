/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:39:32 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/19 22:32:22 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){ 
	index = 0;
}

PhoneBook::~PhoneBook(){ }

int PhoneBook::isValid(const std::string msg){
	for (int i=0; i<msg.size(); i++)
	{
		if (std::isdigit(msg[i]) == 0)
			return 0;
	}
	return 1;
}

void PhoneBook::print(int idx){
	std::cout << std::setw(10) << idx;
	std::cout << "|";
	if (this->contact[idx].getFirstName().size() >= 10)
		std::cout << std::setw(9) << this->contact[idx].getFirstName().substr(0,9) << '.';
	else
		std::cout << std::setw(10) << this->contact[idx].getFirstName();
	std::cout << "|";
	if (this->contact[idx].getLastName().size() >= 10)
		std::cout << std::setw(9) << this->contact[idx].getLastName().substr(0,9) << '.';
	else
		std::cout << std::setw(10) << this->contact[idx].getLastName();
	std::cout << "|";
	if (this->contact[idx].getNickname().size() >= 10)
		std::cout << std::setw(9) << this->contact[idx].getNickname().substr(0,9) << '.';
	else
		std::cout << std::setw(10) << this->contact[idx].getNickname();
	std::cout << std::endl;
}

void PhoneBook::printDtl(int idx){
	std::cout << "First Name: " << this->contact[idx].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contact[idx].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contact[idx].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contact[idx].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contact[idx].getDarkestSecret() << std::endl;
}

void PhoneBook::input(const std::string msg, std::string *input){
	while (1)
	{
		std::cout<< msg;
		std::getline(std::cin, *input);
		if (std::cin.eof())
			exit(1);
		else if (*input == "") 
			std::cout << "Error: empty field" << std::endl;
		else 
			break;
	}
	
}

void PhoneBook::ADD(void){
	std::string str;

	input("input \"first name\": ", &str);
	this->contact[this->index].setFirstName(str);
	input("input [last name]: ", &str);
	this->contact[this->index].setLastName(str);
	input("input [nickname]: ", &str);
	this->contact[this->index].setNickname(str);
	input("input [phone number]: ", &str);
	this->contact[this->index].setPhoneNumber(str);
	input("input [darkest number]: ", &str);
	this->contact[this->index].setDarkestSecret(str);
	this->index = (this->index + 1) % 8;
}

void PhoneBook::SEARCH(void){
	std::string str;

	std::cout << std::setw(10) << "Index" << "|" << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "NickName" << std::endl;
	for (int i=0; i<8; i++)
		print(i);
	input("select index: ", &str);
	if (isValid(str))
		printDtl(atoi(str.data()));
	else
		std::cout << "invalid index!!!" << std::endl;
}