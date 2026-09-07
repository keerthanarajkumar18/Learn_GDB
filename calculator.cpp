#include "calculator.h"
#include <fstream>
#include <iostream>

double applyOperator(double left, char op, double right)
{
    std::ofstream log("calculator.log", std::ios::app);

    log << "Operation: " << left
        << " " << op
        << " " << right << '\n';

    switch (op)
    {
        case '+':
            log << "Addition selected\n";
            return left + right;

        case '-':
            log << "Subtraction selected\n";
            return left - right;

        case '*':
            log << "Multiplication selected\n";
            return left * right;

        case '/':
            log << "Division selected\n";

            if (right == 0)
            {
                log << "ERROR: Division by zero\n";
                return 0;
            }

            return left / right;

        default:
            log << "ERROR: Invalid operator\n";
            return 0;
    }
}

double calculate(double left, char op, double right)
{
    double result = applyOperator(left, op, right);

    double* ptr = &result;

    std::cout << "Pointer value : " << *ptr << "\n" <<"Pointer address : " << ptr <<std::endl;

    std::ofstream log("calculator.log", std::ios::app);
    log << "Result: " << result << '\n';

    return result;
}
