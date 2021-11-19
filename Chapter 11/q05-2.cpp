#include <iostream>
#include <vector>
#include "Student_info.h"
#include "../Chapter 06/analysis.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

// code is taken from §6.2.2/114
int main()
{
    // students who did and didn't do all their homework
    vector<Student_info> did, didnt;

    // read the student records and partition them
    Student_info student;
    // read all student data
    while (student.read(cin)) {
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
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in",
                   optimistic_median, did, didnt);

    return 0;
}