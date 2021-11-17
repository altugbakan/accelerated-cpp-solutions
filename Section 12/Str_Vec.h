#ifndef GUARD_Str
#define GUARD_Str

#include <iostream>
#include <cstring>
#include "Vec.h"

class Str {
    friend std::istream& operator>>(std::istream&, Str&);

public:
    typedef Vec<char>::size_type size_type;

    // default constructor; create an empty Str
    Str() { }

    // create a Str containing n copies of c
    Str(size_type n, char c): data(n, c) { }

    // create a Str from a null-terminated array of char
    Str(const char* cp) {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }

    // create a Str from range denoted by iterators b and e
    template <class In> Str(In b, In e) : data(b, e) { } // Q10

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    size_type size() const { return data.size(); }

    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(),
                  std::back_inserter(data));
        return *this;
    }

private:
    Vec<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
#endif