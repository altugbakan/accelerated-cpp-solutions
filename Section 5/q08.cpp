#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::max;
using std::cout;
using std::endl;

// code taken from §5.8.1/92
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

// code taken from §5.8.3/95, modified to define s
// outside the scope of the while
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;

    // define s here
    string s;

    while (i != left.size() || j != right.size()) {
        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];

        // pad to full width
        s += string(width1 - s.size(), ' ');

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
    vector<string> picture;
    // create a picture
    picture.push_back("*************");
    picture.push_back("* hello     *");
    picture.push_back("* my name   *");
    picture.push_back("* is Altug! *");
    picture.push_back("*************");

    vector<string> another_picture;
    // create another picture to horizontally concatenate
    picture.push_back("***************");
    picture.push_back("* I am        *");
    picture.push_back("* programming *");
    picture.push_back("* in C++!     *");
    picture.push_back("***************");

    // concatenate
    vector<string> result = hcat(picture, another_picture);
    // the code throws an exception if we switch the parameters
    // vector<string> result = hcat(picture, another_picture);

    for (vector<string>::const_iterator line = result.begin();
        line != result.end(); ++line) {
        cout << *line << endl;
    }

    return 0;
}