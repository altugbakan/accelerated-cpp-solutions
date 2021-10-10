#include "Student_info.h"

using std::cout;
using std::istream;
using std::domain_error;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    double midterm, final, homework;
    // read and store the student's name and final grade
    is >> s.name >> midterm >> final;
    try {
        read_hw(is, homework); // read and store the student's homework average
    } catch (domain_error e) {
        cout << e.what();
    }
    s.final_grade = 0.2 * midterm + 0.4 * final + 0.4 * homework;
    return is;
}

istream& read_hw(istream& in, double& hw)
{
    if (in) {
        // read homework grades
        double x;
        double total = 0;
        size_t count = 0;
        while (in >> x) {
            total += x;
            ++count;
        }

        // clear the stream so that input will work for the next student
        in.clear();

        // calculate the average homework grade
        if (count == 0)
            throw domain_error("student has done no homework");
        hw = total / count;
    }
    return in;
}