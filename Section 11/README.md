## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.

### Q1: The `Student_info` structure that we defined in Chapter 9 did not define a copy constructor, assignment operator, or destructor. Why not?

### Q2: That structure did define a default constructor. Why?

### Q3: What does the synthesized assignment operator for `Student_info` objects do?

### Q4: How many members does the synthesized `Student_info` destructor destroy?

### Q5: Instrument the `Student_info` class to count how often objects are created, copied, assigned, and destroyed. Use this instrumented class to execure the student record programs from Chapter 6. Using the instrumented `Student_info` class will let you see how you estimate what proportion of the cost differences we saw are accounted for by the use of each library class. Do this instrumentation and analysis.

### Q6: Add an operation to remove an element from a `Vec` and another to empty the entire `Vec`. These should behave analogously to the `erase` and `clear` options on `vector`s.

### Q7: Once you've added `erase` and `clear` to `Vec`, you can use that class instead of `vector` in most of the earlier programs in this book. Rewrite the `Student_info` programs from Chapter 9 and the programs that work with character pictures from Chapter 5 to use `Vec`s instead of `vector`s.

### Q8: Write a simplified version of the standard `list` class and its associated iterator.

### Q9: The `grow` function in §11.5.1/208 doubles the amount of memory each time it needs more. Estimate the efficiency gains of this strategy. Once you've predicted how much of a difference it makes, change the `grow` function appropriately and measure the difference.