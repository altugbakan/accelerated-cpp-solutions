#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Student_info_pf.h"

using std::domain_error;
using std::setprecision;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::max;
using std::streamsize;
using std::sort;

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
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');

        streamsize prec = cout.precision();
        cout << setprecision(3) << students[i].grade()
                << setprecision(prec) << endl;
    }
    return 0;
}