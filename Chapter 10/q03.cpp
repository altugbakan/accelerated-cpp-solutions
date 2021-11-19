#include <iostream>
#include <vector>
#include "q02.cpp"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    // initialize the array
    double double_arr[] = {
        7.5, 2.2, 1.5, 6.4, 4.9, 5.8, 9.4
    };
    size_t double_arr_length = sizeof(double_arr) / sizeof(*double_arr);

    // initialize the vector from the array
    vector<double> double_vec(double_arr, double_arr + double_arr_length);

    // print the initial values of the array
    cout << "Initial values of the array: " << double_arr[0];
    for (size_t i = 1; i < double_arr_length; ++i)
        cout << ", " << double_arr[i];

    // print the initial values of the vector
    cout << endl << "Initial values of the vector: " << double_vec[0];
    for (size_t i = 1; i < double_vec.size(); ++i)
        cout << ", " << double_vec[i];
    
    // print the median values
    cout << endl << "The median value for the array: "
        << median<double>(double_arr, double_arr + double_arr_length);
    cout << endl << "The median value for the vector: "
        << median<double>(double_vec.begin(), double_vec.end()) << endl;

    // print the final values of the array
    cout << "Final values of the array: " << double_arr[0];
    for (size_t i = 1; i < double_arr_length; ++i)
        cout << ", " << double_arr[i];

    // print the final values of the vector
    cout << endl << "Final values of the vector: " << double_vec[0];
    for (size_t i = 1; i < double_vec.size(); ++i)
        cout << ", " << double_vec[i];

    return 0;
}