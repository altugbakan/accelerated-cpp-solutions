#include <iostream>
#include "Str.h"

using std::cout;
using std::endl;

int main()
{
    Str s1 = "Hello, world!";
    Str s2 = "Goodbye, world!";
    Str s3 = "Hello, world!";
    cout << "s1 and s2 are " << (s1 == s2 ? "equal" : "not equal") << endl;
    cout << "s1 and s3 are " << (s1 == s3 ? "equal" : "not equal") << endl;
    return 0;
}