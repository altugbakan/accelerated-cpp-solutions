#include <iostream>
#include <string>
#include "String_list.h"

using std::cout;
using std::endl;

int main()
{
    // initialize a list
    String_list list;
    list.push_back("test");
    list.push_back("list");
    list.push_back("string");

    // print the values reversed
    cout << "values are: " << list.pop_back();
    while (list.size() > 0)
        cout << ", " << list.pop_back();

    cout << endl;

    return 0;
}