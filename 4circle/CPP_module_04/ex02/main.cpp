/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 02:49:50 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/13 02:33:47 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void leak()
{
	system("leaks Abstract_class");
}

int main()
{
	atexit(leak);
	//const Animal meta;
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

	return (0);
}