#include <iostream>
#include <string>

// A simple function that returns the larger of two numbers
int findMax(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    // 1. Printing output to the console
    std::cout << "--- Welcome to the C++ Example Program ---" << std::endl;

    // 2. Variables and user input
    std::string userName;
    int firstNumber = 0;
    int secondNumber = 0;

    std::cout << "Enter your name: ";
    std::getline(std::cin, userName); // Reads a full line of text

    std::cout << "Enter first whole number: ";
    std::cin >> firstNumber;

    std::cout << "Enter second whole number: ";
    std::cin >> secondNumber;

    // 3. Performing operations and calling a function
    int sum = firstNumber + secondNumber;
    int maxNumber = findMax(firstNumber, secondNumber);

    // 4. Displaying the results
    std::cout << "\nHello, " << userName << "!" << std::endl;
    std::cout << "The sum of your numbers is: " << sum << std::endl;
    std::cout << "The larger number is: " << maxNumber << std::endl;

    return 0; // Signals that the program executed successfully
}
