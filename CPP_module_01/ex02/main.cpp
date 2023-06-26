/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:34:52 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/26 22:24:08 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout<<&str<<std::endl;
	std::cout<<&stringPTR<<std::endl;
	std::cout<<&stringREF<<std::endl;

	std::cout<<str<<std::endl;
	std::cout<<*stringPTR<<std::endl;
	std::cout<<stringREF<<std::endl;
	return (0);
}