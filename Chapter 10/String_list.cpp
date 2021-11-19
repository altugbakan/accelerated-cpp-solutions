#include <string>
#include "String_list.h"

using std::string;
using std::copy;

String_list::String_list(): length(0), values(new string[0]) { }

void String_list::push_back(string s)
{
    string* old_values = values;

    // increment the length
    ++length;

    // create a new string array with the new length
    string* new_values = new string[length];

    // copy and delete the old values
    copy(old_values, old_values + length - 1, new_values);
    delete[] old_values;

    // set the new values
    values = new_values;
    values[length - 1] = s;
}

string String_list::pop_back()
{
    string* old_values = values;

    // decrement the length
    --length;

    // hold the return value
    string ret = *end();

    // create a new string array with the new length
    string* new_values = new string[length];

    // copy and delete the old values
    copy(old_values, old_values + length, new_values);
    delete[] old_values;

    // set the new values
    values = new_values;

    return ret;
}