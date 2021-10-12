#include <vector>
#include "../Section 4/Student_info.h"
// ctime is used for code runtime estimation
#include <ctime>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

typedef vector<Student_info>::size_type vec_std_sz;

// code is taken from §5.1.1/77, modified to fit the simplified
// Student_info structure.
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vec_std_sz i = 0;

    // invariant: elements [0, i) of students represent passing grades
    while (i != students.size()) {
        if (students[i].final_grade < 60) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        } else
            ++i;
    }
    return fail;
}

vector<Student_info> resizing_extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vec_std_sz original_size = students.size();
    
    for (vec_std_sz i = 0; i != students.size(); ++i) {
        if (students[i].final_grade < 60) {
            fail.push_back(students[i]);
        } else {
            students.insert(students.begin(), students[i]);
            ++i;
        }
    }
    students.resize(original_size - fail.size());
    return fail;
}

int main()
{
    vector<Student_info> students;
    Student_info student;
    vec_std_sz count = 0;
    // read all student data
    while (read(cin, student)) {
        students.push_back(student);
        ++count;
    }
    // create a copy to measure both functions
    vector<Student_info> students_copy(students);

    // measure time for the original function
    double begin = clock();
    extract_fails(students);
    double time_original = clock() - begin;

    // measure time for the modified function
    begin = clock();
    resizing_extract_fails(students_copy);
    double time_modified = clock() - begin;

    // output the results
    cout << "Original function took " << time_original / CLOCKS_PER_SEC <<
        " seconds and the modified function took " << time_modified / 
        CLOCKS_PER_SEC << " seconds for " << count << " students." << endl;

    return 0;
}