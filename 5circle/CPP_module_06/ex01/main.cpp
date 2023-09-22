#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data *data = new Data;

	data->str = "aaa";
	data->number = 10;

	std::cout << "Before Data_ptr: " << data << std::endl;
	std::cout << "uint_ptr: " << Serializer::serialize(data) << std::endl;
	std::cout << "After Data_ptr: " << Serializer::deserialize(Serializer::serialize(data)) << std::endl
			  << std::endl;

	std::cout << "test str: " << Serializer::deserialize(Serializer::serialize(data))->str << std::endl;
	std::cout << "test nb: " << Serializer::deserialize(Serializer::serialize(data))->number << std::endl;

	delete data;

	return 0;
}