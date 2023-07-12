/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 02:49:50 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/13 02:41:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void leak()
{
	system("leaks I_don’t_want_to_set_the_world_on_fire");
}

int main()
{
	atexit(leak);
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout<<std::endl;

	delete i;
	delete j;//should not create a leak

	std::cout<<std::endl<<"------------"<<std::endl<<std::endl;
	
	Animal	*zoo[100];

	for (int i = 0; i < 100; i++)
	{
		if (i<50)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
		delete zoo[i];

	std::cout<<std::endl<<"------------"<<std::endl<<std::endl;

	Cat cat;
	Cat* testCat = new Cat(cat);

	std::cout<<std::endl;

	cat.printIdeas();
	testCat->printIdeas();

	std::cout<<std::endl;

	delete testCat;

	std::cout<<std::endl<<"------------"<<std::endl<<std::endl;
	{
		Cat a;
		a.printIdeas();
		std::cout<<std::endl;
		Cat b;
		b.printIdeas();
		std::cout<<std::endl;

		a = b;
		a.printIdeas();
		std::cout<<std::endl;
	}
	

	return (0);
}