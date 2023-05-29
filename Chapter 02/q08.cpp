#include <iostream>

int main()
{
    int product = 1;
    // get the product of the numbers in the range [1, 10).
    for (int i = 1; i < 10; i++)
        product *= i;

    std::cout << product << std::endl;

    return 0;
}