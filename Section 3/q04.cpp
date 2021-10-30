#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::sort;

int main()
{
    // ask for string input
    cout << "Enter a sentence, followed by end-of-file: " << endl;

    typedef vector<int>::size_type vec_sz;
    vector<vec_sz> sizes;
    string word;

    // invariant: sizes contains the length of the words read so far
    while (cin >> word)
        sizes.push_back(word.size());
    
    // sort the sizes vector
    sort(sizes.begin(), sizes.end());

    // write the results
    cout << "Shortest length: " << sizes[0] << endl;
    cout << "Longest length: " << sizes[sizes.size() - 1] << endl;
}