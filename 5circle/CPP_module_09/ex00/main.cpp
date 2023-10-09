#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr<<"Error: could not open file."<<std::endl;
		return 1;
	}
	std::string fileName(argv[1]);
	size_t dotPos = fileName.rfind('.');
	if (dotPos == std::string::npos) {
		std::cerr << "Error: Invalid file format. Valid file format -> .txt" << std::endl;
		return 1;
	}
	std::string tmp = fileName.substr(dotPos);
	if (tmp != ".txt") {
		std::cerr << "Error: Invalid file format. Valid file format -> .txt" << std::endl;
		return 1;
	}
	try{
		BitcoinExchange bitcoinExchange("data.csv");
		bitcoinExchange.exchange(fileName);
	}
	catch(const std::exception &e){
		std::cerr<<e.what()<<std::endl;
		return 1;
	}
	return 0;
}