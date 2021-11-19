#include <iostream>
#include "Lis.h"

using std::cout;
using std::endl;

int main()
{
    Lis<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(4);

    for (Lis<int>::iterator it = l.begin();
         it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;    
}