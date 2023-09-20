#pragma once
#ifndef __SERIALIZATION_HPP__
#define __SERIALIZATION_HPP__

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& rhs);
		~Serializer();
	public:
		static Data* deserialize(uintptr_t data);
		static uintptr_t serialize(Data* ptr);
};

#endif