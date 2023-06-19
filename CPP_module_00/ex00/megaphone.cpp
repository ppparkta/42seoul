/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:02:00 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/19 23:36:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	std::string	str;

	if (ac < 2)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		for(int i = 1; i < ac; i++)
		{
			str = av[i];
			for(int j = 0; j < str.size(); j++)
				std::cout<<(char)toupper(av[i][j]);
		}
		std::cout<<std::endl;
	}
	return 0;
}