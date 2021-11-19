#ifndef GUARD_String_list
#define GUARD_String_list

#include <string>

class String_list {
public:
    typedef size_t size_type;
    typedef std::string* iterator; // Question 5
    String_list();
    std::string* begin() const { return values; }
    std::string* end() const { return values + length; }
    size_type size() const { return length; }
    void push_back(std::string);
    std::string pop_back();
private:
    std::string* values;
    size_type length;
};
#endif