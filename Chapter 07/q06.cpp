#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <string>
#include "../Chapter 05/split.h"

using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::logic_error;
using std::domain_error;
using std::map;
using std::vector;
using std::string;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// code is taken from §7.4.2/131
// read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // read the input
    while (getline(in, line)) {

        // split the input into words
        vector<string> entry = split(line);

        if (!entry.empty())
            // use the category to store the associated rule
            ret[entry[0]].push_back(
                Rule(entry.begin() + 1, entry.end()));
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

// code is taken from §7.4.3/132
vector<string> gen_sentence(const Grammar& g)
{
    vector<string> rules; // holds the rules
    vector<string> sentence; // holds the generated sentence

    rules.push_back("<sentence>");
    while (!rules.empty()) {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(rules[0]);
        if (it == g.end())
            throw logic_error("empty rule");

        // fetch the set of possible rules
        const Rule_collection& c = it->second;

        // from which we select one at random
        const Rule& r = c[nrand(c.size())];

        // remove the used rule
        rules.erase(rules.begin());

        // add results to their vectors
        Rule::iterator rule_it = rules.begin();
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
            if (bracketed(*i)) {
                rule_it = rules.insert(rule_it, *i);
                ++rule_it;
            }
            else
                sentence.push_back(*i);
        }
    }
    
    return sentence;
}

// code is taken from §7.4.3/134
int main()
{
    // generate the sentence
    vector<string> sentence = gen_sentence(read_grammar(cin));

    // write the first word, if any
    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }
    
    // write the rest of the words, each preceded by a space
    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }

    cout << endl;
    return 0;
}