#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data *data = new Data;

	data->str = "aaa";
	data->number = 10;

	std::cout << "test str: " << Serializer::deserialize(Serializer::serialize(data))->str << std::endl;
	std::cout << "test nb: " << Serializer::deserialize(Serializer::serialize(data))->number << std::endl;

	delete data;

	return 0;
}