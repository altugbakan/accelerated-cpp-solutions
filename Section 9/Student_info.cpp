#include <iostream>
#include <vector>
#include "Student_info.h"
#include "../Section 4/grade.h"

using std::vector;
using std::istream;

Student_info::Student_info(): midterm(0), final(0) { }
Student_info::Student_info(istream& is) { read(is); }

// code is taken from §4.1.3/57
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // get rid of previous contetns
        hw.clear();

        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

// code is taken from §9.2.1/157
istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final;
    read_hw(in, homework);
    g = ::grade(midterm, final, homework);
    return in;
}

// code is taken from §9.3.1/162
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}