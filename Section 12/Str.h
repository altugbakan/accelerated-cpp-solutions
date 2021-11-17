#ifndef GUARD_Str
#define GUARD_Str

#include <iostream>
#include <cstring>

class Str {
    friend std::istream& operator>>(std::istream&, Str&);

public:
    typedef size_t size_type;
    typedef char* iterator; // Q7
    typedef const char* const_iterator; // Q7

    // default constructor; create an empty Str
    Str() : value(0), length(0) { }

    // create a Str containing n copies of c
    Str(size_type n, char c) {
        // allocate new memory
        length = n;
        value = new char[length];

        // fill array with c
        for (size_type i = 0; i != length; ++i)
            value[i] = c;
    }

    // create a Str from a null-terminated array of char
    Str(const char* cp) {
        // allocate new memory
        length = std::strlen(cp);
        value = new char[length];

        // copy the char array
        std::copy(cp, cp + length, value);
    }

    // create a Str from another Str
    Str(const Str& s) {
        // allocate new memory
        length = s.length;
        value = new char[length];

        // copy the value
        std::copy(s.value, s.value + s.length, value);
    }

    // deallocate the memory
    ~Str() {
        if (value != 0)
            delete[] value;
    }

    // create a Str from the range denoted by iterators b and e
    template <class In> Str(In b, In e) {
        // allocate new memory
        length = e - b;
        value = new char[length];

        // copy the range
        std::copy(b, e, value);
    }

    char& operator[] (size_type i) { return value[i]; }
    const char& operator[] (size_type i) const { return value[i]; }

    size_type size() const { return length; }

    Str& operator+=(const Str& s) {
        // allocate new memory
        size_type new_length = length + s.length;
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        // obliterate existing value(s)
        if (value != 0)
            delete[] value;

        // copy the Str
        std::copy(s.value, s.value + s.length, new_value + length);
        value = new_value;
        length = new_length;
        return *this;
    }

    Str& operator+=(const char c) {
        // allocate new memory
        size_type new_length = length + 1;
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        // obliterate existing value(s)
        if (value != 0)
            delete[] value;
        
        // append the char
        new_value[length] = c;
        value = new_value;
        length = new_length;
        return *this;
    }

    // Q5
    Str& operator+=(const char* c) {
        // allocate new memory
        size_type new_length = length + strlen(c);
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        // obliterate existing value(s)
        if (value != 0)
            delete[] value;
        
        // append the char
        std::copy(c, c + strlen(c), new_value + length);
        value = new_value;
        length = new_length;
        return *this;
    }

    // Q11
    Str& operator=(const Str& rhs) {
        // check for self-assignment
        if (&rhs != this) {
            // obliterate existing value(s)
            if (value != 0)
                delete[] value;

            length = rhs.length;
            value = new char[length];
            std::copy(rhs.begin(), rhs.end(), value);
        }
        return *this;
    };

    // Q2
    const char* c_str() const { return value + '\0';}
    const char* data() const { return value; }
    void copy(char* p, size_type n) {
        std::copy(value, value + n, p);
    }

    // Q6
    operator bool() const { return length != 0; }

    // Q7
    iterator begin() { return value; }
    iterator end() { return value + length; }
    const_iterator begin() const { return value; }
    const_iterator end() const { return value + length; }

private:
    char* value;
    size_type length;
};

std::ostream& operator<<(std::ostream&, const Str&); // Q9
Str operator+(const Str&, const Str&);
Str operator+(const Str&, const char*); // Q5
Str operator+(const char*, const Str&); // Q11
bool operator<(const Str&, const Str&); // Q3
bool operator>(const Str&, const Str&); // Q3
bool operator<=(const Str&, const Str&); // Q3
bool operator>=(const Str&, const Str&); // Q3
bool operator==(const Str&, const Str&); // Q4
bool operator!=(const Str&, const Str&); // Q4
std::istream& getline(std::istream&, Str&); // Q8
#endif