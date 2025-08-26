#include <iostream>

int main() {
    double num1, num2, result;
    char operation;

    std::cout << "Simple Calculator\n";
    std::cout << "------------------\n";

    
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    
    std::cout << "Choose operation (+, -, *, /): ";
    std::cin >> operation;

    
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << result << "\n";
            break;

        case '-':
            result = num1 - num2;
            std::cout << "Result: " << result << "\n";
            break;

        case '*':
            result = num1 * num2;
            std::cout << "Result: " << result << "\n";
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << result << "\n";
            } else {
                std::cout << "Error: Division by zero is undefined.\n";
            }
            break;

        default:
            std::cout << "Invalid operation. Please use +, -, *, or /.\n";
    }

    return 0;
}
