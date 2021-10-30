#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::vector;
using std::string;

int main()
{
    string s;
    map<string, int> counters; // store each word and an associated counter

    // read the input, keeping track of each word and how often we see it
    while (cin >> s)
        ++counters[s];

    map<int, vector<string> > occurences; // group counts of the occurences

    // fill the occurences
    for (map<string, int>::const_iterator it = counters.begin();
         it != counters.end(); ++it) {
        occurences[it->second].push_back(it->first);
    }

    // write the words and associated counts
    for (map<int, vector<string> >::const_iterator it = occurences.begin();
         it != occurences.end(); ++it) {
        // write the count
        cout << "words that occur " << it->first << " time(s): ";
        
        // followed by one or more words
        vector<string>::const_iterator word_it = it->second.begin();
        cout << *word_it; // write the first word number

        ++word_it;
        // write the rest of the words, if any
        while (word_it != it->second.end()) {
            cout << ", " << *word_it; 
            ++word_it;
        }
        // write a new line to separate each count from the next
        cout << endl;
    }

    return 0;
}