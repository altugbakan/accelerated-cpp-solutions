#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "../Chapter 05/split.h"

using std::map;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::find;

// find all the lines that refer to each word in the input
map<string, vector<int> >
    xref(istream& in,
    vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    // read the next line
    while (getline(in, line)) {
        ++line_number;

        // break the input line into words
        vector<string> words = find_words(line);

        // remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it)
             // push if it does not exist already
             if (find(ret[*it].begin(), ret[*it].end(), line_number)
                == ret[*it].end())
                ret[*it].push_back(line_number);             
    }
    return ret;
}

int main()
{
    // call xref using split by default
    map<string, vector<int> > ret = xref(cin);

    // write the results
    for (map<string, vector<int> >::const_iterator it = ret.begin();
        it != ret.end(); ++it) {
        
        // write the word
        cout << it->first << " occurs on line"
             << (it->second.size() > 1 ? "s: " : ": ");

        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it; // write the first line number

        ++line_it;
        // write the rest of the line numbers, if any
        while (line_it != it->second.end()) {
            cout << ", ";
            
            // break up the output line after 15 lines
            if ((line_it - it->second.begin()) % 15 == 0) {
                cout << endl;
            }
            cout << *line_it;
            ++line_it;
        }
        // write a new line to separate each word from the next
        cout << endl;
    }

    return 0;
}