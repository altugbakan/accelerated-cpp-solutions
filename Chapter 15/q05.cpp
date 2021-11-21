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
    // create the initial pictures
    vector<string> init1;
    init1.push_back("Hello,");
    init1.push_back("World!");
    vector<string> init2;
    init2.push_back("Greetings");
    init2.push_back("to");
    init2.push_back("planet");
    init2.push_back("Earth!");


    Picture p1 = frame(init1);
    Picture p2 = frame(init2);

    cout << hcat(p1, p2) << endl;
    cout << hcat(p2, p1) << endl;

    return 0;
}