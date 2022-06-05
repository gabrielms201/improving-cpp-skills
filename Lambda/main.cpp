#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
/*
[a, &b]   -> Where a is captured by copy and b is captured by reference.
[this]    -> Captures the current object.
[&]       -> Captures all automatic variables used in the body of the lambda by REFERENCE and current object by reference if exists.
[=]       -> Captures all automatic variables used in the body of the lambda by COPY and current object by reference if exists.
[]        -> Captures nothing.
ref: https://en.cppreference.com/w/cpp/language/lambda#Lambda_capture
*/

void ForEach(std::vector<int>& values, std::function<void(int)> fun)
{
	for (int& value : values)
	{
		fun(value);
	}
}

void Example1()
{
	// Declaring Lambda inside the function
	std::cout << "-----------" << std::endl;
	std::vector<int> values = { 1,1,2,3,5,8 };
	std::cout << "Lambda Example 1: " << std::endl;
	ForEach(values,
		[](int value)
		{
			std::cout << "Value: " << value << std::endl;
		});
	std::cout << "-----------" << std::endl;
}
void Example2()
{
	// Declaring Lambda Before
	std::cout << "-----------" << std::endl;
	std::vector<int> values = { 1,1,2,3,5,8 };
	// For instance, we want to acess the "a" variable inside the lambda function.
	// How do we do that? We can solve it by capturing it in the lambda declaration (inside the brackets)
	const char* valueString = "Value: ";
	auto lambda = [=](int value) { std::cout << valueString << value << std::endl;  };
	// If we want to change the value of valueString, then we should use the "mutable" keyword:
	auto lambdaMutable = [=](int value) mutable { valueString = "Content: ";  std::cout << valueString << value << std::endl; };
	std::cout << "Lambda Example 2: " << std::endl;
	ForEach(values, lambda);
	std::cout << "-----------" << std::endl;
}

void Example3()
{
	// find_if example:
	std::cout << "-----------" << std::endl;
	std::vector<int> values = { 1,1,2,3,5,8 };

	auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 2; });

	auto lambda = [&](std::vector<int>::iterator it)
	{
		while (it != values.end())
		{
			std::cout << "Value: " << * it << std::endl;
			it++;
		}
	};
	std::cout << "Lambda Example 3: " << std::endl;
	lambda(it);
	std::cout << "-----------" << std::endl;
}

//
int main()
{
	Example1();
	Example2();
	Example3();
	return 0;
}