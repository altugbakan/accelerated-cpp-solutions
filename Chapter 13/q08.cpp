#include <ios>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Student_info.h"

using std::streamsize;
using std::setprecision;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::max;
using std::domain_error;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), Student_info::compare);

    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double grade = students[i].grade();
            string letter_grade = students[i].letter_grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << grade << "\t" << letter_grade
                 << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}