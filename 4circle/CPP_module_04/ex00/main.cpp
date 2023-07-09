/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:21:33 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/10 02:14:29 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout<<std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout<<std::endl;

		delete i;
		delete j;
		delete meta;
	}
	std::cout << std::endl << "--------------------------" <<std::endl<<std::endl;
	{
		const Cat cat;
		Animal meta;
		meta = cat;

		std::cout << std::endl << meta.getType() << " " <<std::endl;	
		meta.makeSound();
		std::cout<<std::endl;
	}
	std::cout << std::endl << "--------------------------" <<std::endl<<std::endl;
	{
		const Cat cat;
		const Animal meta(cat);

		std::cout << std::endl << meta.getType() << " " <<std::endl;	
		meta.makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl << "--------------------------" <<std::endl<<std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();

		std::cout<<std::endl;
		std::cout<<cat->getType()<<std::endl;
		meta->makeSound();
		cat->makeSound();
		std::cout<<std::endl;

		delete cat;
		delete meta;
	}
	return 0;
}