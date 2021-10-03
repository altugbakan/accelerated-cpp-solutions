#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::streamsize;
using std::setprecision;
using std::fixed;

// function that returns the length of a number
// when converted to a string
int get_length(double number, const streamsize& decimal_points)
{
    int length = 1;
    while (number / 10 > 1.0) {
        number /= 10;
        ++length;
    }
    
    return length + decimal_points + 1;
}

int main()
{
    const double max_number = 1000.0;
    const streamsize decimal_points = 2;

    int max_len = get_length(max_number, decimal_points);
    int max_sq = get_length(max_number * max_number, decimal_points);

    for (double i = 1.0; i < max_number; ++i) {
        streamsize prec = cout.precision();
        cout << fixed << setprecision(decimal_points) << setw(max_len) << i <<
            setw(max_sq + 1) << i * i << setprecision(prec) << endl;
    }
}