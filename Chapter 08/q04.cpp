#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class Bi> void reverse(Bi begin, Bi end)
{
    while (begin != end) {
        --end;
        if (begin != end) {
            Bi temp = begin;
            *begin = *end;
            *end = *temp;
            ++begin;
        }
    }
}

int main()
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    reverse(numbers.begin(), numbers.end());

    cout << "Reversed numbers are: " << numbers[0];

    for (vector<int>::const_iterator it = numbers.begin() + 1;
        it != numbers.end(); ++it)
        cout << ", " << *it;
    
    cout << endl;

    return 0;
}