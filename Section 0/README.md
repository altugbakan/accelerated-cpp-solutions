## Questions and Solutions

### Q0: Compile and run the `Hello, world!` program.

The code can be found on [q00.cpp](./q00.cpp). You have to build it using a compiler you are using (for example: g++). After you have built the program, run the output file (Double click the .exe file if you are using Windows).

### Q1: What does the following statement do?
```
3 + 4;
```
This statement yields an int with a value of 7. Note that this value is not saved anywhere.

### Q2: Write a program that, when run, writes
```
This (") is a quote, and this (\) is a backslash.
```
The solution can be found in [q02.cpp](./q02.cpp). The trick here is using escape characters such as **\\"** and **\\\\** to print characters that might otherwise break the string.

### Q3: The string literal "`\t`" represents a tab character; different C++ implementations display tabs in different ways. Experiment with your implementation to learn how it treats tabs.
A sample program for this question can be found in [q03.cpp](./q03.cpp). It seems g++ uses 8 spaces for a tab. You will see that the output has 7 spaces between the parentheses, as the closing parenthesis is put on the 8<sup>th</sup> space.

### Q4: Write a program that, when run, writes the `Hello, world!` program as its output.
The solution can be found in [q04.cpp](./q04.cpp). Four spaces are used instead of tabs to make the output similar to the original code written in VSCode.

### Q5: Is this a valid program? Why or why not?
```
#include <iostream>
int main() std::cout << "Hello, world!" << std::endl;
```
This is not a valid program as the curly braces which should be present after the main function are missing. We get a compile time error regarding this issue.

### Q6: Is this a valid program? Why or why not?
```
#include <iostream>

int main() {{{{{{ std::cout << "Hello, world!" << std::endl; }}}}}}
```
This is a valid program, as the curly brackets can be stacked indefinitely. One pair of curly brackets was enough but more can be used for other matters such as limiting the scope of a variable. The unnecessary brackets were probably ignored by the compiler. The code is present in [q06.cpp](./q06.cpp) to experiment.

### Q7: What about this one?
```
#include <iostream>

int main()
{
    /* This is a comment that extends over several lines
    because it use /* and */ as its starting and ending delimiters */
    std::cout << "Does this work?" << std::endl;
    return 0;
}
```
This is not a valid program, as the first ***/** in the comment closes the multi-line comment. The words after that remains outside the comment block, causing errors.

### Q8: ...and this one?
```
#include <iostream>

int main()
{
    // This is a comment that extends over several lines
    // by using // at the beginning of each line instead of using /*
    // or */ to delimit comments.
    std::cout << "Does this work?" << std::endl;
    return 0;
}
```
This is a valid program. The code can be found in [q08.cpp](./q08.cpp) to experiment.

### Q9: What is the shortest valid program?
The shortest valid program is `main(){}`. The code is in [q09.cpp](./q09.cpp) to experiment.

### Q10: Rewrite the `Hello, world!` program so that a newline occurs everywhere that whitespace is allowed in the program.
The program can be found in [q10.cpp](./q10.cpp).