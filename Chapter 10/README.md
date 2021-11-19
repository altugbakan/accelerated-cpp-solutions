## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Rewrite the student-grading program from §9.6/166 to generate letter grades.
The rewritten student-grading program can be found in [q01.cpp](./q01.cpp).

### Q2: Rewrite the `median` function from §8.1.1/140 so that we can call it with either a `vector` or a built-in array. The function should allow containers of any arithmetic type.
The rewritten `median` function can be found in [q02.cpp](./q02.cpp). It allows arrays or `vector`s of any arithmetic type by accepting `Random-access iterator`s instead of `vector<T>`. 

### Q3: Write a test program to verify that the `median` function operates correctly. Ensure that calling `median` does not change the order of the elements in the container.
The test program can be found in [q03.cpp](./q03.cpp). It is shown that calling `median` does not change the order of the elements in the container.

### Q4: Write a class that implements a list that holds `string`s.
The `String_list` class implementation can be found in [String_list.cpp](./String_list.cpp). The driver program can be found in [q04.cpp](./q04.cpp).

### Q5: Write a bidirectional iterator for your `String_list` class.
The bidirectional iterator is added to [String_list.h](./String_list.h). It is simply a `typedef` for the `string` pointer. The driver program can be found in [q05.cpp](./q05.cpp).

### Q6: Test the class by rewriting the `split` function to put its output into a `String_list`.
The rewritten `split` function can be found in [split.cpp](./q02.cpp). The driver program can be found in [q06.cpp](./q06.cpp).