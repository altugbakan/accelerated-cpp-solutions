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

    // write the frame
    for (vector<string>::const_iterator it = v.begin();
        it != v.end(); ++it)
        cout << *it << endl;
    
    return 0;
}