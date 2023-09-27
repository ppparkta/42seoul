#include "Array.hpp"
#define MAX_VAL 5

int main()
{
	{
		std::cout << "test1 (INT)" << std::endl;
		// int 테스트
		Array<int> int_arr(3);
		for (int i = 0; i < 3; i++)
		{
			int_arr[i] = i + 1;
		}
		std::cout << int_arr << std::endl;

		// 복사생성연산자 테스트
		Array<int> int_copy_arr(int_arr);
		std::cout << int_copy_arr << std::endl;

		// int 예외처리
		try
		{
			std::cout << int_arr[3] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout << "test2 (DOUBLE)" << std::endl;
		// double 테스트
		Array<double> double_arr(3);
		Array<double> double_equal_arr(3);
		for (int i = 0; i < 3; i++)
		{
			double_arr[i] = i + 4.2;
			double_equal_arr[i] = i + 1.1;
		}
		std::cout << double_arr << std::endl;

		// 대입연산자 테스트
		std::cout << double_equal_arr << std::endl;
		double_equal_arr = double_arr;
		std::cout << double_equal_arr << std::endl;

		// double 예외처리
		try
		{
			std::cout << double_arr[3] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout << "test3 (STRING)" << std::endl;
		// string 테스트
		Array<std::string> str_arr(3);
		str_arr[0] = "number 1";
		str_arr[1] = "number 2";
		str_arr[2] = "number 3";
		std::cout << str_arr << std::endl;

		// string 예외처리
		try
		{
			std::cout << str_arr[3] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
		// -인덱스 예외처리
		try
		{
			std::cout << str_arr[-1] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
	}
}

// int main(void)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 		std::cout << "numbers: " << numbers[i] << std::endl;
// 		std::cout << "mirror: " << mirror[i] << std::endl;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 		std::cout << "tmp: " << tmp;
// 		std::cout << "test: " << test;
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 		std::cout << "numbers: " << numbers[i] << std::endl;
// 		std::cout << "mirror: " << mirror[i] << std::endl;
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;
// 	return 0;
// }