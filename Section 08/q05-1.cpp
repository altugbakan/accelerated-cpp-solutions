#include <iostream>
#include <stdexcept>
#include <map>
#include <list>
#include <string>
#include <iterator>

using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::logic_error;
using std::domain_error;
using std::map;
using std::list;
using std::string;
using std::ostream_iterator;

typedef list<string> Rule;
typedef list<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

list<string> split(const string& s)
{
    list<string> ret;
    typedef string::size_type string_size;
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
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

// read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // read the input
    while (getline(in, line)) {

        // split the input into words
        list<string> entry = split(line);

        if (!entry.empty())
            // use the category to store the associated rule
            ret[*entry.begin()].push_back(
                Rule(++entry.begin(), entry.end()));
    }
    return ret;
}

// code is taken from §7.4.3/132
bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// code is taken from §7.4.4/135
// return a random integer in the range [0, n)
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    
    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}

template <class Out>
void
gen_aux(const Grammar& g, const string& word, Out os)
{
    if (!bracketed(word))
        *os++ = word; // write results to output iterator
    else {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");

        // fetch the set of possible rules
        const Rule_collection& c = it->second;

        // get the nrand'th element of c
        int rand = nrand(c.size());
        Rule_collection::const_iterator rule_it = c.begin();
        for (int i = 0; i < rand; ++i)
            ++rule_it;

        // from which we select one at random
        const Rule& r = *rule_it;

        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, os);
    }
}

template <class Out>
void gen_sentence(const Grammar& g, Out os)
{
    gen_aux(g, "<sentence>", os);
}

int main()
{
    // read the input
    Grammar gr = read_grammar(cin);

    // generate the sentence using output iterator
    cout << "result from ostream: ";
    gen_sentence(gr, ostream_iterator<string>(cout, " "));
    cout << endl;

    // generate the sentence using list<string>
    list<string> sentence;
    cout << "result from list<string>: ";
    gen_sentence(gr, back_inserter(sentence));

    // write the first word, if any
    list<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }
    
    // write the rest of the words, each preceded by a space
    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }

    return 0;
}