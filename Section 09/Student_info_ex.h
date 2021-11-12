#ifndef GUARD_Student_info_ex
#define Guard_Student_info_ex

#include <vector>
#include <string>

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&);
    double grade() const { return g; };
private:
    std::string n;
    double g, midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
#endif