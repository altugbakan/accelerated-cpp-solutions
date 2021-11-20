#include <iostream>
#include <iterator>
#include <cstring>
#include "Str_Ctr.h"

using std::ostream;
using std::istream;
using std::ostream_iterator;
using std::copy;

// code is taken from §12.3.1/216
ostream& operator<<(ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

// code is taken from §12.3.2/216
istream& operator>>(istream& is, Str& s)
{
    // obliterate existing value(s)
    s.data->clear();

    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ; // nothing to do, except testing the condition
    
    // if still something to read, do so until next whitespace character
    if (is) {
        do s.data->push_back(c);
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

// code is taken from §14.4.1/267
// the key to making Ptr< Vec<char> > work
template<>
Vec<char>* clone(const Vec<char>* vp)
{
    return new Vec<char>(*vp);
}