#include "iter.hpp"

void func1(char &target)
{
	target = std::toupper(static_cast<char>(target));
}

int main()
{
	{
		std::cout << "test1" << std::endl;
		char arr[3] = {'i', 'v', 'e'};
		::iter(arr, 3, func1);
		std::cout << "arr[0]: " << arr[0] << std::endl;
		std::cout << "arr[1]: " << arr[1] << std::endl;
		std::cout << "arr[2]: " << arr[2] << std::endl << std::endl;
	}
	{
		std::cout << "test2" << std::endl;
		int arr[3] = {0, 1, 2};
		::iter(arr, 3, test_func);
		std::cout << "arr[0]: " << arr[0] << std::endl;
		std::cout << "arr[1]: " << arr[1] << std::endl;
		std::cout << "arr[2]: " << arr[2] << std::endl << std::endl;
	}
	{
		std::cout << "test3" << std::endl;
		char arr[3] = {'i', 'v', 'e'};
		::iter(arr, 3, test_func);
		std::cout << "arr[0]: " << arr[0] << std::endl;
		std::cout << "arr[1]: " << arr[1] << std::endl;
		std::cout << "arr[2]: " << arr[2] << std::endl << std::endl;
	}
}