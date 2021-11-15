#include <stdexcept>
#include <iomanip>
#include <iostream>
#include "Vec.h"
#include <string>
#include <algorithm>
#include "Student_info_pf_vec.h"

using std::domain_error;
using std::setprecision;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::max;
using std::streamsize;
using std::sort;

int main()
{
    Vec<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    
    Vec<Student_info> passes, fails;
    for (Vec<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
        if (students[i].grade() == 'F')
            fails.push_back(students[i]);
        else
            (passes.push_back(students[i]));
    }

    // write the names and grades of passing students
    for (Vec<Student_info>::size_type i = 0;
         i != passes.size(); ++i) {
        cout << passes[i].name()
             << string(maxlen + 1 - passes[i].name().size(), ' ');

        streamsize prec = cout.precision();
        cout << setprecision(3) << passes[i].grade()
                << setprecision(prec) << endl;
    }

    // write the names and grades of failing students
    for (Vec<Student_info>::size_type i = 0;
         i != fails.size(); ++i) {
        cout << fails[i].name()
             << string(maxlen + 1 - fails[i].name().size(), ' ');

        streamsize prec = cout.precision();
        cout << setprecision(3) << fails[i].grade()
                << setprecision(prec) << endl;
    }
    return 0;
}