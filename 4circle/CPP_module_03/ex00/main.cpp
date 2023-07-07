/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:06:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/07 19:21:09 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Clap1");
    ClapTrap clap2("Clap2");

	for(int i =0;i<11;i++){
		std::cout<<i+1<<"번째 공격!"<<std::endl;
    	clap1.attack("Clap2");
		std::cout<<std::endl;
	}
	
	std::cout<<clap2.getName()<<"은 데미지를 받았다!"<<std::endl;
	clap2.takeDamage(0);
	std::cout<<std::endl;

	std::cout<<clap2.getName()<<"은 치유됐다!"<<std::endl;
    clap2.beRepaired(10);
	std::cout<<std::endl;

	std::cout<<clap1.getName()<<"의 현재 상태"<<std::endl;
	std::cout<<"hp: "<<clap1.getHp()<<std::endl<<"ep: "<<clap1.getEp()<<std::endl<<"ad: "<<clap1.getAd()<<std::endl<<std::endl;

	std::cout<<clap2.getName()<<"의 현재 상태"<<std::endl;
	std::cout<<"hp: "<<clap2.getHp()<<std::endl<<"ep: "<<clap2.getEp()<<std::endl<<"ad: "<<clap2.getAd()<<std::endl;

    return 0;
}