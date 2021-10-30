#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::domain_error;

bool is_palindrome(string s)
{
    string::size_type length = s.size();
    // create a string with the same size as s
    string ret = s;
    for (string::size_type i = 0; i < length; ++i)
        ret[i] = s[length - i - 1];

    return s == ret;
}

int main()
{
    vector<string> palindromes;
    string word;
    string longest_word;
    string::size_type max_length = 0;
    // read all input
    while (cin >> word)
        if (is_palindrome(word)) {
            palindromes.push_back(word);
            string::size_type size = word.size();
            // update the longest word
            if (size > max_length) {
                longest_word = word;
                max_length = size;
            }
        }

    // check if there are any palindromes
    if (palindromes.size() == 0) {
        throw domain_error("no palindromes found");
    }

    // write the first palindrome
    vector<string>::const_iterator it = palindromes.begin();
    cout << "The palindrome(s) are: " << *it;

    ++it;
    // write the rest of the palindromes, if any
    while (it != palindromes.end()) {
        cout << ", " << *it;
        ++it;
    }
    // write the result
    cout << endl << endl << "The longest palindrome is \"" << longest_word
        << "\" with " << max_length << " letters." << endl;

    return 0;
}