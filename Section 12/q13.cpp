#include <iostream>
#include <cstring>
#include "Vec.h"

using std::cout;
using std::endl;

int main()
{
    Vec<char> v;
    char c[] = "Hello, world!";
    v.assign(c, c + strlen(c));
    
    // print all values
    for (Vec<char>::const_iterator it = v.begin();
        it != v.end(); ++it)
        cout << *it;
    cout << endl;

    return 0;
}