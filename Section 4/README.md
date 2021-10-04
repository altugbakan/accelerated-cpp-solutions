## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: We noted in §4.2.3/65 that it is essential that the argument types in a call to `max` match exactly. Will the following code work? If there is a problem, how would you fix it?
```
int maxlen;
Student_info s;
max(s.name.size(), maxlen);
```
The code will not work, as the type of `s.name.size()` is `size_t` and the type of `maxlen` is `int`. If we change the type of `maxlen` to `size_t`, the code now works, as comparison of same types is allowed.

### Q2: Write a program to calculate the squares of `int` values up to 100. The program should write two columns: The first lists the value; the second contains the square of that value. Use `setw` (described below) to manage the output so that the values line up in columns.
> `setw(n)`: Returns a value of type `streamsize` (§3.1/36) that, when written on an output stream `s`, has the effect of calling `s.width(n)`.

The program can be found in *q02.cpp*. It first sets the length of the output stream to 3, to fit numbers between 1 and 100. After that, since we know the longest number is 10000—which is the square of 100—has a length of 5 digits, we can set the size of the output stream to 6, leaving a mininum of one space between columns.

### Q3: What happens if we rewrite the previous program to allow values up to but not including 1000 but neglect to change the arguments to `setw`? Rewrite the program to be more robust in the face of changes to allow `i` to grow without adjusting the `setw` arguments.
If we rewrite the program to allow values up to 1000, the previously set output stream size will be not enough to fit all the results on different columns. The `get_length` function in *q03.cpp* finds the length of an `int` when it is converted to a `string`. Using this function, the `streamsize`s are set to leave a minimum of one space between columns, regardless of the maximum limit.

### Q4: Now change your squares program to use `double` values instead of `int`s. Use manipulators to manage the output so that the values line up in columns.
The `get_length` function is modified to accept double values and different precisions to return the maximum length of a `double` when it is converted to a `string`. `std::fixed` is used here to set the output's formatting to show fixed-point notation instead of scientific notation. The changes can be seen in *q04.cpp*.

### Q5: Write a function that reads words from an input stream and stores them in a `vector`. Use that function both to write programs that count the number of words in the input, and to count how many times each word occured.
The function that reads words and stores them in a `vector` can be found in `read_words.cpp`. The function is similar to the `read_hw` function in the book, with the difference being that the `vector`'s type is `string` on this case. The program that counts the number of the words can be found in *q05-1.cpp*. It simply outputs the size of the vector. The program counting the number of the words in the input can be found in *q05-2.cpp*. It first sorts the `vector` to group same words with each other, to ease the counting process.

### Q6: Rewrite the `Student_info` structure, and the `read` and `grade` functions, so that they calculate each student's grades as part of reading the input, and store only the final grade.
The rewritten `Student_info` structure and `grade` function can be found in *Student_info.cpp* and *grade.cpp* respectively. Since we do not store the homeworks or the exam grades of the students, a single `grade` function is enough for our needs. The demonstration of the rewritten code can be found in *q06.cpp*, which contains a similar code to the grading program on the book.

### Q7: Write a program to calculate the average of the numbers stored in a `vector<double>`.
The program can be found in *q07.cpp*. It first asks the user for double input to fill the `vector<double>`, then it calculates the average of the numbers stored.

### Q8: If the following code is legal, what can we infer about the return type of `f`?
```
double d = f()[n];
```
Since we can access the `n`th element of the return value, and know that it is a `double`, we can infer that `f`'s return type is a `double` container, like `vector` or `array`. 