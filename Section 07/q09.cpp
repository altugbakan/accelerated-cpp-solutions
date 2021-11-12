#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::domain_error;

// return a random integer in the range [0, n)
int nrand(int n)
{
    if (n <= 0)
        throw domain_error("Argument to nrand is out of range");
    
    const int buckets = n / RAND_MAX;

    const int last_bucket = RAND_MAX / (n % RAND_MAX);
    int r;

    do r = rand() / last_bucket;
    while (r >= n);

    // add the remaining buckets for numbers larger than RAND_MAX
    for (int i = 0; i < buckets; ++i) {
        r += rand();
    }
    
    return r;
}

int main()
{
    cout << "RAND_MAX is " << RAND_MAX << endl;

    cout << "The results for n = 100000 are: ";
    // get 5 samples
    for (int i = 0; i < 5; ++i) {
        cout << nrand(100000) << " ";
    }

    cout << endl << "The results for n = 100 are: ";
    // get 5 samples
    for (int i = 0; i < 5; ++i) {
        cout << nrand(100) << " ";
    }

    cout << endl;
    return 0;
}