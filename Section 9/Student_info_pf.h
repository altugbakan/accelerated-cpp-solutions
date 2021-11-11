#ifndef GUARD_Student_info_pf
#define Guard_Student_info_pf

#include <vector>
#include <string>

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
    std::string name() const { return n; }
    std::istream& read(std::istream&);
    char grade() const;
private:
    std::string n;
    double midterm, final;
};

bool compare(const Student_info&, const Student_info&);
#endif