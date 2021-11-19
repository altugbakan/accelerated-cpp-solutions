#include <iostream>
#include <string>
#include "String_list.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    // initialize a list
    String_list list;
    list.push_back("test");
    list.push_back("list");
    list.push_back("string");

    // print the values
    String_list::iterator it = list.begin();
    cout << "Values: " << *it;
    ++it;
    while (it != list.end()) {
        cout << ", " << *it;
        ++it;
    }
    cout << endl;

    // print the values reversed
    it = list.end();
    cout << "Values: " << *--it;
    while (it > list.begin()) {
        cout << ", " << *--it;
    }
    cout << endl;

    return 0;
}