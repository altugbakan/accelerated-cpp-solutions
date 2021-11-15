#include <iostream>
#include <ctime>
#include "Vec.h"

using std::cout;
using std::endl;

int main()
{
    const Vec<int>::size_type count = 100000;

    Vec<int> v1, v2;

    // measure the time for doubling memory
    double begin = clock();
    for (Vec<int>::size_type i = 0; i < count; ++i)
        v1.push_back(i);
    double end = clock();
    cout << "Doubling memory and pushing " << count << " integers took "
        << (end - begin) / CLOCKS_PER_SEC << " seconds." << endl;

    // measure the time for growing one by one
    begin = clock();
    for (Vec<int>::size_type i = 0; i < count; ++i)
        v2.push_back_grow_once(i);
    end = clock();
    cout << "Growing memory one by one and pushing " << count
        << " integers took " << (end - begin) / CLOCKS_PER_SEC
        << " seconds." << endl;

    return 0;
}