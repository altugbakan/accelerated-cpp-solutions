#include <iostream>
#include "Str.h"

using std::cout;
using std::endl;

int main()
{
    Str s = "Hello, world!";

    // print one char at a time
    for (Str::const_iterator it = s.begin();
         it != s.end(); ++it)
         cout << *it;
    cout << endl;
    return 0;
}