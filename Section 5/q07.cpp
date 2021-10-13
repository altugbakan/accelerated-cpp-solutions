#include <iostream>
#include "frame.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<string> v;
    frame(v);

    // output the frame
    for (vector<string>::const_iterator i = v.begin();
        i != v.end(); ++i)
        cout << *i << endl;
    
    return 0;
}