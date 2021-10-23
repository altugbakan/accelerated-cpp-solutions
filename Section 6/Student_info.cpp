#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::cout;
using std::vector;
using std::istream;
using std::domain_error;
using std::sort;

// code is taken from §4.4/69
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

// code is taken from §4.2.2/62
istream& read(istream& is, Student_info& s)
{
    // read and store the student's name and final grade
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework); // read and store all the student's homework grades
    return is;
}

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