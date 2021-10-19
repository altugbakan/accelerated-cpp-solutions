#ifndef GUARD_Student_info
#define Guard_Student_info

#include <iostream>
#include <vector>
#include <string>

struct Student_info {
    std::string name;
    double final_grade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif