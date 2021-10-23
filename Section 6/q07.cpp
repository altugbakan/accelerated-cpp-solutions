#include <iostream>
#include <vector>
#include "Student_info.h"
#include "analysis.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<Student_info> extract_didnt(vector<Student_info>& students)
{
    vector<Student_info> didnt;
    vector<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (!did_all_hw(*iter)) {
            didnt.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return didnt;
}

int main()
{
    vector<Student_info> students;
    Student_info student;

    // read all student data
    while (read(cin, student))
        students.push_back(student);

    // extract students who did not do their homework
    vector<Student_info> didnt = extract_didnt(students);

    // output the results
    cout << "Students who did all their homework are: ";
    for (vector<Student_info>::const_iterator i = students.begin();
        i != students.end(); ++i)
        cout << i->name << (i + 1 == students.end() ? "." : ", ");
    cout << endl;

    cout << "Students who did not do all their homework are: ";
    for (vector<Student_info>::const_iterator i = didnt.begin();
        i != didnt.end(); ++i)
        cout << i->name << (i + 1 == didnt.end() ? "." : ", ");
    cout << endl;

    return 0;
}