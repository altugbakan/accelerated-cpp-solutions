#include <iostream>
#include <ctime>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> u(1000000, 100);
    
    // calculate the time for copying
    double begin_copy = clock();
    vector<int> v(u);
    double end_copy = clock();

    // clear vector for the next test
    v.clear();

    // calculate the time for back inserter
    double begin_back = clock();
    copy(u.begin(), u.end(), back_inserter(v));
    double end_back = clock();

    // output the results
    cout << "copying took " << (end_copy - begin_copy) /
        CLOCKS_PER_SEC << " seconds for " << u.size() << " items.";

    cout << "back_inserter took " << (end_back - begin_back) /
        CLOCKS_PER_SEC << " seconds for " << u.size() << " items." << endl;

    return 0;
}