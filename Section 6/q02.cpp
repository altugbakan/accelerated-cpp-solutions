#include <iostream>
#include "find_urls.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    // create an example text
    const string test = "Hello, welcome to my GitHub! The link to my"
        "repository is https://github.com/altugbakan/accelerated-cpp-solutions"
        " and the link to the book's website is http://www.acceleratedcpp.com/";

    // find the urls
    vector<string> urls = find_urls(test);

    // output the results
    cout << "Found URLs are: " << endl;
    for (vector<string>::const_iterator it = urls.begin();
        it != urls.end(); ++it)
        cout << *it << endl;

    return 0;
}