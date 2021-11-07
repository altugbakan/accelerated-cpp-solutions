#include <iostream>
#include <vector>
#include <algorithm>
#include "../Section 6/Student_info.h"
#include "../Section 6/median.h"
#include "../Section 6/grade.h"
#include "../Section 6/analysis.h"

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::domain_error;
using std::vector;
using std::string;

template <class Func>
double analysis_tmp(const vector<Student_info>& students, Func grade_function)
{
    vector<double> grades;

    transform(students.begin(), students.end(),
              back_inserter(grades), grade_function);
    return median(grades);
}

template <class Func>
void write_analysis_tmp(ostream& out, const string& name,
                    Func grade_function,
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis_tmp(did, grade_function)
        << ", median(didnt) = " << analysis_tmp(didnt, grade_function) << endl;
}

int main()
{
    // students who did and didn't do all their homework
    vector<Student_info> did, didnt;

    // read the student records and partition them
    Student_info student;
    // read all student data
    while (read(cin, student)) {
        if (did_all_hw(student)) 
            did.push_back(student);
        else
            didnt.push_back(student);
    }
    
    // verify that the analyses will show us something
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    // do the analyses
    write_analysis_tmp(cout, "median", grade_aux, did, didnt);
    write_analysis_tmp(cout, "average", average_grade, did, didnt);
    write_analysis_tmp(cout, "median of homework turned in",
                       optimistic_median, did, didnt);

    return 0;
}

