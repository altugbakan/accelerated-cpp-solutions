#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
    vector<double> doubles;

    // ask the for double input
    cout << "Enter doubles, followed by end-of-file: " << endl;

    double d;
    while (cin >> d)
    {
        doubles.push_back(d);
    }

    // find the average of the numbers stored in the vector
    double total = 0;
    double count = doubles.size();
    for (vector<double>::size_type i = 0; i < count; ++i) {
        total += doubles[i];
    }
    
    cout << "The average is: " << total / count << endl;
}