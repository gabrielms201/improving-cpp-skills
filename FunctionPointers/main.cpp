#include <iostream>
#include <vector>

// How to use it:
int Sum(int a, int b)
{
	return a + b;
}
void SumExample()
{
	std::cout << "-----------" << std::endl;
	std::cout << "Sum Example: " << std::endl;
	// Without using typedef
	{
		int(*test)(int a, int b) = Sum;
		std::cout << "Without typedef: " << test(1, 1) << std::endl;
	}
	// Using Typedef
	{
		typedef int(*test)(int a, int b);
		test fun = Sum;
		std::cout << "With Typedef: " << fun(2, 3) << std::endl;
	}
	// Using "auto" keyword
	{
		auto func = Sum;
		std::cout << "Using \"auto\" keyword: " << func(5, 8) << std::endl;
	}
	std::cout << "-----------" << std::endl;
}

// "Real Life" (useful) usage example:
void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}
void ForEach(std::vector<int>& values, void(*fun)(int number))
{
	for (int& value : values)
	{
		fun(value);
	}
}
void Example()
{
	std::cout << "-----------" << std::endl;
	std::vector<int> values = { 1,1,2,3,5,8 };
	// Example Declaring the print function
	{
		std::cout << "Example Declaring func: " << std::endl;
		ForEach(values, PrintValue);
	}
	// Example Without Declaring the print function (lambda)
	{
		std::cout << "Example without declaring it (lambda): " << std::endl;
		ForEach(values, [](int value)
			{
				std::cout << "Value: " << value << std::endl;
			});
	}
	std::cout << "-----------" << std::endl;
}

//
int main()
{
	SumExample();
	Example();
	return 0;
}