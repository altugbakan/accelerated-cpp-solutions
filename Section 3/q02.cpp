#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

int main()
{
    vector<int> numbers;
    int n;

    // ask for number input
    cout << "Please enter the numbers, followed by end-of-file." << endl;

    // invariant: numbers contains numbers read so far
    while (cin >> n) {
        numbers.push_back(n);
    }

    // sort the numbers
    sort(numbers.begin(), numbers.end());
    
    // get the properties of the vector
    typedef vector<int>::size_type vec_sz;
    vec_sz count = numbers.size();
    int quartile_size = count / 4;
    int quartile_remainder = count % 4;

    // handle not enough numbers condition
    if (count < 4) {
        cout << "You must enter at least 4 numbers." << endl;
        return(1);
    }

    // print the quartiles
    for (vec_sz i = count; i-- > 0; ) {
        if (i == count - 1) {
            cout << "First quartile: ";
        } else if (i == 3 * quartile_size - 1 + quartile_remainder) {
            cout << endl << "Second quartile: ";
        } else if (i == 2 * quartile_size - 1 + (quartile_remainder > 1 ?
            quartile_remainder - 1 : 0)) {
            cout << endl << "Third quartile: ";
        } else if (i == quartile_size - 1 + (quartile_remainder == 3 ? 1 : 0)) {
            cout << endl << "Fourth quartile: ";
        }
        cout << numbers[i] << " ";
    }

    return 0;
}