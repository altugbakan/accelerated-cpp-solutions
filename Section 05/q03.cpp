#include <iostream>
#include <vector>
// #include <list>
// ctime is used for code runtime estimation
#include <ctime>
// include the simplified version of Student_info
#include "../Section 04/Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::clock_t;

typedef std::vector<Student_info> student_container;
// typedef std::list<Student_info> student_container;

student_container extract_fails(student_container& students)
{
    student_container fails;
    student_container::iterator it = students.begin();
    while (it != students.end()) {
        // we can access only the final grade from simplified version
        if (it->final_grade < 60) {
            fails.push_back(*it);
            it = students.erase(it);
        } else
            ++it;
    }

    return fails;
}

int main()
{
    student_container students;
    Student_info student;

    // read all student data
    while (read(cin, student))
        students.push_back(student);

    // save the original size
    student_container::size_type count = students.size();

    double begin = clock();
    student_container fails = extract_fails(students);
    double end = clock();

    cout << "Extracting fails for " << count << " students took "
        << (end - begin) / CLOCKS_PER_SEC << " seconds." << endl;

    return 0;
}