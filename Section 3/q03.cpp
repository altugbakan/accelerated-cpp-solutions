#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
    // ask for string input
    cout << "Enter a sentence, followed by end-of-file: " << endl;

    vector<string> words;
    vector<int> counts;
    typedef vector<string>::size_type vec_sz;
    string word;
    vec_sz size;

    // read the sentence
    // invariant: words contains the words read so far
    while (cin >> word) {   
        int found_index = -1;
        size = words.size();
        // search the vector for word
        for (vec_sz i = 0; i < size; i++)
            if (words[i] == word)
                found_index = i;

        // if word exists, increment its count
        if (found_index > 0)
            ++counts[found_index];
        else {
            words.push_back(word);
            counts.push_back(1);
        }
    }

    // write the results
    size = words.size();
    for (vec_sz i = 0; i < size; ++i)
        cout << "Word: " << words[i] << ", Count: " << counts[i] << endl;

    return 0;
}