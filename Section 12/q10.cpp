#include <iostream>
#include "Str_Vec.h"

using std::cout;
using std::endl;

int main()
{
    Str s1 = "Hello, world!";

    // create new Str from iterators
    Str s2(&s1[0], &s1[5]);
    cout << s2 << endl;
    return 0;
}