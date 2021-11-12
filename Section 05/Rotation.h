#ifndef GUARD_Rotation
#define GUARD_Rotation

#include <vector>
#include <string>

struct Rotation {
    std::vector<std::string> words;
    std::vector<std::string>::size_type start;
};

std::vector<Rotation> get_rotations(const std::string&);
std::vector<Rotation> sort_rotations(std::vector<Rotation>&);
std::string format_rotation(Rotation&, std::string::size_type);
std::string::size_type first_width(const Rotation&);
std::string::size_type first_width(const std::vector<Rotation>&);
bool compare(const Rotation&, const Rotation&);
#endif