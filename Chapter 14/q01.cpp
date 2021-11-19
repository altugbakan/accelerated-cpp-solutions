#include <iostream>
#include <vector>
#include <algorithm>
#include "Student_info.h"
#include "Ptr.h"
#include "compare_Core_ptrs.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

int main()
{
    vector< Ptr<Core> > students;       // store Ptrs, not objects
    Ptr<Core> record;                   // temporary must be a Ptr as well
    char ch;

    // read and store the data
    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;          // allocate a Core object
        else
            record = new Grad;          // allocate a Grad object
        record->read(cin);              // virtual call
        students.push_back(record);
    }

    // pass the version of compare that works on Ptrs
    sort(students.begin(), students.end(), compare_Core_ptrs);

    // write the names
    for (vector< Ptr<Core> >::size_type i = 0;
         i != students.size(); ++i) {
        // students[i] is a pointer that we dereference to call the functions
        cout << students[i]->name() << endl;
    }

    return 0;
}