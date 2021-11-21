## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Test your system by writing a program that executes
```
Picture p = // some initial starting picture
Picture q = frame(p);
Picture r = hcat(p, q);
Picture s = vcat(q, r);
cout << frame(hcat(s, vcat(r, q))) << endl;
```
The test program can be found in [q01.cpp](./q01.cpp).

### Q2: Reimplement the `Frame_Pic` class so that the frame uses three different characters: one for the corners, another for the top and bottom borders, and a third for the side borders.
The border characters were added to [Pic.h](./Pic.h). The `Frame_Pic::display` function in [Pic.cpp](./Pic.cpp) is also modified. The driver program can be found in [q02.cpp](./q02.cpp).

### Q3: Give users the option to specify what characters to use for these border characters.
The `frame` function in [Pic.h](./Pic.h) is modified to accept specifications for border characters. The driver program can be found in [q03.cpp](./q03.cpp).

### Q4: Add an operation to `reframe` a `Picture`, which changes the frame characters. The operation should change all of the frames in the interior picture.
The `reframe` function is added to the `Pic_base` class. The implementations for each derived class can be found in [Pic.cpp](./Pic.cpp). The driver program can be found in [q04.cpp](./q04.cpp).

### Q5: Reimplement `HCat_Pic` so that when pictures of a different size are concatenated, the shorter one is centered in the space consumed by the longer one. That is, if we horizontally concatenate two pictures, one of which is four lines long and the other is two lines long, the first and last rows of the output picture will be blank on the side of the shorter picture. What can we now conclude about the necessity of the tests between `row` and `0`.
The reimplemented `HCat_Pic::display` can be found in [Pic.cpp](./Pic.cpp). The driver program can be found in [q05.cpp](./q05.cpp). Since we now supply a modified row number to the display function, tests between `row` and `0` are required.

### Q6: The `Vec` and `Str` classes that we developed in Chapters 11 and 12 are powerful enough to be used to implement `Pictures`. Reimplement the material in this chapter to use `Vec<Str>` instead of `vector<string>` and test your implementation.
The reimplemented classes can be found in [Pic_Re.h](./Pic_Re.h). The driver program can be found in [q06.cpp](./q06.cpp).