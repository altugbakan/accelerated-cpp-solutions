#include <iostream>

int main()
{
    // program that asks the user to enter two numbers and
    // tells the user which number is larger than the other.
    int num1, num2;
    
    std::cout << "Enter number 1: ";
    std::cin >> num1;
    std::cout << "Enter number 2: ";
    std::cin >> num2;
    std::cout << "The larger number is: ";

    if (num1 > num2)
        std::cout << num1;
    else
        std::cout << num2;
}