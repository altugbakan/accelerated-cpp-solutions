#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <vector>
#include <string>

class Core {
    friend class Student_info;
public:
    Core(): midterm(0), final(0) {
        // std::cerr << "Core::Core()" << std::endl; // Q1
    }
    Core(std::istream& is) {
        read(is);
        // std::cerr << "Core::Core(istream&)" << std::endl; // Q1
    }
    virtual ~Core() { }
    std::string name() const;
    virtual double grade() const;
    virtual std::istream& read(std::istream&);
    virtual bool valid() const { return !homework.empty(); } // Q3
    virtual std::string letter_grade() const; // Q4, Q6
    virtual bool meets_requirements() const { return valid(); } // Q5
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
    Grad(): thesis(0) {
        // std::cerr << "Grad::Grad()" << std::endl; // Q1
    }
    Grad(std::istream& is) {
        read(is);
        // std::cerr << "Grad::Grad(istream&)" << std::endl; // Q1
    }
    double grade() const;
    std::istream& read(std::istream&);
    bool meets_requirements() const { return thesis != 0; } // Q5
protected:
    Grad* clone() const { return new Grad(*this); }
private:
    double thesis;
};

// Q6
class PassFail: public Core {
public:
    PassFail() { }
    PassFail(std::istream& is) {
        read(is);
    }
    double grade() const;
    bool valid() const { return midterm > 0 || final > 0; }
    std::string letter_grade() const { return grade() > 60 ? "P" : "F"; }
protected:
    PassFail* clone() const { return new PassFail(*this); }
};

// Q7
class Audit: public PassFail {
public:
    Audit() { }
    Audit(std::istream& is) {
        read(is);
    }
    bool valid() const { return name().size() > 0; }
    std::string letter_grade() const { return "N/A"; }
protected:
    Audit* clone() const { return new Audit(*this); }
};

class Student_info {
public:
    // constructors and copy control
    Student_info(): cp(0) { }
    Student_info(std::istream& is): cp(0) { read(is); }
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info() { delete cp; }

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

    // Q3
    bool valid() const {
        if (cp) return cp->valid();
        else throw std::runtime_error("uninitialized Student");
    }

    // Q4
    std::string letter_grade() const {
        if (cp) return cp->letter_grade();
        else throw std::runtime_error("uninitialized Student");
    }

    // Q5
    bool meets_requirements() const {
        if (cp) return cp->meets_requirements();
        else throw std::runtime_error("uninitialized Student");
    }
    
    // code is taken from §13.4/244
    static bool compare(const Student_info& s1,
                        const Student_info& s2) {
        return s1.name() < s2.name();
    }

private:
    Core* cp;
};

std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const Core&, const Core&);
bool compare_grades(const Core& c1, const Core& c2);
#endif