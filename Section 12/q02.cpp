#include <iostream>
#include "Str.h"

using std::cout;
using std::endl;

int main()
{
    Str s = "Hello, world!";
    cout << s.c_str() << endl;
    cout << s.data() << endl;
    
    // copy the first 5 characters
    char msg[6];
    s.copy(msg, 5);

    // add null terminating byte
    msg[5] = '\0';
    cout << msg << endl;
    return 0;
}