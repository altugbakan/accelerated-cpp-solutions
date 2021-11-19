## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Implement the comparison operation that operates on `Ptr<Core>`.
The implementation of the comparison operator can be found in [compare_Core_ptrs.cpp](./compare_Core_ptrs.cpp). The driver program can be found in [q01.cpp](./q01.cpp).

### Q2: Implement and test the student grading program using `Ptr<Core>` objects.
The implemented student grading program can be found in [q02.cpp](./q02.cpp).

### Q3: Implement the `Student_info` class to use the final version of `Ptr`, and use that version to implement the grading program in §13.5/247.
The implemented `Student_info` class can be found in [Student_info.h](./Student_info.h). The driver program can be found in [q02.cpp](./q02.cpp).

### Q4: Reimplement the `Str` class to use the final version of `Ptr`.
The reimplemented `Str` class can be found in [Str.h](./Str.h).
### Q5: Test the reimplemented `Str` class by recompiling and rerunning programs that use `Str`, such as the version of `split` and the picture operations that use `Vec<Str>`.
The driver function can be found in [q05.cpp](./q05.cpp).

### Q6: The `Ptr` class really solves two problems: maintaining reference counts, and allocating and deallocating objects. Define a class that does reference counting and nothing else; then use that class to implement the `Ptr` class.