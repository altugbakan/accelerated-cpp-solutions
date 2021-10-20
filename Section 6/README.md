## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Reimplement the `frame` and `hcat` operations from §5.8.1/93 and §5.8.3/95 to use iterators.
The program can be found in [q01.cpp](./q01.cpp). The index loops are changed with `iterator` loops.

### Q2: Write a program to test the `find_urls` function.
The test program can be found in [q02.cpp](./q02.cpp). The program finds the URLs in the sample text.

### Q3: What does this program fragment do?
```
vector<int> u(10, 100);
vector<int> v;
copy(u.begin(), u.end(), v.begin());
```
### Write a program that contains this fragment, and compile and execute it.
The program fragment first creates a `vector<int>` with ten items, with each being 100. It then tries to copy the firstly created vector to the second one; however, it throws an error as `v.begin()` is invalidated after writing to `v`. The program can be found in [q03.cpp](./q03.cpp).

### Q4: Correct the program you wrote in the previous exercise to copy from `u` into `v`. There are at least two possible ways to correct the program. Implement both, and describe the relative advantages and disadvantages of each approach.

### Q5: Write an analysis function to call `optimistic_median`.

### Q6: Note that the function from the previous exercise and the functions from §6.2.2/113 and §6.2.3/115 do the same task. Merge these three analysis functions into a single function.

### Q7: The portion of the grading analysis program from §6.2.1/110 that read and classified student records depending on whether they did (or did not) do all the homework is similar to the problem we solved in `extract_fails`. Write a function to handle this subproblem.

### Q8: Write a single function that can be used to classify students based on criteria of your choice. Test this function by using it in place of the `extract_fails` program, and use it in the program to analyze student grades.

### Q9: Use a library algorithm to concatenate all the elements of a `vector<string>`.