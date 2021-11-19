## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Annotate the `Core` and `Grad` constructors to write the constructor's name and argument list when the constructor is executed. For example, you should add a statement such as
```
cerr << "Grad::Grad(istream&)" << endl;
```
### to the `Grad` constructor taking an `istream&` parameter. Then write a small program that exercises each constructor. Predict beforehand what the output will be. Revise your program and predictions until your predictions match what is actually written.
The annotations were added to [Student_info.h](./Student_info.h). The driver program can be found in [q01.cpp](./q01.cpp).

### Q2: Given the `Core` and `Grad` classes defined in this chapter, indicate which function is called for each of these invocations:
```
Core* p1 = new Core;
Core* p2 = new Grad;
Core s1;
Grad s2;

p1->grade();
p1->name();

p2->grade();
p2->name();

s1.grade();
s1.name();

s2.grade();
s2.name();
```
### Check whether you are correct by adding output statements to the `name` and `grade` functions that indicate which function is being executed.
The annotations were added to [Student_info.cpp](./Student_info.cpp). The driver program can be found in [q02.cpp](./q02.cpp).

### Q3: The class that we built in Chapter 9 included a `valid` member that allowed users to check whether the object held values for a student record or not. Add that functionality to the inheritance-based system of classes.
The `valid` function is added to the `Core` class in [Student_info.h](./Student_info.h). The driver program can be found in [q03.cpp](./q03.cpp).

### Q4: Add to these classes a function that will map a numeric grade to a letter grade according to the grading policy outlined in §10.3/177.
The `letter_grade` function is added to the `Core` class in [Student_info.h](./Student_info.h). The driver program can be found in [q04.cpp](./q04.cpp).

### Q5: Write a predicate to check whether a particular student met all the relevant requirements. That is, check whether a student did all the homework, and if a graduate student, whether the student wrote a thesis.
The `meets_requirements` function is added to the `Core` and `Grade` classes in [Student_info.h](./Student_info.h). The driver program can be found in [q05.cpp](./q05.cpp).

### Q6: Add a class to the system to represent students taking the course for pass/fail credit. Assume that such students need not do the homework, but might do so. If they do, the homework should participate in determining whether they passed or failed, according to the normal formula. If they did no homework, then the grade is the average of their midterm and final grades. A passing grade is 60 or higher.
The `PassFail` class is added to [Student_info.h](./Student_info.h). Since this class has a different validity constraint, the `valid` and the `letter_grade` functions of the `Core` class is changed to a `virtual` function to support custom validity constraints. The `read` function of the `Student_info` class is also updated to include the `PassFail` class members, which are indicated with a `P` at the start of their names.

### Q7: Add a class to the system to represent students auditing the course.
The `Audit` class is added to [Student_info.h](./Student_info.h). The `read` function of the `Student_info` class is also updated to include the `Audit` class members, which are indicated with an `A` at the start of their names.

### Q8: Write a program to generate a grade report that can handle all four kinds of students.
The driver program in [q08.cpp](./q08.cpp) generates a grade report that can handle all four kinds of students. For `Audit` class students, it shows `N/A` as the letter grade.

### Q9: Describe what would happen if the assignment operator in §13.4.2/247 failed to check for self-assignment.
If the assignment operator did not check for self-assignment, in the case of self-assignment, `cp` would be deleted, which would make the expression `if(s.cp)` always `false`. This would make the assignment operator return a zero pointer, which is not the intended result.