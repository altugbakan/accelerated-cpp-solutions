#include <iostream>
#include <list>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
using std::isupper;

bool is_all_lower(string word)
{
    for (string::const_iterator it = word.begin();
        it != word.end(); ++it)
        if (isupper(*it))
            return false;
    return true;
}

int main()
{
    list<string> upper;
    list<string> lower;
    string word;
    // read all input
    while (cin >> word)
        if (is_all_lower(word))
            lower.push_back(word);
        else
            upper.push_back(word);
    
    // output all lowercase words
    for (list<string>::const_iterator it = lower.begin();
        it != lower.end(); ++it)
        cout << *it << " ";
    
    // output words that contain uppercase
    for (list<string>::const_iterator it = upper.begin();
        it != upper.end(); ++it)
        cout << *it << " ";
}