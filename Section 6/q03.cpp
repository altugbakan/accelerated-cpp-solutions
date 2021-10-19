#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    // the code throws an error if we use v.begin()
    // copy(u.begin(), u.end(), v.begin());
    copy(u.begin(), u.end(), front_inserter(v));

    // output the contents
    cout << "u has:" << endl;
    for (vector<int>::const_iterator i = u.begin(); i != u.end(); ++i)
        cout << *i << " ";
    cout << endl << endl;

    cout << "v has:" << endl;
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
}