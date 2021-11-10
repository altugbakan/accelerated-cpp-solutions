#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class For1, class For2>
bool equal(For1 b, For1 e, For2 b2)
{
    while (b != e) {
        if (*b != *b2)
            return false;
        ++b; ++b2;
    }
    return true;
}

template <class For1, class For2>
For1 search(For1 b, For1 e, For2 b2, For2 e2)
{
    while (b != e) {
        For1 bi = b;
        For2 b2i = b2;
        while (*bi == *b2i) {
            ++bi; ++b2i;
            if (b2i == e2)
                return b;
            if (bi == e)
                return e;
        }
        ++b;
    }
    return e;
}

template <class In, class T>
In find(In b, In e, const T& t)
{
    while (b != e) {
        if (*b == t)
            return b;
        ++b;
    }
    return e;
}

template <class In, class Pred>
In find_if(In b, In e, Pred p)
{
    while (b != e) {
        if (p(*b))
            return b;
        ++b;
    }
    return e;
}


template <class In, class Out>
Out copy(In b, In e, Out d)
{
    while (b != e) {
        *d = b;
        ++b; ++d;
    }
    return d;
}

template <class In, class Out, class T>
Out remove_copy(In b, In e, Out d, T t)
{
    while (b != e) {
        if (*b != t) {
            *d = *b;
            ++d;
        }
        ++b;
    }
    return d;
}

template <class In, class Out, class Pred>
Out remove_copy_if(In b, In e, Out d, Pred p)
{
    while (b != e) {
        if (!p(*b)) {
            *d = *b;
            ++d;
        }
        ++b;
    }
    return d;
}

template <class For, class T>
For remove(For b, For e, T t)
{
    For i = b;
    while (b != e) {
        if (*b != t) {
            *i = *b;
            ++i;
        }
        ++b;
    }
    return i;
}

template <class In, class Out, class Func>
Out transform(In b, In e, Out d, Func f)
{
    while (b != e) {
        *d = f(*b);
        ++b; ++d;
    }
    return d;
}

template <class Bi, class Pred>
Bi partition(Bi b, Bi e, Pred p)
{
    while (b != e) {
        while (p(*b)) {
            ++b;
            if (b == e)
                return b;
        }
        do {
            --e;
            if (b == e)
                return b;
        } while (!p(*e));
        Bi tmp = b;
        *b = *e;
        *e = *tmp;
        ++b;
    }
    return b;
}

template <class In, class T>
T accumulate(In b, In e, T t)
{
    while (b != e) {
        t += *b;
        ++b;
    }
    return t;
}

bool less_than_5(int i)
{
    return i < 5;
}

int main()
{
    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(2);
    numbers.push_back(9);
    numbers.push_back(8);
    numbers.push_back(1);
    numbers.push_back(3);

    // write the original vector
    cout << "The original vector is: " << numbers[0];
    for (vector<int>::const_iterator it = numbers.begin() + 1;
        it != numbers.end(); ++it)
        cout << ", " << *it;
    cout << endl;

    // partition the numbers using less_than_5
    partition(numbers.begin(), numbers.end(), less_than_5);

    // write the partitioned vector
    cout << "The partitioned vector is: "<< numbers[0];
    for (vector<int>::const_iterator it = numbers.begin() + 1;
        it != numbers.end(); ++it)
        cout << ", " << *it;
    cout << endl;

    return 0;
}