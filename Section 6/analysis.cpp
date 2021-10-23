#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include "analysis.h"

using std::ostream;
using std::vector;
using std::string;
using std::domain_error;
using std::endl;

double analysis(const vector<Student_info>& students,
    double metric(const Student_info&))
{
    vector<double> grades;
    transform(students.begin(), students.end(),
              back_inserter(grades), metric);
    return median(grades);
}

// code is taken from §6.2.4/116
// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
        back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(),
              back_inserter(grades), optimistic_median);
    return median(grades);
}

// code is taken from §6.2.2/113
double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

// code is taken from §6.2.2/113
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(),
              back_inserter(grades), grade_aux);
    return median(grades);
}

// code is taken from §6.2.3/115
double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

// code is taken from §6.2.3/115
double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

// code is taken from §6.2.3/115
double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(),
              back_inserter(grades), average_grade);
    return median(grades);
}

// code is taken from §6.2.1/110
bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0))
        == s.homework.end());
}

// code is taken from §6.2.2/113
void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
                   ", median(didnt) = " << analysis(didnt) << endl;
}

void write_analysis(ostream& out, const string& name,
                    double metric(const Student_info&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did, metric) <<
                   ", median(didnt) = " << analysis(didnt, metric) << endl;
}