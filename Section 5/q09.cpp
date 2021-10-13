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
    for (string::const_iterator i = word.begin();
        i != word.end(); ++i)
        if (isupper(*i))
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
    for (list<string>::const_iterator i = lower.begin();
        i != lower.end(); ++i)
        cout << *i << " ";
    
    // output words that contain uppercase
    for (list<string>::const_iterator i = upper.begin();
        i != upper.end(); ++i)
        cout << *i << " ";
}