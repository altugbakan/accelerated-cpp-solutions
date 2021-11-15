#include <iostream>
#include <vector>
#include "Student_info.h"
#include "../Section 06/analysis.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<Student_info> extract_didnt(vector<Student_info>& students)
{
    vector<Student_info> didnt;
    vector<Student_info>::iterator it = students.begin();

    while (it != students.end()) {
        if (!did_all_hw(*it)) {
            didnt.push_back(*it);
            it = students.erase(it);
        } else
            ++it;
    }
    return didnt;
}

int main()
{
    vector<Student_info> students;
    Student_info student;

    // read all student data
    while (student.read(cin))
        students.push_back(student);

    // extract students who did not do their homework
    vector<Student_info> didnt = extract_didnt(students);

    // write the results
    cout << "Students who did all their homework are: ";
    for (vector<Student_info>::const_iterator it = students.begin();
        it != students.end(); ++it)
        cout << it->name() << (it + 1 == students.end() ? "." : ", ");
    cout << endl;

    cout << "Students who did not do all their homework are: ";
    for (vector<Student_info>::const_iterator it = didnt.begin();
        it != didnt.end(); ++it)
        cout << it->name() << (it + 1 == didnt.end() ? "." : ", ");
    cout << endl;

    return 0;
}