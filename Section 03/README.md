## Questions and Solutions

### Q0: Compile, execute and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Suppose we wish to find the median of a collection of values. Assume that we have read some of the values so far, and that we have no idea how many values remain to be read. Prove that we cannot afford to discard any of the values that we have read. *Hint:* One proof strategy is to assume that we can discard a value, and then find values for the unread—and therefore unknown—part of our collection that would cause the median to be the value that we discarded.
Let's say we have read the values 3, 4, and 7. It seems probable that we can discard the smallest or the largest value. Let's discard them. Now we have 4. Now, let's say we now read 1 and 2. Now we have 1, 2, and 4. It seems that the median should be 2, however, if we have not discarded any values, we would have 1, 2, 3, 4, and 7. The median would be 3, which we have discarded. That proves that we cannot afford to discard any value we have already read.

### Q2: Write a program to compute and print the quartiles (that is, the quarter of the numbers with the largest values, the next highest quarter, and so on) of a set of integers.
The program can be found in [q02.cpp](./q02.cpp). It sorts the input numbers and prints each quartile. Note that if the number is not divisible by 4, the remainders are shared within the quartiles.

### Q3: Write a program to count how many times each distinct word appears in its input.
The program can be found in [q03.cpp](./q03.cpp). It stores the input words and the number of appearances in separate `vector`s with the same indices for word and its respective count.

### Q4: Write a program to report the length of the longest and the shortest `string` in its input.
The program can be found in [q04.cpp](./q04.cpp). It stores the lengths of the `string`s from the input into a `vector`, then sorts the `vector` to find the shortest and longest lengths. The shortest length is the first element, and the longest length is the last element of the vector.

### Q5: Write a program that will keep track of grades for several students at once. The program could keep two `vector`s in sync: The first should hold the students' names, and the second the final grades that can be computed as input is read. For now, you should assume a fixed number of homework grades. We'll see in §4.1.3/56 how to handle a variable number of grades intermixed with student names.
The solution can be found in [q05.cpp](./q05.cpp). The program first reads the student's name, followed by final grade, midterm grade, and homework grades. It stores the student's name in a `vector`. Then, it calculates the student's final grade and stores it in another vector, with the same index as the student name `vector`.

### Q6: The average-grade computation in §3.1/36 might divide by zero if the student didn't enter any grades. Division by zero is undefined in C++, which means the implementation is permitted to do anything it likes. What does your C++ implementation do in this case? Rewrite the program so that its behavior does not depend on how the implementation treats division by zero.
My implementation, g++, outputs nan when no homework grades are entered. In [q06.cpp](./q06.cpp), the program is rewritten so that it sets the homework grade as zero if no grade is entered.