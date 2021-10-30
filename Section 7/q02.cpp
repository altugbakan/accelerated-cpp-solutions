#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <string>
#include "../Section 4/Student_info.h" // using the simplifed version

using std::cin;                             using std::setprecision;
using std::cout;                            using std::sort;
using std::domain_error;                    using std::streamsize;
using std::endl;                            using std::string;
using std::max;                             using std::vector;
using std::map;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records, and find the length of the longest name
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the records
    sort(students.begin(), students.end(), compare);

    // assign letter grades
    map<string, vector<Student_info> > grades;
    for (vector<Student_info>::const_iterator it = students.begin();
        it != students.end(); ++it) {
        if (it->final_grade > 90)
            grades["A"].push_back(*it);
        else if (it->final_grade > 80)
            grades["B"].push_back(*it);
        else if (it->final_grade > 70)
            grades["C"].push_back(*it);
        else if (it->final_grade > 60)
            grades["D"].push_back(*it);
        else
            grades["B"].push_back(*it);
    }

    for (map<string, vector<Student_info> >::const_iterator it = grades.begin();
        it != grades.end(); ++it) {
        cout << "Students who got " << (it->first == "A" || it->first == "F"
        ? "an " : "a ") << it->first << " are:\t";
        for (vector<Student_info>::const_iterator jt = it->second.begin();
            jt != it->second.end() - 1; ++jt) {
            cout << jt->name << ", ";
        }
        // write the last student's name without a comma
        cout << (it->second.end() - 1)->name << endl;
    }
    
    return 0;
}