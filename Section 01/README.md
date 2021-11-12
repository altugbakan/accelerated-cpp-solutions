## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Are the following definitions valid? Why or why not?
```
const std::string hello = "Hello";
const std::string message = hello + ", world" + "!";
```
The definitions are valid. The first definition is a generic string definition. In the second definition, at first, it seems like we are adding two string literals, however, the add operation is left-associative so we are adding a string variable and a string literal in each operation. The operation can be visualized as follows:
<p align=middle>(variable + literal) + literal</p>
<p align=middle>variable + literal</p>
<p align=middle>variable</p>

### Q2: Are the following definitions valid? Why or why not?
```
const std::string exclam = "!";
const std::string message = "Hello" + ", world" + exclam;
```
The first definition is valid, however, the second one is not. This is due to the addition of two string literals, which is invalid.

### Q3: Is the following program valid? If so, what does it do? If not, why not?
```
#include <iostream>
#include <string>

int main()
{
    { const std::string s = "a string";
      std::cout << s << std::endl; }
    { const std::string s = "another string";
      std::cout << s << std::endl; }
    return 0;
}
```
This program is valid. It seems like we are defining the same string twice but they are both in their own block, meaning the first one will be discarded from memory after reaching the ending curly bracket. This program prints `a string` followed by `another string` to the console.

### Q4: What about this one? What if we change `}}` to `};}` in the third line from the end?
```
#include <iostream>
#include <string>

int main()
{
    { const std::string s = "a string";
      std::cout << s << std::endl;
    { const std::string s = "another string";
      std::cout << s << std::endl; }}
    return 0;
}
```
This program is valid. It also seems like we are defining the same string twice but they are both in their own block, even if one is inside the other block. The inside definition makes the outer `s` unreachable from the inside. Changing `}}` to `};}` does not change anything in this context.

### Q5: Is this program valid? If so, what does it do? If not, say why not, and rewrite it to be valid.
```
#include <iostream>
#include <string>

int main()
{
    { std::string s = "a string";
    { std::string x = s + ", really";
      std::cout << s << std::endl; }
      std::cout << x << std::endl;
    }
    return 0;
}
```
The program is not valid as `x` is not reachable from outside its block. The code can be fixed by removing the inner brackets surrounding the definition of `x`. An example can be found in [q05.cpp](./q05.cpp).

### Q6: What does the following program do if, when it asks you for input, you type two names (for example, `Samuel Beckett`)? Predict the behavior before running the program, then try it.
```
#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name
              << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name
              << "; nice to meet you too!" << std::endl;
    return 0;
}
```
This example takes two inputs to greet two people. Typing two names at the same time is the same as typing two names separately, as `std::cin` takes the first input until the whitespace (not before a character), so both inputs will be consumed by the two `std::cin` input streams.