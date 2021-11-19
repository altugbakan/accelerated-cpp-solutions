#ifndef GUARD_Str
#define GUARD_Str

#include <iostream>
#include <cstring>
#include "../Chapter 12/Vec.h"
#include "Ptr.h"

class Str {
    friend std::istream& operator>>(std::istream&, Str&);

public:
    Str& operator+=(const Str& s) {
        data.make_unique();
        std::copy(s.data->begin(), s.data->end(),
                  std::back_inserter(*data));
        return *this;
    }

    // interface as before
    typedef Vec<char>::size_type size_type;
    typedef Vec<char>::iterator iterator;
    typedef Vec<char>::const_iterator const_iterator;

    // reimplement constructors to create Ptrs
    Str(): data(new Vec<char>) { }
    Str(const char* cp): data(new Vec<char>) {
        std::copy(cp, cp + std::strlen(cp),
                  std::back_inserter(*data));
    }

    Str(size_type n, char c): data(new Vec<char>(n, c)) { }
    template <class In> Str(In i, In j): data(new Vec<char>) {
        std::copy(i, j, std::back_inserter(*data));
    }

    // call make_unique as necessary
    char& operator[](size_type i) {
        data.make_unique();
        return (*data)[i];
    }
    const char& operator[](size_type i) const { return (*data)[i]; }
    size_type size() const { return data->size(); }
    iterator begin() { return data->begin(); };
    const_iterator begin() const { return data->begin(); };
    iterator end() { return data->end(); };
    const_iterator end() const { return data->end(); };

private:
    // store a Ptr to a vector
    Ptr< Vec<char> > data;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
template<> Vec<char>* clone(const Vec<char>*);
#endif