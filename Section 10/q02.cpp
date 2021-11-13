#include <stdexcept>
#include <vector>
#include <algorithm>

using std::domain_error;
using std::vector;
using std::sort;

template <class T, class Ran>
T median(Ran b, Ran e)
{
    vector<T> v(b, e);

    typedef typename vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("median of an empty container");

    sort(v.begin(), v.end());

    size_t mid = size / 2;

    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid]; 
}