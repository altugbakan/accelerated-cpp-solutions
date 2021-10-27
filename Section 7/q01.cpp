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
        cout << "words that occur " << it->first << " time"
            << (it->first > 1 ? "s:\t" : ":\t");
        
        for (vector<string>::const_iterator sit = it->second.begin();
            sit != it->second.end() - 1; ++sit) {
            cout << *sit << ", ";
        }
        // write the last word without a comma
        cout << *(it->second.end() - 1) << endl;
    }

    return 0;
}