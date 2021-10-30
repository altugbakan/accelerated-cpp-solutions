#include "read_words.h"
#include <algorithm>

// program that counts how many times each word occured

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::sort;

typedef vector<string>::size_type vec_sz;

int main()
{
    vector<string> words;

    // ask for string input
    cout << "Enter a sentence, followed by end-of-file: " << endl;

    // using the created function
    read_words(cin, words);
    
    // sort the vector to group same words
    sort(words.begin(), words.end());

    // write the results
    string word = words[0];
    vec_sz count = 0;
    for (vec_sz i = 0; i < words.size(); ++i)
        if (word != words[i]) {
            cout << "Word " << word << " appeared "
                << ++count << " time" << (count > 1 ? "s." : ".") << endl;
            word = words[i];
            count = 0;
        } else
            ++count;

    return 0;
}