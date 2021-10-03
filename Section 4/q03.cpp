#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

// function that returns the length of a number
// when converted to a string
int get_length(int number)
{
    int length = 1;
    while (number / 10 > 0) {
        number /= 10;
        ++length;
    }
    
    return length;
}

int main()
{
    const int max_number = 999;

    int max_len = get_length(max_number);
    int max_sq = get_length(max_number * max_number);

    for (int i = 1; i <= max_number; ++i) {
        cout << setw(max_len) << i << setw(max_sq + 1) << i * i << endl;
    }
}