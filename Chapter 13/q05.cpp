#include <iostream>
#include <vector>
#include "Student_info.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info student;

    // read all student data
    while (student.read(cin))
        students.push_back(student);

    for (vector<Student_info>::const_iterator it = students.begin();
        it != students.end(); ++it)
        cout << it->name() << ":\t"
             << (it->meets_requirements() ? "meets requirements"
             : "does not meet requirements") << endl;

    return 0;
}