#include "Rotation.h"

using std::string;
using std::vector;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::sort;
using std::max;
using std::min;

typedef string::size_type str_sz;
typedef vector<string>::size_type vec_str_sz;

// get every rotation for a line
vector<Rotation> get_rotations(const string& line)
{
    vector<Rotation> rotations;
    vector<string> words = split(line);

    vec_str_sz size = words.size();
    for (vec_str_sz i = 0; i < size; ++i) {
        Rotation r;
        r.start = (size - i) % size;
        for (vec_str_sz j = 0; j < size; ++j)
            r.words.push_back(words[(j + i) % size]);

        rotations.push_back(r);
    }

    return rotations;
}

// we can get the first width by adding the width of first
// (size - 1) words and (size - 2) spaces of rotations
str_sz first_width(const Rotation& rotation)
{
    str_sz width = 0;

    // if the rotation is unsorted
    if (rotation.start != 0) {
        vec_str_sz size = rotation.words.size();
        // invariant: we have processed i words of the rotation
        for (vec_str_sz i = rotation.start; i < size; ++i)
            width += rotation.words[i].size();

        // add spaces between words
        width += size - rotation.start - 1;
    }

    return width;
}

// we can get the longest first part width by finding the
// widths where start is 1, and returning the maximum
str_sz first_width(const vector<Rotation>& rotations)
{
    str_sz longest = 0;
    // invariant: we have processed i rotations
    for (vector<Rotation>::const_iterator i = rotations.begin();
        i != rotations.end(); ++i)
        // if words are ordered originally
        if (i->start == 1)
            longest = max(longest, first_width(*i));

    return longest;
}

// format the rotation by adding 4 spaces to the first word,
// unrotate, and add spaces to fit in max width
string format_rotation(Rotation& rotation, str_sz max_width)
{
    // get the width of the first part of the rotation
    str_sz width = first_width(rotation);

    // add 4 spaces to the first word in order to align,
    // add 5 if the words are sorted
    if (rotation.start == 0)
        rotation.words[0] = string(5, ' ') + rotation.words[0];
    else
        rotation.words[0] = string(4, ' ') + rotation.words[0];

    // add spaces equal to the difference between max_width and
    // width to the starting word
    rotation.words[rotation.start] = string(max_width - width, ' ') +
        rotation.words[rotation.start];

    // unrotate the rotation
    string line;
    vec_str_sz size = rotation.words.size();
    // invariant: we have processed i words of the rotation
    for (vec_str_sz i = 0; i < size; ++i) {
        line += rotation.words[(rotation.start + i) % size];
        // add spaces between words
        if ((i + 1) != size)
            line += " ";
    }

    return line;
}

// compare first words of the rotations converted to lowercase
bool compare(const Rotation& x, const Rotation& y)
{
    string word_x = x.words[0];
    string word_y = y.words[0];
    str_sz x_length = word_x.length();
    str_sz y_length = word_y.length();
    // convert to lowercase
    for (str_sz i = 0; i < x_length; ++i)
        word_x[i] = tolower(word_x[i]);

    for (str_sz i = 0; i < y_length; ++i)
        word_y[i] = tolower(word_y[i]);

    // if words are equal, return unconverted versions with
    // lower case < upper case, the opposite of the string
    // comparison implementation
    if (word_x != word_y)
        return word_x < word_y;
    else
        return x.words[0] > y.words[0];
}