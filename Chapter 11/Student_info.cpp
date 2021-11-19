#include <iostream>
#include <vector>
#include "Student_info.h"
#include "../Chapter 04/grade.h"

using std::cout;
using std::endl;
using std::istream;
using std::vector;
using std::copy;

Student_info::Student_info(): midterm(0), final(0)
{
    cout << "create" << endl;
}
Student_info::Student_info(istream& is)
{
    cout << "create" << endl;
    read(is); 
}

Student_info::Student_info(const Student_info& s)
{
    cout << "copy" << endl;
    this->n = s.n;
    this->midterm = s.midterm;
    this->final = s.final;
    this->homework = s.homework;
}

Student_info& Student_info::operator=(const Student_info& rhs)
{
    cout << "assign" << endl;
    this->n = rhs.n;
    this->midterm = rhs.midterm;
    this->final = rhs.final;
    copy(rhs.homework.begin(), rhs.homework.end(), this->homework.begin());
    return *this;
}

Student_info::~Student_info()
{
    cout << "destroy" << endl;
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