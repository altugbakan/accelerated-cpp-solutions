## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: The `Student_info` structure that we defined in Chapter 9 did not define a copy constructor, assignment operator, or destructor. Why not?
As the synthesized operators for the class implemented the operations that we would implement, not defining them made no difference in the class behavior. Copying, destroying, and assigning the name and the grades were synthesized automatically by the compiler.

### Q2: That structure did define a default constructor. Why?
If we did not have a default constructor, the `midterm` and `final` grades would be default-initialized, meaning they would have random data from the memory they were created in, resulting in unwanted errors.

### Q3: What does the synthesized assignment operator for `Student_info` objects do?
The synthesized assignment operator copies the values of the `midterm`, `final`, and `n` to the assigned object. It also creates a new `vector<double>` filled with the homework grades of the source object.

### Q4: How many members does the synthesized `Student_info` destructor destroy?
Destructor destroys 4 members, `midterm`, `final`, `n`, an the entire `vector<double>`.

### Q5: Instrument the `Student_info` class to count how often objects are created, copied, assigned, and destroyed. Use this instrumented class to execute the student record programs from Chapter 6. Using the instrumented `Student_info` class will let you see how you estimate what proportion of the cost differences we saw are accounted for by the use of each library class. Do this instrumentation and analysis.

### Q6: Add an operation to remove an element from a `Vec` and another to empty the entire `Vec`. These should behave analogously to the `erase` and `clear` options on `vector`s.

### Q7: Once you've added `erase` and `clear` to `Vec`, you can use that class instead of `vector` in most of the earlier programs in this book. Rewrite the `Student_info` programs from Chapter 9 and the programs that work with character pictures from Chapter 5 to use `Vec`s instead of `vector`s.

### Q8: Write a simplified version of the standard `list` class and its associated iterator.

### Q9: The `grow` function in §11.5.1/208 doubles the amount of memory each time it needs more. Estimate the efficiency gains of this strategy. Once you've predicted how much of a difference it makes, change the `grow` function appropriately and measure the difference.