#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class ForwardIterator1, class ForwardIterator2>
bool equal(ForwardIterator1 b, ForwardIterator1 e, ForwardIterator2 b2)
{
    while (b != e) {
        if (*b != *b2)
            return false;
        ++b; ++b2;
    }
    return true;
}

template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 b, ForwardIterator1 e,
                      ForwardIterator2 b2, ForwardIterator2 e2)
{
    while (b != e) {
        ForwardIterator1 bi = b;
        ForwardIterator2 b2i = b2;
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

template <class InputIterator, class T>
InputIterator find(InputIterator b, InputIterator e, const T& t)
{
    while (b != e) {
        if (*b == t)
            return b;
        ++b;
    }
    return e;
}

template <class InputIterator, class Predicate>
InputIterator find_if(InputIterator b, InputIterator e, Predicate p)
{
    while (b != e) {
        if (p(*b))
            return b;
        ++b;
    }
    return e;
}


template <class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator b, InputIterator e, OutputIterator d)
{
    while (b != e) {
        *d = b;
        ++b; ++d;
    }
    return d;
}

template <class InputIterator, class OutputIterator, class Type>
OutputIterator remove_copy(InputIterator b, InputIterator e,
                              OutputIterator d, Type t)
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

template <class InputIterator, class OutputIterator, class Predicate>
OutputIterator remove_copy_if(InputIterator b, InputIterator e,
                              OutputIterator d, Predicate p)
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

template <class ForwardIterator, class Type>
ForwardIterator remove(ForwardIterator b, ForwardIterator e, Type t)
{
    ForwardIterator i = b;
    while (b != e) {
        if (*b != t) {
            *i = *b;
            ++i;
        }
        ++b;
    }
    return i;
}

template <class InputIterator, class OutputIterator, class Function>
OutputIterator transform(InputIterator b, InputIterator e,
                         OutputIterator d, Function f)
{
    while (b != e) {
        *d = f(*b);
        ++b; ++d;
    }
    return d;
}

template <class BidirectionalIterator, class Predicate>
BidirectionalIterator partition(BidirectionalIterator b, BidirectionalIterator e,
                                Predicate p)
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
        BidirectionalIterator tmp = b;
        *b = *e;
        *e = *tmp;
        ++b;
    }
    return b;
}

template <class InputIterator, class Type>
Type accumulate(InputIterator b, InputIterator e, Type t)
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