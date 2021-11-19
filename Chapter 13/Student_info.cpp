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
string Core::name() const {
    // cerr << "Core::name()" << endl; // Q2
    return n;
}

// code is taken from §13.1.2/230
double Core::grade() const
{
    // cerr << "Core::grade()" << endl; // Q2
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

// Q4
string Core::letter_grade() const
{
    // calculate the grade
    double grade = this->grade();

    // range posts for numeric grades
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    // names for the letter grades
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    // compute the number of grades given the size of the array
    // and the size of a single element
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

    // given a numeric grade, find and return the associated letter grade
    for (size_t i = 0; i < ngrades; ++i) {
        if (grade >= numbers[i])
            return letters[i];
    }

    return "?\?\?";
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
    // cerr << "Grad::grade()" << endl; // Q2
    return min(Core::grade(), thesis);
}

// Q6
double PassFail::grade() const
{
    if (homework.empty())
        return (final + midterm) / 2;
    else
        return Core::grade();
}

istream& Student_info::read(istream& is)
{
    delete cp;              // delete previous object, if any

    char ch;
    is >> ch;               // get record type

    if (ch == 'U')
        cp = new Core(is);
    else if (ch == 'G')
        cp = new Grad(is);
    else if (ch == 'P')
        cp = new PassFail(is);
    else                    
        cp = new Audit(is);

    return is;
}

// code is taken from §13.4.2/247
Student_info::Student_info(const Student_info& s): cp(0)
{
    if (s.cp) cp = s.cp->clone();
}

// code is taken from §13.4.2/247
Student_info& Student_info::operator=(const Student_info& s)
{
    if (&s != this) {
        delete cp;
        if (s.cp)
            cp = s.cp->clone();
        else
            cp = 0;
    }
    return *this;
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