/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:21:46 by sooyang           #+#    #+#             */
/*   Updated: 2023/06/28 00:17:11 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string ft_replace(std::string line, std::string s1, std::string s2){
	for (size_t i = 0; i < line.size(); i++){
		if (line.compare(i, s1.size(), s1) == 0){
			line.erase(i, s1.size());
			line.insert(i, s2);
			i += s2.size() - 1;
		}
	}
	return (line);
}

int main(int ac, char **av){
	std::string s1, s2, infile_name, outfile_name, line;
	std::ifstream infile;
	std::ofstream outfile;

	if(ac!=4)
	{
		std::cout<<"error: wrong input"<<std::endl;
		return (1);
	}
	infile_name=av[1];
	s1=av[2];
	s2=av[3];
	infile.open(av[1]);
	if (infile.is_open())
		std::cout<<"infile successfully opened"<<std::endl;
	else{
		std::cout<<"infile open failed"<<std::endl;
		return (1);
	}
	outfile_name=infile_name+".replace";
	outfile.open(outfile_name.c_str());
	if (outfile.is_open())
		std::cout<<"outfile successfully opened"<<std::endl;
	else{
		std::cout<<"outfile open failed"<<std::endl;
		return (1);
	}
	while (getline(infile, line))
		outfile << ft_replace(line, s1, s2)<<std::endl;
	infile.close();
	outfile.close();
	return (0);
}