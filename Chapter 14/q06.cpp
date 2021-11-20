#include <iostream>
#include <algorithm>
#include <vector>
#include "Str_Ctr.h"

using std::cout;
using std::endl;
using std::find_if;
using std::copy;
using std::max;
using std::vector;

vector<Str> split(const Str& s)
{
    vector<Str> ret;
    typedef Str::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size()) {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            ++j;

        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and taking j - i chars
            ret.push_back(Str(s.begin() + i, s.begin() + j));
            i = j;
        }
    }
    return ret;
}

bool not_isspace(char c)
{
    return !isspace(c);
}

vector<Str> other_split(const Str& str)
{
    typedef Str::const_iterator iter;
    vector<Str> ret;

    iter i = str.begin();
    while (i != str.end()) {

        // ignore leading blanks
        i = find_if(i, str.end(), not_isspace);

        // find end of next word
        iter j = find_if(i, str.end(), isspace);

        // copy the characters in [i, j)
        if (i != str.end())
            ret.push_back(Str(i, j));
        i = j;
    }
    return ret;
}

Str::size_type width(const vector<Str>& v)
{
    Str::size_type maxlen = 0;
    for (vector<Str>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<Str> frame(const vector<Str>& v)
{
    vector<Str> ret;
    Str::size_type maxlen = width(v);
    Str border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk and a space
    for (vector<Str>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] +
                      Str(maxlen - v[i].size(), ' ') + " *");
    }

    // write the bottom border
    ret.push_back(border);
    return ret;
}

vector<Str> vcat(const vector<Str>& top, const vector<Str>& bottom)
{
    // copy the top picture
    vector<Str> ret(top);

    // copy entire bottom picture
    for (vector<Str>::const_iterator it = bottom.begin();
         it != bottom.end(); ++it)
        ret.push_back(*it);

    return ret;
}

vector<Str> hcat(const vector<Str>& left, const vector<Str>& right)
{
    vector<Str> ret;

    // add 1 to leave a space between pictures
    Str::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<Str>::size_type i = 0, j = 0;

    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size()) {
        // construct new Str to hold characters from both pictures
        Str s;

        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];
        
        // pad to full width
        s += Str(width1 - s.size(), ' ');

        // copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];

        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}

int main()
{
    Str s1 = "Hello, world!";
    Str s2 = "Goodbye, world!";
    vector<Str> f1 = frame(split(s1));
    vector<Str> f2 = frame(other_split(s2));

    vector<Str> v = vcat(f1, f2);
    vector<Str> h = hcat(f1, f2);

    for (vector<Str>::size_type i = 0; i != v.size(); ++i)
        cout << v[i] << endl;

    for (vector<Str>::size_type i = 0; i != h.size(); ++i)
        cout << h[i] << endl;

    return 0;
}