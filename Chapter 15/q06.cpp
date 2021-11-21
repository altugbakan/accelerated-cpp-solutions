#include <iostream>
#include "../Chapter 12/Vec.h"
#include "../Chapter 12/Str.h"
#include "Pic_Re.h"

using std::cout;
using std::endl;

int main()
{
    // create the initial picture
    Vec<Str> init;
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