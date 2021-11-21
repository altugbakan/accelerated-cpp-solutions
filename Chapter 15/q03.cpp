#include <iostream>
#include <vector>
#include <string>
#include "Pic.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    // create the initial picture
    vector<string> init;
    init.push_back("Hello,");
    init.push_back("World!");

    Picture p = init;
    cout << frame(p, '-', '#', '@') << endl;

    return 0;
}