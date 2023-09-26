#include "Array.hpp"

int main()
{
	{
		std::cout << "test1" << std::endl;
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
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "test2" << std::endl;
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
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "test3" << std::endl;
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
			std::cerr << e.what() << std::endl;
		}
	}
}