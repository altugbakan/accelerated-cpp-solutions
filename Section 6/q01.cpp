#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::max;
using std::cout;
using std::endl;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::const_iterator i = v.begin();
        i != v.end(); ++i)
        maxlen = max(maxlen, i->size());
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk and a space
    for (vector<string>::const_iterator i = v.begin();
        i != v.end(); ++i)
        ret.push_back("* " + *i + string(maxlen - i->size(), ' ') + " *");

    // write the bottom border
    ret.push_back(border);
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;

    // iterators to look at elements from left and right respectively
    vector<string>::const_iterator i = left.begin(), j = right.begin();

    // continue until we've seen all rows from both pictures
    while (i != left.end() || j != right.end()) {
        // construct new string to hold characters from both pictures
        string s;

        // copy a row from the left-hand side, if there is one
        if (i != left.end())
            s = *i++;

        // pad to full width
        s += string(width1 - s.size(), ' ');

        // copy a row from the right-hand side, if there is one
        if (j != right.end())
            s += *j++;

        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}

 // test reimplemented functions
int main()
{
    // create two vectors
    vector<string> left;
    left.push_back("hello");
    left.push_back("my name");
    left.push_back("is Altug");

    vector<string> right;
    right.push_back("I am");
    right.push_back("programming");
    right.push_back("in C++!");

    // frame the vectors
    vector<string> framed_left = frame(left);
    vector<string> framed_right = frame(right);

    // horizontally concatenate
    vector<string> concatenated = hcat(framed_left, framed_right);

    // output the results
    for (vector<string>::const_iterator i = concatenated.begin();
        i != concatenated.end(); ++i)
        cout << *i << endl;

    return 0;
}