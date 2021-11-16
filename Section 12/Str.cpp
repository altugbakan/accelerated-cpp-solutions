#include <iostream>
#include <cstring>
#include "Str.h"

using std::ostream;
using std::istream;

ostream& operator<<(ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

istream& operator>>(istream& is, Str& s)
{
    // obliterate existing value(s)
    if (s.value != 0)
        delete[] s.value;

    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ;   // nothing to do, except testing the condition

    // if still something to read, do so until the next whitespace character
    if (is) {
        do s += c;
        while (is.get(c) && !isspace(c));

        // if we read whitespace, then put it back on the stream
        if (is)
            is.unget();
    }

    return is;
}

Str operator+(const Str& s, const Str& t)
{
    Str r = s;
    r += t;
    return r;
}

// Q5
Str operator+(const Str& s, const char* t)
{
    Str r = s;
    r += t;
    return r;
}

// Q3
bool operator<(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

// Q3
bool operator>(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

// Q3
bool operator<=(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

// Q3
bool operator>=(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

// Q4
bool operator==(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

// Q4
bool operator!=(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}