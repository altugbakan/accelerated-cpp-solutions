#include <iostream>
#include "Vec.h"
#include "Student_info_vec.h"
#include "grade.h"

using std::istream;

Student_info::Student_info(): midterm(0), final(0) { }
Student_info::Student_info(istream& is) { read(is); }

istream& read_hw(istream& in, Vec<double>& hw)
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
    return in;
}

// code is taken from §9.3.1/158
double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
}

// code is taken from §9.3.1/162
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}