#include "Span.hpp"

int main(void)
{
	{
		std::cout << "test1 (subject)" << std::endl;
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	{
		std::cout << "test2 (addManyNumbers)" << std::endl;
		try
		{
			Span sp = Span(1000);
			sp.addManyNumbers(1000);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;

			Span woop_sp = Span(10);
			woop_sp.addManyNumbers(1000);
			std::cout << woop_sp.shortestSpan() << std::endl;
			std::cout << woop_sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << std::endl;
	}
	{
		std::cout << "test3 (addNumbers)" << std::endl;
		try
		{
			Span tmp_sp(10);
			Span a(10);
			tmp_sp.addManyNumbers(10);
			a.addNumbers(tmp_sp.begin(), tmp_sp.end());

			std::cout << tmp_sp.shortestSpan() << std::endl;
			std::cout << a.shortestSpan() << std::endl;

			std::cout << tmp_sp.longestSpan() << std::endl;
			std::cout << a.longestSpan() << std::endl;

			std::vector<int> tmp_v(5);
			Span b(5);
			for (int i = 0; i < 5; i++)
				tmp_v[i] = i + 1;
			b.addNumbers(tmp_v.begin(), tmp_v.end());

			std::cout << b.shortestSpan() << std::endl;
			std::cout << b.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	return (0);
}