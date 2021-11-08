#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::domain_error;

template <class RandomAccessIterator>
double median(RandomAccessIterator b, RandomAccessIterator e)
{
    size_t size = e - b;
    if (size == 0)
        throw domain_error("median of an empty container");

    sort(b, e);

    size_t mid = size / 2;

    return size % 2 == 0 ? (*(b + mid) + *(b + mid - 1)) / 2.0 : *(b + mid); 
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(4);

    cout << "median is " << median(vec.begin(), vec.end()) << endl;

    return 0;
}