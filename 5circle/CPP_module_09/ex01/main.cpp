#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr<< "error: no enought arguments\n";
		return 1;
	}
	try{
		RPN::rpn_calc(argv[1]);	
	} catch(const std::exception &e){
		std::cerr<< e.what() << std::endl;
		return 1;
	}
	return 0;
}