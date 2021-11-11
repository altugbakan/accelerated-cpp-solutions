## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Reimplement the `Student_info` class so that it calculates the final grade when reading the student's record, and stores that grade in the object. Reimplement the `grade` function to use this precomputed value.
The reimplementations of `Student_info` and `grade` can be found in [Student_info_ex.cpp](./Student_info_ex.cpp). The `grade` function of the `Student_info` now returns the final grade that is stored in the object. The calculation is done in the `read` function. The driver program can be found in [q01.cpp](./q01.cpp).

### Q2: If we define the `name` function as a plain, non`const` member function, what other functions in our system must change and why?
If we define the `name` function as a non`const` function, we need to change the `compare` function as it uses `const Student_info&` references.

### Q3: Our `grade` function was written to throw an exception if a user tried to calculate a grade for a `Student_info` object whose values had not yet been read. Users who care are expected to catch this exception. Write a program that triggers the exception but does not catch it. Write a program that catches the exception.
The program that triggers the exception but does not catch it can be found in [q03-1.cpp](./q03-1.cpp). The program that catches the exception can be found in [q03-2.cpp](./q03-2.cpp).

### Q4: Rewrite your program from the previous exercise to use the `valid` function, thereby avoiding the exception altogether.
The program that uses `valid` can be found in [q04.cpp](./q04.cpp).

### Q5: Write a class and associated functions to generate grades for students who take the course for pass/fail credit. Assume that only the midterm and final grades matter, and that a student passes with an average exam score greater than 60. The report should list the students in alphabetical order, and indicate `P` or `F` as the grade.
The created class can be found in [Student_info_pf.cpp](./Student_info_pf.cpp). The driver program can be found in [q05.cpp](./q05.cpp).

### Q6: Rewrite the grading program for the pass/fail students so that the report shows all the students who passed, followed by all students who failed.
The rewritten grading program can be found in [q06.cpp](./q06.cpp).

### Q7: The `read_hw` function §4.1.3/57 solves a general problem (reading a sequence of values into a `vector`) even though its name suggests that it should be part of the implementation of `Student_info`. Of course, we could change its name—but suppose, instead, that you wanted to integrate it with the rest of the `Student_info` code, in order to clarify that it was not intended for public access despite its apparent generality? How would you do so?
We could add the `read_hw` function as a `private` member function of the class `Student_info`, or we could put the definition of the `read_hw` function in the `Student_info.cpp` file without interfacing it to everyone.