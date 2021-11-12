#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef string::size_type str_sz;
typedef vector<string>::size_type vec_sz;

vector<string> center(const vector<string>& picture)
{
    vector<string> centered_picture = picture;
    // the picture is assumed to be rectangular
    str_sz width = centered_picture[0].size() - 2;
    // iterate over the picture
    for (vector<string>::iterator it = centered_picture.begin();
        it != centered_picture.end(); ++it)
        // skip first and last lines
        if (it != centered_picture.begin() && it != centered_picture.end() - 1) {
            // remove * characters
            (*it)[0] = ' ';
            (*it)[width + 1] = ' ';
            vector<string> words = split(*it);
            string unpadded_line = "";
            // get each word to find the unpadded line
            for (vector<string>::const_iterator jt = words.begin();
                jt != words.end(); ++jt) {
                // add the word to unpadded line
                unpadded_line += *jt;
                // add one space if word is not the last one
                if (jt + 1 != words.end())
                    unpadded_line += " ";
            }
            // get the unpadded line width
            str_sz unpadded_line_width = unpadded_line.size();
            // get the size of the paddings
            str_sz left_padding = (width - unpadded_line_width) / 2;
            str_sz right_padding = width - unpadded_line_width - left_padding;
            // set centered line
            *it = "*" + string(left_padding, ' ') +
                unpadded_line + string(right_padding, ' ') + "*";
        }
    
    return centered_picture;
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

    vector<string> centered_picture = center(picture);

    // picture and centered_picture have the same size
    vec_sz size = picture.size();
    for (vec_sz i = 0; i < size; ++i) {
        cout << picture[i] << "    ";
        if (i == size / 2)
            cout << "=>";
        else
            cout << "  ";
        cout << "    " << centered_picture[i] << endl;
    }

    return 0;
}