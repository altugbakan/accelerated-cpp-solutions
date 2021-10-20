#include <list>
// ctime is used for code runtime estimation
#include <ctime>
// include the simplified version of Student_info
#include "../Section 4/Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;

list<Student_info> extract_fails(list<Student_info> students)
{
    list<Student_info> fails;
    list<Student_info>::iterator it = students.begin();
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
    list<Student_info> students;
    Student_info student;
    list<Student_info>::size_type count = 0;
    // read all student data
    while (read(cin, student)) {
        students.push_back(student);
        ++count;
    }

    double begin = clock();
    list<Student_info> fails = extract_fails(students);
    double end = clock();

    cout << "Extracting fails for " << count << " students took "
        << (end - begin) / CLOCKS_PER_SEC << " seconds." << endl;

    return 0;
}