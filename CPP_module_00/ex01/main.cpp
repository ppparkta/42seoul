#include "./PhoneBook.hpp"

int main(int ac, char **av)
{
	PhoneBook phonebook;
	std::string input;

	while (!std::cin.eof()){
		std::cout<<"enter command(ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.ADD();
		else if (input == "SEARCH")
			phonebook.SEARCH();
		else if (input == "EXIT")
			phonebook.EXIT();
		else
			std::cout<<"invalid command" << std::endl;
	}
	return (0);
}