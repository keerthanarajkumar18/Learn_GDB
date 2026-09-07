#include <iostream>
#include "calculator.h"

int main(int argc, char* argv[])
{
	if(argc != 4)
	{
		std::cout << "Usage : ./calculator <number> <operator> <number>\n";
 
		return 1;
	}
	
	double left = std::stod(argv[1]);
	
	char op = argv[2][0];

	double right = std::stod(argv[3]);

	double result = calculate(left, op, right);

	std::cout << "Result: " << result << '\n';

	return 0;
}

