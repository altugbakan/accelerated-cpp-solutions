#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    // create the vector
    vector<string> words;
    words.push_back("hello ");
    words.push_back("my ");
    words.push_back("name ");
    words.push_back("is ");
    words.push_back("Altug");

    // concatenate all elements
    string concatenated_words = accumulate(words.begin(), words.end(), string());

    // write the result
    cout << "The result of concatenation is: " << concatenated_words << endl;

    return 0;
}