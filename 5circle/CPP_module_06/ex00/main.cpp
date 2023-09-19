#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	int (argc != 2){
		std::cerr<<"exception: not enough arguments"<<std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1].c_str());
	return (0);
}