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
    Picture q = frame(p);
    Picture r = hcat(p, q);
    Picture s = vcat(q, r);
    Picture t = frame(hcat(s, vcat(r, q)));
    cout << t << endl;

    t.reframe('#', '&', '<');
    cout << t << endl;

    return 0;
}