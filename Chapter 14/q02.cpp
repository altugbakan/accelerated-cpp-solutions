#include <ios>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Student_info.h"
#include "Ptr.h"
#include "compare_Core_ptrs.h"

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
    vector< Ptr<Core> > students;       // store Ptrs, not objects
    Ptr<Core> record;                   // temporary must be a Ptr as well
    char ch;
    string::size_type maxlen = 0;

    // read and store the data
    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;          // allocate a Core object
        else
            record = new Grad;          // allocate a Grad object
        record->read(cin);              // virtual call
        maxlen = max(maxlen, record->name().size()); // dereference
        students.push_back(record);
    }

    // pass the version of compare that works on Ptrs
    sort(students.begin(), students.end(), compare_Core_ptrs);

    // write the names and grades
    for (vector< Ptr<Core> >::size_type i = 0;
         i != students.size(); ++i) {
        // students[i] is a pointer that we dereference to call the functions
        cout << students[i]->name()
             << string(maxlen + 1 - students[i]->name().size(), ' ');
        try {
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}