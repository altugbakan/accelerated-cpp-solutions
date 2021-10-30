#include <iostream>
#include <vector>
#include "Student_info.h"
#include "analysis.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

bool fgrade(const Student_info& s)
{
    return optimistic_median(s) < 60;
}

// code is taken from §5.3/62
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}

int main()
{
    vector<Student_info> students;
    Student_info student;

    // read all student data
    while (read(cin, student))
        students.push_back(student);

    vector<Student_info> fails = extract_fails(students);

    // output the results
    cout << "Students who passed the class are: ";
    for (vector<Student_info>::const_iterator it = students.begin();
        it != students.end(); ++it)
        cout << it->name << (it + 1 == students.end() ? "." : ", ");
    cout << endl;

    cout << "Students who failed the class are: ";
    for (vector<Student_info>::const_iterator it = fails.begin();
        it != fails.end(); ++it)
        cout << it->name << (it + 1 == fails.end() ? "." : ", ");
    cout << endl;

    return 0;
}