#include "read_words.h"

using std::istream;
using std::vector;
using std::string;

istream& read_words(istream& is, vector<string>& words)
{
    if (is) {
        string word;

        // clear the vector
        words.clear();

        // read and store the words
        while (is >> word) {
            words.push_back(word);
        }

        // reset the error state
        is.clear();
    }
    
    return is;
}

