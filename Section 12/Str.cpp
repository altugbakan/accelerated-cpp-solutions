#include <iostream>
#include <iterator>
#include <cstring>
#include "Str.h"

using std::ostream;
using std::istream;
using std::ostream_iterator;
using std::copy;

// Q9
ostream& operator<<(ostream& os, const Str& s)
{
    copy(s.begin(), s.end(), ostream_iterator<char>(os));
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

// code is taken from §12.3.3/219
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

// Q11
Str operator+(const char* t, const Str& s)
{
    Str r(t);
    r += s;
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

// Q8
istream& getline(istream& is, Str& s)
{
    // read until newline
    char c;
    while (is.get(c) && c != '\n')
        s += c;

    return is;
}