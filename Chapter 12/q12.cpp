#include <iostream>
#include "Str_Vec.h"

using std::cout;
using std::endl;

int main()
{
    Str s1 = "Hello, !";
    Str s2 = "world";
    s1.insert(s1.begin() + 7, s2.begin(), s2.end());
    cout << s1 << endl;
    return 0;
}