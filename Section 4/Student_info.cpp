#include "Student_info.h"

using std::cout;
using std::vector;
using std::istream;
using std::domain_error;
using std::sort;

// code is taken from §4.1.1/53
// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// code is taken from §4.4/69
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    double midterm, final;
    vector<double> homework;
    // read and store the student's name and final grade
    is >> s.name >> midterm >> final;

    // check for end-of-file
    if(is) {
        read_hw(is, homework);
        s.final_grade = 0.2 * midterm + 0.4 * final + 0.4 * median(homework);
    }
    
    return is;
}

// code is taken from §4.1.3/57
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // get rid of previous contetns
        hw.clear();

        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}