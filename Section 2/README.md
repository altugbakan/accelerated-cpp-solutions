## Questions and Solutions

### Q0: Compile and run the program presented in this chapter.
The program in this chapter is compiled and tested. The program can be found in the book.

### Q1: Change the framing program so that it writes its greeting with no separation from the frame.
Changing the pad value to `0` makes the program write its greeting with no separation. Code can be found in [q01.cpp](./q01.cpp).

### Q2: Change the framing program so that it uses a different amount of space to separate the sides from the greeting than it uses to separate the top and bottom borders from the greeting.
Separating `pad` variable to `pad_horizontal` and `pad_vertical` and changing the `pad`s into their corresponding variable makes the framing program use a different amount of space to separate the sides from the greeting than it uses to separate the top and bottom borders. The code can be found in [q02.cpp](./q02.cpp).

### Q3: Rewrite the framing program to ask the user to supply the amount of spacing to leave between the frame and the greeting.
Instead of defining the pad variable, we can ask for user input with `cin`. Note that for this change, we also need to remove the `const` tag from the variable, as it will change with user input. The code can be found in [q03.cpp](./q03.cpp).

### Q4: The framing program writes the mostly blank lines that separate the borders from the greeting one character at a time. Change the program so that it writes all the spaces needed in a single output expression.
For the non-border rows excluding the name row, we can calculate the number of spaces by subtracting 2 from `cols`. For the name row, the amount of spaces is specified by `pad`. Using this knowledge and the string constructor `string(const char* s, size_t n)`, we can print the required spaces in a single output expression. The code can be found in [q04.cpp](./q04.cpp).

### Q5: Write a set of "*" characters so that they form a square, a rectangle, and a triangle.
The shapes are written with parameters in [q05.cpp](./q05.cpp). You can experiment with the variables `square_length`, `rectangle_width`, `rectangle_height`, and `triangle_height`.

### Q6: What does the following code do?
```
int i = 0;
while (i < 10) {
    i += 1;
    std::cout << i << std::endl;
}
```
This code outputs the numbers from 1 to 10. It increments `i` first and outputs it later.

### Q7: Write a program to count down from `10` to `-5`.
The code to count down from `10` to `-5` can be found in [q07.cpp](./q07.cpp).

### Q8: Write a program to generate the product of the numbers in the range `[1, 10]`.
The code that generates the product of the numbers in the range `[1, 10]` can be found in [q08.cpp](./q08.cpp). The result is 3,628,800.

### Q9: Write a program that asks the user to enter two numbers and tells the user which number is larger than the other.
The code can be found in [q09.cpp](./q09.cpp). If both numbers are equal, the program outputs the value.

### Q10: Explain each of the uses of `std::` in the following program:
```
int main()
{
    int k = 0;
    while (k != 10) {               // invariant: we have written k asterisks so far
        using std::cout;
        cout << "*";
        ++k;
    }
    std::cout << std::endl;         // std:: is required here
    return 0;
}
```
The first `std::` tells that we will be using `cout` to mean `std::cout` exclusively. However, this `using` statement is valid for the block it has been used only. Outside that block, we must still use `std::cout` to indicate our intent.