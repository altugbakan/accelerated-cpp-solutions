#include <stdexcept>
#include <iostream>
#include "Student_info_vec.h"

using std::cout;
using std::endl;
using std::domain_error;

int main()
{
    Student_info student;
    
    try {
        student.grade();
    }
    catch(domain_error e) {
        cout << e.what() << endl;
    }

    return 0;
}