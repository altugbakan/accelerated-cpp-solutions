#include <iostream>
#include <string>
#include "String_list.h"
#include "split.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    // split the sentence into a String_list
    string sentence = "string list test";
    String_list list = split(sentence);

    // print the results
    String_list::iterator it = list.begin();
    cout << "Values: " << *it;
    ++it;
    while (it != list.end()) {
        cout << ", " << *it;
        ++it;
    }
    cout << endl;
}