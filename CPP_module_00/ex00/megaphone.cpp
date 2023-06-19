/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:02:00 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/19 22:52:37 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	std::string	s;

	if (ac < 2)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		for(int i = 1; i < ac; i++)
		{
			s = av[i];
			for(int j = 0; j < s.size(); j++)
				std::cout<<(char)toupper(av[i][j]);
		}
		std::cout<<std::endl;
	}
	return 0;
}