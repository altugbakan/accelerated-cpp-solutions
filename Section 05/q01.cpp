#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "Rotation.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::istream;
using std::sort;

// read every line in an input stream until end-of-file
list<string> read_each_line(istream& in)
{
    list<string> lines;
    string s;
    // read each line and add them to a vector
    while (getline(in, s))
        lines.push_back(s);
    
    return lines;
}

int main()
{
    // using list for optimization, as we will only
    // iterate over read lines
    list<string> lines = read_each_line(cin);

    // Save the rotations for each vector
    vector<Rotation> rotations;

    // loop for each line
    for (list<string>::const_iterator it = lines.begin();
        it != lines.end(); ++it) {
        // save each line's rotations and concatenate them
        // to the rotations vector
        vector<Rotation> lr = get_rotations(*it);
        rotations.insert(rotations.end(), lr.begin(), lr.end());
    }
    
    // sort and format the permutations
    sort(rotations.begin(), rotations.end(), compare);

    // write the results
    string::size_type max_width = first_width(rotations);
    for (vector<Rotation>::iterator it = rotations.begin();
        it != rotations.end(); ++it)
        cout << format_rotation(*it, max_width) << endl;
    
    return 0;
}