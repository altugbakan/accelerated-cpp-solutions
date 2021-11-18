#include <iostream>
#include <string>
#include "Vec.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    const string s = "Hello, world!";
    Vec<char> v(s.begin(), s.end());

    // print all values
    for (Vec<char>::const_iterator it = v.begin();
        it != v.end(); ++it)
        cout << *it;
    cout << endl;

    return 0;
}