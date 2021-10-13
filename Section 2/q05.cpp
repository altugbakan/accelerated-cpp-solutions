#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    int square_length = 3;
    // invariant: we have written r rows so far
    for (int r = 0; r < square_length; r++)
        cout << string(square_length, '*') << endl;

    cout << endl;
    
    int rectangle_width = 4;
    int rectangle_height = 3;
    // invariant: we have written r rows so far
    for (int r = 0; r < rectangle_height; r++)
        cout << string(rectangle_width, '*') << endl;

    cout << endl;

    int triangle_height = 3;
    // invariant: we have written r rows so far
    for (int r = 0; r < triangle_height; r++) {
        int length = r * 2 + 1;
        int spaces = (triangle_height * 2 - 1 - length) / 2;
        cout << string(spaces, ' ');
        cout << string(length, '*');
        cout << string(spaces, ' ') << endl;
    }

    return 0;
}