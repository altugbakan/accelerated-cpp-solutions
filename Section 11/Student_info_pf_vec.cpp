#include <iostream>
#include "Student_info_pf_vec.h"

using std::istream;

Student_info::Student_info(): midterm(0), final(0) { }
Student_info::Student_info(istream& is) { read(is); }

istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

char Student_info::grade() const
{
    return ((midterm + final) / 2) > 60 ? 'P' : 'F';
}

// code is taken from §9.3.1/162
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}