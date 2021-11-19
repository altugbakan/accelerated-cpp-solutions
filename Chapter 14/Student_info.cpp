#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"
#include "../Chapter 04/grade.h"

using std::istream;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::min;

// code is taken from §13.1.2/230
string Core::name() const { return n; }

// code is taken from §13.1.2/230
double Core::grade() const
{
    return ::grade(midterm, final, homework);
}

// code is taken from §13.1.2/230
istream& Core::read_common(istream& in)
{
    // read and store the student's name and exam grades
    in >> n >> midterm >> final;
    return in;
}

// code is taken from §13.1.2/230
istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

// code is taken from §13.1.2/230
istream& Grad::read(istream& in)
{
    Core::read_common(in);
    in >> thesis;
    read_hw(in, Core::homework);
    return in;
}

// code is taken from §13.1.2/230
double Grad::grade() const
{
    return min(Core::grade(), thesis);
}

istream& Student_info::read(istream& is)
{
    char ch;
    is >> ch;               // get record type

    if (ch == 'U')
        cp = new Core(is);
    else
        cp = new Grad(is);

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

// code is taken from §13.2/232
bool compare(const Core& c1, const Core& c2)
{
    return c1.name() < c2.name();
}

// code is taken from §13.2.1/234
bool compare_grades(const Core& c1, const Core& c2)
{
    return c1.grade() < c2.grade();
}