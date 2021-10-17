#ifndef GUARD_Student_info
#define Guard_Student_info

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

struct Student_info {
    std::string name;
    double final_grade;
};

double median(std::vector<double>);
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif