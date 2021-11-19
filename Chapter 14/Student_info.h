#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <vector>
#include <string>
#include "Ptr.h"

class Core {
    friend class Student_info;
public:
    Core(): midterm(0), final(0) { }
    Core(std::istream& is) { read(is); }
    virtual ~Core() { }
    std::string name() const;
    virtual double grade() const;
    virtual std::istream& read(std::istream&);
protected:
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
    virtual Core* clone() const { return new Core(*this); }
private:
    std::string n;
};

class Grad: public Core {
public:
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }
    double grade() const;
    std::istream& read(std::istream&);
protected:
    Grad* clone() const { return new Grad(*this); }
private:
    double thesis;
};

class Student_info {
public:
    // constructors and copy control
    Student_info(): cp(0) { }
    Student_info(std::istream& is): cp(0) { read(is); }

    // operations
    std::istream& read(std::istream&);

    // code is taken from §13.4/243
    std::string name() const {
        if (cp) return cp->name();
        else throw std::runtime_error("uninitialized Student");
    }

    // code is taken from §13.4/243
    double grade() const {
        if (cp) return cp->grade();
        else throw std::runtime_error("uninitialized Student");
    }
    
    // code is taken from §13.4/244
    static bool compare(const Student_info& s1,
                        const Student_info& s2) {
        return s1.name() < s2.name();
    }

private:
    Ptr<Core> cp; // Q3
};

std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const Core&, const Core&);
bool compare_grades(const Core& c1, const Core& c2);
#endif