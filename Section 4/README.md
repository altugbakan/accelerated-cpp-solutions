## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.

### Q1: We noted in §4.2.3/65 that it is essential that the argument types in a call to `max` match exactly. Will the following code work? If there is a problem, how would you fix it?
```
int maxlen;
Student_info s;
max(s.name.size(), maxlen);
```

### Q2: Write a program to calculate the squares of `int` values up to 100. The program should write two columns: The first lists the value; the second contains the square of that value. Use `setw` (described below) to manage the output so that the values line up in columns.
> `setw(n)`: Returns a value of type `streamsize` (§3.1/36) that, when written on an output stream `s`, has the effect of calling `s.width(n)`.

### Q3: What happens if we rewrite the previous program to allow values up to but not including 1000 but neglect to change the arguments to `setw`? Rewrite the program to be more robust in the face of changes to allow `i` to grow without adjusting the `setw` arguments.

### Q4: Now change your squares program to use `double` values instead of `int`s. Use manipulators to manage the output so that the values line up in columns.

### Q5: Write a function that reads words from an input stream and stores them in a `vector`. Use that function both to write programs that count the number of words in the input, and to count how many times each word occured.

### Q6: Rewrite the `Student_info` structure, and the `read` and `grade` functions, so that they calculate each student's grades as part of reading the input, and store only the final grade.

### Q7: Write a program to calculate the average of the numbers stored in a `vector<double>`.

### Q8: If the following code is legal, what can we infer about the return type of `f`?