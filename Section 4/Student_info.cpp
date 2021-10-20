#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "grade.h"
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

istream& read(istream& is, Student_info& s)
{
    double midterm, final;
    vector<double> homework;
    // read and store the student's name and final grade
    is >> s.name >> midterm >> final;

    // handle end-of-file
    if (is) {
        read_hw(is, homework);
        // save only the final grade
        s.final_grade = grade(midterm, final, homework);
    }
    
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