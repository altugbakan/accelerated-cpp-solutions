#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

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

    // output the results
    cout << "The palindromes are: ";
    for (vector<string>::const_iterator it = palindromes.begin();
        it != palindromes.end() - 1; ++it)
        cout << *it << ", ";
    // output the last palindrome
    cout << *(palindromes.end() - 1) << "." << endl << endl;
    cout << "The longest palindrome is \"" << longest_word
        << "\" with " << max_length << " letters." << endl;

    return 0;
}