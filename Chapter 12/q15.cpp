#include <iostream>
#include "Str.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Str s;
    
    // read until end-of-file
    while (cin >> s)
        cout << "1: " << s << endl;

    // code will not enter the second loop
    while (cin >> s)
        cout << "2: " << s << endl;
    
    return 0;
}