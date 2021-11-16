#include <iostream>
#include "Str.h"

using std::cout;
using std::endl;

int main()
{
    Str s1 = "a";
    Str s2 = "b";
    Str s3 = "c";
    cout << "s1 is " << (s1 > s2 ? "larger" : "smaller") << " than s2" << endl;
    cout << "s3 is " << (s3 < s1 ? "smaller" : "larger") << " than s1" << endl;
    return 0;
}