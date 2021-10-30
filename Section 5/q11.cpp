#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

bool is_ascender_or_descender(char c)
{
    return c == 'b' || c == 'd' || c == 'f' || c == 'h' ||
        c == 'k' || c == 'l' || c == 'g' || c == 'j' ||
        c == 'p' || c == 'q' || c == 'y';
}

bool has_ascender_or_descender(string s)
{
    // search all characters
    for (string::const_iterator it = s.begin();
        it != s.end(); ++it)
        if (is_ascender_or_descender(*it))
            return true;
    
    return false;
}

int main()
{
    vector<string> words;
    string word;
    string longest_word;
    string::size_type max_length = 0;
    // read all input
    while (cin >> word)
        if (has_ascender_or_descender(word))
            words.push_back(word);
        else {
            string::size_type size = word.size();
            // update the longest word
            if (size > max_length) {
                longest_word = word;
                max_length = size;
            }
        }

    // output the results
    cout << "The words that have ascenders or descenders are: ";
    for (vector<string>::const_iterator it = words.begin();
        it != words.end() - 1; ++it)
        cout << *it << ", ";
    // output the last word
    cout << *(words.end() - 1) << "." << endl << endl;
    cout << "The longest word that does not have ascenders or "
        "descenders is \"" << longest_word << "\" with " << max_length
        << " letters." << endl;

    return 0;
}