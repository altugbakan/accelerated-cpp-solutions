## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.
The programs in this chapter are compiled and tested. The programs can be found in the book.

### Q1: Design and implement a program to produce a permuted index. A permuted index is one in which each phrase is indexed by every word in the phrase. So, given the following input,
```
The quick brown fox
jumped over the fence
```
### the output would be
```
      The quick    brown fox
jumped over the    fence
The quick brown    fox
                   jumped over the fence
         jumped    over the fence
            The    quick brown fox
    jumped over    the fence
                   The quick brown fox
```
### A good algorithm is suggested in *The AWK Programming Language* by Aho, Kernighan, and Weinberger (Addison-Wesley, 1988). That solution divides the problem into three steps:

### &emsp; 1. Read each line of the input and generate a set of rotations of that line. Each rotation puts the next word of the input in the first position and rotates the previous first word to the end of the phrase. So the output of this phase for the first line of our input would be
```
The quick brown fox
quick brown fox The
brown fox The quick
fox The quick brown
```
### Of course, it will be important to know where the original phrase ends and where the rotated beginning begins.
### &emsp; 2. Sort the rotations.
### &emsp; 3. Unrotate and write the permuted index, which involves finding the separator, putting the phrase back together, and writing it properly formatted.
The solution of this problem can be found in *q01.cpp*. It follows the algorithm explained in the question, which can be examined in *Rotation.cpp*. The `split` function from §5.6/88 in the book is also used to break the input lines into words.

### Q2: Write the complete new version of the student-grading program, which extracts records for failing students, using `vector`s. Write another that uses `list`s. Measure the performance difference on input files of ten lines, 1,000 lines, and 10,000 lines.
The `vector` based solution and the `list` based solution can be found in *q02-1.cpp* and *q02-2.cpp* respectively. For ten lines, the amount of seconds cannot be estimated as it finishes quickly. For 1,000 lines, the `vector` based solution took 0.004 seconds and the `list` based solution took 0.001 seconds, showing 4 times the performance. for 10,000 lines, the `vector` based solution took 0.345 seconds and the `list` based solution took 0.007 seconds, showing nearly 50 times the performance. The tests are conducted on an Intel Core i5-10600KF CPU @ 4.10GHz.

### Q3: By using a `typedef`, we can write one version of the program that implements either a `vector`-based solution or a `list`-based one. Write and test this version of the program.
A `typedef` which has the name `student_container` is created in *q03.cpp*. By setting this value to `vector<Student_info>` or `list<Student_info>` and including the corresponding directive, we can easily swap our implementation between containers.

### Q4: Look again at the driver functions you wrote in the previous exercise. Note that it it possible to write a driver that differs only in the declaration of the type for the data structure that holds the input file. If your `vector` and `list` test drivers differ in any other way, rewrite them so that they differ only in this declaration.
The solution in *q03.cpp* already only uses functions that are defined for both `vector` and `list`.

### Q5: Write a function named `center(const vector<string>&)` that returns a picture which all the lines in the original picture are padded out to their full width, and the padding is as evenly divided as possible between the left and right sides of the picture. What are the properties of pictures for which such a function is useful? How can you tell whether a given picture has those properties?
The solution can be found in *q05.cpp*. The `split` function from §5.6/88 in the book is used to get only the words from a line. This function is useful for pictures that have non zero and even number of paddings. A sample output can be seen below.
```
*************           *************
* hello     *           *   hello   *
* my name   *   =>      *  my name  *
* is Altug! *           * is Altug! *
*************           *************
```

### Q6: Rewrite the `extract_fails` function from §5.1.1/77 so that instead of erasing each failing student from the input vector `students`, it copies the records for the passing students to the beginning of `students`, and then uses the `resize` function to remove the extra elements from the end of `students`. How does the performance of this version compare with the one in §5.1.1/77?
The comparison of both implementations can be found in *q06.cpp*. For 10,000 students, the results were 0.351 seconds for the original implementation and 0.911 seconds for the modified implementation. We can see that adding elements to the start of `vector` and resizing is slower than erasing elements from the `vector`.

### Q7: Given the implementation of `frame` in §5.8.1/93, and the following code fragment
```
vector<string> v;
frame(v);
```
### describe what happens in this call. In particular, trace through how both the `width` function and the `frame` function operate. Now, run this code. If the results differ from your expectations, first understand why your expectations and the program differ, and then change one to match the other.
My expectation was for the program to output nothing, as the `width` function will return 0 and loops will be skipped. The program in *q07.cpp* shows that this is the case.

### Q8: In the `hcat` function from §5.8.3/95, what would happen if we defined `s` outside the scope of the `while`? Rewrite and execute the program to confirm your hypothesis.

### Q9: Write a program to write the words in the input that do not contain any uppercase letters followed by the words that contain one or more uppercase letters.

### Q10: Palindromes are words that are spelled the same right to left as left to right. Write a program to find all palindromes in a dictionary. Next, find the longest palindrome.

### Q11: In text processing it is sometimes useful to know whether a word has any ascenders or descenders. Ascenders are the parts of lowercase letters that extend above the text line; in the English alphabet, the letters b, d, f, h, k, l, and t have ascenders. Similarly, the descenders are the parts of lowercase letters that descend below the line; in English, the letters, g, j, p, q, and y have descenders. Write a program to determine if a word has any ascenders or descenders. Extend the program to find the longest word in the dictionary that has neither ascenders nor descenders.