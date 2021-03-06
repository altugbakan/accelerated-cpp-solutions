#include <iostream>
#include <vector>
#include <string>
#include "read_words.h"

// program that counts the number of words in the input

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<string> words;
    vector<string>::size_type count = 0;

    // ask for string input
    cout << "Enter a sentence, followed by end-of-file: " << endl;

    // using the created function
    read_words(cin, words);
    
    // write the result
    cout << "There are " << words.size() << " words in the input." << endl;

    return 0;
}